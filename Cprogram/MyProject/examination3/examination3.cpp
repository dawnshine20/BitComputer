#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <Windows.h>

typedef struct
{
    int width;
    int height;
    int bmpSize;
	int pictureCnt;
}JSF_INFORMATION;

#define HEADER_SIZE 250         // JSF파일 헤더 사이즈
#define PIXEL_SIZE 3            // 픽셀 한 개의 크기 3바이트(24비트)
#define PIXEL_ALIGN 4           // 픽셀 데이터 가로 한 줄은 4의 배수 크기로 저장됨

RGBTRIPLE changeRGB(short color)
{
	RGBTRIPLE rgbPixel;

	rgbPixel.rgbtRed = (color & 0xF800) >> 8;
	rgbPixel.rgbtGreen = (color & 0x07E0) >> 3;
	rgbPixel.rgbtBlue = (color & 0x001F) << 3;

	return rgbPixel;
}

int main()
{
	JSF_INFORMATION jsfInform;
	memset(&jsfInform, 0, sizeof(JSF_INFORMATION));

	BITMAPFILEHEADER fileHeader;    // 비트맵 파일 헤더 구조체 변수
	BITMAPINFOHEADER infoHeader;    // 비트맵 정보 헤더 구조체 변수
	memset(&fileHeader, 0, sizeof(fileHeader));    // fileHeader이 가리키는 메모리를 0으로 초기화
	memset(&infoHeader, 0, sizeof(infoHeader));    // infoHeader이 가리키는 메모리를 0으로 초기화

	FILE* fpInputFile = NULL;
	FILE* fpOutputFile = NULL;

	RGBTRIPLE rgbPixel;

	RGBTRIPLE rgbSpacePixel; // 검정바탕
	memset(&rgbSpacePixel, 0, sizeof(RGBTRIPLE));    // 초기화를 통해 rgb 검정색으로 설정

	//---------------------------JSF 파일 읽기-----------------------------
	fpInputFile = fopen("0000.JSF", "rb");
	if (fpInputFile == NULL)
	{
		printf("읽기 실패");
		return 0;
	} // 파일 열기에 실패하면

	fseek(fpInputFile, 0, SEEK_SET); // 첫번째 파일포인터
	fseek(fpInputFile, HEADER_SIZE, SEEK_CUR); //처음 위치에서 헤더사이즈byte 뒤로 설정

	fread(&jsfInform.pictureCnt, sizeof(long), 1, fpInputFile);
	printf("그림의 갯수는 : %d개 입니다.\n", jsfInform.pictureCnt);
	fseek(fpInputFile, 26, SEEK_CUR);// 예약어 무시

	fread(&jsfInform.bmpSize, sizeof(long), 1, fpInputFile);
	printf("압축해상도 size는 %d 입니다..\n", jsfInform.bmpSize);

	fread(&jsfInform.width, sizeof(short), 1, fpInputFile);
	printf("가로 size는 : %d입니다.\n", jsfInform.width);
	fread(&jsfInform.height, sizeof(short), 1, fpInputFile);
	printf("세로 size는 : %d입니다.\n\n", jsfInform.height);

	int padding;		    // 픽셀 데이터의 가로 크기가 4의 배수가 아닐 때 남는 공간의 크기
	int pixelDataSize;      // 픽셀 데이터 전체 크기

	padding = (PIXEL_ALIGN - ((jsfInform.width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;
	pixelDataSize = (jsfInform.width * PIXEL_SIZE + padding) * jsfInform.height;

	short* idNumber = new short[jsfInform.height];
	short* color = new short[pixelDataSize];

	for (int y = 0; y < jsfInform.height; y++)
	{
		short setCount = 0; // 세트갯수
		short spaceCount = 0; // 공백갯수
		short pixelCount = 0; // 그림갯수

		fread(idNumber, sizeof(short), 1, fpInputFile); // 식별번호 읽기
		switch (*idNumber)
		{
			case 0: // 전부 공백인 경우
			{
				printf("전부 공백입니다.\n");
				for (int x = 0; x < jsfInform.width; x++)
				{
					fread(color++, sizeof(short), 0, fpInputFile);
				}
			}break;
			case 1: // 전부 그림인 경우
			{
				printf("전부 그림입니다.\n");
				for (int x = 0; x < jsfInform.width; x++)
				{
					fread(color++, sizeof(short), 1, fpInputFile);
				}
			}break;
			
			default: // 공백과 그림이 공존하는 경우
			{
				int temp = 0;
				setCount = *idNumber - 1;
				printf("세트 갯수는 : %d입니다.\n", setCount);

				for (int i = 0; i < setCount; i++)
				{
					fread(&spaceCount, sizeof(short), 1, fpInputFile);//공백갯수
					printf("공백 갯수는 : %d입니다.\n", spaceCount);

					fread(&pixelCount, sizeof(short), 1, fpInputFile);//데이터갯수
					printf("픽셀 갯수는 : %d입니다.\n", pixelCount);
					
					temp += spaceCount;
					temp += pixelCount;

					for (int x = 0; x < spaceCount; x++)
					{
						fread(color++, sizeof(short), 0, fpInputFile);
					}

					for (int x = 0; x < pixelCount; x++)
					{
						fread(color++, sizeof(short), 1, fpInputFile);
					}
				}
				int rest = jsfInform.width - temp - 1;
				printf("남은 공백 갯수는 : %d입니다.\n", rest);

				printf("\n------------------------------\n");
				for (int x = 0; x < rest; x++) // 남은 공백 이미지 읽기
				{
					fread(color++, sizeof(short), 0, fpInputFile);//공백 이미지 읽기

				}
			}break;
		}
	}
		
	fclose(fpInputFile);    // jsf 파일 닫기

	//--------------------------------헤더파일 등록--------------------

	fileHeader.bfType = 'MB';		// 비트맵 타입
	fileHeader.bfSize = 54 + pixelDataSize;//전체 헤더 + 비트맵 이미지 픽셀 데이터 크기
	fileHeader.bfReserved1 = 0x00;
	fileHeader.bfReserved2 = 0x00;
	fileHeader.bfOffBits = 54;		// 비트맵 그림은 54byte 뒤부터 기록

	infoHeader.biSize =		40;					//현재 비트맵 정보 헤더(BITMAPINFOHEADER)의 크기
	infoHeader.biWidth =	73;//jsfInform.width;    // 비트맵 이미지의 가로 크기
	infoHeader.biHeight =	56;//jsfInform.height;   // 비트맵 이미지의 세로 크기
	infoHeader.biSizeImage = pixelDataSize;//비트맵 이미지의 픽셀 데이터 크기(압축 되지 않은 크기)
	infoHeader.biPlanes =	1;					//사용하는 색상판의 수.항상 1입니다.
	infoHeader.biBitCount =	24;					//픽셀 하나를 표현하는 비트 수 (3byte)
	infoHeader.biCompression =	0;				//압축 방식.보통 비트맵은 압축을 하지 않으므로 0입니다.
	infoHeader.biXPelsPerMeter = 0;				//그림의 가로 해상도(미터당 픽셀)
	infoHeader.biYPelsPerMeter = 0;				//그림의 세로 해상도(미터당 픽셀)
	infoHeader.biClrUsed =		0;				//색상 테이블에서 실제 사용되는 색상 수
	infoHeader.biClrImportant =	0;				//비트맵을 표현하기 위해 필요한 색상 인덱스 수

	
	//----------------------------출력파일설정 영역-----------------------------
	
	
	fpOutputFile = fopen("0000.bmp", "wb");
	if (fpOutputFile == NULL)    // 파일 열기에 실패하면
	{
		printf("생성 실패\n");
		return 0;				// 프로그램 종료
	}

	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpOutputFile);
	fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpOutputFile);

	fseek(fpOutputFile, fileHeader.bfOffBits, SEEK_SET); // 파일 포인터를 픽셀 데이터의 시작 위치로 이동

	//----------------------------쓰기 영역-----------------------------

	//for (int i = 0; i < jsfInform.height; i++)
	//{
	//	short idNumber = 0; // 식별번호
	//
	//	short setCount = 0; // 세트갯수
	//	short spaceCount = 0; // 공백갯수
	//	short pixelCount = 0; // 그림갯수
	//
	//	fread(&idNumber, sizeof(short), 1, fpInputFile); // 식별번호 읽기
	//	printf("시작 식별번호는 : %d입니다.\n", idNumber);
	//	switch (idNumber)
	//	{
	//	case 0:
	//	{
	//		for (int i = 0; i < jsfInform.width; i++)
	//		{
	//			fwrite(&rgbSpacePixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//공백 이미지 쓰기
	//		}
	//	}break;
	//	case 1:
	//	{
	//		for (int i = 0; i < jsfInform.width; i++)
	//		{
	//			fread(&color, sizeof(short), 1, fpInputFile);
	//			rgbPixel = changeRGB(color); // 2byte -> 3byte rgb로 변경
	//			fwrite(&rgbPixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//이미지 쓰기
	//		}
	//	}break;
	//	default: // 공백과 데이터 공존
	//	{
	//		int temp = 0;
	//		setCount = idNumber - 1;
	//
	//		for (int i = 0; i < setCount; i++)
	//		{
	//			fread(&spaceCount, sizeof(short), 1, fpInputFile);//공백갯수
	//			printf("공백 갯수는 : %d입니다.\n", spaceCount);
	//
	//			fread(&pixelCount, sizeof(short), 1, fpInputFile);//데이터갯수
	//			printf("픽셀 갯수는 : %d입니다.\n", pixelCount);
	//
	//			temp += spaceCount;
	//			temp += pixelCount;
	//
	//			for (int j = 0; j < spaceCount; j++)
	//			{
	//				fwrite(&rgbSpacePixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//공백 이미지 쓰기
	//			}
	//			for (int j = 0; j < pixelCount; j++)
	//			{
	//				fread(&color, sizeof(short), 1, fpInputFile);
	//				rgbPixel = changeRGB(color); // 2byte -> 3byte rgb로 변경
	//				fwrite(&rgbPixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//픽셀 이미지 쓰기
	//			}
	//		}
	//		printf("\n------------------------------\n");
	//
	//		int rest = jsfInform.width - temp - 1;
	//		for (int i = 0; i < rest; i++)
	//		{
	//			fwrite(&rgbSpacePixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//공백 이미지 쓰기
	//		}
	//	}break;
	//
	//	}
	//}

	//----------------------------비트맵 초기 환경 테스트-------------
	/*char* testAllBlack = new char[pixelDataSize];
	memset(testAllBlack, 0, pixelDataSize);
	fwrite(testAllBlack, pixelDataSize, 1, fpOutputFile);*/
	//---------------------------------------------------------------

	fclose(fpOutputFile);    // bmp 출력 파일 닫기

}


