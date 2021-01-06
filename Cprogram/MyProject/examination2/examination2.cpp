
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <Windows.h>

#define HEADERSIZE 250
#define INTBYTESIZE 4
#define SHORTBYTESIZE 2
typedef struct
{
	int width;
	int height;
	int pictureNumber;
	int size;
}INFORMATION;

#pragma pack(push, 1)                // 구조체를 1바이트 크기로 정렬



//typedef struct _RGBTRIPLE            // 24비트 비트맵 이미지의 픽셀 구조체
//{
//	unsigned char rgbtBlue;          // 파랑
//	unsigned char rgbtGreen;         // 초록
//	unsigned char rgbtRed;           // 빨강
//} RGBTRIPLE;

#pragma pack(pop)

#define PIXEL_SIZE   3    // 픽셀 한 개의 크기 3바이트(24비트)
#define PIXEL_ALIGN  4    // 픽셀 데이터 가로 한 줄은 4의 배수 크기로 저장됨

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

	INFORMATION jsfInfo;
	memset(&jsfInfo, 0, sizeof(INFORMATION));    // p1을 구조체 크기만큼 0으로 설정

	BITMAPFILEHEADER fileHeader;    // 비트맵 파일 헤더 구조체 변수
	BITMAPINFOHEADER infoHeader;    // 비트맵 정보 헤더 구조체 변수
	memset(&fileHeader, 0, sizeof(fileHeader));    // fileHeader이 가리키는 메모리를 0으로 초기화
	memset(&infoHeader, 0, sizeof(infoHeader));    // infoHeader이 가리키는 메모리를 0으로 초기화

	FILE* fpInputFile = NULL;
	FILE* fpOutputFile = NULL;

	FILE* fpOutputTxtFile____ = NULL;

	RGBTRIPLE rgbPixel;
	RGBTRIPLE rgbSpacePixel; // 검정바탕
	memset(&rgbSpacePixel, 0, sizeof(RGBTRIPLE));    // p1을 구조체 크기만큼 0으로 설정
	memset(&rgbPixel, 0, sizeof(RGBTRIPLE));    // p1을 구조체 크기만큼 0으로 설정

	/////////int padding;             // 픽셀 데이터의 가로 크기가 4의 배수가 아닐 때 남는 공간의 크기
	/////////int size;                // 픽셀 데이터 크기
	/////////
	/////////fpInputFile = fopen("0000.JSF", "rb");
	/////////if (fpInputFile == NULL)
	/////////{
	/////////	printf("읽기 실패");
	/////////	return 0;
	/////////} // 파일 열기에 실패하면
	/////////
	/////////fseek(fpInputFile, 0, SEEK_SET); // 첫번째 파일포인터
	/////////
	/////////fseek(fpInputFile, HEADERSIZE, SEEK_CUR);                    //처음 위치에서 헤더사이즈byte 뒤로 설정
	/////////printf("현재 위치는 : %ld\n", ftell(fpInputFile));			//fseek 후 파일 포인터 위치 확인
	/////////
	/////////fread(&jsfInfo.pictureNumber, sizeof(long), 1, fpInputFile);
	/////////printf("그림의 갯수는 : %d개 입니다.\n", jsfInfo.pictureNumber);
	/////////
	/////////fseek(fpInputFile, 26, SEEK_CUR);// 예약어 무시
	/////////
	/////////fread(&jsfInfo.size, sizeof(long), 1, fpInputFile);
	/////////printf("압축해상도 size는 %d 입니다..\n", jsfInfo.size);
	/////////
	/////////fread(&jsfInfo.width, sizeof(short), 1, fpInputFile);
	/////////printf("가로 size는 : %d입니다.\n", jsfInfo.width);
	/////////fread(&jsfInfo.height, sizeof(short), 1, fpInputFile);
	/////////printf("세로 size는 : %d입니다.\n\n", jsfInfo.height);

	//padding = (PIXEL_ALIGN - ((infoHeader.biWidth * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;
	//size = (infoHeader.biWidth * PIXEL_SIZE + padding) * infoHeader.biHeight;
	//printf("size크기는 %d입니다.\n", size);

	//--------------------------------헤더파일 등록--------------------
	//fileHeader.bfSize = 54 + 220 * 56 = 12374; 
	fileHeader.bfType = 'MB';
	fileHeader.bfSize = 54 + 220 * 56;//54 + size;
	fileHeader.bfReserved1 = 0x00;
	fileHeader.bfReserved2 = 0x00;
	fileHeader.bfOffBits = 54; // 54

	
	infoHeader.biSize = 40;		//현재 비트맵 정보 헤더(BITMAPINFOHEADER)의 크기
	infoHeader.biWidth = 73;//jsfInfo.width;       // 비트맵 이미지의 가로 크기
	infoHeader.biHeight = 56;//jsfInfo.height;     // 비트맵 이미지의 세로 크기
	infoHeader.biPlanes = 1; //사용하는 색상판의 수.항상 1입니다.
	infoHeader.biBitCount = 24;//픽셀 하나를 표현하는 비트 수
	infoHeader.biCompression = 0;		//압축 방식.보통 비트맵은 압축을 하지 않으므로 0입니다.
	infoHeader.biSizeImage = 220 * 56;//220 * 56;		//비트맵 이미지의 픽셀 데이터 크기(압축 되지 않은 크기)
	infoHeader.biXPelsPerMeter = 0;		//그림의 가로 해상도(미터당 픽셀)
	infoHeader.biYPelsPerMeter = 0;		//그림의 세로 해상도(미터당 픽셀)
	infoHeader.biClrUsed = 0;		//색상 테이블에서 실제 사용되는 색상 수
	infoHeader.biClrImportant = 0;		//비트맵을 표현하기 위해 필요한 색상 인덱스 수



	fpOutputTxtFile____ = fopen("sample.txt", "w");
	fpOutputFile = fopen("sample.bmp", "wb");
	if (fpOutputFile == NULL)    // 파일 열기에 실패하면
	{
		printf("실패");
		return 0;         // 프로그램 종료
	}

	
	

	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpOutputFile);
	fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpOutputFile);

	fseek(fpOutputFile, fileHeader.bfOffBits, SEEK_SET); // 파일 포인터를 픽셀 데이터의 시작 위치로 이동
	printf("output 파일 포인터 위치는 %d입니다.\n\n", ftell(fpOutputFile));

	char* buffer = new char[220 * 56];
	memset(buffer, 0, sizeof(220 * 56));
	fwrite(buffer, sizeof(220 * 56), 1, fpOutputFile);

	//--------------------------------------쓰기영역-------------------------

	//////int heightCount = 0;
	//////short color = 0;
	//////while (jsfInfo.height > heightCount)
	//////{
	//////	//int location = ftell(fpFile);
	//////	heightCount++; //엔터 후 
	//////
	//////	short idNumber = 0; // 식별번호
	//////
	//////	short setCount = 0; // 세트갯수
	//////	short spaceCount = 0; // 공백갯수
	//////	short pixelCount = 0; // 그림갯수
	//////
	//////	fread(&idNumber, sizeof(short), 1, fpInputFile); // 식별번호 읽기
	//////	printf("시작 식별번호는 : %d입니다.\n", idNumber); 
	//////	switch (idNumber)
	//////	{
	//////	case 0:
	//////	{
	//////		for (int i = 0; i < jsfInfo.width; i++)
	//////		{
	//////			fwrite(&rgbSpacePixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//공백 이미지 쓰기
	//////
	//////			///////////////////////////////////////////
	//////			fprintf(fpOutputTxtFile____, "%c%c", '-', '-');
	//////		}
	//////		fprintf(fpOutputFile, "\n");
	//////	}break;
	//////	case 1:
	//////	{
	//////		for (int i = 0; i < jsfInfo.width; i++)
	//////		{
	//////			fread(&color, sizeof(short), 1, fpInputFile);
	//////			rgbPixel = changeRGB(color); // 2byte -> 3byte rgb로 변경
	//////			fwrite(&rgbPixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//이미지 쓰기
	//////
	//////			///////////////////////////////////////////////
	//////			//fseek(fpInputFile, sizeof(short), SEEK_CUR);
	//////			fprintf(fpOutputTxtFile____, "%c%c", '0', '0');
	//////		}
	//////		fprintf(fpOutputFile, "\n");
	//////	}break;
	//////	default: // 공백과 데이터 공존
	//////	{
	//////		int temp = 0;
	//////		setCount = idNumber - 1;
	//////
	//////		for (int i = 0; i < setCount; i++)
	//////		{
	//////			//int location = ftell(fpInputFile);
	//////			fread(&spaceCount, sizeof(short), 1, fpInputFile);//공백갯수
	//////			printf("공백 갯수는 : %d입니다.\n", spaceCount);
	//////
	//////			fread(&pixelCount, sizeof(short), 1, fpInputFile);//데이터갯수
	//////			printf("픽셀 갯수는 : %d입니다.\n", pixelCount);
	//////
	//////			temp += spaceCount;
	//////			temp += pixelCount;
	//////
	//////			for (int j = 0; j < spaceCount; j++)
	//////			{
	//////				fwrite(&rgbSpacePixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//공백 이미지 쓰기
	//////
	//////				////////////////////////////////////////////////
	//////				fprintf(fpOutputTxtFile____, "%c%c", '-', '-');
	//////			}
	//////			for (int j = 0; j < pixelCount; j++)
	//////			{
	//////				fread(&color, sizeof(short), 1, fpInputFile);
	//////				rgbPixel = changeRGB(color); // 2byte -> 3byte rgb로 변경
	//////				fwrite(&rgbPixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//픽셀 이미지 쓰기
	//////
	//////				///////////////////////////////////////////////////
	//////				//fseek(fpInputFile, sizeof(short), SEEK_CUR);
	//////				fprintf(fpOutputTxtFile____, "%c%c", '0', '0');
	//////			}
	//////		}
	//////		printf("\n------------------------------\n");
	//////
	//////		int rest = jsfInfo.width - temp - 1;
	//////		for (int i = 0; i < rest; i++)
	//////		{
	//////			fwrite(&rgbSpacePixel, sizeof(RGBTRIPLE), 1, fpOutputFile);//공백 이미지 쓰기
	//////
	//////
	//////			/////////////////////////////////////////////////
	//////			fprintf(fpOutputTxtFile____, "%c%c", '-', '-');
	//////		}
	//////
	//////		fprintf(fpOutputTxtFile____, "\n");
	//////	}break;
	//////
	//////	}
	//////}
	
	fclose(fpOutputFile);    // 텍스트 파일 닫기
	fclose(fpOutputTxtFile____);    // 텍스트 파일 닫기
	//fclose(fpInputFile);    // 이미지 파일 닫기






	//printf("--------------------------------------------------------------------");

	//fseek(fpInputFile, 16, SEEK_CUR);// 예약어 무시

	//fread(&jsfInfo.width, sizeof(long), 1, fpInputFile);
	//printf("압축해상도 size는 건너 뛰었습니다.\n");

	//fread(&jsfInfo.width, sizeof(short), 1, fpInputFile);
	//printf("가로 size는 : %d입니다.\n", jsfInfo.width);
	//fread(&jsfInfo.height, sizeof(short), 1, fpInputFile);
	//printf("세로 size는 : %d입니다.\n\n", jsfInfo.height);


	//heightCount = 0;
	////while (jsfInfo.height != heightCount)
	//while (jsfInfo.height >= heightCount)
	//{
	//	//int location = ftell(fpFile);
	//	heightCount++; //엔터 후 

	//	short idNumber = 0; // 식별번호

	//	short setCount = 0; // 세트갯수
	//	short spaceCount = 0; // 공백갯수
	//	short pixelCount = 0; // 그림갯수

	//	fread(&idNumber, sizeof(short), 1, fpInputFile); // 식별번호 읽기
	//	printf("시작 식별번호는 : %d입니다.\n", idNumber);

	//	if (idNumber == 0x0000)
	//	{
	//		for (int i = 0; i < jsfInfo.width; i++)
	//		{
	//			fprintf(fpOutputFile, "%c%c", '-', '-');
	//		}
	//		fprintf(fpOutputFile, "\n");
	//	}
	//	else if (idNumber == 0x0001)
	//	{
	//		for (int i = 0; i < jsfInfo.width; i++)
	//		{
	//			fseek(fpInputFile, sizeof(short), SEEK_CUR);
	//			fprintf(fpOutputFile, "%c%c", '0', '0');
	//		}
	//		fprintf(fpOutputFile, "\n");
	//	}
	//	else // 공백과 데이터 공존
	//	{
	//		int temp = 0;
	//		setCount = idNumber - 1;

	//		for (int i = 0; i < setCount; i++)
	//		{
	//			int location = ftell(fpInputFile);
	//			fread(&spaceCount, sizeof(short), 1, fpInputFile);//공백갯수
	//			printf("공백 갯수는 : %d입니다.\n", spaceCount);
	//			fread(&pixelCount, sizeof(short), 1, fpInputFile);//데이터갯수
	//			printf("픽셀 갯수는 : %d입니다.\n", pixelCount);

	//			temp += spaceCount;
	//			temp += pixelCount;

	//			for (int j = 0; j < spaceCount; j++)
	//			{
	//				//fseek(fpFile, sizeof(short), SEEK_CUR);
	//				fprintf(fpOutputFile, "%c%c", '-', '-');
	//			}
	//			for (int j = 0; j < pixelCount; j++)
	//			{
	//				fseek(fpInputFile, sizeof(short), SEEK_CUR);
	//				fprintf(fpOutputFile, "%c%c", '0', '0');
	//			}
	//		}

	//		int rest = jsfInfo.width - temp - 1;
	//		for (int i = 0; i < rest; i++)
	//		{
	//			//fseek(fpFile, sizeof(short), SEEK_CUR);
	//			fprintf(fpOutputFile, "%c%c", '-', '-');
	//		}

	//		fprintf(fpOutputFile, "\n");
	//	}
	//}
	return 0;
}