#pragma warning(disable : 4996)
#include <iostream>
#include <windows.h>
#include "time.h"
#include <list> // cpp 라이브러리
#include <algorithm>
using namespace std;

#pragma region 순차정렬
////참고하는 함수는 약속된 형식이 존재한다.
////정렬의 조건을 만들어 주는 함수
//int QuickSort1(const void* arg1, const void* arg2) {
//    int* p1 = (int*)arg1; // 주소전달, 값전달
//    int* p2 = (int*)arg2;
//
//    // (앞의 인수 - 뒤의 인수) 라는 표현을 사용하게 되면
//    // 순차 정렬을 하라는 것이다.
//    return *p1-*p2;
//}
//int QuickSort2(const void* arg1, const void* arg2) {
//    int* p1 = (int*)arg1; // 주소전달, 값전달
//    int* p2 = (int*)arg2;
//
//    // (앞의 인수 - 뒤의 인수) 라는 표현을 사용하게 되면
//    // 역순 정렬을 하라는 것이다.
//    return *p2-*p1;
//}
//int QuickSort3(const void* arg1, const void* arg2) {
//    int* p1 = (int*)arg1; // 주소전달, 값전달
//    int* p2 = (int*)arg2;
//
//    // (>)
//    // 순차 정렬을 하라는 것이다.
//    /*if (*p1 > *p2) {
//        return +1;
//    }
//    else 
//        return -1;*/
//    return (*p1 > *p2) ? +1 : -1;
//}
//int QuickSort4(const void* arg1, const void* arg2) {
//    int* p1 = (int*)arg1; // 주소전달, 값전달
//    int* p2 = (int*)arg2;
//
//    // (<)
//    // 역순 정렬을 하라는 것이다.
//    //if (*p1 < *p2) {
//    //    return +1;
//    //}
//    //else 
//    //    return -1;
//    return (*p1 < *p2) ? +1 : -1;
//}
//int main()
//{
//    int SortData[] = { 20, 25, 82, 48, 49, 29, 98, 77, 45, 32 };
//    for(int i = 0; i < 10; i++){
//        printf("%d ", SortData[i]);
//    }printf("\n");
//
//    // 정렬 옵션을 정의한 함수 이름.
//    qsort(SortData, 10, sizeof(int), QuickSort1); // quick Sort
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", SortData[i]);
//    }printf("\n");
//
//    qsort(SortData, 10, sizeof(int), QuickSort2); // quick Sort
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", SortData[i]);
//    }printf("\n");
//    
//    qsort(SortData, 10, sizeof(int), QuickSort3); // quick Sort
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", SortData[i]);
//    }printf("\n");
//    
//    qsort(SortData, 10, sizeof(int), QuickSort4); // quick Sort
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", SortData[i]);
//    }printf("\n");
//}
#pragma endregion
#pragma region 구조체 정렬
//struct STRU {
//    int  index;
//    int data[3];
//};
//
//int QuickSort4(const void* arg1, const void* arg2) {
//    STRU* p1 = (STRU*)arg1; // 주소전달, 값전달
//    STRU* p2 = (STRU*)arg2;
//
//    return (p1->index - p2->index);
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//    STRU DataInfo[6];
//    for (int i = 0; i < 6; i++)
//    {
//        DataInfo[i].index = rand() % 10;
//        for (int j = 0; j < 3; j++)
//        {
//            DataInfo[i].data[j] = rand() % 50 + 50;
//        }
//    }
//    //출력
//    for (int i = 0; i < 6; i++) {
//        printf("%d : ", DataInfo[i]);
//        for (int j = 0; j < 3; j++) {
//            printf("%d ", DataInfo[i].data[j]);
//        }printf("\n");
//    }printf("\n");
//
//    qsort(DataInfo, 6, sizeof(STRU), QuickSort4);
//
//    //출력
//    for (int i = 0; i < 6; i++) {
//        printf("%d : ", DataInfo[i]);
//        for (int j = 0; j < 3; j++) {
//            printf("%d ", DataInfo[i].data[j]);
//        }printf("\n");
//    }printf("\n");
//}
#pragma endregion
#pragma region 대소 관계를 물어야 하는 경우
//int main() {
//	srand((unsigned)time(NULL));
//	//정렬이 일어나는 경우
//	float data1[] = { 3.14f, 2.12f, 9.34f };
//	//정렬이 안일어나는 경우
//	//해결책 -> 대소관계를 활용해서 구해야한다.
//	float data2[] = { 0.14f, 0.12f, 0.34f };
//}

