//#include "apple.h"
//#include <stdio.h>
//
//void CApple::f1() { // �����Լ� f1�ε�...
//	printf("f1\n");
//}
//void CApple::f2() { // �����Լ� f1�ε�...
//	printf("f2\n");
//}

//--------------------------------------------
#include "apple.h"
#include <stdio.h>

CApple::CApple() {

}

void CApple::f2(CBanana* app) {// 4
	printf("f2\n");
	app->f3(); //5
}