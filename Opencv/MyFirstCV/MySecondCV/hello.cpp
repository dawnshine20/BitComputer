#include <opencv2/opencv.hpp>
#include <direct.h>
using namespace cv;
using namespace std;
//opencv 4.5.1버전 사용 가능 형태
int main()
{ㄴ

#pragma region 창띄우기 예제
	//	Mat image1(300, 400, CV_8U, Scalar(255));
//	string title1 = "white window";
//	namedWindow(title1, WINDOW_AUTOSIZE);
//	moveWindow(title1, 100, 200);
//	imshow(title1, image1);
//	waitKey();
//	destroyAllWindows();
//	return 0;
#pragma endregion
#pragma region 그림 가져오기 예제
	//char curDir[1000] = { 0, };
	//_getcwd(curDir, 1000);
	//printf("%s\n", curDir);
	////string filename = "tiger.jpg";
	//string filename = "./pok.jpg";
	//// string filename = "image/tiger.jpg";
	//Mat color2color = imread(filename, IMREAD_COLOR);
	//// 참고
	////cout << color2color << endl;
	//cout << 1 << endl;
	//imshow("color2color", color2color);
	//cout << 2 << endl;
	//waitKey(0);
	//return 0;
#pragma endregion
#pragma region 마우스 이벤트 예제
	//void onMouse(int event, int x, int y, int flags, void* param)
	//{
	//	switch (event)
	//	{
	//	case EVENT_LBUTTONDOWN:
	//		cout << "마우스 왼쪽버튼 누르기--" << *(int*)param << endl;
	//		break;
	//	case EVENT_RBUTTONDOWN:
	//		cout << "마우스 오른쪽버튼 누르기" << endl;
	//		break;
	//	case EVENT_RBUTTONUP:
	//		cout << "마우스 오른쪽버튼 떼기" << endl;
	//		break;
	//	case EVENT_LBUTTONDBLCLK:
	//		cout << "마우스 왼쪽버튼 더블클릭" << endl;
	//		break;
	//	}
	////////////////////////////////////
	//	Mat image(200, 300, CV_8U);
	//	image.setTo(255);
	//	imshow("마우스 이벤트1", image);
	//	imshow("마우스 이벤트2", image);
	//	int a = 10;
	//	setMouseCallback("마우스 이벤트1", onMouse, &a);
	//	waitKeyEx(0);
	//	return 0;
#pragma endregion
#pragma region 키보드 방향키 이벤트 예제
//	Mat image(200, 300, CV_8U, Scalar(255));
//	namedWindow("키보드 이벤트", WINDOW_AUTOSIZE);
//	imshow("키보드 이벤트", image);
//	while (1)
//	{
//		int key = waitKeyEx(20);
//		if (key == 27) // ESC
//			break;
//		switch (key)
//		{
//		case 'a': cout << "a 입력" << endl;
//			break;
//		case 'b': cout << "b 입력" << endl;
//			break;
//		case 0x41: cout << "A 입력" << endl;
//			break;
//		case 66: cout << "B 입력" << endl;
//			break;
//		case 0x250000: cout << "왼쪽 화살표 입력" << endl;
//			break;
//		case 0x260000: cout << "위쪽 화살표 입력" << endl;
//			break;
//		case 0x270000: cout << "오른쪽 화살표 입력" << endl;
//			break;
//		case 0x280000: cout << "아래쪽 화살표 입력" << endl;
//			break;
//		}
//	}
//	return 0;
#pragma endregion

	
}
