//#include "banana.h"
//#include <stdio.h>
//
//void CBanana::f1() { // �����Լ� f1�ε�...
//	printf("f1\n");
//}
//void CBanana::f2() { // �����Լ� f1�ε�...
//	printf("f2\n");
//}
//
//--------------------------------------------
#include "apple.h"
#include "banana.h"
#include <stdio.h>

	void CBanana::f1() { //2
		printf("f1\n");
		CApple app;
		app.f2(this);//3
	}
	void CBanana::f3() {//6
		printf("f3\n");
	}
