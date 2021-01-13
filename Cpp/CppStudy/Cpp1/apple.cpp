//#include "apple.h"
//#include <stdio.h>
//
//void CApple::f1() { // 전역함수 f1인데...
//	printf("f1\n");
//}
//void CApple::f2() { // 전역함수 f1인데...
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