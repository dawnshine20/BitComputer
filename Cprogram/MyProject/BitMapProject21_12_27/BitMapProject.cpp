#pragma region 이효빈 과제1

#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>    // fopen, fread, fseek, fprintf, fclose 함수가 선언된 헤더 파일
#include <stdlib.h>   // malloc, free 함수가 선언된 헤더 파일

#pragma pack(push, 1)                // 구조체를 1바이트 크기로 정렬

//typedef struct TEST     // BMP 비트맵 파일 헤더 구조체
//{
//    char a;
//    short b;
//} BITMAPFILEHEADER;
//4의 배수값으로 값이 나옴 = sizeof(TEST);
//그러나 #pragma pack(push, 1)를 사용해서 최적화

typedef struct _BITMAPFILEHEADER     // BMP 비트맵 파일 헤더 구조체
{
    unsigned short bfType;           // BMP 파일 매직 넘버
    unsigned int   bfSize;           // 파일 크기
    unsigned short bfReserved1;      // 예약
    unsigned short bfReserved2;      // 예약
    unsigned int   bfOffBits;        // 비트맵 데이터의 시작 위치
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
    unsigned int   biSize;           // 현재 구조체의 크기
    int            biWidth;          // 비트맵 이미지의 가로 크기
    int            biHeight;         // 비트맵 이미지의 세로 크기
    unsigned short biPlanes;         // 사용하는 색상판의 수
    unsigned short biBitCount;       // 픽셀 하나를 표현하는 비트 수
    unsigned int   biCompression;    // 압축 방식
    unsigned int   biSizeImage;      // 비트맵 이미지의 픽셀 데이터 크기
    int            biXPelsPerMeter;  // 그림의 가로 해상도(미터당 픽셀)
    int            biYPelsPerMeter;  // 그림의 세로 해상도(미터당 픽셀)
    unsigned int   biClrUsed;        // 색상 테이블에서 실제 사용되는 색상 수
    unsigned int   biClrImportant;   // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE            // 24비트 비트맵 이미지의 픽셀 구조체
{
    unsigned char rgbtBlue;          // 파랑
    unsigned char rgbtGreen;         // 초록
    unsigned char rgbtRed;           // 빨강
} RGBTRIPLE;

#pragma pack(pop)

#define PIXEL_SIZE   3    // 픽셀 한 개의 크기 3바이트(24비트)
#define PIXEL_ALIGN  4    // 픽셀 데이터 가로 한 줄은 4의 배수 크기로 저장됨

int main()
{
    FILE* originalFpBmp;                    // 비트맵 파일 포인터
    FILE* changedFpBmp;             // 텍스트 파일 포인터
    BITMAPFILEHEADER fileHeader;    // 비트맵 파일 헤더 구조체 변수
    BITMAPINFOHEADER infoHeader;    // 비트맵 정보 헤더 구조체 변수

    unsigned char* image;    // 픽셀 데이터 포인터
    int size;                // 픽셀 데이터 크기
    int prevWidth, prevHeight;       // 비트맵 이미지의 가로, 세로 크기
    int padding;             // 픽셀 데이터의 가로 크기가 4의 배수가 아닐 때 남는 공간의 크기

    originalFpBmp = fopen("sample.bmp", "rb");    // 비트맵 파일을 바이너리 모드로 열기
    if (originalFpBmp == NULL)    // 파일 열기에 실패하면
        return 0;         // 프로그램 종료

    // 비트맵 파일 헤더 읽기. 읽기에 실패하면 파일 포인터를 닫고 프로그램 종료
    if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, originalFpBmp) < 1)
    {
        fclose(originalFpBmp);
        return 0;
    }

    // 매직 넘버가 MB가 맞는지 확인(2바이트 크기의 BM을 리틀 엔디언으로 읽었으므로 MB가 됨)
    // 매직 넘버가 맞지 않으면 프로그램 종료
    if (fileHeader.bfType != 'MB')
    {
        fclose(originalFpBmp);
        return 0;
    }

    // 비트맵 정보 헤더 읽기. 읽기에 실패하면 파일 포인터를 닫고 프로그램 종료
    if (fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, originalFpBmp) < 1)
    {
        fclose(originalFpBmp);
        return 0;
    }

    // 24비트 비트맵이 아니면 프로그램 종료
    if (infoHeader.biBitCount != 24)
    {
        fclose(originalFpBmp);
        return 0;
    }

    size = infoHeader.biSizeImage;    // 픽셀 데이터 크기
    prevWidth = infoHeader.biWidth;       // 비트맵 이미지의 가로 크기
    prevHeight = infoHeader.biHeight;     // 비트맵 이미지의 세로 크기

    // 이미지의 가로 크기에 픽셀 크기를 곱하여 가로 한 줄의 크기를 구하고 4로 나머지를 구함
    // 그리고 4에서 나머지를 빼주면 남는 공간을 구할 수 있음.
    // 만약 남는 공간이 0이라면 최종 결과가 4가 되므로 여기서 다시 4로 나머지를 구함
    padding = (PIXEL_ALIGN - ((prevWidth * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;

    if (size == 0)    // 픽셀 데이터 크기가 0이라면
    {
        // 이미지의 가로 크기 * 픽셀 크기에 남는 공간을 더해주면 완전한 가로 한 줄 크기가 나옴
        // 여기에 이미지의 세로 크기를 곱해주면 픽셀 데이터의 크기를 구할 수 있음
        size = (prevWidth * PIXEL_SIZE + padding) * prevHeight;
    }

    image = (unsigned char*)malloc(size);    // 픽셀 데이터의 크기만큼 동적 메모리 할당

    // 파일 포인터를 픽셀 데이터의 시작 위치로 이동
    fseek(originalFpBmp, fileHeader.bfOffBits, SEEK_SET);

    // 파일에서 픽셀 데이터 크기만큼 읽음. 읽기에 실패하면 파일 포인터를 닫고 프로그램 종료
    if (fread(image, size, 1, originalFpBmp) < 1)
    {
        fclose(originalFpBmp);
        return 0;
    }

    fclose(originalFpBmp);    // 비트맵 파일 닫기


    ///////////// 여기서부터는 비트맵 쓰기 영역//////////////////////////

    changedFpBmp = fopen("changed.bmp", "wb");    // 결과 출력용 bmp 파일 열기
    if (changedFpBmp == NULL)    // 파일 열기에 실패하면
    {
        free(image);      // 픽셀 데이터를 저장한 동적 메모리 해제
        return 0;         // 프로그램 종료
    }


    infoHeader.biWidth = prevWidth / 2;       // 비트맵 이미지의 가로 크기
    infoHeader.biHeight = prevHeight / 2;     // 비트맵 이미지의 세로 크기

    padding = (PIXEL_ALIGN - ((infoHeader.biWidth * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;

    if (size == 0)    // 픽셀 데이터 크기가 0이라면
    {
        // 이미지의 가로 크기 * 픽셀 크기에 남는 공간을 더해주면 완전한 가로 한 줄 크기가 나옴
        // 여기에 이미지의 세로 크기를 곱해주면 픽셀 데이터의 크기를 구할 수 있음
        size = (infoHeader.biWidth * PIXEL_SIZE + padding) * infoHeader.biHeight;
    }

    infoHeader.biSizeImage = size;    // 픽셀 데이터 크기

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, changedFpBmp);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, changedFpBmp);

    // 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복
    // 세로 크기만큼 반복
    for (int y = 0; y < prevHeight; y++)// 600 > 300
    {
        /*if (y % 2 != 0) 최적화 논리에 맞지 않음
            continue;*/

        // 가로 크기만큼 반복
        for (int x = 0; x < prevWidth; x++) // 800 >> 400
        {
            // 일렬로 된 배열에 접근하기 위해 인덱스를 계산
            // (x * 픽셀 크기)는 픽셀의 가로 위치
            // (y * (세로 크기 * 픽셀 크기))는 픽셀이 몇 번째 줄인지 계산
            // 남는 공간 * y는 줄별로 누적된 남는 공간

        /*    if (x % 2 != 0) 최적화 논리와 맞지 않음
                continue;*/

            int index = (x * PIXEL_SIZE) + (y * (prevWidth * PIXEL_SIZE)) + (padding * y);

            // 현재 픽셀의 주소를 RGBTRIPLE 포인터로 변환하여 RGBTRIPLE 포인터에 저장
            RGBTRIPLE* pixel = (RGBTRIPLE*)&image[index];

            fwrite(pixel, sizeof(RGBTRIPLE), 1, changedFpBmp);
        }
    }

    fclose(changedFpBmp);    // 텍스트 파일 닫기

    free(image);      // 픽셀 데이터를 저장한 동적 메모리 해제

    return 0;
}
#pragma endregion


#pragma region 정세연 과제1
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#pragma warning (disable:4996)
// 영상의 가로줄은 4바이트의 배수
//#define  WIDTHBYTES(bits)    (((bits)+31)/32*4)
//#define  BYTE                unsigned char
//void main()
//{
//    //  int n = 13;
//    //  q = n / 4; // 3
//    //  r = n % 4; // 1
//    //  if (r != 0)
//    //  {
//    //      result(q + 1) * 4;
//    //  }
//    
//    //  비트맵 주의 사항
//    //  가로해상도 * 4 의 결과를 무조껀 4의 배수로 맞추어주어야 한다
//    //  r g b < ->b g r 반대로 저장되기때문에 색상 반전이 일어날 수 있다.
//    //  위 아래 반전되서 사진 출력됨
//    //  
//    //  7byte 전송 방법
//    //  1 * 7 (7번 날림
//    //  1 + 2 + 4 (3번 날림)
//    //  4 * 2(2번날림)---- - 비트맵 방식 채택(최적화 되기때문 + 그러나 쓸때 없는 1바이트 정보가 들어감 rgb 데이터가 뒤집혔
//    //  
//    //  0x12345678
//    //  12 34 56 78 (x)
//    //  78 56 34 12 <= 리틀 엔디언 < -- - 이러한 이유로 b g r로 구성했음
//    //  
//    //  마이크로 소프트 사에서 최근 jpg, png	처리 api함수 제공하고 있음
//    //  
//    //  t = a;
//    //  a = b;
//    //  b = t;
//    //  위와 아래는 같은 코드이나 위 코드가 훨씬 좋은 코드
//    //  a ^= b ^= a ^= b;
//
//
//    FILE * InFile;
//    FILE * OutFile;
//    BITMAPFILEHEADER  hf;           // "파일정보헤드" 변수 선언 14byte
//    BITMAPINFOHEADER  hInfo;        // "영상정보헤드" 변수 선언 40byte
//    RGBQUAD           hRGBpal[256]; // 팔레트정보를 위한 배열
//                                   // (흑백 또는 256색 비트맵 파일)
//    BYTE * InputImage;
//    BYTE * OutputImage;
//    int rwsize;
//    int out_rwsize;
//    int nBitCount = 1;
//    InFile = fopen("1.bmp", "rb");   // 입력할 파일을 오픈
//    if (InFile == NULL)
//    {
//        printf("영상파일이 없음");
//        return;
//    }
//    // BMP헤드정보의 입력
//    // 파일정보헤드 읽음
//    fread(&hf, sizeof(BITMAPFILEHEADER), 1, InFile);
//    // 파일 타입이 "BM" (0x4D42)인지 검사
//    if (hf.bfType != 0x4d42) // <---아스키코드 BM
//    {
//        printf("에러 : 비트맵 파일이 아닙니다. 프로그램이 종료됩니다.\n");
//        fclose(InFile); // 읽기 파일을 닫아줌
//        exit(1);
//    }
//    // 비트맵 16 진수로 읽어 오는법 열기 -> 파일 -> 연결 프로그램 -> 바이너리 편집기
//    // 영상정보헤드 읽음(40 BYTE)
//    fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, InFile);
//    // 24비트 비트맵은 팔레트가 필요없다.
//    // 비트맵 팔레트는 크기가 가변적일 수 있으므로 주의해야 함
//    // 24비트 비트맵 사용
//    if (hInfo.biBitCount != 24)
//    {
//        // 24비트 비트맵이 아니면 에러메시지 출력 후 종료
//        printf("24비트 bmp만 지원.\n");
//        // 읽기 파일을 닫아줌
//        fclose(InFile);
//    }
//
//    // 한 픽셀에 몇 바이트를 썼는지 구한다.
//        // (8비트는 1바이트)
//    nBitCount = hInfo.biBitCount / 8;
//    // 어떤 비트맵은 비트맵파일헤더의 크기 값에
//    // 쓰레기 값이 들어간 경우가 있으므로
//    // 강제로 값을 넣어준다.
//    hf.bfSize = sizeof(BITMAPFILEHEADER);
//    // 메모리 할당
//    // 저장할 영상메모리 할당
//    printf("-------------------\n");
//    printf("%d\n", hInfo.biSizeImage);
//    InputImage = (BYTE*)malloc(hInfo.biSizeImage);
//    
//    // 현재 이미 이동이 되어있는 상태
//    //fseek(InFile, hf.bfOffBits, SEEK_SET);
//
//    // 영상데이터 읽음
//    fread(InputImage, sizeof(BYTE), hInfo.biSizeImage, InFile);
//    // 읽기 파일을 닫아줌
//    fclose(InFile);
//
//    //InputImage << 리딩 데이터
//
//    // 영상 이미지 저장할 메모리 할당
//    //OutputImage = (BYTE*)malloc(hInfo.biSizeImage);
//
//    SIZE = W * H * 3
//
//    OutputImage = (BYTE*)malloc(SIZE);
//    // 비트맵파일에서 하나의 line이 차지하는 길이를 구함
//    rwsize = WIDTHBYTES(hInfo.biBitCount * hInfo.biWidth);
//    out_rwsize = WIDTHBYTES(hInfo.biBitCount * hInfo.biWidth / 2);
//    printf("-------------------\n");
//    printf("%d", rwsize);
//    //int outputlow, outcolumn;
//    // 영상 이미지 구하기
//    for (int inputlow = 0, outputlow = 0; inputlow < hInfo.biHeight/2; outputlow++, inputlow++) //600 -> 300
//    {
//        for (int incolumn = 0, outcolumn = 0; incolumn < hInfo.biWidth * nBitCount; outcolumn++, incolumn += 4) // 800*3
//        {
//
//            k += inputlow;
//            result =(OutputImage + (outputlow * out_rwsize))
//            red = *(OutputImage + (outputlow * out_rwsize + (outcolumn + count))) = *(InputImage + (inputlow * rwsize + (incolumn + count)));
//            green = *(OutputImage + (outputlow * out_rwsize + (outcolumn + count))) = *(InputImage + (inputlow * rwsize + (incolumn + count)));
//            blue = *(OutputImage + (outputlow * out_rwsize + (outcolumn + count))) = *(InputImage + (inputlow * rwsize + (incolumn + count)));
//            outcolumn += 2; 
//            incolumn += 2;
//        }
//    }//printf("outputlow:%d outcolumn:%d inputlow:%d incolumn:%d\n", outputlow, outcolumn, inputlow, incolumn);
//    // 영상 출력 너비 높이 변경하기
//    hInfo.biWidth = hInfo.biWidth / 2;
//    hInfo.biHeight = hInfo.biHeight / 2;
//    printf("%d %d\n", hInfo.biWidth, hInfo.biHeight);
//    // 영상 출력
//    // 출력할 파일 오픈
//    OutFile = fopen("2.bmp", "wb");
//    // 파일헤드 출력
//    fwrite(&hf, sizeof(char), sizeof(BITMAPFILEHEADER), OutFile);
//    // 영상헤드 출력
//    fwrite(&hInfo, sizeof(char), sizeof(BITMAPINFOHEADER), OutFile);
//    // 영상데이터출력
//    fwrite(OutputImage, sizeof(BYTE), hInfo.biSizeImage / 4, OutFile);
//    fclose(OutFile); // 쓰기 파일을 닫아줌
//    // 메모리 해제
//    free(InputImage);
//    free(OutputImage);
//    printf("완료\n");
//}
#pragma endregion
