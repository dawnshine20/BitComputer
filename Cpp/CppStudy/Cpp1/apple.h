//// 한번만 컴파일 하라고 프리프로세서을 준다.(여러번 컴파일 될 경우를 방지)
#pragma once
//
////----------------------------------위 프리프로세서와 아래 프리프로세서는 동일한 구문
//
//// (n은 not) 컴파일을 하는데 _APPLE이 디파인 된걸 본적이 없느냐??
//// 없다면 아래로 내려가서 컴파일 해버림
//#ifndef _APPLE 
//#define _APPLE // 본적 있는 것으로 처리하기 위해 #define으로 한번 보여준다.
//
//class CApple {
//public:
//	CApple() {}
//	void f1();
//	void f2();
//};
//
//#endif
//--------------------------------------------
#include "banana.h"

class CApple {
public:
	CApple();
	void f2(CBanana* app); // 4
};
