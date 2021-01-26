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
//	출력코드
//	endIt = li.end();
//	for (it = li.begin(); it != endIt; ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
// 3의 배수만 모두 삭제..(3항 연산 버젼)
//	for (it = li.begin(); it != li.end(); )
//	{
//		it = (*it % 3 == 0) ? li.erase(it) : ++it;
//	} printf("\n");
//	
//	// 출력코드
//	for (it = li.begin(); it != li.end(); ++it)
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
//	list<int> li;
//	list<int>::iterator it;
//	for (int i = 0; i < 10; i++)
//	{
//		li.push_back(i * 10 + 40);
//	}
//	li.push_back(70);
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//	li.remove(70); // 중복된 70 모두를 제거하는 코드
//
//	for (it = li.begin(); it != li.end(); ++it)
//	{
//		printf("%d ", *it);
//	} printf("\n");
//
//	//1. 특정 데이타 제거 2. 짝수만 제거 3. 범위 설정하고 제거
//	//remove_if()를 사용한다면 메모리 해제는 옵션 설정 함수 안에서 하는 것이 맞음
//	li.remove_if(f1); // 제거될 수 있는 조건을 함수 내에서 걸어주어 제거할 수 있다.
//
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
#pragma region STL3(구조체 타입을 활용)

// 추가, 삭제, 갱신, 검색, 정렬
struct STRU {
	int id;
	int x, y, z;
};

bool f3(STRU a)
{
	// 제거 시키고 싶은 조건에서는 true를 걸어주고 반대는 false
	return (a.id % 3 == 0) ? true : false;
}
bool f4(STRU a, STRU b)
{
	return a.id > b.id; // 역순 정렬
}
bool f5(STRU a) {
	return a.id == 20;
}

