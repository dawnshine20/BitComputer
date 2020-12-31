#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <math.h>


int main()
{
	//↓↑
	
}

#pragma region 12/29 Problem 1번
//1.
/* 배열 사용 (x) 10명이  0점부터 100점 랜덤하게 받아서 아래처럼 출력*/
//95 * * * * * * * * *    수
//90 * * * * * * * *      우
//48 * * * *              가
//65 * * * * * *          양
//23 * *                  가
//33 * * *                가
//30 * * *                가
//-------------------------------------
//srand((signed)time(NULL));
//int numberOfPeople = 0;
//printf("사람 수를 입력하세요 : ");
//scanf_s("%d", &numberOfPeople);
//
//for (int i = 0; i < numberOfPeople; i++)
//{
//	int* score = new int;
//	*score = rand() % 101;
//	printf("%d ", *score);
//
//	int numberOfGraphicScore = 0;
//	numberOfGraphicScore = *score / 10;
//
//	for (int i = 0; i < numberOfGraphicScore; i++)
//	{
//		printf("* ");
//	}
//
//	for (int i = 0; i < 10 - numberOfGraphicScore; i++)
//	{
//		printf("  ");
//	}
//
//	if (numberOfGraphicScore == 0)
//	{
//		printf(" ");
//	}
//
//	switch (numberOfGraphicScore)
//	{
//	case 9:
//	{
//		printf(" 수");
//	}break;
//	case 8:
//	{
//		printf(" 우");
//	}break;
//	case 7:
//	{
//		printf(" 미");
//	}break;
//	case 6:
//	{
//		printf(" 양");
//	}break;
//	default:
//	{
//		printf(" 가");
//	}break;
//
//	}printf("\n");
//
//	delete score;
//}
#pragma endregion
#pragma region 12/29 Problem 2번
//2.
/* 배열 사용 (x)*/
// num = 5일때 결과.(단, num은 무조건 짝수 아님)
//      *
//    * * *
//  * * * * *
//    * * *
//      *
//-------------------------------------------------
//int lineNumber = 0;
//printf("(짝수만 입력) 라인 줄 수 : ");
//scanf_s("%d", &lineNumber);
//
//if (lineNumber % 2 != 1) // 홀수가 아니라면
//return 0;
//
//int halfLineNumber = lineNumber / 2;
//for (int i = 0; i < lineNumber; i++)
//{
//	for (int j = 0; j < lineNumber; j++)
//	{
//		if (i + j > 3 * (halfLineNumber))
//			printf("  ");
//		else if ((i + j >= halfLineNumber) && (j - i <= halfLineNumber) && (i - j <= halfLineNumber))
//			printf("* ");
//		else
//			printf("  ");
//	}printf("\n");
//}
#pragma endregion
#pragma region 12/29 Problem 3번
	//3. 배열 (x) 랜덤하게 o 와 x를 출력한 결과.
	// o o o x x o o x o o >> 총 10 //// x o o o o o o x x x >> 총 10
	// o : 3                          // o : 6개
	// x : 2                          // x : 3개
//---------------------------------------------------------
//srand((signed)time(NULL));
//int* saveO;
//int* saveX;
//int currentValue;
//int countO = 0;
//int countX = 0;
//int prevValue = 0;
//
//int countAddressO = 0;
//int countAddressX = 0;
//
//int number;
//printf("총 출력 갯수 입력 : ");
//scanf_s("%d", &number);
//
//saveO = new int[number / 2];
//saveX = new int[number / 2];
//
//for (int i = 0; i < number; i++)
//{
//	currentValue = rand() % 2;
//
//	if (currentValue == 0)
//	{
//		countX++;
//		printf("X ");
//		if (prevValue != currentValue)
//		{
//			countAddressO++;
//			*(saveO + countAddressO) = countO;
//			countO = 0;
//		}
//	}
//	else
//	{
//		countO++;
//		printf("O ");
//		if (prevValue != currentValue)
//		{
//			countAddressX++;
//			*(saveX + countAddressX) = countX;
//			countX = 0;
//		}
//	}
//	prevValue = currentValue;
//}printf("\n");
//
//if (currentValue == 0)
//*(saveX + (++countAddressX)) = countX;
//else
//*(saveO + (++countAddressO)) = countO;
//
//
//int result = 0;
//for (int i = 1; i <= countAddressO; i++)
//{
//	if (result < *(saveO + i))
//		result = *(saveO + i);
//}printf("O : %d \n", result);
//
//result = 0;
//for (int i = 1; i <= countAddressX; i++)
//{
//	if (result < *(saveX + i))
//		result = *(saveX + i);
//}printf("X : %d \n", result);
//
//
//delete[] saveO;
//delete[] saveX;
//
//return 0;
#pragma endregion
#pragma region 12/29 Problem 4번
// 1월달부터 12월 달까지 출력 (배열 ㅇ)
//4. 2021년 달력 출력(1월 1일은 금요일)
// 일 월 화 수 목 금 토
//                1  2
// 3  4  5  6  7  8  9
// 10 11 12 13 14 15 16
// 17 18 19 20 21 22 23
// 24 25 26 27 28 29 30
// 31
#pragma endregion
#pragma region 12/29 Problem 5번
//5. 배열 사용 x
//int a = 랜덤;(0-9)          // 3     3
//int b = 랜덤;(0-9)          // 5     3
//int c = 랜덤;(0-9)          // 9     6
// 세개의 중간 수를 출력하시오     5     3
//-----------------------------------------
// 가독성에 문제가 되기 때문에 좋은 코드가 아님
// 가독성을 추가시키기 위해서는 주석이 필요하다.(if else 케이스에 대한 주석이 필수적으로 필요하다.)
//srand((signed)time(NULL));
//int a; int b; int c;
//int middleNumber;
//a = rand() % 10; b = rand() % 10; c = rand() % 10;
//printf("%d\n", a);
//printf("%d\n", b);
//printf("%d\n", c);
//
//if ((a > b && a < c) || (a < b && a > c))
//	middleNumber = a;
//else if ((a < b && b < c) || (a > b && b > c))
//middleNumber = b;
//else
//middleNumber = c;
//printf("중간 수는 %d 입니다.", middleNumber);
#pragma endregion

