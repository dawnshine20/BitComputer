#include <windows.h>
#include <iostream>
#include <time.h>
using namespace std;
#pragma region 상속1
//
//// 클래스는 상속이 핵심이다.
//// 상속을 하고 나면 다형성이 핵심이다.
//// C++은 다형성을 알면 끝난거다.
//// 객체지향의 핵심은 다형성이다.
//class CApple {
//public:
//    void f1() {
//        printf("부모의 f1\n");
//    }
//    void f3() {
//        printf("부모의 f3\n");
//    }
//    
//};
//class CBanana : public CApple { // 상속 관계 ( : public )
//public:
//    void f2() {
//        printf("자식의 f2\n");
//    }
//    void f3() {
//        printf("자식의 f3\n");
//    }
//};
//int main()
//{
//    CApple a; // 상속과는 전혀 무관함
//    CBanana b;
//    b.f1(); // 자신을 먼저 찾아본다. ->없다면 부모를 찾는다.
//    b.f2(); // 자신을 먼저 찾아본다.
//    b.f3(); // 자신을 먼저 찾아본다.
//    b.CApple::f3(); // 직접 부모를 찾아가서 찾는다.
//}
//
#pragma endregion
#pragma region protected
//class CApple {
//private:
//	int a;// 상속을 받은 녀석도 못쓴다.
//public:
//	int b;
//protected:
//	int c; // private랑 동일 하나, 상속 받은 녀석은 사용 가능
//};
//
//class CBanana :public CApple {
//public:
//	void f1() {
//		a = 0;
//		b = 10;
//		c = 20;
//	}
//};
//
//int main()
//{
//	CBanana bpp;
//	bpp.a = 10; // x
//	bpp.b = 10; // o
//	bpp.c = 10  // x
//}

#pragma endregion
#pragma region 상속 자식 부모 호출 순서
//class CApple {
//private:
//	
//public:
//	CApple() {
//		printf("1\n");
//	}
//	CApple(int a, int b) {
//		printf("5\n");
//	}
//	~CApple() {
//		printf("4\n");
//	}
//}; // 호출 순서 부모 -> 자식->자식 -> 부모
//
//class CBanana :public CApple {
//public:
//	CBanana():CApple(3, 5) { // 결과적으로는 자식 생성자를 먼저 간다.(생략된 구문 살려둠)
//		printf("2\n");
//	}
//	~CBanana() {
//		printf("3\n");
//	}
//};
//
//int main()
//{
//	CBanana bpp;
//	
//}
#pragma endregion
#pragma region 상속 호출순서 2
//class CApple {
//private:
//
//public:
//	CApple() {
//		printf("1\n");
//	}
//	CApple(int a, int b) {
//		printf("5\n");
//	}
//	
//	~CApple() {
//		printf("4\n");
//	}
//}; // 호출 순서 부모 -> 자식->자식 -> 부모
//
//class CBanana :public CApple {
//public:
//	CBanana() :CApple(3, 5) { // 결과적으로는 자식 생성자를 먼저 간다.(생략된 구문 살려둠)
//		printf("2\n");
//	}
//	CBanana(int x, int y) : CApple(x, y) { // 결과적으로는 자식 생성자를 먼저 간다.(생략된 구문 살려둠)
//		printf("2\n");
//	}
//	~CBanana() {
//		printf("3\n");
//	}
//};
//
//int main()
//{
//	
//
//}
//
#pragma endregion
#pragma region 상속 호출순서 3
//class CApple {
//public:
//	void f3() {
//		printf("3\n");
//		f4();
//	}
//	void f4() {
//		printf("41\n");
//	}
//}; // 호출 순서 부모 -> 자식->자식 -> 부모
//
//class CBanana :public CApple {
//public:
//	void f1() {
//		printf("1\n");
//		f2();
//	}
//	void f2() {
//		printf("2\n");
//		f3();
//	}
//	void f4() {
//		printf("42\n");
//		
//	}
//};
//
//int main()
//{
//	CBanana bpp;
//	bpp.f1();
//
//}
//
//
#pragma endregion
#pragma region virtual-1
//class CApple {
//public:
//	void f1() {
//		printf("2\n");
//		f2();
//		f3();
//	}
//	virtual void f2() { // virtual은 우선 자식에 포함되어 있나 찾아본다
//		printf("21\n");
//	}
//	virtual void f3() { // virtual은 우선 자식에 포함되어 있나 찾아본다
//		printf("31\n");
//	}
//	
//}; // 호출 순서 부모 -> 자식->자식 -> 부모
//
//class CBanana :public CApple {
//public:
//	void f2() {
//		printf("22\n");
//	}
//};
//
//int main()
//{
//	CApple app;
//	app.f2();
//	CBanana bpp;
//	bpp.f1();
//
//}
#pragma endregion
#pragma region 다형성(업캐스팅), (다운캐스팅)
//class CA {
//public:
//	void f1() {
//		printf("1\n");
//	}
//};
//
//class CB :public CA {
//public:
//	void f2() {
//		printf("2\n");
//	}
//};
//
//int main()
//{
//	CA* p1 = new CA;
//	p1->f1();
//
//	CA* p2 = new CB;//업캐스팅	부모 <- 자식
//	p2->f1();
//
//	CB* p3 = (CB*)new CA;//다운캐스팅 자식 <- 부모
//	p3->f1();
//	//p3->f2(); // 완전히 죽는 코드
//
//	CB* p4 = new CB;
//	p4->f1();
//	p4->f2();
//
//}