bool f6(STRU* a, STRU* b)
{
	return a->id > b->id; // 역순 정렬
}

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
			uIT = user.erase(uIT);
			break;
		}
	} printf("\n");
	
	for (uIT = user.begin(); uIT != user.end(); ++uIT) {
		printf("%d %d %d %d \n", uIT->id, uIT->x, uIT->y, uIT->z);
	}printf("\n");
	
	// id가 3의 배수인 데이터 제거(remove_if 사용)
	user.remove_if(f3);
	
	for (uIT = user.begin(); uIT != user.end(); ++uIT) {
		printf("%d %d %d %d \n", uIT->id, uIT->x, uIT->y, uIT->z);
	}printf("\n");
	
	// id에 대해서 역순 정렬
	user.sort(f4);
	for (uIT = user.begin(); uIT != user.end(); ++uIT) {
		printf("%d %d %d %d \n", uIT->id, uIT->x, uIT->y, uIT->z);
	}printf("\n");
	
	// id가 20가 있는지 확인하고 싶음
	uIT = find_if(user.begin(), user.end(), f5);
	if (uIT != user.end()) {
		printf("find\n");
	}
	else {
		printf("not find\n");
	}
	// 위에 방법은 메모리 측면에서 손해가 크기 때문에 사용 안함
	//----------------------------------------------------
	printf("\n\n");
	list<STRU*> pUser;
	list<STRU*>::iterator puIt;

	// Create
	for (size_t i = 0; i < 10; i++)
	{
		STRU* t = new STRU;
		t->id = i * 10;
		t->x = i * 3 + 0;
		t->y = i * 3 + 1;
		t->z = i * 3 + 2;
		pUser.push_back(t); // 이제는 주소(4byte) 가 넘어감
	}

	// Read
	for (puIt = pUser.begin(); puIt != pUser.end(); ++puIt) {
		printf("%d %d %d %d \n", 
			(*puIt)->id, //puIT는 주소의 주소
			(*puIt)->x,(*puIt)->y,(*puIt)->z
		);
	}printf("\n");

	// id 20인 데이터 삭제
	for (puIt = pUser.begin(); puIt != pUser.end(); ++puIt) {
		if ((*puIt)->id == 20) {
			// 아주머니는 주소만 관리하지 메모리는 별도로 해제 시켜주어야 한다.
			delete(*puIt); //leak 요소 제거
			pUser.erase(puIt); // 주소만 제거
			// clear(); // 메모리 모두 제거하고 함수 사용
			break;
		}
	}

	// 역순 정렬 (id를 기준으로 역순)
	pUser.sort(f6);
	for (puIt = pUser.begin(); puIt != pUser.end(); ++puIt) {
		printf("%d %d %d %d \n", (*puIt)->id, (*puIt)->x, (*puIt)->y, (*puIt)->z);
	}printf("\n");
}
#pragma endregion
#pragma region STL4(구조체 갱신)
//bool f1(int data) {
//	return data == 200;
//}
//void update(list<int> &li, int pos, int newValue) {
//	list<int>::iterator it;
//	it = li.begin();
//	for (int i = 0; i < pos; i++){
//		++it;
//	}
//	*it = newValue;
//}
//int main() {
//	list<int> li;
//	list<int>::iterator it;
//	li.push_back(10);
//	li.push_back(20);
//	li.push_back(30);
//
//	//------------
//	// 삽입 방법1
//	it = li.begin();
//	++it;
//	*it = 100;
//	for (it = li.begin(); it != li.end(); ++it) {
//		printf("%d ", *it);
//	}printf("\n");
//
//	// 삽입 방법2
//	replace(li.begin(), li.end(), 100, 200);// 시작, 끝, 바꿀 예정 데이터, 바꾸는 데이터
//	for (it = li.begin(); it != li.end(); ++it) {
//		printf("%d ", *it);
//	}printf("\n");
//
//	// 삽입 방법3
//	replace_if(li.begin(), li.end(), f1, 300);// 조건에 만족하면 300으로 바꿔라
//	for (it = li.begin(); it != li.end(); ++it) {
//		printf("%d ", *it);
//	}printf("\n");
//
//	// 함수 별도로 만들어 볼 것(2번째 데이터 400으로 바꾸시오)
//	// 0  1  2
//	//10 20 30
//	update( li, 1, 400);
//	for (it = li.begin(); it != li.end(); ++it) {
//		printf("%d ", *it);
//	}printf("\n");
//}
#pragma endregion
#pragma region (별 die or live)문제 이효빈 솔루션
//struct STAR {
//	int id;
//	int age;
//};
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	list<STAR> user;
//	list<STAR>::iterator uIT;
//
//	int index = 10;
//
//	
//	for (size_t i = 0; i < 10; i++)
//	{
//		STAR star;
//		star.id = i;
//		star.age = 0;
//		user.push_back(star);
//	}
//
//	for (uIT = user.begin(); uIT != user.end(); ++uIT) {
//		printf("%02d ", uIT->id);
//	}printf("\n");
//
//	for (uIT = user.begin(); uIT != user.end(); ++uIT) {
//		printf("%2d ", uIT->age);
//	}printf("\n");
//
//	int inputData = 0;
//	int randomValue;
//	int removeCnt = 0;
//	do {
//		removeCnt = 0;
//
//		for (uIT = user.begin(); uIT != user.end();) {
//			randomValue = rand() % 100;
//			if (randomValue < 50)
//			{
//				removeCnt++;
//
//				uIT = user.erase(uIT);
//			}
//			else 
//			{
//				++(uIT->age);
//				++uIT;
//			}
//		}
//
//		for (size_t i = 0; i < removeCnt; i++)
//		{
//			STAR star;
//			star.id = index++;
//			star.age = 0;
//
//			user.push_back(star);
//		}
//		
//		for (uIT = user.begin(); uIT != user.end(); ++uIT) {
//			printf("%02d ", uIT->id);
//		}printf("\n");
//		for (uIT = user.begin(); uIT != user.end(); ++uIT) {
//			printf("%2d ", uIT->age);
//		}printf("\n");
//
//		scanf("%d", &inputData);
//	} while (inputData != 99 );
//}
#pragma endregion
#pragma region (별 die or live)문제 강사님 솔루션
//struct STAR {
//	int id;
//	int age;
//};
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	list<STAR*> star;
//	list<STAR*>::iterator it;
//
//	while (true)
//	{
//		//갱신( 죽고 사는 )
//		for (it = star.begin(); it != star.end();) {
//			if (rand() % 2) {// 죽었을 때
//				delete(*it);
//				it = star.erase(it);
//			}
//			else {//살았을 때
//				(*it)->age++;
//				++it;
//			}
//		}
//		
//		// 데이터 생성
//		while (star.size() < 10) {
//			STAR* t = new STAR;
//			static int id = 0;
//			t->id = id++;
//			t->age = 0;
//			star.push_back(t);
//		}
//
//		//출력코드
//		for (it = star.begin(); it != star.end(); ++it) {
//			printf("%02d ", (*it)->id);
//		}printf("\n");
//		for (it = star.begin(); it != star.end(); ++it) {
//			printf("%02d ", (*it)->age);
//		}printf("\n");
//
//
//		int num;
//		scanf_s("%d", &num);
//		if (num == 99) {
//			printf("Exit\n");
//			break;
//		}
//	}
//
//	// 마무리 된 코드
//	printf("1:%02d\n", star.size());
//	for (it = star.begin(); it != star.end(); ++it) 
//	{
//			delete (*it);
//	}
//	printf("2:%02d\n", star.size());// 주소만 가지고 있고 메모리 할당은 안되어 있다
//	star.clear();// 메모리 할당이 안되어 있는 값들을 0으로 초기화한다.
//	printf("3:%02d\n", star.size());
//}
	
#pragma endregion