#pragma region review 김선일 1번
//int num = 0;
//for (int a = 0; a < 10; a++)
//{
//	int num = ((rand() % 100) + 1);
//	int result = num / 10;
//	printf("%2d", num);
//
//	for (int b = 0; b < result; b++)
//	{
//		printf("*");
//	}
//	for (int b = 0; b < 10 - result; b++)
//	{
//		printf(" ");
//	}
//	switch (result)
//	{
//	case 10:
//		printf("수");
//		break;
//	case 9:
//		printf("우");
//		break;
//	case 8:
//		printf("미");
//		break;
//	case 7:
//		printf("양");
//		break;
//	default:
//		printf("가");
//		break;
//	}printf("\n");
//}
#pragma endregion

#pragma region review 정세연 2번
//int inputData;
//printf("숫자를 입력하세요(홀수만 가능): ");
//scanf_s("%d", &inputData);
//int halfInputData = inputData / 2 + 1;
//if (inputData % 2 == 0) {
//	printf("홀수만 가능합니다.");
//	return 0;
//}
//
//for (int i = 1; i <= inputData; i++) {
//	for (int j = 1; j <= inputData; j++) {
//		if (i <= halfInputData)
//		{
//			if ((j > halfInputData - i) && (j < halfInputData + i)) printf("* ");
//			else printf("  ");
//		}
//		else
//		{
//			if ((j > i - halfInputData) && (j <= inputData - (i - halfInputData))) printf("* ");
//			else printf("  ");
//		}
//	} printf("\n");
//}
#pragma endregion
#pragma region review 이현 2번
//int num;
//int i, j;
//int n = 1;
//printf("num : ");
//scanf_s("%d", &num);
//int b = num / 2;
//int s = num / 2;
//for (i = 0; i < num; i++)
//{
//	if (i == num / 2)
//	{
//		n = n * -1;
//	}
//	for (j = 0; j < b; j++)
//	{
//		printf(" ");
//	}
//	for (j = 0; j < num - (2 * s); j++)
//	{
//		printf("*");
//	}
//	printf("\n");
//	b = b - n;
//	s -= n;
//}
#pragma endregion
#pragma region review 이민혁 2번
//int i, j;
//int num = 9;
//int count = num / 2 + 1; //마름모의 가운데 좌표
////피라미드 그리기
//for (i = 0; i < count; i++)
//{
//	//오른쪽 삼각형
//	for (j = 0; j < count - i - 1; j++)
//		printf(" ");
//	for (j = 0; j <= i; j++)
//		printf("*");
//	//왼쪽 삼각형
//	for (j = 1; j <= i; j++)
//	{
//		printf("*");
//	}
//	printf("\n");
//}
//////역 피라미드 그리기
//for (i = 0; i < count - 1; i++)
//{
//	//역삼각형
//	for (j = count; j >= count - i; j--)
//	{
//		printf(" ");
//	}
//	for (j = 1; j < count - i - 1; j++)
//	{
//		printf("*");
//	}
//	//왼쪽 역삼각형
//	for (j = 0; j < count - i - 1; j++)
//		printf("*");
//	for (j = 0; j <= i; j++)
//		printf(" ");
//	printf("\n");
//}
#pragma endregion
#pragma region review sample 2번(best)
//int n = 5;
//const int start = (n / 2) * -1;
//const int end = (n / 2);
//
//for (int i = start; i <= end; i++)
//{
//	for (int j = start; j <= end; j++)
//	{
//		int result = abs(i) + abs(j);
//		if (result <= 2)
//			printf("*");
//		else
//			printf(" ");
//	}printf("\n");
//}
#pragma endregion