#pragma endregion
#pragma region 정렬 응용
//int QuickSort5(const void* arg1, const void* arg2) {
//    int* p1 = (int*)arg1;
//    int* p2 = (int*)arg2;
//
//    int arg1q = *p1 / 10;
//    int arg1r = *p1 / 10;
//    int arg2q = *p2 / 10;
//    int arg2r = *p2 / 10;
//    
//    int r1 = arg1q * arg1q + arg1r * arg1r;
//    int r2 = arg2q * arg2q + arg2r * arg2r;
//    
//    return r1 - r2;
//}
//
//int main()
//{
//    srand((unsigned)time(NULL));
//    int data[10];
//    
//    for (int i = 0; i < 10; i++)
//    {
//        data[i] = rand() % 100;
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d ", data[i]);
//    }printf("\n");
//
//    qsort(data, 10, sizeof(int), QuickSort5);
//
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d ", data[i]);
//    }printf("\n");
//}
#pragma endregion
#pragma region 야구게임(이효빈)
//typedef struct TeamInfo {
//	char name[10] = { 0, };
//	int winNum = 0;
//	int drawNum = 0;
//	int loseNum = 0;
//};
//
//int Asend(const void* arg1, const void* arg2) 
//{
//	TeamInfo* pTeamInfo1 = (TeamInfo*)arg1;
//	TeamInfo* pTeamInfo2 = (TeamInfo*)arg2;
//
//	float winningRate1 = ((float)pTeamInfo1->winNum + (float)pTeamInfo1->drawNum) / 40.0f;
//	float winningRate2 = ((float)pTeamInfo2->winNum + (float)pTeamInfo2->drawNum) / 40.0f;
//
//	if (winningRate1 >= winningRate2)	{
//		return +1;
//	}
//	else {
//		return -1;
//	}
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	const int teamCnt = 5;
//	int  numOfGamesPerTeam = 0;
//
//	TeamInfo baseBallTeam[teamCnt];
//	const char* teamName[teamCnt] = { "삼성", "엘지", "현대", "한화", "롯데" };
//
//	for (int i = 0; i < 5; i++)
//	{
//		strcpy(baseBallTeam[i].name, teamName[i]);
//		//printf("%s \n", baseBallTeam[i].name);
//	}
//
//	for (int gameCnt = 0; gameCnt < 10; gameCnt++)
//	{
//		for (int i = 0; i < teamCnt - 1; i++)
//		{
//			for (int j = i + 1; j < teamCnt; j++)
//			{
//				int probability = rand() % 100;
//
//				if (probability < 10) // 비긴다면
//				{
//					baseBallTeam[i].drawNum++;
//					baseBallTeam[j].drawNum++;
//				}
//				else
//				{
//					if (probability < 55) // 이긴다면
//					{
//						baseBallTeam[i].winNum++;
//						baseBallTeam[j].loseNum++;
//					}
//					else // 진다면
//					{
//						baseBallTeam[j].winNum++;
//						baseBallTeam[i].loseNum++;
//					}
//				}
//			}
//			numOfGamesPerTeam++;
//		}
//	}
//	
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%s %d %d %d %d\n",
//			baseBallTeam[i].name,
//			numOfGamesPerTeam,
//			baseBallTeam[i].winNum,
//			baseBallTeam[i].drawNum,
//			baseBallTeam[i].loseNum
//		);
//	}
//	qsort(baseBallTeam, teamCnt, sizeof(TeamInfo), Asend);
//	printf("\n오름차 정렬 후(승률 순) \n");
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%s %d %d %d %d\n",
//			baseBallTeam[i].name,
//			numOfGamesPerTeam,
//			baseBallTeam[i].winNum,
//			baseBallTeam[i].drawNum,
//			baseBallTeam[i].loseNum
//		);
//	}
//}
#pragma endregion

