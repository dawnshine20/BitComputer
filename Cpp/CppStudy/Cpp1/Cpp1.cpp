#include <iostream>
using namespace std;

#pragma region 21_01_12

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
//// ex6) 구조체 >> 버전업이 되어서 >> 클래스
//struct STRU { // default가 public
//	int a, b;
//};
//class Tiger { // default가 private + 함수 있다.
//private:	
//	int a, b;
//	void f1() {
//
//	}
//};
//
//int main() {
//	STRU s = { 10,20 };
//
//	Tiger* t = new Tiger();
//}
#pragma endregion
#pragma region ex7(21_01_13)
//struct STRU {
//	
//};
//
//class Apple {
//	// 멤버 변수
//	// 클래스의 속성을 가지고 있다.
//	// field
//private:
//
//public:
//
//public:
//	int a, b;
//	int color, weight, calories, Price; 
//
//	// 멤버 함수
//	// Tiger 클래스의 동작(행위)를 가지고 있다.
//	// method
//	void Cook() { 
//		//need fuel
//	}
//	void Throw() { 
//		//need runTime
//	}
//	void Sell() { 
//		//need runTime
//	}
//	void f1() // function
//	{
//		printf("f1");
//	}
//};
//
//
////OOP (Object Oriented Programming)
//int main()
//{
//	//STRU s;		// s라는 변수를 선언한다. <- 값, 주소 등등
//	// a는 인스턴스(객체)
//	Apple app;	// a라는 객체를 생성한다. <- 속성 + 동작
//	app.a = 10;
//	app.f1();
//}
#pragma endregion
#pragma region ex8(생성자)
// 생성자 함수 != 소멸자 함수
//class Apple {
//public:
//	// 1. 클래스 이름과 동일한 함수명이여야 한다.
//	// 2. 리턴타입이 없다.
//	// 3. 임의로 호출할 수 없고 객체가 생성될 때 자동 1회 호출
//	// 4. Apple cpp(); // () >> 넣으면 안된다.
//	// 5. 생성자 함수도 함수이므로 함수 재정의가 가능하다.
//	// 6. 사용 목적 : 멤버 변수 초기화.
//	Apple() {
//		printf("2\n");
//	}
//	Apple(int a) {
//		printf("6\n");
//	}
//	Apple(int a, int b) {
//		printf("7\n");
//	}
//
//};
//int main()
//{
//	//printf("1\n");
//	//Apple app; // << 여기가 객체가 생성되는 시점이다.
//	//printf("3\n");
//	//Apple bpp; 
//	//printf("5\n");
//	//Apple bpp();// () <= 함수 호출 및 선언 연산자이기 때문에 오해하지 말 것
//	////void f1(int a, int b); // 함수 원형 선언
//	Apple a;// () <= 함수 호출 및 선언 연산자이기 때문에 오해하지 말 것
//	Apple b(10);// () <= 함수 호출 및 선언 연산자이기 때문에 오해하지 말 것
//	Apple c(10, 20);// () <= 함수 호출 및 선언 연산자이기 때문에 오해하지 말 것
//}
#pragma endregion
#pragma region ex8-1
//class Apple { // 멤버변수 초기화 -> 생성자 초기화
//	//생성자에서 변수 초기화하는 것을 원칙으로 정하자
//	int price;
//	int b;
//
//public:
//	Apple() {
//		price = 1000;
//		b = 20;
//	}
//
//	void f1(int x, int y) {
//		printf("%d %d\n", price, b);
//	}
//};
//int main()
//{
//	Apple app;
//	app.f1(10 ,20);
//}
#pragma endregion
#pragma region ex8-2
////8. 생성자를 작성하지 않으면 (자동으로) 디폴트 생성자가 만들어진다.
//// 중요 : (무조껀 (수동으로) 디폴트 생성자를 만들어 놓아야함_안쓰더라도 만들어 놓을 것
//// 이유 : 생성자가 1개라도 생겨버리면 (자동으로) 디폴트 생성자가 만들어지지 않는 현상이 생김
//class Apple {
//	int x, y;
//	
//public:
//	Apple() {}
//	
//
//	//중요 : 내부적으로 Apple* this는 자동으로 항상 만들어버림
//	//(메모리가 항상 구조체에 비해 많이 소모됨)
//	Apple(int a, int b) 
//	{
//		x = a; // 멤버변수 == 인수 값;
//		y = b;
//		printf("%p\n", this);
//	}
//
//	void show() {
//		printf("%d %d\n", x, y);
//	}
//};
//
//int main()
//{
//	Apple app(0,0);
//	printf("%p\n", &app);
//	app.show();
//}
#pragma endregion
#pragma region ex8-3(this)
//아래 코드는 개인이 만들지 않아도 클래스가 만들어지면 스스로 만들어지는 코드임
//class Apple {
//public:
//	Apple() {} // 1번
//	Apple* this; // 2번
//	this = &app; // 4번
//}

