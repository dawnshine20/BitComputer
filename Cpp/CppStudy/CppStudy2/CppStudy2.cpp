#include <windows.h>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
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
//int main()
//{
//	srand((signed)time(NULL));
//	
//	
//	//CCat a; CDog b; CSnake  c;
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	int num = rand() % 3; // 0 1 2
//	//	switch (num) {
//	//	case 0:
//	//	{
//	//		a.cry();
//	//	}break;
//	//	case 1:
//	//	{
//	//		b.cry();
//	//	}break;
//	//	case 2:
//	//	{
//	//		c.cry();
//	//	}break;
//	//	}
//	//}
//	//---------위 코드와 아래코드는 같은 코드이다.(ㄷㄷ)------------------------
//
//	CCat* a = new CCat;
//	CDog* b = new CDog;
//	CSnake* c = new CSnake;
//
//	CAnimal* ani[] = { new CCat , new CDog, new CSnake };
//	//ani[0] = new CCat;
//	//ani[1] = new CDog;
//	//ani[2] = new CSnake;
//
//	for (int i = 0; i < 5; i++)
//	{
//		int num = rand() % 3; // 0 1 2
//		ani[num]->cry();
//	}
//	
//}
//
#pragma endregion
#pragma region 같은 level의 상속 단계는 아무런 관계가 없다.
//class CA{
//public:
//	void f1() { printf("f1"); }
//};
//class CB : public CA {
//	void f2() { printf("f2"); }
//};
//class CC : public CB {
//	void f3() { printf("f3"); }
//};
//class CD : public CB {
//	void f4() { printf("f4"); }
//};
//
////		A(f1)
////		B(f2)
////	C(f3)		D(f4)
//// 같은 레벨에 존재하지만 C와 D는 아무런 관계가 없다.
//int main()
//{
//	CA a; // 1
//	CB b; // 12
//	CC c; // 123
//	CD d; // 124
//
//}

#pragma endregion
#pragma region 생성자 (신)문법
//class CA {
//public:
//	int x, y;
//public:
//	/*CA() {
//		x = 0;
//		y = 0;
//	}*/
//	// 위와 아래 코드는 완전한 동격 코드이다.(아래 코드가 성능이 더 좋음)
//	CA() : x(0), y(0) {}
//
//	//-----------------------------------------
//
//	/*CA(int a, int b)
//	{
//		x = a;
//		y = b;
//	}*/
//	// 위와 아래 코드는 완전한 동격 코드이다.
//	CA(int a, int b) : x(a), y(b) {
//	}
//
//	//---------------------------------------
//	/*CA(int x, int y)
//	{
//		this -> x = x;
//		this -> y = y;
//	}*/
//	// 위와 아래 코드는 완전한 동격 코드이다.
//	CA(int x, int y) : x(x), y(y) {
//	}
//};
//
//int main()
//{
//
//}