#pragma region LinkedList
//
//struct LL {
//	int x, y;
//	LL* next; // * right
//	LL* before; // * left
//};
//int main()
//{
//	LL h;
//	h.x = 10; h.y = 20;
//	h.next = new LL;
//
//	h.next->x = 30;
//	h.next->y = 40;
//	h.next->next = new LL;
//
//	h.next->next->x = 50;
//	h.next->next->y = 60;
//	h.next->next->next = NULL;
//}
#pragma endregion
#pragma region STL1
//void main() 
//{
//	list<int> li; // linkedList<컨테이너> 아주머니 이름 li.
//	printf("%d\n", li.size());
//
//	// Insert(create)
//	li.push_back(10);// 리스트 맨 뒤에 데이터 넣음
//	printf("%d\n", li.size());
//	li.push_back(20);
//	li.push_front(30);
//	printf("%d\n", li.size());
//
//	for (int i = 0; i < 10; i++)
//	{
//		li.push_back(i * 10 + 40);
//	}
//
//	// Read( Select )
//	list<int>::iterator it;//집게의 이름
//	list<int>::iterator beginIt = li.begin();
//	list<int>::iterator endIt = li.end();
//	//	it = li.begin(); // it가 시작점을 알게됨(가르키고 있음)
//	//	++연산자는 연산자 재정의가 되어있다.
//	//	it++은 내부적으로 코드의 속도가 약 10배 느리다.
//	for (it = beginIt; it != endIt; ++it) // 처음부터 시작해서 끝이 아닐 때까지 계속 돌아라
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//	printf("%s \n", li.empty() ? "Empty" : "Not Empty");
//
//	// 모두 삭제( delete, clear, remove, erase)
//	//li.clear();
//	//printf("%s \n", li.empty() ? "Empty" : "Not Empty");
//	
//	// 1개의 데이터를 검색하여 삭제한다.
//	for (it = beginIt; it != endIt; ++it) 
//	{
//		if (*it == 60) {
//			li.erase(it); // remove
//			break;
//		}
//	} printf("\n");
//	for (it = beginIt; it != endIt; ++it) 
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//
//	// 3의 배수만 모두 삭제..
//	for (it = li.begin(); it != li.end(); )
//	{
//		if (*it % 3 == 0) {
//			// 삭제 함수 사용시에 it는 지시 위치를 잃어 버린다.
//			//li.erase(it);
//			it = li.erase(it);
//		}
//		else {
//			++it;
//		}
//	} printf("\n");
//
//
//	endIt = li.end();
//	for (it = li.begin(); it != endIt; ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//}
#pragma endregion
#pragma region STL2(3항 연산자 활용, remove)
//bool f1(long a) {
//	// 제거 시키고 싶은 조건에서는 true를 걸어주고 반대는 false
//	/*if (a >= 50 && a <= 110) {
//		return true;
//	}
//	else
//		return false;*/
//
//	return (a >= 50 && a <= 110) ? true : false;
//}
//bool f2(long a, long b)
//{
//	//int s1 = 변형;
//	//int s2 = 변형;
//	//return s1 < s2;
//	return a < b; //순차 정렬, 반대의 경우 역순 정렬
//}
//
//void main()
//{
//	//std::list<int> li;
//	list<int> li; 
//	printf("%d\n", li.size());
//
//	// Insert(create)
//	li.push_back(10);
//	printf("%d\n", li.size());
//	li.push_back(20);
//	li.push_front(30);
//	printf("%d\n", li.size());
//
//	for (int i = 0; i < 10; i++)
//	{
//		li.push_back(i * 10 + 40);
//	}
//
//	// Read( Select )
//	list<int>::iterator it;
//	list<int>::iterator beginIt = li.begin();
//	list<int>::iterator endIt = li.end();
//	
//	for (it = beginIt; it != endIt; ++it) 
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//	printf("%s \n", li.empty() ? "Empty" : "Not Empty");
//
//	for (it = beginIt; it != endIt; ++it)
//	{
//		if (*it == 60) {
//			li.erase(it);
//			break;
//		}
//	} printf("\n");
//	for (it = beginIt; it != endIt; ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//
//	// 3의 배수만 모두 삭제..(3항 연산 버젼)
//	for (it = li.begin(); it != li.end(); )
//	{
//		it = (*it % 3 == 0) ? li.erase(it) : ++it;
//	} printf("\n");
//
//
//	endIt = li.end();
//	for (it = li.begin(); it != endIt; ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//	// remove 사용
//	li.remove(70); // 중복된 70 모두를 제거하는 코드
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//	//1. 특정 데이타 제거 2. 짝수만 제거 3. 범위 설정하고 제거
//	li.remove_if(f1); // 제거될 수 있는 조건을 함수 내에서 걸어주어 제거할 수 있다.
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//	
//	for (int i = 0; i < 10; i++)
//	{
//		li.push_back(rand() % 100);
//	}
//
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//	li.sort(f2); // (data, 10, 4, f2) li는 data, 갯수, 사이즈 모두 알고 있음
//
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//	//----------------------------------
//	printf("%d %d \n", li.front(), li.back());
//
//	//----------------------------------
//	//find는 있는지 없는지 판별할 때 주로 쓰인다.
//	printf(li.end() != (it = find(li.begin(), li.end(), 40)) ? "find\n": "not find\n");
//		
//}
//
////-------------템플릿 문법
////void f1(T a, T b) {// 템플릿을 사용하면 모든 코드를 사용 할 수 있다.
////	t = a;
////	a = b;
////	b = t;
////}
////f1(3, 4);
////f1(3.0, 4.0);
#pragma endregion
#pragma region STL3
// 추가, 삭제, 갱신, 검색, 정렬
struct STRU {
	int id;
	int x, y, z;
};
void main()
{
	list<STRU> user;
	list<STRU>::iterator uIT;
	// Create
	for (size_t i = 0; i < 10; i++)
	{
		STRU t;
		t.id = i * 10;
		t.x = i * 3 + 0;
		t.y = i * 3 + 1;
		t.z = i * 3 + 2;
		user.push_back(t);
	}
	// Read
	for (uIT = user.begin(); uIT != user.end(); ++uIT){
		printf("%d %d %d %d \n", uIT->id, uIT->x,uIT->y, uIT->z);
	}printf("\n");
	
	// id 60번인 데이터 제거
	// remove 사용
	for (uIT = user.begin(); uIT != user.end(); ++uIT)
	{
		if (uIT->id == 60)
		{
			user.erase(uIT);
			break;
		}
	} printf("\n");

	for (uIT = user.begin(); uIT != user.end(); ++uIT) {
		printf("%d %d %d %d \n", uIT->id, uIT->x, uIT->y, uIT->z);
	}printf("\n");
}
#pragma endregion