#pragma region review 홍석우 3번
//int SameCharacterO(int* OX, int number, int order)
//{
//	int Ocount = 1;
//	for (int i = order; i < number; i++)
//	{
//		if (OX[i] == OX[i + 1] && OX[i] == 1)
//			Ocount++;
//		else
//			return Ocount;
//	}
//}
//int SameCharacterX(int* OX, int number, int order)
//{
//	int Xcount = 1;
//	for (int i = order; i < number; i++)
//	{
//		if (OX[i] == OX[i + 1] && OX[i] == 0)
//			Xcount++;
//		else
//			return Xcount;
//	}
//}
//int FindLongest(int* OX, int number, int wh)
//{
//	int* characterO;
//	int* characterX;
//	int longestO = 0;
//	int longestX = 0;
//	characterO = new int[number];
//	characterX = new int[number];
//	for (int i = 0; i < number; i++)
//	{
//		switch (OX[i])
//		{
//		case 1:
//			characterO[i] = SameCharacterO(OX, number, i);
//			break;
//		case 0:
//			characterX[i] = SameCharacterX(OX, number, i);
//			break;
//		}
//	}
//	switch (wh)
//	{
//	case 1:
//	{
//		for (int j = 0; j < number; j++)
//		{
//			(characterO[j] >= longestO) ? longestO = characterO[j] : longestO += 0;
//		}
//		delete[] characterO, characterX;
//		return longestO;
//		break;
//	}
//	case 0:
//	{
//		for (int j = 0; j < number; j++)
//		{
//			(characterX[j] >= longestX) ? longestX = characterX[j] : longestX += 0;
//		}
//		delete[] characterO, characterX;
//		return longestX;
//		break;
//	}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int number;							// O, X의 총 개수
//	int* OX;							// O, X 포인터 변수
//	int OO = 0;
//	int XX = 0;
//	printf("O, X의 총 개수를 입력하시오. : ");
//	scanf_s("%d", &number);
//	OX = new int[number];
//	for (int i = 0; i < number; i++)  // OX변수에 O or X 대입
//	{
//		OX[i] = rand() % 2;
//		/*(OX[i] == 1) ? OO++ : XX++;*/
//	}
//	for (int i = 0; i < number; i++)  // 1 이면 'O', 0 이면 'X' 출력
//	{
//		(OX[i] == 1) ? printf("O ") : printf("X ");
//	}
//	printf("\n");
//	OO = FindLongest(OX, number, 1);
//	XX = FindLongest(OX, number, 0);
//	delete[] OX;
//	printf("O : %d\n", OO);
//	printf("X : %d\n", XX);
//}
#pragma endregion
#pragma region review 이민혁 3번
//srand((unsigned)time(NULL));
//int Ocount = 0;
//int Xcount = 0;
//int maxo = 0;
//int maxx = 0;
//for (int i = 0; i < 10; i++)
//{
//	int random = rand();
//	//짝수면 O 홀수면 X를 출력
//	printf("%c ", random % 2 == 0 ? 'O' : 'X');
//	//연속된 문자 갯수 카운팅 연속성이 끝나면 최대횟수인지 비교 후 다시 카운팅
//	if (random % 2 == 0)
//	{
//		Xcount = 0; // 다른 변수는 재 초기화
//		Ocount++;
//		if (maxx < Xcount)
//			maxx = Xcount;
//		/*maxx = maxx > Xcount ?
//			maxx : Xcount;*/
//
//	}
//	else
//	{
//		Ocount = 0;
//		Xcount++;
//		if (maxo < Ocount)
//			maxo = Ocount;
//	}
//	//마지막에 최대횟수가 나올 경우를 대비해서 한번더 비교
//	/*maxx = maxx > Xcount ? maxx : Xcount;
//	maxo = maxo > Ocount ? maxo : Ocount;*/
//}printf("\n");
//printf("O의 연속된 최대횟수는 %d\n", maxo);
//printf("X의 연속된 최대횟수는 %d\n", maxx);
#pragma endregion
#pragma region 신민영 3번
//srand((unsigned)time(NULL));
//int rn;
//int oCnt = 0, xCnt = 0;
//int oMax = 0, xMax = 0;
//for (int i = 0; i < 10; i++) {
//	rn = rand() % 2;
//	rn == 1 ? printf("O ") : printf("X ");
//	rn == 1 ? oCnt++ : oCnt = 0;
//	if (oMax < oCnt) oMax = oCnt;
//	rn == 0 ? xCnt++ : xCnt = 0;
//	if (xMax < xCnt) xMax = xCnt;
//}
//printf("\n");
//printf("O : %d\n", oMax);
//printf("X : %d\n", xMax);
#pragma endregion
#pragma region sample 3번
//int rn;
//int oCnt = 0, xCnt = 0;
//int oMax = 0, xMax = 0;
//for (int i = 0; i < 10; i++)
//{
//	rn = rand() % 2;
//	rn == 1 ? printf("O ") : printf("X ");
//	if (rn == 1) {
//		xCnt = 0;
//		oCnt++;
//
//		if (oCnt > oMax) {
//			oMax = oCnt;
//		}
//	}
//	else
//	{
//		xCnt = 0;
//		oCnt++;
//
//		if (xCnt > xMax) {
//			xMax = xCnt;
//		}
//	}
//	printf("\n");
//	printf("o의 최대 갯수 : %d");
//	printf("x의 최대 갯수 : %d");
//}
#pragma endregion

#pragma region 조인희 4번(best)
//int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//const char* wname[7] = { "일","월","화","수","목","금","토" };
//
//int DrawMonth(int month, int start)
//{
//	int i = 0;
//	printf(" << %d 월>>\n", month + 1);//달
//	printf("=====================================================\n");
//	for (i = 0; i < 7; i++)//요일
//	{
//		printf("%7s", wname[i]);//폭 설정
//	}
//	printf("\n");
//	printf("-----------------------------------------------------\n");
//	for (i = 0; i < start; i++)//첫 주 시작일까지 공백 출력
//	{
//		printf("%7s", " ");//폭을 7로 설정
//	}
//	for (i = 0; i < days[month]; i++)//일 출력
//	{
//		printf("%7d", i + 1);//폭을 7로 설정
//		start++;
//		if (start == 7)//요일이 7이면
//		{
//			start = 0;//0으로 변경
//			printf("\n");//개행 출력
//		}
//	}
//	printf("\n");//개행 출력
//	printf("=====================================================\n");
//	return start;//다음 달 시작 요일 반환
//}
//
//int main()
//{
//	//↓↑
//	//srand((signed)time(NULL));
//	int year = 2021;
//	int start = 5;
//	int i = 0;
//  윤년 규칙
//	1) 4년으로 나누어지는 해는 윤달(2월 29일)이 있다.
//	2) 그러나 100년으로 나누어지는 해는 윤달이 없다. 
//	3) 그러나 400년으로 나누어지는 해는 윤달이 있다.
//	if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
//	{
//		days[1] = 29;//2월달 29일
//	}
//	printf("[ %d년 ]\n", year);
//	for (int i = 0; i < 12; i++)
//	{
//		start = DrawMonth(i, start);
//	}
//	return 0;
//}
// 2021년 
// 0001년 1월 1일 >> 무슨 요일인가? 월요일
// 400년 마다 반복해서 똑같은 규칙 나옴(윤년)

// 1372년 7월8일 ....요일은....
//양력개념...음력...식이 없다.... 과거 데이터가 존재해야한다.(음력은 공식이 없다.)
#pragma endregion
#pragma region sample(java) 4번
//for (int a = 0; a < 12; a++)
//{
//	System.out.println(a + 1 + "월달 달력");
//	// 일(0) 월(1) 화(2) 수(3) 목(4) 금(5) 토(6)
//	System.out.println("일    월    화    수    목    금    토");
//	for (int b = 0; b < InitDay; b++)
//		System.out.print("   "); // 스페이스 3개
//	for (int b = 0; b < Month[a]; b++)
//	{
//		System.out.printf("%2d ", b + 1);
//		if ((InitDay + b) % 7 == 6)
//		{
//			System.out.println();
//		}
//	}
//	InitDay = (InitDay + Month[a]) % 7;
//	System.out.println("\n");
//}
#pragma endregion