#pragma endregion
#pragma region 컴파일러가 자동으로 생성해주는 주요 구문들
//class CA {
//	//private:
//	// 디폴트 생성자가 만들어진다.
//	// 복사 생성자가 만들어진다.
//	// CA* this
//	//객체가 생성 될때 this 안에는 생성된 객체의 주소가 들어가 있다.
//	//this = &a;
//	//소멸자 자동생성
//};
//
//int main()
//{
//	CA a;
//}
#pragma endregion
#pragma region 알파고 베타고
//class AI {
//public:
//	virtual void playSet() = 0;
//};
//class CAlphaGo : public AI {
//public:
//	void playSet() {
//		printf("인공지능은 알파고입니다.\n");
//	}
//};
//class CBetaGo : public AI {
//public:
//	void playSet() {
//		printf("인공지능은 베타고입니다.\n");
//	}
//};
//
//class CA {
//public:
//	CA() {
//		printf("경기를 시작합니다.\n");
//	}
//	//void play(CAlphaGo* ag) { // 문제의 코드: 비슷한 동일한 함수 생김(업캐스팅 필요)
//	//	ag->playSet();
//	//	printf("바둑 대국 중...\n");
//	//}
//	//void play(CBetaGo* bg) { // 문제의 코드: 비슷한 동일한 함수 생김(업캐스팅 필요)
//	//	bg->playSet();
//	//	printf("바둑 대국 중...\n");
//	//}
//	void play(AI* ai) {  // 해결된 코드
//		ai->playSet();
//		printf("바둑 대국 중...\n");
//	}
//};
//
//
//int main()
//{
//	CA a;
//	a.play(new CAlphaGo);
//	a.play(new CBetaGo);
//}
//
#pragma endregion
#pragma region 알파고 베타고 진화버전(질나쁜 코드)
//class AI {
//public:
//	virtual void playSet() = 0;
//	virtual void end() = 0;
//};
//
//class CAlphaGo : public AI {
//public:
//	void playSet() {
//		printf("인공지능은 알파고입니다.\n");
//	}
//	void end() {
//		printf("알파고가 개가 중입니다.\n");
//	}
//};
//class CBetaGo : public AI {
//public:
//	void playSet() {
//		printf("인공지능은 베타고입니다.\n");
//	}
//	void end() {
//		printf("베타고가 개가 중입니다.\n");
//	}
//};
//
//class CA {
//public:
//
//	CA() {
//		printf("경기를 시작합니다.\n");
//	}
//	//---------질나쁜 코드----------(구태여 인수 전달해서 비용을 증가시킴)
//	void play(AI * ai) {
//		ai->playSet();
//		printf("바둑 대국 중...\n");
//	}
//
//	void end(AI * ai) {
//		ai->end();
//	}
//	//---------질나쁜 코드----------
//};
//
//
//int main()
//{
//	CA a;
//	a.play(new CAlphaGo);//문제점
//	a.play(new CBetaGo);//문제점
//	a.end(new CAlphaGo);//문제점
//	a.end(new CBetaGo);//문제점
//}
#pragma endregion
#pragma region 해결(질 좋은 코드)_클래스의 의존적 관계 사용
//class AI {
//public:
//	virtual void playSet() = 0;
//	virtual void end() = 0;
//};
//
//class CAlphaGo : public AI {
//public:
//	void playSet() {
//		printf("인공지능은 알파고입니다.\n");
//	}
//	void end() {
//		printf("알파고가 개가 중입니다.\n");
//	}
//};
//class CBetaGo : public AI {
//public:
//	void playSet() {
//		printf("인공지능은 베타고입니다.\n");
//	}
//	void end() {
//		printf("베타고가 개가 중입니다.\n");
//	}
//};
//
//class CA { // AI 클래스와 CA는 의존적 관계에 있다.
//public:
//	AI* ai;
//	CA(AI* ai):ai(ai) { // >>>>>>>>> 주입(injection)
//		//this -> ai = ai
//		printf("경기를 시작합니다.\n");
//	}
//	//---------고친 코드----------
//	void play() {
//		ai->playSet();
//		printf("바둑 대국 중...\n");
//	}
//
//	void end() {
//		ai->end();
//	}
//	//-------------------------
//};
//
//
//int main()
//{
//	CA a(new CAlphaGo);
//	a.play();
//	a.end();
//
//	printf("\n");
//	printf("\n");
//
//	CA b(new CBetaGo);
//	b.play();
//	b.end();
//	
//}
#pragma endregion
#pragma region 상속과 소멸자의 관계(upcasting케이스) virtual을 붙이는 이유
//class A {
//public:
//	A() {
//		printf("A생콜\n");
//	}
//	virtual ~A() { // virtual을 붙임으로써 자식 소멸자도 불러주게 된다.
//		printf("A소콜\n");
//	}
//};
//class B : public A {
//public:
//	B() {
//		printf("B생콜\n");
//	}
//	virtual ~B() { // 누가 또 상속 받을 것을 대비해서 virtual을 사용한다.
//		printf("B소콜\n");
//	}
//};
//
//int main()
//{
//	//부자자부
//	A* a = new B;
//	delete a;
//}
//
//class A {
//public:
//	A() {
//		printf("A생콜\n");
//	}
//	virtual ~A() { // virtual을 붙임으로써 자식 소멸자도 불러주게 된다.
//		printf("A소콜\n");
//	}
//};
//class B : public A {
//public:
//	B() {
//		printf("B생콜\n");
//	}
//	virtual ~B() { // 누가 또 상속 받을 것을 대비해서 virtual을 사용한다.
//		printf("B소콜\n");
//	}
//};
//
//int main()
//{
//	//부자자부
//	A* a = new B;
//	delete a;
//}
//
//
#pragma endregion
#pragma region 자식이 부모를 2개 상속?(다중 상속)
//class AI {
//
//};
//
//class A: public AI {
//public:
//	void f1() {
//		printf("1\n");
//	}
//};
//class B: public AI {
//public:
//	void f2() {
//		printf("2\n");
//	}
//};
//class C: public A, public B  {
//public:
//	void f3() {
//		printf("3\n");
//	}
//};
//
//int main()
//{
//	C c;
//	c.f1();
//	c.f2();
//	c.f3();
//}
#pragma endregion
#pragma region namespace 사용법
//// std도 사용하지 않더라도 프로그램 메모리에 무조껀 잡고 들어가는건지?
//
////전역변수로 쓰면 되지 왜 네임스페이스로 만드는가?
////산 사람 입장에서 int a, int b라는 더이상 선언 할 수 없다.
//// 다른 회사 라이브러리 가져오면 변수명 겹칠 가능성 다분히 존재한다.
//// 보통 namespace는 회사 이름을 사용한다.
//using namespace std;
//
//namespace AAA {
//	int a = 10;
//	int b = 20;
//	void f1() {
//		printf("test\n");
//	}
//};
//
//int main()
//{
//	printf("%d\n", AAA::a);
//	AAA::f1();
//}
#pragma endregion