////this가 사용되는 용도(겹치는 이름 분리)
//class Apple { // 만드는 사람이 따로 있다.
//public:
//	int a, b;
//	Apple(int a, int b) {
//		this->a = a;//(this는 우리가 따로 선언하지 않아도 컴파일 시 알아서 변환해 준다.)
//		this->b = b;
//	} 
//	// 만드는 사람이 따로 있다.
//	void show()
//	{
//		printf("%d %d\n", a, this->b);
//	}
//};
//
//int main() {
//	Apple app(10,20); // 사용하는 사람이 따로 있다.
//	app.show();
//}
#pragma endregion
#pragma region ex8-4(생성자 정석화 된 코드(틀))
//class Apple {
//public:
//	int price, weight, height;
//	Apple() {}
//	Apple(int price, int weight) {
//		this->price = price;
//		this->weight = weight;
//	}
//};
//int main()
//{
//
//}
#pragma endregion
#pragma region ex8-5(this 2번째 용법)
//class CBanana {
//public:
//	CBanana() {}
//};
//
//class CApple {
//public:
//	CApple() {}
//
//	void f1(
//		int a, int* b, int& c,
//		CBanana d, CBanana* e, CBanana&  f
//	){}
//	int f2() { int a = 10; return a; }
//	int* f3() { return NULL; }
//	int& f4() { int a = 10; return a; }
//
//	CBanana f5() { CBanana a; return a; }
//	CBanana* f6() { return NULL; }
//	CBanana& f7() { CBanana a; return a; }
//	// 비일비재하게 보게 되는 코드
//	CBanana* f8(int a, int* b, int& c,
//		CBanana d, CBanana* e, CBanana& f)
//	{
//		return NULL;
//	}
//};
//int main()
//{
//	CApple app;
//	CBanana bpp;
//	int d = 0;
//	app.f1(10,new int,d, bpp, &bpp, bpp);
//}
#pragma endregion
#pragma region ex8-6(클래스 체이닝 방법)
//class CApple {
//public:
//	CApple() {}
//
//	int aa = 10, bb =20;
//
//	CApple f1() {
//		CApple a;
//		return a;
//	}
//	CApple* f2() {
//		CApple a;
//		return &a;
//	}
//	CApple* f3() {
//		printf("f3\n");
//		return this; // this는 CApple타입---->(*this 값이 리턴됨)
//	}
//
//	void f4() {
//		printf("f4\n");
//	}
//
//	CApple& f5() {
//		printf("f5\n");
//		return *this; 
//	}
//};
//
//int main()
//{
//	CApple app;
//	app.f3(); // 안받으면 사라진다.
//
//	CApple* bpp = app.f3();
//	printf("%d %d\n", bpp->aa, bpp->bb);
//	bpp->f4();
//
//	app.f3()->f4(); //이 코드가 핵심이다. (함수를 체이닝 하는 용도로 사용)
//	app.f3()->f3()->f3()->f3()->f4();// 체이닝 예시
//	
//	app.f5().f3()->f3()->f5(); // .형태의 체이닝 방법도 존재(가장 흔하게 사용되는 방법)
//}
#pragma endregion
#pragma region ex8-7(this 3번째 용법)
//class CApple;
//class CBanana;
//
//class CApple {
//public:
//	CApple() {}
//	void f2(CBanana* bb) {
//		bb->f2(); // 3
//	}
//};
//class CBanana {
//public:
//	CBanana() {}
//	void f1() {
//		printf("f1\n");
//		CApple app;
//		app.f2(this);//2
//	}
//	void f2() {
//		printf("f2\n");
//	}
//};
//
//int main() {
//	CBanana bpp;
//	bpp.f1(); // 1
//	//파일 분리를 하면 되는 문법이나 하나의 파일 안에서 사용하려고 하기 때문에 사용이 안됨
//}
#pragma endregion
#pragma region 파일분리
//// 클래스 이름이 CApple이면
//// 파일명은 apple.cpp, apple.h
////-----------------------------------------------
//// .h로 들어간다.
////class CApple {
////public:
////	CApple() {
////		printf("Init\n");
////	}
////	void f1();
////	void f2();
////};
////.cpp로 들어간다.
////void CApple::f1() { // 전역함수 f1인데...
////	printf("f1\n");
////}
////void CApple::f2() { // 전역함수 f1인데...
////	printf("f2\n");
////}
//
////-----------------------------------------------
//#include "apple.h"
//#include "banana.h"
//
//int main()
//{
//	CApple app;
//	app.f1();
//	app.f2();
//
//	CBanana bpp;
//	bpp.f1();
//	bpp.f2();
//
//}
#pragma endregion
#pragma region ifdef 프리프로세서
//#define _NETWORK //<---------- 주석 사용시 서버코드는 사용하지 않음을 알려줄 수 있다.
//int main()
//{
//	// 클라이언트 코드(UI)............
//#ifdef _NETWORK
//	// 서버코드(통신 프로그램)
//#endif 
//
//	// 클라이언트 코드
//#ifdef _NETWORK
//	// 서버코드(통신 프로그램)
//#endif 
//
//	// 클라이언트 코드
//#ifdef _NETWORK
//// 서버코드(통신 프로그램)
//#endif 
//}
#pragma endregion
#pragma region ex)9.h/.cpp 분리 솔루션
//#include "banana.h"
//
//int main() {
//	CBanana bnn;
//	bnn.f1(); // 1
//	//파일 분리를 하면 되는 문법이나 하나의 파일 안에서 사용하려고 하기 때문에 사용이 안됨
//}
#pragma endregion
#pragma region ex10.소멸자
//class CTest {
//public:
//	int* p = NULL;
//
//	CTest() {
//		if(p == NULL)
//			p = new int[10];
//	}
//
//	//객체가 사라질 때 소멸자가 자동 호출된다.
//	~CTest() {
//		//메모리 해제하는 용도로 주로 사용된다.
//		if (p != NULL)
//			delete[] p;
//		
//		
//	}
//	void f1() {
//		if (p == NULL) { // delete 된 포인터를 다시 한번 delete 하지 못하도록 방어
//			return;
//		}
//		
//		p[0] = 10;
//		printf("%d\n", p[0]);
//		delete[] p; //delete가 두번 나오면 프로그램이 죽어버리는 프로그램이 된다
//		p = NULL;
//		
//		
//	}
//};
//int main()
//{
//	////CTest t1;
//	////printf("1\n");
//	////CTest* t2; 
//	////printf("2\n");
//	////t2 = new CTest; // 생성자 나타나는 시점
//	////
//	////delete t2; // 포인터 소멸자 콜
//	//{
//	//	CTest* t2 = new CTest; // scope내에서 delete 사용하지 않을 경우 메모리 누수 발생
//	//}
//
//	CTest t1;
//	t1.f1();
//
//}// 일반 변수 소멸자 콜
#pragma endregion
#pragma region 10-1 소멸자 2.
//class CTest {
//	int* p = NULL;
//	CTest() {
//		if (p == NULL)
//			p = new int[10];
//	}
//
//	// 100% 소멸자는 무조껀 virtual 붙여야 한다.
//	virtual ~CTest() {
//
//	}
//};
//
//int main()
//{
//	
//}
#pragma endregion
#pragma region 11.getter, setter 사용
//class CTest {
//private:
//	// 멤버 변수는 99% private 안에 넣어야 한다.
//	// 데이터 은닉
//	int width, height;
//public:
//	CTest() {
//		width = 10;
//		height = 20;
//	}
//	// User에게 필요한 속성인 경우 setter, getter로 제공해 준다.
//	// 어째서 public으로 제공 안하는가??? <---- set만 제공할 수도 있고, get만 제공할 수 도있기 때문에
//	// setter,getter를 사용해서 사용자에게 제공하는 것이 맞는 경우
//	void SetWidth(int width){// Setter 함수
//		this->width = width;
//	}
//	void SetHeight(int height){// Setter 함수
//		this->height = height;
//	}
//	int GetWidth(){// Getter 함수
//		return width;
//	}
//	int GetHeight(){// Getter 함수
//		return height;
//	}
//};
//
//int main()
//{
//	CTest t;
//	t.SetWidth(100);
//	printf("%d\n", t.GetWidth());
//	printf("%d\n", t.GetHeight());
//	
//}
#pragma endregion
#pragma region 12.클래스 체이닝 응용
//class CTest {
//public:
//	CTest& eat() {
//		printf("1\n");
//		return *this;
//	}
//	CTest& drink() {
//		printf("2\n");
//		return *this;
//	}
//	CTest& make() {
//		printf("3\n");
//		return *this;
//	}
//};
//int main()
//{
//	CTest t;
//	t.eat().eat().drink().make();
//}
#pragma endregion
#pragma region 13.friend 함수
//class CBanana;
//class CApple {
//	int data = 30;
//public:
//	//int getData() { return data; }
//	// friend 키워드가 있으면 밖에서 원형에 관련된 함수를 찾아 낸다.
//	// friend는 정확하게 클래스 소속은 아니지만 클래스 내부 데이터를 사용할 수 있다.
//	// 예) 홍길동 - 자식은 아니지만 밥도 먹고 잠도자고 집에 있는 것들 사용 가능
//	friend void com(CApple& app, CBanana& bpp);
//};
//class CBanana {
//	int data = 20;
//public:
//	friend void com(CApple& app, CBanana& bpp);
//};
//
////friend보다 setter, getter 사용하는 것이 더 유리함 friend는 setter,getter 개념이 약했을때 사용되었었음
////클래스 소속인 경우 선언 차이 void CApple::com
//void com(CApple& app, CBanana& bpp) {
//	if (app.data > bpp.data) {
//		printf("1\n");
//	}
//}
//int main() {
//	CApple a; 
//	CBanana b;
//	com(a, b);
//}
#pragma endregion
#pragma region 14.복사생성자

