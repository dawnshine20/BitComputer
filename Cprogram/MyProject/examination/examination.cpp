/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	FILE* FpJsfInput;                       // 입력 이미지 파일 포인터.
	FILE* FpJsfOutput;                      // 출력 이미지 파일 포인터.
	short Widthtmp[2], Heighttmp[2];        // 가로, 세로 해상도 임시 저장.
	long width, height;                     // 가로, 세로 해상도.
	short LineIDtmp[2];                     // 라인 식별 번호 임시 저장.
	long LineIDNum;                         // 라인 식별 번호.
	short BgPixeltmp[2], ImgPixeltmp[2];    // 배경, 이미지 픽셀 개수 임시 저장.
	long BgPixelNum, ImgPixelNum;           // 배경, 이미지 픽셀 개수.
	short RemainingPixels;                  // 세트로 채워지지 않은 나머지 픽셀.
	int JumpingPixel;                       // 다음 라인 식별 번호까지 건너뛰기 위한 변수.
	char dot = '.';                         // 배경 부분 출력 문자.
	char circle = 'o';                      // 이미지 부분 출력 문자.
	char NextLine = '\n';                   // 줄 바꿈 문자.

	// 0000.JSF 파일을 읽기 모드로 open.
	FpJsfInput = fopen("0000.JSF", "rb");
	// 파일열기에 실패하면 프로그램 종료.                                                     
	if (FpJsfInput == NULL)
	{
		perror("읽기 모드 열기 실패.\\n");
		return 0;
	}

	printf("읽기 모드 열기 성공.\\n");

	// 가로, 세로 해상도 정보 위치 찾기
	fseek(FpJsfInput, 0x11c, SEEK_SET);

	// 가로, 세로 해상도 초기화.
	for (int i = 0; i < 2; i++)
		Widthtmp[i] = fgetc(FpJsfInput);
	width = long(Widthtmp[0] + (Widthtmp[1] << 8));

	for (int i = 0; i < 2; i++)
		Heighttmp[i] = fgetc(FpJsfInput);
	height = long(Heighttmp[0] + (Heighttmp[1] << 8));

	//printf("가로: %d, 세로: %d\\n", width, height);
	// 쓰기 모드로 파일 open
	FpJsfOutput = fopen("ASCIIDog.txt", "w");
	if (FpJsfOutput == NULL)
	{
		perror("쓰기 모드 열기 실패.\\n");
		return 0;
	}
	printf("쓰기 모드 열기 성공.\\n");

	// 픽셀 데이터 접근.
	fseek(FpJsfInput, 0x120, SEEK_SET);

	//printf("픽셀 데이터 시작: %x\\n", ftell(FpJsfInput));
	// 파일에 배경, 이미지에 따른 문자 저장.
	for (int i = 0; i < height; i++)
	{
		// 라인 식별 번호 초기화.
		for (int i = 0; i < 2; i++)
			LineIDtmp[i] = fgetc(FpJsfInput);
		LineIDNum = long(LineIDtmp[0] + (LineIDtmp[1] << 8));
		// 라인 식별 번호에 따른 3가지 케이스.
		// 1. All 배경.
		// 2. All 이미지.
		// 3. 배경 & 이미지.
		switch (LineIDNum)
		{
			// 1. All 배경. (00 00)
			// 라인 식별 번호(2) → 라인 식별 번호(2) → ...
		case 0:
		{
			// 가로 해상도만큼 '.' 저장.
			for (int i = 0; i < width; i++)
				fputc(dot, FpJsfOutput);
			fputc(NextLine, FpJsfOutput);
		}break;

		// 2. All 이미지. (01 00)
		// 라인 식별 번호(2) → 색상 정보(가로 해상도 * 2) → 라인 식별 번호(2) → ...
		case 1:
		{
			// 가로 해상도만큼 'o' 저장.
			for (int i = 0; i < width; i++)
				fputc(circle, FpJsfOutput);
			fputc(NextLine, FpJsfOutput);
			// 색상 정보 건너 뛰기.
			JumpingPixel = width * 2;
			for (int i = 0; i < JumpingPixel; i++)
				fgetc(FpJsfInput);
		}break;

		// 3. 배경 & 이미지. (0n 00)
		// 라인 식별 번호(2) → 배경 개수(2) → 이미지 개수(2) 
		// → 색상 정보(이미지 개수 * 2) → 배경 개수 → 이미지 개수 → 색상 정보 → ...
		default:
		{
			// 배경 & 이미지 셋에 따른 문자 저장 후,
			// 나머지 픽셀에 배경을 채우기 위한 변수.
			int BgPixelCnt = 0;     // 총 배경 픽셀 개수.
			int ImgPixelCnt = 0;    // 총 이미지 픽셀 개수.
			// 세트 수 만큼 반복. (n - 1)
			for (int i = 0; i < LineIDNum - 1; i++)
			{
				// 배경 픽셀 개수 초기화.
				for (int i = 0; i < 2; i++)
					BgPixeltmp[i] = fgetc(FpJsfInput);
				BgPixelNum = long(BgPixeltmp[0] + (BgPixeltmp[1] << 8));
				// 이미지 픽셀 개수 초기화.
				for (int i = 0; i < 2; i++)
					ImgPixeltmp[i] = fgetc(FpJsfInput);
				ImgPixelNum = long(ImgPixeltmp[0] + (ImgPixeltmp[1] << 8));

				// 배경 픽셀 수만큼 '.' 채우기.
				for (int i = 0; i < BgPixelNum; i++)
					fputc(dot, FpJsfOutput);
				// 이미지 픽셀 수만큼 'o' 채우기.
				for (int i = 0; i < ImgPixelNum; i++)
					fputc(circle, FpJsfOutput);
				// 색상 정보 건너 뛰기.
				JumpingPixel = ImgPixelNum * 2;
				for (int i = 0; i < JumpingPixel; i++)
					fgetc(FpJsfInput);
				//printf("배경: %x\\n", ftell(FpJsfInput));
				// 총 배경, 이미지 픽셀 수.
				BgPixelCnt += BgPixelNum;
				ImgPixelCnt += ImgPixelNum;
			}
			// 나머지 픽셀 배경으로 채우기
			//printf("나머지");
			RemainingPixels = (short)(width - BgPixelCnt - ImgPixelCnt);
			for (int i = 0; i < RemainingPixels; i++)
				fputc(dot, FpJsfOutput);
			fputc(NextLine, FpJsfOutput);
		}break;
		}
	}

	// 파일 닫기.
	fclose(FpJsfOutput);
	fclose(FpJsfInput);
	return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define HEADERSIZE 250