#pragma region MFC 다운캐스팅 문법을 위한  실습예제
////
////class A {
////public:
////	void f1(){}
////};
////class B: public A {
////public:
////	void f2() {}
////};
////
////class D {
////public:
////	void f1(A* a) { // 부<=자 업 캐스팅
//		//
//		a->f1();
//		B* b = (B * )a;
//		b->f2();
//	}
////	A* GetDlgItem() {
//		return new B;
//	}
////};
////
////int main() {
//	A* a = new B;
//	D d;
//	d.f1(new B);
//
//	A* a1 = d.GetDlgItem();
//	a1->f1();
//
//	B* a2 = (B*)d.GetDlgItem();
//	a2->f2();
//
//	//다형성 이용하기 위해 부모 주소 먼저 받고 쓰고자하는 함수는 다운 캐스팅 해서 사용해라
	// 버튼 클래스 뿐만 아니라 리스트박스 클래스, 등등 여러개의 자식 클래스가 있는데 일일히 다 함수로 만들 수 없기 때문에
	// 다형성을 이용하는것이 최적화된 코드이기 때문에 사용된 기법이다.
//}
//
#pragma endregion

#pragma region 자식이 할 일을 다하고 부모도 같이 일을 해야하는 경우 상속을 사용

//class A {
//public:
//	virtual void f1() {
//		printf("칼\n");
//	}
//};
//
//class B : public A {
//public:
//	void f1() {
//		printf("방패\n");
//		A::f1();
//	}
//
//};
//
//int main()
//{
//	A* a = new B;
//	a->f1();
//}
//------아래와 같은 형식의 코드로 사용된다면 자식이 먼저 일을 수행한 후에 
//부모가 또 뒷처리 일을 수행해야하는 경우로 추측할 수 있다.
//class A {
//public:
//	virtual void f1() {}
//};
//
//class B : public A {
//public:
//	void f1() {
//		// 코드를 작성하시오
//		A::f1();
//	}
//
//};
//
//int main()
//{
//	A* a = new B;
//	a->f1();
//}
#pragma endregion