#pragma region sample 5번
//코드가 좀 더 길어져도 가독성을 좀 더 좋게 만들어야한다.
// 코드 늘린것과 최적화와는 별개이기 때문에 가독성 + 최적화를 중시해야함
//for (int i = 0; i < 20; i++)
//{
//	int a, b, c, m;
//	a = 1; b = 2; c = 3; m = 0;
//	//a = 1; b = 3; c = 2; m = 0;
//	//a = 2; b = 1; c = 3; m = 0;
//	//a = 2; b = 3; c = 1; m = 0;
//	//a = 3; b = 1; c = 2; m = 0;
//	//a = 3; b = 2; c = 1; m = 0;
//	if (a > b) { // a는 최대 아니면 중간 : 왜냐하면 a가 최소가 아니니까.
//		if (a > c) { // a는 최대
//				//m = (b > c) ? b : c;
//			m = Math.max(b, c);
//		}
//		else { // 중간
//			m = a;
//		}
//	} // 64 64 4
//	else {// (a<b) a는 최소 아니면 중간
//		if (a < c) { // a는 최소
//				//m = (b > c) ? c : b;
//			m = Math.min(b, c);
//		}
//		else {
//			m = a;
//		}
//	}
//}
//		}
// }
#pragma endregion

#pragma region Function2
//void f5(int* p, int s)
//{
//	for (int i = 0; i < s; i++)
//	{
//		printf("%d ", p[i]);
//	}
//}
//
//void f4(const char* p)
//{
//	int strLength = strlen(p);
//	for (int i = 0; i < strLength; i++)
//	{
//		printf("%c", p[i]);
//		printf("%c", 0x20);// spacebar ascii code
//	}
//}

//f4("Tiger Win");

	//int ar[4] = { 1, 2, 3, 4 };
	//int s = sizeof(ar) / sizeof(int);
	//printf("%d\n", s);

	//f5(ar, s);
	//f5(&ar[0], s);

	///*ar[0] == *(ar+0)
	//&ar[0] == ar
	//ar[1] == *(ar + 1)*/
#pragma endregion
#pragma region Function1
//void f1(int width, int height, char c) 
//{
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			printf("%c ", c);
//		}printf("\n");
//	}printf("\n");
//}
//
//void f2(int w, int h, char c1, char c2)
//{
//	for (int i = 0, k = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++, j++)
//		{
//			printf("%c ", ((i + j) % 2 == 0) ? c1 : c2);
//		}printf("\n");
//	}printf("\n");
//}
//
//void f3(int* p, int s)
//{
//	for (int i = 0; i < s; i++)
//	{
//		printf("%d ", p[i]); // *(p+i)
//	}
//	delete[] p;
//}

	/*f1(4, 3, '#');*/
	/*f2(4, 3, 'o', 'x');
	f2(3, 5, 'o', 'x');*/

	//// 1
		//int num = 10;
		//f3(&num, 1);

	//// 2
		//int* p = new int;
		//f3(p, 1);

	//// 3
		//f3(new int[10], 10); // <<<<<<<<<<< 
		//delete[] f3(new int[10], 10); << 보편적으로 해제시키는 방안1(f3함수 return 주소 반환)
		//f4(new int, 10); // <<<<<<<<<<< 
		//delete f3(new int[10], 10); << 보편적으로 해제시키는 방안2
#pragma endregion
#pragma region struct5
	//struct ST01 {
	//	int a; // 일반변수
	//	int b[3]; // 배열변수 == 일반변수
	//	int* c; // 포인터변수 //←
	//};
	//struct ST02 {
	//	ST01 s01;//←
	//	ST01 s02[3];
	//	ST01* s03;
	//};
	//struct ST03 {
	//	ST02 s04;
	//	ST02 s05[3];
	//	ST02* s06;//←
	//};

/*ST03 x, y[3], * z;

	z = new ST03;
	z->s06 = new ST02[2];
	for (int i = 0; i < 2; i++)
	{
		z->s06[i].s03 = new ST01[2];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			z->s06[i].s03[j].c = new int;
		}
	}

	int count = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			count++;
			*z->s06[i].s03[j].c = count;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", *z->s06[i].s03[j].c);
		}printf("\n");
	}printf("\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			delete z->s06[i].s03[j].c;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		delete[] z->s06[i].s03 ;
	}
	delete[] z->s06;
	delete z;*/
	//----------------------------------------------------------
	/*z = new ST03;
	z->s06 = new ST02;
	z->s06->s03 = new ST01;
	z->s06->s03->c = new int;
	*z->s06->s03->c = 10;
	printf("%d", *z->s06->s03->c);
	delete z->s06->s03->c;
	delete z->s06->s03;
	delete z->s06;
	delete z;*/
#pragma endregion
#pragma region struct4
	//struct ST01 {
	//	int a; // 일반변수
	//	int b[3]; // 배열변수 == 일반변수
	//	int* c; // 포인터변수 //←
	//};
	//struct ST02 {
	//	ST01 s01;//←
	//	ST01 s02[3];
	//	ST01* s03;
	//};
	//struct ST03 {
	//	ST02 s04;
	//	ST02 s05[3];
	//	ST02* s06;//←
	//};

	//ST03 x, y[3], * z; 

		///*z->s05[1].s01.c = new int[2000];
		//z->s05[1].s01.c[0~1999] >> 값;
		//&z->s05[1].s01.c[0~1999] >> 주소;

		//z = new ST03;
		//z->s05[1].s01.c = new int;
		//*z->s05[1].s01.c >> 값
		//z->s05[1].s01.c >> 주소*/
		////↓↓↓↓↓ 문제 풀이
		//z = new ST03;
		//for (int i = 0; i < 3; i++)
		//{
		//	z->s05[i].s01.c = new int[10];
		//}
		//int count = 0;
		//for (int i = 0; i < 3; i++)
		//{
		//	for (int j = 0; j < 10; j++)
		//	{
		//		count++;
		//		z->s05[i].s01.c[j] = count;
		//	}
		//}
		//for (int i = 0; i < 3; i++)
		//{
		//	for (int j = 0; j < 10; j++)
		//	{
		//		printf("%d %p\n", z->s05[i].s01.c[j], &z->s05[i].s01.c[j]);
		//	}printf("\n");
		//}
		//for (int i = 0; i < 3; i++)
		//{
		//	delete[] z->s05[i].s01.c;
		//}
		//
