
#include <iostream>
using namespace std;



#pragma region 21_01_12(ex3)
#pragma region ex4
	
#pragma endregion
#pragma region ex3
////ex3) 인수전달에 초기값을 설정할 수 있다.
//// 1. 코드는 보는 문법(보는 문법) <-> 2. 짜는 문법
//
//// c++ 문법 : 참조를 받을 수도 있다.
//// 포인터와 동일하게 공유가 일어난다.
//void f3(int& a, int& b) // call by reference
//{
//	int t;
//	printf("%d %d\n", a, b);
//	t = a;
//	a = b;
//	b = t;
//	printf("%d %d\n", a, b);
//}
//int f4(int* const a,int* const b) { // 참조가 생긴원인
//	if (a == NULL || b == NULL) {
//		 return; // 방어적인 프로그램
//	}
//	int t;
//	t = *a;
//	*a = *b;
//	*b = t;
//}
//int f5(int& a, int& b) 
//{ 
//	// 참조가 생긴원인
//	//처음부터 공유된 것이 오기 때문에 방어적인 프로그램이 빠로 필요없음
//	//(애초부터 NULL을 초기값으로 못받음)
//	// 받은 이후에 다른 메모리와 공유할 일도 없음
//	// 메모리 할당 불가 <= 애초부터 공유받기 위해 만들어짐
//	int t;
//	t = a;
//	a = b;
//	b = t;
//	
//}
//
//int main()
//{
//	int x = 10, y = 20;
//	//
//	//f3(x, y);
//	//
//	//int aa = 10;
//	//int xx = aa;
//	//int& yy = aa; // 공유(참조)
//	//int* yy = &aa; // 공유(포인터)
//	//// 참조는 공유를 단 1번만 받을 수 있다.
//	//
//	////int& tt; // 불가능
//	//int& tt = aa; // (o)
//	//int tt = aa; // 더이상 공유가 불가능
//	//
//	////포인터는 여러번 공유가 가능하다.
//	//int* ss;
//	//ss = &aa;
//	////ss <<<< 주소를 받을 수 있다. (공유 할당)
//	
//	f4(NULL, NULL); 
//	// 함수 사용할 때 인수 전달로 NULL을 사용할 수 없도록 하기 위해서 참조형 사용해야한다.
//
//}
#pragma endregion
#pragma region ex6(구조체와 클래스)
// ex6) 구조체 >> 버전업이 되어서 >> 클래스
struct STRU { // default가 public
	int a, b;
};
class Tiger { // default가 private + 함수 있다.
private:	
	int a, b;
	void f1() {

	}
};

int main() {
	STRU s = { 10,20 };

	Tiger* t = new Tiger();
}
#pragma endregion


#pragma endregion



