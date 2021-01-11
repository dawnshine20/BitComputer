#include <iostream>
#include <windows.h>
// 마이크로소프트에서 공식적으로 무시해도 괜찮다고 이야기된 warning
#pragma warning(disable: 4996) 

int main()
{

	FILE* rf = fopen("0000.jsf", "rb");

	if (rf == NULL)
	{
		printf("Open Error");
		return 0;
	}


	BYTE FileHeader[250]; //고정되어있는 값이기 때문에 배열을 사용한다.
	fread(FileHeader, 1, 250, rf); // 읽으려고하는 메모리의 시작 주소(1byte씩 250번 읽어라)
	//BYTE, WORD, DWORD
	DWORD imageNumber; // 이미지변수에 음수가 들어올리가 없기 떄문에 unsigned추가
	fread(&imageNumber, sizeof(DWORD), 1, rf); // 조사식에서 16진수로 확인 가능
	printf("imageNumber : %d\n", imageNumber);

	int pictureNumber = 0;
	WORD width221, height221;
	width221 = (128 * 3); // rgb 때문에 * 3 
	height221 = 96;
	long size221 = (width221 * 16) * (height221 * 14); // 가로에는 16개 사진 , 세로에는 14개 사진
	BYTE* Image221 = new BYTE[size221];
	memset(Image221, 0, size221);

	//-----------------------첫번째 그림의 정보가 시작된다.----------------------------
	for (int a = 0; a < imageNumber; a++)
	{
		BYTE reserver[26];
		fread(reserver, 1, 26, rf); // 읽으려고하는 메모리의 시작 주소(1byte씩 26번 읽어라)

		DWORD compressSize;
		WORD width, height;
		fread(&compressSize, sizeof(DWORD), 1, rf);
		fread(&width, sizeof(WORD), 1, rf); // 73(점의 갯수)
		fread(&height, sizeof(WORD), 1, rf); // 56(점의 갯수)

		printf("compressSize: %d\n", compressSize);

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
			DWORD _OFFSET = (height - 1 - i) * (width * 2) + 0;
			printf("%d\n", _OFFSET);
			switch (idNum) // switch == goto 문장
			{

			case 0: { // 공백인 경우

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

		for (int i = 0, k = 0; i < height; i++) {
			for (int j = 0; j < width; j++, k++) {
				WORD data16 = *(WORD*)(Image16 + k * 2);
				BYTE R = (data16 & 0xf800) >> 8;
				BYTE G = (data16 & 0x07E0) >> 3;
				BYTE B = (data16 & 0x001F) << 3;

				*(Image24 + (i * width24) + (j * 3) + 2) = R;
				*(Image24 + (i * width24) + (j * 3) + 1) = G;
				*(Image24 + (i * width24) + (j * 3) + 0) = B;
			}
		}
		for (int i = 0, k = 0; i < height; i++) {
			for (int j = 0; j < width; j++, k++) {
				WORD data16 = *(WORD*)(Image16 + k * 2);
				BYTE R = (data16 & 0xf800) >> 8;
				BYTE G = (data16 & 0x07E0) >> 3;
				BYTE B = (data16 & 0x001F) << 3;

				*(Image221 + (i * width221 * 16) + (96 * width221 * 16) * (13 - a / 16) + (width221 * pictureNumber) + (j * 3) + 2) = R;
				*(Image221 + (i * width221 * 16) + (96 * width221 * 16) * (13 - a / 16) + (width221 * pictureNumber) + (j * 3) + 1) = G;
				*(Image221 + (i * width221 * 16) + (96 * width221 * 16) * (13 - a / 16) + (width221 * pictureNumber) + (j * 3) + 0) = B;
			}
			//i 변화에 따라 사진세로 갯수 달라지도록 설계할 것
		}
		pictureNumber++;

		//24bit 출력 파일을 작성한다. 24bit bmp
		BITMAPFILEHEADER bfh; // 14byte 정보 저장
		bfh.bfType = 19778; // bmp >> 19778 -> 'BM'
		bfh.bfSize = width24 * height24 + 54; // 220 * 56 + 54 = 12374
		bfh.bfReserved1 = 0;
		bfh.bfReserved2 = 0;
		bfh.bfOffBits = 54; // 고정(정적)(static) 그림정보 시작지점

		BITMAPINFOHEADER bif;
		bif.biSize = 40;// 인포헤더사이즈 40byte
		bif.biWidth = width;
		bif.biHeight = height;
		bif.biPlanes = 1; // 그림의 갯수
		bif.biBitCount = 24;// 24bit color
		bif.biCompression = 0; // 압축 여부
		bif.biSizeImage = width24 * height24; // 가변적 (순수한 이미지 사이즈)
		bif.biXPelsPerMeter = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
		bif.biYPelsPerMeter = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
		bif.biClrUsed = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
		bif.biClrImportant = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)

		char name[32] = "";
		sprintf(name, "%04d.bmp", a);

		FILE* wf = fopen(name, "wb");

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
	}

	//24bit 출력 파일을 작성한다. 24bit bmp
	BITMAPFILEHEADER bfhResult; // 14byte 정보 저장
	bfhResult.bfType = 19778; // bmp >> 19778 -> 'BM'
	bfhResult.bfSize = size221 + 54; // 220 * 56 + 54 = 12374
	bfhResult.bfReserved1 = 0;
	bfhResult.bfReserved2 = 0;
	bfhResult.bfOffBits = 54; // 고정(정적)(static) 그림정보 시작지점

	BITMAPINFOHEADER bifResult;
	bifResult.biSize = 40;// 인포헤더사이즈 40byte
	bifResult.biWidth = width221 * 16 / 3;
	bifResult.biHeight = height221 * 14;
	bifResult.biPlanes = 1; // 그림의 갯수
	bifResult.biBitCount = 24;// 24bit color
	bifResult.biCompression = 0; // 압축 여부
	bifResult.biSizeImage = size221; // 가변적 (순수한 이미지 사이즈)
	bifResult.biXPelsPerMeter = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
	bifResult.biYPelsPerMeter = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
	bifResult.biClrUsed = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)
	bifResult.biClrImportant = 0;// (디프리케이트됨)기능이 약해서 사용되지 않음(과거와 호환성을 위해 없어지지 않음)

	FILE* wfResult = fopen("result.bmp", "wb");
	if (wfResult == NULL)
	{
		printf("Open Error");
		return 0;
	}

	fseek(wfResult, 0, SEEK_SET);
	fwrite(&bfhResult, sizeof(BITMAPFILEHEADER), 1, wfResult);
	fwrite(&bifResult, sizeof(BITMAPINFOHEADER), 1, wfResult);
	fwrite(Image221, 1, size221, wfResult);

	fclose(wfResult);
	delete[] Image221;

	printf("성공");
	fclose(rf);
}