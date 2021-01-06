//#include <iostream>
//#include<Windows.h>
/*

typedef struct _BITMAPFILEHEADER     // BMP 비트맵 파일 헤더 구조체
{
	unsigned short bfType;           // 19778
	unsigned int   bfSize;           // 12374
	unsigned short bfReserved1;      // 0
	unsigned short bfReserved2;      // 0
	unsigned int   bfOffBits;        // 54
} BITMAPFILEHEADER;
typedef struct _BITMAPINFOHEADER     // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
	unsigned int   biSize;           // 40
	int            biWidth;          // 73
	int            biHeight;         // 56
	unsigned short biPlanes;         // 1
	unsigned short biBitCount;       // 24
	unsigned int   biCompression;    // 0
	unsigned int   biSizeImage;      // 12374 - 54
	int            biXPelsPerMeter;  // 0
	int            biYPelsPerMeter;  // 0
	unsigned int   biClrUsed;        // 0
	unsigned int   biClrImportant;   // 0
} BITMAPINFOHEADER;
typedef struct _RGBTRIPLE            // 24비트 비트맵 이미지의 픽셀 구조체
{
	unsigned char rgbtBlue;          // 파랑
	unsigned char rgbtGreen;         // 초록
	unsigned char rgbtRed;           // 빨강
} RGBTRIPLE;

*/
//int main()
//{
//	typedef struct tagBITMAPFILEHEADER {
//		WORD    bfType; // BM << WORD 0X424D
//		DWORD   bfSize; // 만들어질 파일 사이즈
//		WORD    bfReserved1; // 0
//		WORD    bfReserved2; // 0
//		DWORD   bfOffBits; // 54
//	} BITMAPFILEHEADER, FAR* LPBITMAPFILEHEADER, * PBITMAPFILEHEADER;
//
//	BITMAPFILEHEADER bfh;
//	bfh.bfType = 0x424d;
//	bfh.bfSize = 54 + 220 * 56;
//	bfh.bfReserved1 = 0;
//	bfh.bfReserved1 = 0;
//	bfh.bfOffBits = 54;
//	fwrite(14byte);
//
//	typedef struct tagBITMAPINFOHEADER {
//		DWORD      biSize; // 무조껀 40
//		LONG       biWidth; // 73
//		LONG       biHeight; // 56
//		WORD       biPlanes; // 1
//		WORD       biBitCount; // 24(0x18)
//		DWORD      biCompression; // 0
//		DWORD      biSizeImage; // file사이즈 - 54(순수한 이미지 크기가 얼마인가)
//		LONG       biXPelsPerMeter; // 0
//		LONG       biYPelsPerMeter; //0
//		DWORD      biClrUsed; // 0
//		DWORD      biClrImportant;// 0
//	} BITMAPINFOHEADER, FAR* LPBITMAPINFOHEADER, * PBITMAPINFOHEADER;
//	
//	fwrite(40byte);
//
//
//	FILE* fpt = fopen("000000.jsf");
//	1.방법 : fread()를 이용해서 250byte를 읽는 방법
//	
//	fread(temp) // temp == 배열
//	unsigned char temp1[250];
//	fread(temp, 1, 250, fpt);
//
//	2.방법 : fseek(); 파일 선두에서부터 250만큼 파일 포인트를 이동하세요.
//		int imageSize;
//	fread(&imageSize, 1, 1, fpt); //221이 들어가있다.
//
//	temp2[26]
//	fread(temp2, 1, 26, fpt); // 읽은 데이터는 ㅓ린다.
//
//		
//		fread(temp, 4, 1, fpt);
//		fread(width, 2, 1, fpt);  // 73 >> 220
//		fread(height, 2, 1, fpt); // 56 >> 56
//
//		// 220, 56을 저장한다.
//		unsigned char* p = new char[220 * 56];
//		// memset >> 메모리를 모두 초기화 시킨다.
//
//		for (size_t i = 0; i < 56; i++)
//		{
//			fread(&idNum, 2, 1, fpt); // 02
//
//			switch (idNum)
//			{
//			case 0:
//				//p = 
//				break;
//			case 1:
//				//p =
//				break;
//			default:
//				for (idNum - 1) 
//				{
//					p에 대한 공백처리
//					p에 대한 픽셀처리
//
//				}
//				//p = 
//				break;
//			}
//		}
//
//		fclose(fpt);
//
//		FILE* wfpt = fopen("0000.bmp");
//		fwrite(14); // BITMAPFILEHEADER
//		fwrite(40); // BITMAPINFOHEADER
//		fwrite(p, 220 * 56, wfpt);
//
//		fclose(wfpt);
//		image16
//		image24
//}
//
//
