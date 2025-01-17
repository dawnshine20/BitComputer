﻿#include <iostream>
#include <windows.h>
// 마이크로소프트에서 공식적으로 무시해도 괜찮다고 이야기된 warning
#pragma warning(disable: 4996) 

int main()
{
	//한꺼번에 열수 있는 파일은 40~60개(그러니 쓰고나서 꼭 닫아줄것)
	FILE* rf = fopen("0000.jsf", "rb"); // 보안상 window환경에서는 createfile(인자 5개) 사용//

	if (rf == NULL) // 비정상적인 값이 들어올 경우 널문자 반환
	{
		printf("Open Error");
		return 0;
	}

	// 함수 호출, 파일 입출력은 속도에 대해서 프로그래머의 제어가 불가

	BYTE FileHeader[250]; //고정되어있는 값이기 때문에 배열을 사용한다.
	fread(FileHeader, 1, 250, rf); // 읽으려고하는 메모리의 시작 주소(1byte씩 250번 읽어라)
	//BYTE, WORD, DWORD
	DWORD imageNumber; // 이미지변수에 음수가 들어올리가 없기 떄문에 unsigned추가
	fread(&imageNumber, sizeof(DWORD), 1, rf); // 조사식에서 16진수로 확인 가능
	printf("imageNumber : %d\n", imageNumber);

	//-----------------------첫번째 그림의 정보가 시작된다.----------------------------
	// for문장 예약. for( int i = 0; i < imageNumber; i++)
	BYTE reserver[26];
	fread(reserver, 1, 26, rf); // 읽으려고하는 메모리의 시작 주소(1byte씩 26번 읽어라)


	//typedef struct tagJSFImageInfo {
	//	DWORD CompressSize;
	//	WORD width, height;
	//}JSFImageInfo;
	//JSFImageInfo st;
	// 압축사이즈, 가로,세로 해상도 리딩
	DWORD compressSize;
	WORD width, height;
	fread(&compressSize, sizeof(DWORD), 1, rf);
	fread(&width, sizeof(WORD), 1, rf); // 73(점의 갯수)
	fread(&height, sizeof(WORD), 1, rf); // 56(점의 갯수)

	printf("compressSize: %d\n", compressSize);
	//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ fread 한번만으로 모든것들을 부름(성능 증가)
	//fread(&st, sizeof(STRU), 1, rf);
	printf("width:%d height:%d\n", width, height);

	WORD width24, height24; // 24bit
	width24 = width * 3; // 점 1개당 3byte 필요
	height24 = height;
	printf("width24:%d  height24:%d\n", width24, height24);

	WORD q = width24 / 4; // 몫이 나옴     //  219 / 4
	WORD r = width24 % 4; // 나머지가 나옴 //  219 % 4 

	if (r != 0)
	{
		width24 = (q + 1) * 4;
	}
	//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓안좋은 코드 예) 조사식 활용이 어려움
	//if (width24 % 4 != 0)
	//{
	//	width24 = (width24 / 4 + width24 % 4) * 4;
	//}
	printf("width24: %d height24: %d\n", width24, height24);
	long size16 = width * 2 * height; // 가로픽셀 갯수 * 2 * 세로해상도
	long size24 = width24 * height24;

	printf("size16: %d size24: %d\n", size16, size24);
	// size16: 8176, size24: 12320

	BYTE* Image16 = new BYTE[size16];// 16bit형을 받는 메모리 사이즈 확보
	BYTE* Image24 = new BYTE[size24];// 데이타를 받지는 않았지만
	memset(Image16, 0, size16);
	memset(Image24, 0, size24);

	for (int i = 0; i < height; i++)
	{
		WORD idNum = 0;
		fread(&idNum, 2, 1, rf);
		printf("idNum:%d\n", idNum);
		//Offset 공식 = y * w + x
		DWORD _OFFSET = (height - 1 - i) * (width * 2) + 0; // 어셈블리 예약어 피하기 위해 _, 사용 16bit메모리이기 떄문에 2사용
		printf("%d\n", _OFFSET);
		switch (idNum) // switch == goto 문장
		{

		case 0: { // 공백인 경우
			//이미 0으로 메모리 모두 세팅했기 때문에 바로 다음 라인으로 이동(코드 처리 안함)
			//단, 배경색을 변경하고 싶으면 그에 맞게 코드를 작성
		}break;
		case 1: { // 라인이 채워진 경우
			fread(Image16 + _OFFSET, 2, width, rf); // 2 byte씩 가로길이만큼 읽음
		}break;
			//WORD XXX = 0a0d;공백을 위한
		default: { // 공백과 픽셀 데이터가 공존하는 경우
			WORD BlankNum, PixelNum;
			for (int j = 0; j < idNum - 1; j++) {
				fread(&BlankNum, 2, 1, rf);
				_OFFSET += (BlankNum * 2);

				fread(&PixelNum, 2, 1, rf);
				fread(Image16 + _OFFSET, 2, PixelNum, rf);
				_OFFSET += (PixelNum * 2);
			}
		}break;
		}
	}
	// move 16bit memory to 24bit memory
	for (int i = 0, k = 0; i < height; i++) {
		for (int j = 0; j < width; j++, k++) {
			WORD data16 = *(WORD*)(Image16 + k * 2);
			BYTE R = (data16 & 0xf800) >> 8;
			BYTE G = (data16 & 0x07E0) >> 3;
			BYTE B = (data16 & 0x001F) << 3;

			// i는 메모리에서 몇번째 줄이냐 j는 해당 줄에 
			// 몇번째 칸인지 알려주는 오프셋 정보
			*(Image24 + (i * width24) + (j * 3) + 2) = R; 
			*(Image24 + (i * width24) + (j * 3) + 1) = G;
			*(Image24 + (i * width24) + (j * 3) + 0) = B;
		}
	}

	//24bit 출력 파일을 작성한다. 24bit bmp
	BITMAPFILEHEADER bfh; // 14byte 정보 저장
	bfh.bfType = 19778; // bmp >> 19778 -> 'BM'
	bfh.bfSize = 12374; // 220 * 56 + 54 = 12374
	bfh.bfReserved1 = 0;
	bfh.bfReserved2 = 0;
	bfh.bfOffBits = 54; // 고정(정적)(static) 그림정보 시작지점

	BITMAPINFOHEADER bif;
	bif.biSize = 40;// 인포헤더사이즈 40byte
	bif.biWidth = 73;
	bif.biHeight = 56;
	bif.biPlanes = 1; // 그림의 갯수
	bif.biBitCount = 24;// 24bit color
	bif.biCompression = 0; // 압축 여부
	bif.biSizeImage = 12374 - 54; // 가변적 (순수한 이미지 사이즈)
	bif.biXPelsPerMeter = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
	bif.biYPelsPerMeter = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
	bif.biClrUsed = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
	bif.biClrImportant = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)

	FILE* wf = fopen("0000.bmp", "wb");
	if (wf == NULL)
	{
		printf("Write Open Error");
		return 0;
	}

	fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, wf);
	fwrite(&bif, sizeof(BITMAPINFOHEADER), 1, wf);
	fwrite(Image24, 1, size24, wf);

	fclose(wf);
	delete[] Image16;
	delete[] Image24;

	printf("성공");
	fclose(rf);
}