#define INTBYTESIZE 4
#define SHORTBYTESIZE 2
typedef struct
{
	int width;
	int height;
	int pictureNumber;
}INFORMATION;

int main()
{
	INFORMATION jsfInfo;
	memset(&jsfInfo, 0, sizeof(INFORMATION));    // p1을 구조체 크기만큼 0으로 설정

	FILE* fpInputFile = NULL;
	FILE* fpOutputFile = NULL;
	int currentPos = 0;

	fpInputFile = fopen("0000.JSF", "rb");
	if (fpInputFile == NULL)
	{
		printf("읽기 실패");
		return 0;
	} // 파일 열기에 실패하면

	fseek(fpInputFile, 0, SEEK_SET); // 첫번째 파일포인터

	fseek(fpInputFile, HEADERSIZE, SEEK_CUR);                    //처음 위치에서 헤더사이즈byte 뒤로 설정
	printf("현재 위치는 : %ld\n", ftell(fpInputFile));			//fseek 후 파일 포인터 위치 확인

	fread(&jsfInfo.pictureNumber, sizeof(long), 1, fpInputFile);
	printf("그림의 갯수는 : %d개 입니다.\n", jsfInfo.pictureNumber);

	fseek(fpInputFile, 26, SEEK_CUR);// 예약어 무시

	fread(&jsfInfo.width, sizeof(long), 1, fpInputFile);
	printf("압축해상도 size는 : %d입니다.\n", jsfInfo.width);

	fread(&jsfInfo.width, sizeof(short), 1, fpInputFile);
	printf("가로 size는 : %d입니다.\n", jsfInfo.width);
	fread(&jsfInfo.height, sizeof(short), 1, fpInputFile);
	printf("세로 size는 : %d입니다.\n\n", jsfInfo.height);


	fpOutputFile = fopen("sample.txt", "w");
	
	//--------------------------------------쓰기영역
	int heightCount = 0;
	//while (jsfInfo.height != heightCount)
	while (jsfInfo.height >= heightCount)
	{
		//int location = ftell(fpFile);
		heightCount++; //엔터 후 

		short idNumber = 0; // 식별번호

		short setCount = 0; // 세트갯수
		short spaceCount = 0; // 공백갯수
		short pixelCount = 0; // 그림갯수

		fread(&idNumber, sizeof(short), 1, fpInputFile); // 식별번호 읽기
		printf("시작 식별번호는 : %d입니다.\n", idNumber); 

		if (idNumber == 0x0000)
		{
			for (int i = 0; i < jsfInfo.width; i++)
			{
				fprintf(fpOutputFile, "%c%c", '-', '-');
			}
			fprintf(fpOutputFile, "\n");
		}
		else if (idNumber == 0x0001)
		{
			for (int i = 0; i < jsfInfo.width; i++)
			{
				fseek(fpInputFile, sizeof(short), SEEK_CUR);
				fprintf(fpOutputFile, "%c%c", '0', '0');
			}
			fprintf(fpOutputFile, "\n");
		}
		else // 공백과 데이터 공존
		{
			int temp = 0;
			setCount = idNumber - 1;

			for (int i = 0; i < setCount; i++)
			{
				int location = ftell(fpInputFile);
				fread(&spaceCount, sizeof(short), 1, fpInputFile);//공백갯수
				printf("공백 갯수는 : %d입니다.\n", spaceCount);
				fread(&pixelCount, sizeof(short), 1, fpInputFile);//데이터갯수
				printf("픽셀 갯수는 : %d입니다.\n", pixelCount);

				temp += spaceCount;
				temp += pixelCount;

				for (int j = 0; j < spaceCount; j++)
				{
					//fseek(fpFile, sizeof(short), SEEK_CUR);
					fprintf(fpOutputFile, "%c%c", '-', '-');
				}
				for (int j = 0; j < pixelCount; j++)
				{
					fseek(fpInputFile, sizeof(short), SEEK_CUR);
					fprintf(fpOutputFile, "%c%c", '0', '0');
				}
			}

			int rest = jsfInfo.width - temp - 1;
			for (int i = 0; i < rest; i++)
			{
				//fseek(fpFile, sizeof(short), SEEK_CUR);
				fprintf(fpOutputFile, "%c%c", '-', '-');
			}

			fprintf(fpOutputFile, "\n");
		}
	}
	

	fclose(fpOutputFile);    // 텍스트 파일 닫기
	fclose(fpInputFile);    // 이미지 파일 닫기

	return 0;
}