#pragma endregion
#pragma region struct3

//struct STRU {
//	int a; // 일반변수
//	int b[3]; // 배열변수 == 일반변수
//	int* c; // 포인터변수
//	// int* d[3]
//};
//////struct STRU st;
//struct STRU* z;
//////z = &st; // 공유
//////st.a = 10;
//////
////////(*z).
////////↓ 별을 떼고 화살표 연산자를 사용
//////printf("%d %p %p \n", z->a, &z->a, &st.a);

////// 1개 or n개
////z = new STRU;
//////z->a = 10;
//////z->b[0, 1, 2] = 10;
////z->c = new int;
////*z->c = 20;

////printf("%p %d\n",
////	z->c, *z->c);

////delete z->c;
////delete z;

////*z입장 <-> *c입장
////   1			1
////----------------------
////   1			n
////z = new STRU;
////z->c = new int[5];
////z->c[0, 1, 2, 3, 4] = 10; // 값
////&z->c[0, 1, 2, 3, 4] ; // 주소
////for (int i = 0; i < 5; i++)
////{
////	z->c[i] = 10;
////}
////for (int i = 0; i < 5; i++)
////{
////	printf("%d %p", z->c[i], &z->c[i]);
////}
//////메모리 해제
////delete[] z->c;
////delete z;

////   n			1
//int num = 10;
//z = new STRU[3];
//z[0].c = &num; // 공유
////값: *z[0].c	주소 z[0].c

//z[1].c = new int; // 할당
////값: *z[1].c	주소 z[1].c

//z[2].c = new int[5];
////값: z[1].c[?]	주소 &z[1].c[?]

//// n : 1
//z = new STRU[2];
//z[0].c = new int;		// 주소 1개 담을 수 있음
//*z[0].c = 100;	//1

//z[1].c = new int[3];	// 주소 3개 담을 수 있음
//z[1].c[0] = 100; //2
//z[1].c[1] = 200;
//z[1].c[2] = 300;
//printf("%p %d\n", z[0].c, *z[0].c);
//for (int i = 0; i < 3; i++)
//{
//	printf("%p %d\n", &z[1].c[i], z[1].c[i]);
//}
//delete[] z[1].c;	//
//delete z[0].c;	//
//delete[] z;


//   n			n


//--------------------------------------------
//struct STRU y[2];
//int num = 10;
//y[0].c = &num;
//y[1].c = new int;
//y[0].c = new int[4];

/*int count = 0;
for (int i = 0; i < 2; i++)
{
	y[i].c	= new int[4];
	for (int j = 0; j < 4; j++)
	{
		count++;
		y[i].c[j] = count;
	}
}
for (int i = 0; i < 2; i++)
{
	for (int j = 0; j < 4; j++)
	{
		printf("%d ", y[i].c[j]);
	}printf("\n");
}printf("\n");

for (int i = 0; i < 2; i++)
{
	delete[] y[i].c;
}*/

/*printf("%d %p\n", y[0].c[0, 1, 2, 3], &y[0].c[0, 1, 2, 3]);

printf("%d %p\n",
	*y[0].c, y[1].c);*/


	/*y[0].a = 10;
	y[1].a = 20;
	printf("%d %p\n", y[0].a, &y[0].a);
	printf("%d %p\n", y[1].a, &y[1].a);*/

	/*y[0].b[0]
	y[0].b[1]
	y[0].b[2]
	y[1].b[0]
	y[1].b[1]
	y[1].b[2]*/

	/*for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			y[i].b[j] = 10;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d %p ", y[i].b[j], &y[i].b[j]);
		}printf("\n");
	}printf("\n");*/
	//-----------------------------------
	//struct STRU x;

	//int num = 10;
	//x.c = &num; // 메모리 공유
	//x.c = &x.a;
	//x.c = new int; // 할당
	//*x.c = 15;
	//printf("%d %p \n", *x.c, x.c);
	//delete x.c;

	//x.c = new int[10]; // 할당
	//*(x.c + 5) = 10;
	//x.c[5] = 10;
	//printf("%d %p %d %p\n", 
	//	*(x.c + 5), 
	//	x.c + 5,
	//	x.c[5], // 이 코드가 편하기 때문에
	//	&x.c[5] // 이 코드가 편하기 때문에
	//	);
	//delete[] x.c;

	//x.a = 10;
	//printf("%d %p %p\n", x.a, &x, &x.a);
	//x.b[0] = 10;
	//x.b[1] = 20;
	//x.b[2] = 20;
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%d %d\n", x.b[i], &x.b[i]);
	//}