#pragma endregion
#pragma region 업캐스팅 예제
//class CA {
//public:
//	void f1() {
//		f2();
//	}
//	virtual void f2() {
//		printf("1");
//	}
//};
//
//class CB :public CA {
//public:
//	void f2() {
//		printf("2\n");
//	}
//};
//class CC :public CA {
//public:
//	void f2() {
//		printf("3\n");
//	}
//};
//
//int main()
//{
//	CA* p1 = new CB; // upcasting
//	p1->f1();
//
//	CA* p2 = new CC; // upcasting
//	p2->f1();
//}
#pragma endregion
#pragma region 업캐스팅 예제2
////class CAnimal {
////public:
////	virtual void cry() {
////		printf("1");
////	}
////};
////
////class CCat :public CAnimal {
////public:
////	void cry() {
////		printf("야옹\n");
////	}
////};
////class CDog :public CAnimal {
////public:
////	void cry() {
////		printf("멍멍\n");
////	}
////};
////class CSnake :public CAnimal {
////public:
////	void cry() {
////		printf("쉭쉭\n");
////	}
////};
////
////void sound(CCat* cat) {
////	cat->cry();
////}
////void sound(CDog* dog) {
////	dog->cry();
////}
////void sound(CSnake* snake) {
////	snake->cry();
////}
////int main()
////{
////	sound(new CCat);
////	sound(new CDog);
////	sound(new CSnake);
////}
////위 코드의 문제점 : 소리를 내려고 할때마다 동물마다 소리를 만들어줘야하는 불편함이 있음
////-----------------------------------------
//// 문제를 해결하기 위해서 업캐스팅을 활용해서 확장성 넓힘
//class CAnimal {
//public:
//	virtual void cry() = 0; // 순수 가상함수.(처음부터 코드가 없는 형태)
//};
//
//class CCat :public CAnimal {
//public:
//	void cry() {
//		printf("야옹\n");
//	}
//};
//class CDog :public CAnimal {
//public:
//	void cry() {
//		printf("멍멍\n");
//	}
//};
//class CSnake :public CAnimal {
//public:
//	void cry() {
//		printf("쉭쉭\n");
//	}
//};
//
//void sound(CAnimal* animal) {
//	// 클래스 코드를 만드는 사람은 어떤 동물의 소리가 들어올지 전혀 모른다
//	// 결과가 다양한 형태로 나타날 수 있다! <- 다형성을 충족시키는 코드
//	animal->cry(); 
//}
//int main()
//{
//	sound(new CCat);
//	sound(new CDog);
//	sound(new CSnake);
//}
#pragma endregion
#pragma region 업캐스팅 예제3
class CAnimal {
public:
	virtual void cry() = 0; // 순수 가상함수.(처음부터 코드가 없는 형태)
};

class CCat :public CAnimal {
public:
	void cry() {
		printf("야옹\n");
	}
};
class CDog :public CAnimal {
public:
	void cry() {
		printf("멍멍\n");
	}
};
class CSnake :public CAnimal {
public:
	void cry() {
		printf("쉭쉭\n");
	}
};

int main()
{
	srand((signed)time(NULL));
	
	
	//CCat a; CDog b; CSnake  c;
	//for (int i = 0; i < 5; i++)
	//{
	//	int num = rand() % 3; // 0 1 2
	//	switch (num) {
	//	case 0:
	//	{
	//		a.cry();
	//	}break;
	//	case 1:
	//	{
	//		b.cry();
	//	}break;
	//	case 2:
	//	{
	//		c.cry();
	//	}break;
	//	}
	//}
	//---------위 코드와 아래코드는 같은 코드이다.(ㄷㄷ)------------------------

	CCat* a = new CCat;
	CDog* b = new CDog;
	CSnake* c = new CSnake;

	CAnimal* ani[] = { new CCat , new CDog, new CSnake };
	//ani[0] = new CCat;
	//ani[1] = new CDog;
	//ani[2] = new CSnake;

	for (int i = 0; i < 5; i++)
	{
		int num = rand() % 3; // 0 1 2
		ani[num]->cry();
	}
	
}

#pragma endregion