#pragma region 연산자 오버로딩(VECTOR 예제)
//class CVector {
//public:
//	float x, y; // 성분값이다. z는 버린다.
//	CVector() {}
//	CVector(float x, float y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	void output() {
//		printf("%.02f %.02f\n", x, y);
//	}
//	CVector add(CVector v) {
//		CVector r;
//		r.x = x + v.x;
//		r.y = y + v.y;
//		return r;
//	}
//	// operator + << 함수 이름이다.
//	//CVector operator +(CVector v) {
//	//	CVector r;
//	//	r.x = x + v.x;
//	//	r.y = y + v.y;
//	//	return r;
//	//}
//
//	//-----위 코드보다 더 좋은 코드 주소만 
//	// 던저주기 때문에 메모리 절약
//	// 그러나 사용자에게 불편한 코드-----
//	CVector operator +(CVector* v) { 
//		CVector r;
//		r.x = x + v->x;
//		r.y = y + v->y;
//		return r;
//	}
//	CVector operator -(CVector* v) { 
//		CVector r;
//		r.x = x - v->x;
//		r.y = y - v->y;
//		return r;
//	}
//
//
//	//-----위 코드를 수정하여 사용자를 생각해 만들면서 
//	// 공유를 통해 성능을 올린 코드-----
//	CVector operator +(const CVector& v) const { 
//		// const를 통해 데이터 무결성 보장(인자 데이터 상수화 및 함수 내에서 멤버 변수 상수화)
//		//v.x = 100(앞에 있는 const로 인해 불가)
//		//x = 100;(뒤에 붙은 const로 인해 불가)
//		
//		CVector r;
//		r.x = x + v.x;
//		r.y = y + v.y;
//		return r;
//	}
//	CVector operator -(const CVector& v) const {
//		CVector r;
//		r.x = x - v.x;
//		r.y = y - v.y;
//		return r;
//	}
//};
//int main()
//{
//	CVector a(2.0f, 1.0f), b(1.0f, 2.0f);
//	a.output();
//	CVector c = a.add(b);
//	c.output();
//
//	CVector d = a.operator+(b); // 연산자 오버로딩.
//	d.output();
//
//	CVector e = a+b; // 컴파일시 d와 같이 컴퓨터가 바꿈
//	e.output();
//
//	CVector f = a + (&b); // 사용자가 불편함을 많이 느끼므로 변경이 필요(참조형태가 필요)
//	f.output();
//}
//
#pragma endregion
#pragma region +=에 대한 연산자 재정의(VECTOR 재정의)
//class CVector {
//public:
//	float x, y; // 성분값이다. z는 버린다.
//	CVector() {}
//	CVector(float x, float y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	void output() {
//		printf("%.02f %.02f\n", x, y);
//	}
//	
//	CVector operator +(const CVector& v)const { 
//		CVector r;
//		r.x = x + v.x;
//		r.y = y + v.y;
//		return r;
//	}
//	CVector& operator +=(const CVector& v) {
//		this->x += v.x;
//		this->y += v.y;
//
//		return *this;
//	}
//	
//	//수학에서 벡터의 곱은 존재하지 않기 때문에 제공하지 않는다.
//	//곱에 대한 합인 내적 함수만 존재한다.
//	
//};
//int main()
//{
//	CVector a(2.0f, 1.0f), b(1.0f, 2.0f), c(2.0f, 3.0f);
//
//	//a = a + b;
//	a += b;
//	a.output();
//
//	int x = 1, y = 2, z = 3;
//	(x += y) += z;
//	printf("%d %d %d\n", x, y, z);
//
//	(a += b) += c; // return이 필요한 형태이기 때문에 코드의 수정이 필요하다.
//	
//}