//int linenumber = 0;
//while (linenumber != jsfInfo.height)
//{
//
//	int setCount = 0;
//	int spacePixelCnt = 0;
//	int dotPixelCnt = 0;
//	int twoByteCnt = 0;
//	//식별번호
//	fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//	fread(&setCount, sizeof(short), 1, fpFile);
//
//	//0000 공백, 0001 모두 색상, 그 외에는 모두 공백 색상 존재
//	if (setCount != 0x0000 && setCount != 0x0001)
//	{
//		int setLoopCnt = 0;
//		while (1)
//		{
//			//공백 갯수
//
//			fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//			fread(&spacePixelCnt, sizeof(short), 1, fpFile);
//			//점의 갯수
//			fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//			fread(&dotPixelCnt, sizeof(short), 1, fpFile);
//
//			for (int i = 0; i < spacePixelCnt; i++)
//			{
//				twoByteCnt++;
//				fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//
//				fprintf(fpFile1, "%c%c", '-', '-');    // 텍스트 파일에 문자 2BYTE 출력
//
//			}
//			for (int i = 0; i < dotPixelCnt; i++)
//			{
//				twoByteCnt++;
//				fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//
//				fprintf(fpFile1, "%c%c", 'O', 'O');    // 텍스트 파일에 문자 2BYTE 출력
//			}
//			setLoopCnt++;
//
//			//총 세트 카운트와 세트의 반복횟수가 같으면 나머지도 마저 처리한다.
//			if (setCount - 1 == setLoopCnt)
//			{
//				while (1)
//				{
//					twoByteCnt++;
//					fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//
//					fprintf(fpFile1, "%c%c", '-', '-');    // 텍스트 파일에 문자 2BYTE 출력
//					if (twoByteCnt == jsfInfo.height - 1)
//					{
//						break;
//					}
//				}
//			}
//			//한줄 다 읽었으면 루프문 탈출
//			if (twoByteCnt == jsfInfo.height - 1)
//			{
//				break;
//			}
//		}
//	}
//
//
//	if (setCount == 0x0000)
//	{
//		for (int i = 0; i < jsfInfo.width; i++)
//		{
//			twoByteCnt++;
//			fprintf(fpFile1, "%c%c", '-', '-');    // 텍스트 파일에 문자 2BYTE 출력
//		}
//	}
//
//	if (setCount == 0x0001)
//	{
//		//점의 갯수
//		fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//		fread(&dotPixelCnt, sizeof(short), 1, fpFile);
//
//		for (int i = 0; i < jsfInfo.width; i++)
//		{
//			twoByteCnt++;
//			fseek(fpFile, SHORTBYTESIZE, SEEK_CUR);
//
//			fprintf(fpFile1, "%c%c", 'O', 'O');    // 텍스트 파일에 문자 2BYTE 출력
//		}
//	}
//
//	linenumber++;
//	fprintf(fpFile1, "\n");    // 가로 픽셀 저장이 끝났으면 줄바꿈을 해줌
//
//}*/