#pragma endregion
#pragma region struct2
//typedef struct tagAPPLE { // 원본에게는 tag를 붙여준다.
//	int a;
//	int b, c;
//}APPLE, * PAPPLE, * LPAPPLE;
//
//APPLE a; // 일반 변수
//PAPPLE b; // 포인터 변수
//LPAPPLE c; // 포인터 변수
//b = &a;
//c = new APPLE;
//delete c;
//
//c = new APPLE[10];
//delete[] c;
#pragma endregion
#pragma region STRUCT1
//// 타입 재정의
//// 1. 코드의 가독성.
//typedef int ROBOT;
//typedef int ROBOT;
//typedef int RESULT;
//// 2. 코드의 약식표현
//typedef unsigned int UINT;
//// 3. 대소문자 오타 방지
//typedef int INT;
//// 4. 무조건 대문자로 정의 : 관례(암묵적인 약속)
//
//typedef int* PAPPLE;// P는 포인터 를 알리는 약어
//typedef int* LPAPPLE;// LP는 포인터 를 알리는 약어
//
//typedef int* BANANA, * PBANANA, * LPBANANA;
//
////int* t;
//LPAPPLE pt;
//pt = new int;
//
////int a;
////ROBOT a;
////RESULT b;
#pragma endregion
#pragma region defence program
//void f1(int num, int* p) {
//	if (p == NULL) {
//		return;
//	}
//	printf(*p)
//
//		if (num < 0) { // defence 프로그램
//			return;
//		}
//	// 짝수 홀수 판별 프로그램
//	//
//	//
//	int* p = NULL;
//// 중간에 코드 들어감
//	if (p == NULL) { // 방어적인 프로그램
//		p = new int;
//	}
//
//	*p = 10;
//
//	if (p != NULL) { // 방어적인 프로그램
//		delete p;
//		p = NULL;
//	}
//}
#pragma endregion
#pragma region pointer8(삼중 포인터 사용)
//int*** p = NULL;
//int ar[2][3][4];
//
//p = new int** [2]; // 면 갯수 2개    

//p[0] = new int* [3]; //면 1번 행 갯수 3개
////*(p+0) = new int* [3];
//p[1] = new int* [3]; //면 2번 행 갯수 3개

//p[0][0] = new int[4]; //열 갯수 4개
//p[0][1] = new int[4]; //열 갯수 4개
//p[0][2] = new int[4]; //열 갯수 4개
//p[1][0] = new int[4]; //열 갯수 4개
//p[1][1] = new int[4]; //열 갯수 4개
//p[1][2] = new int[4]; //열 갯수 4개

//for (int i = 0; i < 2; i++)
//{
//	p[i] = new int* [3]; // 행 단위 갯수 선언
//}
//for (int i = 0; i < 2; i++) // 면
//{
//	for (int j = 0; j < 3; j++) //행
//	{
//		p[i][j] = new int[4]; // i는 면, j는 행 -> new를 통해서 열 4개씩 생성
//	}
//}
//int count = 0;
//// 할당 part
//for (int i = 0; i < 2; i++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		for (int k = 0; k < 4; k++)
//		{
//			count++;
//			p[i][j][k] = count;
//		}
//	}
//}
//// 출력 part
//for (int i = 0, count = 0; i < 2; i++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		for (int k = 0; k < 4; k++)
//		{
//			printf("%d ", p[i][j][k]);
//		}printf("\n");
//	}printf("\n");
//}
//
//for (int i = 0; i < 2; i++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		delete[] p[i][j];// 열 해제
//	}
//}
//
//for (int i = 0; i < 2; i++)
//{
//	delete[] p[i]; // 행 해제
//}
//
//delete[] p; //면 해제
#pragma endregion
#pragma region Pointer7(이중포인터)
//void f1(int** pp)// 메모리 확보 역할
//{
//	*pp = new int;
//	**pp = 100;
//}
//void f2(int** pp, int s) {
//	*pp = new int[s];
//}
//int* f3(){
//int* pp = new int[10];
//return pp;
//}
//int main()
//{
//	int* p = f3();
//	delete[] p;
///////////////////
//	int* p;
//	f1(&p);
//	printf("%d\n", *p); // 확보된 메모리 사용
//	delete p; // 확보된 메모리 해제 담당
///////////////////
//	int* tt;
//	f2(&tt, 10);
//	//tt[0-9] 만들어짐
//	delete[] tt;
//}
#pragma endregion
#pragma region Pointer6
//int* a;
//int** b;
//a = 주소; //              &a(현재 알고있음), a(x), *a(x)

//*b = 주소;
//b = &a; //
//b = 주소; // &b(알고있음,  b(o),             *b(x),**b(x)

//a = new int;
//*b = new int;// a = new int; 한것 과 같음 (&a와 b는 공유되고있기 때문)
//*a = 100;// **b = 100;
//printf("%d\n", *a);
//printf("%p %p\n", a, *b);
//printf("%p %p\n", &a, b);
//delete* b;
//↑메모리 할당을 위임 할 때 2차원 포인터를 사용
// b는 할당 역할
// a는 사용 역할
// 왜 b한테 할당 역할을 위임하는가???
//Pointer7에서 이유 적어 놓음
#pragma endregion
#pragma region Pointer5
////1. ↓가로길이 O (4개)	세로길이 O (3개)
//int ar[3][4];
//for (int i = 0, k = 0; i < 3; i++)
//{
//	for (int j = 0; j < 4; j++, k++)
//	{
//		ar[i][j] = k;
//	}
//}
//for (int i = 0, k = 0; i < 3; i++)
//{
//	for (int j = 0; j < 4; j++)
//	{
//		printf("%02d ", ar[i][j]);
//	}printf("\n");
//}

////2. ↓가로길이 X 세로길이 O
//int* br[3];
////int* br[3][?]
///*br[0] = new int[4];
//br[1] = new int[4];
//br[2] = new int[4];*/
//for (int i = 0; i < 3; i++)
//{
//	br[i] = new int[4];
//}
//for (int i = 0; i < 3; i++)
//{
//	delete[] br[i];
//}

////3. ↓가로길이 O	세로길이 X(ex.주민등록 번호) 
//int(*cr)[4];
//cr = new int[3][4];// 이후는 이차원 배열 쓰듯이 쓰면 됨

//for (int i = 0, k = 0; i < 3; i++)
//{
//	for (int j = 0; j < 4; j++, k++)
//	{
//		cr[i][j] = k;
//	}
//}
//for (int i = 0, k = 0; i < 3; i++)
//{
//	for (int j = 0; j < 4; j++)
//	{
//		printf("%02d ", cr[i][j]);
//	}printf("\n");
//}
//delete[] cr;