//class CTest { // code를 비워 놓으면 컴파일러가 자동으로 만들어주는 내용
//	// 1. private:
//	// 2. 디폴트 생성자
//	// 3. 복사 생성자(내가 만들면 컴파일러가 안 만든다.)
//	// 4. CTest* this;
//};
//
//class CTiger {
//private:
//	int a = 10, b = 20;
////복사 생성자는 안만들면 자동으로 만들어 진다.
//public:
//	CTiger() { // default 생성자
//		printf("생성자 콜\n");
//	};
//	// 복사 생성자를 내가 만들 것이다.
//	CTiger(CTiger& temp) { //<---컴파일러 내부에서 printf를 제외하고 복사생성자 (자동) 만들어줌
//		//printf("복사 생성자 콜\n"); 
//	}
//	~CTiger() {
//		printf("소멸자 콜\n");
//	};
//	void show() {
//		printf("%d %d\n", this->a, this->b);
//	}
//};
//
//int main()
//{
//	CTiger t1;
//	t1.show();
//	CTiger t2 = t1; // << 문제의 코드
//	t2.show();
//}
#pragma endregion
#pragma region 14.복사생성자-2
//class CTest { // code를 비워 놓으면 컴파일러가 자동으로 만들어주는 내용
//	// 1. private:
//	// 2. 디폴트 생성자
//	// 3. 복사 생성자(내가 만들면 컴파일러가 안 만든다.)
//	// 4. CTest* this;
//};
//
//class CTiger {
//private:
//	int a, b;
//	//복사 생성자는 안만들면 자동으로 만들어 진다.
//public:
//	CTiger() { // default 생성자
//		a = 10;
//		b = 20;
//		printf("생성자 콜\n");
//	};
//	// 복사 생성자를 내가 만들 것이다.(내가 책임지고 변수 값도 넣어주어야 한다.)
//	CTiger(CTiger& temp) { 
//		a = 10;
//		b = 20;
//		printf("복사 생성자 콜\n"); 
//	}
//	void show() {
//		printf("%d %d\n", this->a, this->b);
//	}
//};
//
//int main()
//{
//	CTiger t1;
//	t1.show();
//	CTiger t2 = t1; // << 문제의 코드
//	t2.show();
//}
#pragma endregion
#pragma region 14.복사생성자-3(deep copy)
//class CTiger {
//private:
//	int a, b;
//	int* p;
//public:
//	CTiger() { // default 생성자
//		a = 10;	b = 20;
//		p = new int;
//		*p = 30;
//	};
//	
//	// 컴파일러가 해주는 복사 형태
//	//CTiger(CTiger& t) {
//	//	a = t.a;
//	//	b = t.b;
//	//	p = t.p;// 공유가 일어남(shallow copy) <--- 문제가 되는 부분
//	//}
//
//	// 내가 직접 해주는 복사형태(깊은 복사 형태로 만들어줘야한다)
//	CTiger(CTiger& t) {
//		a = t.a;
//		b = t.b;
//		p = new int;// (deep copy) 
//		*p = 30; // 직접 넣어서 제어해주어야한다.
//	}
//
//	void show() {
//		printf("%d %d\n", *this->p, p);
//	}
//	~CTiger() {
//		delete p; // < 공유된 메모리를 해제하기 떄문에 2번 해제, 때문에 프로그램이 죽어버림
//	}
//};
//
//int main()
//{
//	CTiger t1;
//	CTiger t2 = t1;
//	t1.show();
//	t2.show();
//
//}
#pragma endregion
#pragma region 15.static 변수
//class CTiger {
//public:
//	int a;
//	//컴파일 후에 전역화 된다.
//	static int b; // 스테틱 변수는 반드시 값을 초기화 해야 한다.
//
//	static void f1() {
//		
//	}
//};
//int CTiger::b = 100; // static변수는 클래스 외부에서 초기화 가능하다.
//
////void f1() {
////	int a = 0;
////	// 다른 함수에서 접근을 불가하도록 만들면서 전역으로 사용하기 위해 static 키워드를 사용한다.
////	static int b = 0; // 컴파일 되고 나면 전역변수로 올라감
////	a++;
////	b++;
////	printf("%d %d\n", a, b);
////}
//
//int main()
//{
//	//객체를 생성시키지 않고도 바로 사용할 수 있다.
//	printf("%d\n", CTiger::b);
//	CTiger::b++;
//	printf("%d\n", CTiger::b);
//
//	CTiger t1;
//	printf("%d\n", t1.b);
//	t1.b++;
//// 모든 생성되는 객체의 공용 변수 == static 변수
//	CTiger t2;
//	printf("%d\n", t2.b);
//}
#pragma endregion
#pragma region 15.static 변수-2
//class CTiger {
//public:
//	int a;
//	//컴파일 후에 전역화 된다.
//	static int b; // 스테틱 변수는 반드시 값을 초기화 해야 한다.
//
//	CTiger() {
//		b++;
//	}
//	~CTiger() {
//		b--;
//	}
//	static void f1() {
//
//	}
//};
//int CTiger::b = 0; // static변수는 클래스 외부에서 초기화 가능하다.
////↓↓↓↓ static 변수 초기화 잘못 사용하는 예
////CTiger::b = 0;
////int b = 0;
//
//int main()
//{
//	// 메모리 누수 여부를 생성자와 소멸자 갯수로 판단이 가능하다.
//	{
//		CTiger t1, t2, t3;
//		CTiger* t4 = new CTiger;
//		printf("%d\n", CTiger::b);
//
//		delete t4;
//	}
//	printf("%d\n", CTiger::b);
//}
//
#pragma endregion
#pragma region 16.static 함수
//class CTiger {
//	int a, b, c, d;
//	int ar[100];
//	static int count;
//public:
//	//객체를 생성시키지 않고 바로 사용 할 수 있다.
//	static void f1() {
//		printf("콜\n");
//	}
//	//// 잘못된 사용
//	//void f2() {
//	//	count++;
//	//	printf("콜\n");
//	//}
//	// 맞는 사용
//	static void f2() {
//		count++;
//		printf("콜\n");
//	}
//	//// 잘못된 사용
//	//void f3() {
//	//	f2();
//	//}
//	// 옳은 사용
//	static void f3() {
//		f2();
//	}
//};
//
//int main()
//{
//	CTiger::f1();
//}

#pragma endregion
#pragma region MyRegion
class CTiger {
private:
	int a;
	void 기침약() {
		//함수는 최소한의 기능을 가지도록 제작된다.
		// 한 함수는 한 기능만 수행되도록 만들어져야 한다.
	}
	void 해열제() {

	}
	void 콧물약() {

	}
public:
	//void f1(const int x,const int* const p) const{
	//	//멤버 변수 변경 불가
	//	//a = 10; // 불가
	//}
	
	void 종합감기약() { // 캡슐화
		기침약();
		해열제();
		콧물약();
	}
};
int main()
{
	CTiger t;
	//t.기침약();
	//t.해열제();
	//t.콧물약();
	t.종합감기약();

}
#pragma endregion



#pragma endregion