#pragma endregion
#pragma region 단항연산자에 대한 연산자 재정의(VECTOR 예제)
//class CVector {
//private:
//	float x, y; // 성분값이다. z는 버린다.
//public:
//	CVector() {}
//	CVector(float x, float y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	void output() {
//		printf("%.02f %.02f\n", x, y);
//	}
//	
//	//-------------------------
//	CVector operator -() const{
//		CVector r;
//		r.x = -this->x;
//		r.y = -this->y;
//		return r;
//	}
//	CVector operator +() const{
//		CVector r;
//		r.x = +this->x;
//		r.y = +this->y;
//		return r;
//	}
//	bool operator ==(CVector& v) const {
//		if (this->x == v.x && this->y == v.y) {
//			return true;
//		}
//		return false;
//	}
//
//	bool operator !=(CVector& v) const {
//		if (this->x != v.x || this->y != v.y) {
//			return true;
//		}
//		return false;
//	}
//
//	CVector operator *(float value) const {
//		CVector r;
//		r.x = x * value;
//		r.y = y * value;
//		return r;
//	}
//
//	//수학에서 벡터의 곱은 존재하지 않기 때문에 제공하지 않는다.
//	//곱에 대한 합인 내적 함수만 존재한다.
//
//
//	// 우리 멤버는 아니지만 멤버변수를 사용할 수 있다.
//	friend CVector operator *(float f, const CVector& v); 
//};
//
//CVector operator *(float f, const CVector& v) { // 사용하기 위해서 friend 혹은 setter,getter를 사용
//	CVector r;
//	r.x = f * v.x;
//	r.y = f * v.y;
//	return r;
//}
//
//int main()
//{
//	int x, y, z = 10;
//	// 비용이 좀 더 들더라도 음수 양수 맞춰줘야 한다.
//	x = +z;
//	y = -z;
//
//	CVector a(2.0f, 1.0f), b(2.0f, 1.0f), c(2.0f, 3.0f);
//
//	CVector d;
//	d = -a;		 // 단항 연산에 대한 연산자 재정의 필요.
//	d.output();
//	if (a == b) { // 부동 소수점 계산해서 비교하는건 사실 말이 안되는 경우이지만 그냥 비교하는건 제공
//		printf("1\n");
//	}
//
//	b = a * 2.0f;
//	b.output();
//	//사용자가 아래와 같이 사용하고 싶을 수도 있다.
//	b = 2.0f * a;
//	b.output();
//	
//	//---------------
//}
#pragma endregion
#pragma region 주의case 전위 후위 연산자 재정의
//class CVector {
//private:
//	float x, y; // 성분값이다. z는 버린다.
//public:
//	CVector() {}
//	CVector(float x, float y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	void output() {
//		printf("%.02f %.02f\n", x, y);
//	}
//
//	CVector operator++() { //전위 연산자 사용 ++a
//		printf("1\n");
//		x += 1.0f;
//		y += 1.0f;
//		return *this;
//	}
//	CVector operator++(int) { //후위 연산자 a++를 사용하기 위해서 인자에 int를 넣어 준다.
//		printf("2\n");
//		CVector r;
//		r.x = x; 
//		r.y = y;
//
//		x += 1.0f;
//		y += 1.0f;
//
//		return r; //백업시켜놓은 데이터 먼저 제공한다.
//	}
//};
//int main()
//{
//	CVector a(2.0f, 1.0f), b(2.0f, 1.0f), c(2.0f, 3.0f);
//	++a;
//	a.output();
//	a++;// 연산자가 위와 다르다.
//
//	b = ++a;
//	b.output();
//	c = a++;
//	c.output();
//}
#pragma endregion

#pragma region 몬테카를로 원리
//int main()
//{
//	srand((signed)time(NULL));
//	int RandNum, pick;
//	int cntChange = 0, cntMaintain = 0;
//	for (int i = 0; i < 1000; i++)
//	{
//		int cards[3] = { 0, };
//		RandNum = rand() % 3;
//		cards[RandNum] = 1;
//
//		pick = rand() % 3;
//		if (cards[pick] == 1)
//			++cntMaintain;
//		else
//			++cntChange;
//	}
//	printf("안바꿈: %d,  바꿈: %d\n", cntMaintain, cntChange);
//}
#pragma endregion

#pragma region 주사위 확률 게임
//int main()
//{	
//	int n = 10;
//	for (int i = 1; i <= n; i++)
//	{
//		int six = pow(6, i);
//		int notsix = pow(5, i);
//		printf("%d : %d 퍼센트\n", i, notsix * 100 / six);
//	}
//}
// 몬테카를로 활용
int main()
{
	int n = 10;
	float percent = 1.0f;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= 6; j++)
		{
			if (j != 6)
				cnt++;
		}
		float eachPercent = (float)cnt / 6.0f;
		percent *= eachPercent;
		printf("%f\n", percent);
	}
}
#pragma endregion