////4. ↓가로길이 X	세로길이 X
//int** dr;
//dr = new int* [3];
//// int* dr[3]; 동격 문법이 되었다.
//for (int i = 0; i < 3; i++)
//{
//	dr[i] = new int[4];
//}
////int dr[3][4]; 동격 문법이 되었다.
//// 사용하는 것은 윗과 동일.... 저도 생략
////메모리 해제는 선언한 순서 반대로 진행
//for (int i = 0; i < 3; i++)
//{
//	delete[] dr[i];
//}
//delete[] dr;
#pragma endregion
#pragma region Point4
//int a, b, c;
//int ar[3]; // 배열을 사용하는 이유

//int* p1, * p2, * p3;
////↓ height는 알고 있는데 width를 모르는 경우
//int* br[3];// 포인터 배열
//int d = 100;
//br[0] = &d;
//br[1] = new int;
//br[2] = new int[4];

//br[0] = br[2]; // 메모리 공유
//
//delete br[1];// 메모리 해제 후
//br[1] = new int[1000]; // 다시 할당 가능
//delete[] br[1];// 메모리 해제

//
//int** t;
//t = new int* [3];
////↑코드가 실행이 끝난 다음에는 다음의 코드와 완전 동격이다.
//int* t[3];



//int** p;
//p = new int*; // 주소 받음
//*p = new int; // 주소 받음
//**p = 10;

//int** b;
//b = new int*[3] ; //포인터 배열(주소를 저장하기 위한 메모리 공간)
// *(b + 0) = 주소1;
// *(b + 1) = 주소2;
// *(b + 2) = 주소3;
// b[0] = 주소1;
// b[1] = 주소2;
/*int c = 100;
 b[0] = new int;
 b[1] = new int[4];
 b[2] = &c;*/

 // 2차원 포인터를 사용하는 첫번째 이유는
 // 1. 2차원 배열은 정적인데 동적으로 메모리를 할당 받아서 사용하기 위함
 /*b[1] = new int[4];
 b[0] = new int[4];
 b[2] = new int[4];
 *(b[0] + 0) = 10;
 b[0, 1, 2][0, 1, 2, 3] = 10;
 int ar[3][4];*/


 //int ar[2][3][4];

 //ar[2][3][4] = 10;
 //// ar[2][3][4]
 //// *(ar[2][3] + 4);
 //// *(*(ar[2] + 3) + 4);
 //// *(*(*(ar+2) + 3) + 4);
 //printf("%d\n", *(*(*(ar + 2) + 3) + 4));

 //// (ar[1][1]) ([2]) ;
 //// 토끼[거북이]
#pragma endregion
#pragma region Pointer3(과제)
///*
//키보드로 부터 숫자를 하나 입력 받는다.
//입력된 숫자가 12라고 가정할 때
//랜덤한 숫자를 입력한다.(0-9)
//앞과 뒤의 숫자를 순차적으로 합한 결과를
//출력하세요.
//*/

//// 랜덤한 숫자를 초기화시키고
//// 앞과 뒤를 더한 결과 출력.

////상태변경 함수 + 결과(그리기,움직임) 함수로 나누는게 좋은 코드
////mvc패턴 중요 => member <-> view <-> control
//int input;
//scanf_s("%d", &input);
//int* data = new int[input];
//for (int i = 0; i < input; i++) // 상태 변경
//{
//	*(data + i) = rand() % 10;
//}printf("\n");

//for (int i = 0; i < input; i++) // 결과
//{
//	printf("%d ", *(data + i));
//}printf("\n");

//int data_sum;
//int half_input = input / 2;
//for (int i = 0; i < half_input; i++)
//{
//	data_sum = data[i] + data[input - 1 - i]; // 출력을 위한 임시변수이기 때문에 분리 안함
//	printf("%d ", data_sum);
//}

//delete[] data;
#pragma endregion
#pragma region Pointer2

//int* a = new int;
//int* c;
//c = a; // 메모리 공유
//*c = 777;
//printf("%d %d\n", *a, *c);
////delete a; // 공유되어 있기 때문에 a만 해제 할경우 c까지 같이 해제된다.

//////*(c + 5) == c[5] (왼쪽은 컴파일 되었을 때 코드)
////int ar[4] = { 0, };
////ar[0] = 10;
////*(ar + 0) = 10;

///*int* a = new int;
//*a = 100;*/
////printf("%d %d\n", *a, a);
////delete a;

//////출력이 되더라도 메모리 해제되었기 때문에 죽은코드
////printf("%d %d\n", *a, a); 
//
////메모리 누수 되는 예제 2
////a = new int; // 1000번지
//////해제하지 않고 메모리 할당 할 경우
////a = new int; // 2000번지

////for (int i = 0; i < 10000; i++)
////{
////	a = new int; // 1000

////	*a = i * 10;
////	delete a;
////}
////a = new int[5];
////*(a + 0) = 10;
////*(a + 1) = 20;
////*(a + 4) = 40;
////for (int i = 0; i < 5; i++)
////{
////	printf("%d %p\n", *(a + i), (a + i));
////}

////delete[] a;

////// 1
////int* a;
////a = new int;

////// 2 : 여기 시점. 실행 S시점.
////// 메모리 1개 주세요.
////int* b = new int; // 여기부터 포인터를 사용할 수 있다.
////delete  b;

//////메모리 한개 이상 주세요.
////int* c = new int[3];
////delete[] c;

//int d;
//int* e = new int;
//*e = 10;
//d = *e; // 이 문장은 생략된 문장
//d = *(int*)e; // 생략된 내용 포함한 문장
//d = (int)*e;

//d = (int)*(int*)e; // 생략된 내용 포함한 문장

//// 잡혀진 메모리를 일부만 사용하게 되도록 강제로 설정
//char f;
//f = (char)*(short*)e; 
//

#pragma endregion
#pragma region Pointer
//1. 대입 연산자는 쌍반간의 타입이 반드시 같아야 한다.
//int a = 10;
//int b;
//short c;
//b = a;
//c = a;// 문제가 생길 예정인 코드
//c = (short)a;// 해결된 코드

