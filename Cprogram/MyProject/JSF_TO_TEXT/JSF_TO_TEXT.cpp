#include <iostream>
#include<windows.h>
#pragma warning(disable: 4996) 

int main()
{
    FILE* fpJsf;
    fpJsf = fopen("0000.JSF", "rb");

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    // 파일헤더 250byte만큼 읽기
    BYTE fileHeader[250];
    memset(fileHeader, 0, 250);
    fread(fileHeader, sizeof(BYTE), 250, fpJsf);
     
    // 그림갯수 정보 읽기
    DWORD imageNumber;
    fread(&imageNumber, sizeof(DWORD), 1, fpJsf);
    printf("그림 갯수는 %d입니다.\n", imageNumber);
    for (int a = 0; a < imageNumber; a++)
    {
        // 예약어 정보 읽기
        BYTE reserver[26];
        fread(&reserver, sizeof(BYTE), 26, fpJsf);


        DWORD compressSize;
        WORD width, height;
        fread(&compressSize, sizeof(DWORD), 1, fpJsf);
        fread(&width, sizeof(WORD), 1, fpJsf);
        fread(&height, sizeof(WORD), 1, fpJsf);
        printf("width : %d, height : %d\n", width, height);

        DWORD width16 = width * 2;
        //DWORD width24 = width * 3;
        DWORD size16 = width16 * height;

        //DWORD q = width24 / 4;
        //DWORD r = width24 % 4;

        //width24 = (q + 1) * 4; // 4의 배수로 픽셀 단위 크기 맞추어 가로길이 도출
        //DWORD size24 = width24 * height;


        BYTE* Image16 = new BYTE[size16];
        //BYTE* Image24 = new BYTE[size24];
        memset(Image16, 0, size16);
        //memset(Image24, 0, size24);

        char name[32];
        sprintf(name, "%04d.txt", a);
        FILE* wf = fopen(name, "w");

        for (int i = 0; i < height; i++)
        {
            // y * w + x 오프셋 주소 공식
            DWORD idNum = 0;
            DWORD _offset = (height - 1 - i) + 0;
            DWORD pixelNum;
            

            fread(&idNum, sizeof(WORD), 1, fpJsf);
            printf("idNum : %d\n", idNum);

            switch (idNum)
            {

            case 0:
            {
                // 어짜피 모두 0으로 초기화 되어있음
                for (int b = 0; b < width; b++)
                {
                    fprintf(wf, "%c", '-');
                }
            }break;
            case 1:
            {
                fread(Image16 + _offset, 2, width, fpJsf); // 2 byte씩 가로길이만큼 읽음

                for (int b = 0; b < width; b++)
                {
                    fprintf(wf, "%c", 'o');
                }
                
            }break;
            default:
            {
                int remainer = 0;
                WORD blankNum, pixelNum;
                for (int j = 0; j < idNum - 1; j++)// 세트 갯수대로 읽기
                {
                    fread(&blankNum, 2, 1, fpJsf); // 공백 갯수 읽기
                    _offset += (blankNum * 2);

                    for (int b = 0; b < blankNum; b++)
                    {
                        fprintf(wf, "%c", '-');
                    }

                    fread(&pixelNum, 2, 1, fpJsf); // 그림 갯수 읽기
                    fread(Image16 + _offset, 2, pixelNum, fpJsf); // -----***** <- -----제외하고 *****읽음
                    _offset += (pixelNum * 2);

                    for (int b = 0; b < pixelNum; b++)
                    {
                        fprintf(wf, "%c", 'o');
                    }
                    
                    remainer += blankNum;
                    remainer += pixelNum;
                    
                }

                remainer = width - remainer;// 남는 공간
                for (int b = 0; b < remainer; b++)
                {
                    fprintf(wf, "%c", '-');
                }
            }break;
            }
            fprintf(wf, "\n");
        }

        //for (int i = 0, k = 0; i < height; i++)
        //{
        //    for (int j = 0; j < width; j++, k++)
        //    {
        //        WORD data16 = *((WORD*)Image16 + k * 2);
        //        BYTE R = (data16 & 0xf800) >> 8;
        //        BYTE G = (data16 & 0x07E0) >> 3;
        //        BYTE B = (data16 & 0x001F) << 3;
        //
        //        *(Image24 + (i * width) + (j * 3) + 2) = R;
        //        *(Image24 + (i * width) + (j * 3) + 1) = G;
        //        *(Image24 + (i * width) + (j * 3) + 0) = B;
        //    }
        //}
        
        fclose(wf);
        delete[] Image16;
        //delete[] Image24;
    }
    printf("성공");
    fclose(fpJsf);
}