/*void f1(int a, int* p) {  }
f1(10, new int);

int a = 10;
int* p = new int;*/

//int* d = NULL; //포인터 변수
// 2. 포인트 변수는 주소를 받기 전에는 절대 사용할 수 없다.

// 3. 주소를 받는 방법은 2가지가 존재한다.
// 1) 메모리 공유
// 2) 메모리 할당

// 포인터 변수던지 일반변수던지
// 주소 표현 하는 문법과 내용(값) 표현하는
// 문법을 알고 있어야 한다.

//int a;
//int* b;
// 4.
/*
			주소  값
	int  a	 &a    a
	int* b   b    *b
*/

//// 공유
//int a = 10;
//int* b;

//// 5.
//b = &a; // 주소 = 주소(메모리 공유)
//printf("%d %d \n", a, *b);
//printf("%p %p \n", &a, b);

////*b = a; // 내용 = 내용
//*b = 100; // 내용 = 내용
//printf("%d %d \n", a, *b);

//a = 200;
//printf("%d %d \n", a, *b);

// 6. 일반변수는 주소를 받을 수 없다.
// 주소를 받기 위해서 태어난 문법이 포인터이다.

//&a = b; (x) a는 l-value(상수)
// b = &a; (0) b는 r-value(변수)

//int a = 10;
//int* b;
//b = &a;
//int* c;
//c = &a; // c = b;

//int d;
//int* e;
//e = &d;
//
//// 사용하다가 ... 100줄 정도
//b = e;

//실제 사용처
//int a = 10;
//int* b = &a;
////--컴파일 시 위 아래는 같은 형식으로 컴파일 하게 된다.
//int a = 10;
//int* b;
//b = &a;

//void f1(int* p) {}
//f1(&a);
#pragma endregion
#pragma region FOR
// for(int i = 5; i > 20; i+=3)
//	1. i 출발 시점이 1초과 (너무 큼)
//	2.부등호 방향 바뀐 경우 
//	3.1개 초과 증가 식 사용
// (알고리즘)프로그램을 작성하다가 안되니까 for문의 형식을 수정한다.
// 위 코드는 스파게티 코드를 만드는 형식

//for (int i = -5; i <= 5; i++)
//{		// 수학 처리 알고리즘에서 쓰이는 코드
//}
//for (int i = 0; i < 10; i++)
//{
//}
//for (int i = 1; i <= 10; i++)
//{
//}
// for 예외사항
// for(int i = 5; i > 20; i+=3)
// 실행속도에서 급격히 이득을 얻을 때
//(상대방이 납득할 수 있을 정도의 주석을 추가해 준다.)

//잘못된 코드(가독성 감소)
//for (int i = x1; i <= x2; i++) {
//}
////옳은 코드(가독성 증가)
//int s = x2 - x1 + 1;
//printf(s); // 로그를 남기는 코드(덤프 파일)
//for (int i = 0; i < s; i++) {
//}
#pragma endregion
#pragma region WHILE
// if와 else의 실행 비중을 맞춘다.
/*while () {
	if (a < 0) {
		b = abs(a);
		printf()
	}
	else {
		b = abs(a);
		printf()
	}
}*/

// 금지된 코드 (for문으로 사용해도 되는 코드)
// 반복하는 횟수가 정해지지 않은 경우 사용할 것
/*while (a < 10) {
}*/

//int num = 0;
//int count = 0;
//scanf_s("%d", &num);
////콜라스 추측
//while (1) {
//	if (num % 2 == 0)
//		num /= 2;
//	else if (num == 1)
//	{
//		printf("%d\n", count);
//		printf("1에 도달하였습니다.\n");
//		return 0;
//	}
//	else
//		num = num * 3 + 1;

//	count++;
//}

#pragma endregion
#pragma region ARRAY

//char ar[] = "tiger";
//const char* br = "tiger"; 

//ar[0] = 'D';
//br[0] = 'D'; // 이 변수는 상수화 되었기 때문에 읽기만 가능하다.



//int a = 10; // 일반 변수
//int ar[3] = { 20,30,40 };		// 배열 변수
//printf("%d %d\n", a, ar[0]);	// value
//printf("%p %p\n", &a, &ar[0]);	// address



//int ar[10];  
//int br[10] = { 0, }; //자동 초기화
//int cr[] = { 0, 1, 2 }; // 정적 메모리(static)
// new  동적 메모리(dynamic)


//int s = 5;
//int dr[s]; 실행되지 않음

/*printf("%d\n", sizeof(cr));
for (int i = 0; i < sizeof(cr)/sizeof(int); i++)
{
	printf("%d\n", cr[i]);
}*/

#pragma endregion
#pragma region Two-Dimensional Array
/*srand((signed)time(NULL));

for (size_t i = 0; i < length; i++)
{
	int a = rand() % 5;
	printf("%d ", a);
}*/

//int ar[3][4]; // 행 갯수 3, 열 갯수 4

//for (int i = 0; i < 3; i++) // 행 반복 횟수
//{
//	for (int j = 0; j < 4; j++) // 열 반복 횟수
//	{
//		ar[i][j] = i * 4 + j;
//	}
//}
//for (int i = 0; i < 3; i++) // 행 반복 횟수
//{
//	for (int j = 0; j < 4; j++) // 열 반복 횟수
//	{
//		printf("%02d ", ar[i][j]);
//	}printf("\n");
//}printf("\n");

//for (int i = 0; i < ROW; i++) // 행 반복 횟수
//{
//	for (int j = 0; j < COLUMN; j++) // 열 반복 횟수
//	{
//		printf("%p ", &ar[i][j]);
//	}printf("\n");
//}

/*srand((signed)time(NULL));
int ar[3][4] = { 0, };
int rowSum[4] = { 0, };

for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 4; j++)
	{
		ar[i][j] = rand() % 10;
		printf("%d ",ar[i][j]);

		rowSum[i] += ar[i][j];
	}
	printf(" >> %d", rowSum[i]);
	printf("\n");
}*/
#pragma endregion