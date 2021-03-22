#include <opencv2/opencv.hpp>
#include <direct.h>

using namespace cv;
using namespace std;
//opencv 3버젼

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
//}
int main(void)
{
	//char curDir[1000] = { 0, };
	//_getcwd(curDir, 1000);
	//printf("%s\n", curDir);

	string title = "Main Window";
	namedWindow(title, WINDOW_AUTOSIZE);
	moveWindow(title, 100, 200);

	string filename = "1.bmp";
	Mat color2color = imread(filename, IMREAD_COLOR);
	cout << color2color << endl;

	//cout << 1 << endl;
	//imshow("color2color", color2color);
	//cout << 2 << endl;
	//waitKey(0);

	return 0;

	//// ex11) 이벤트 사용법
	//// 현재 경로를 얻는다.
	//char curDir[1000] = { 0, };
	//_getcwd(curDir, 1000);
	//printf("%s\n", curDir);
	//
	////
	//Mat image(300, 400, CV_8U, Scalar(255));
	//string title = "Main Window";
	//namedWindow(title, WINDOW_AUTOSIZE);
	//moveWindow(title, 100, 200);
	//
	//int a = 10;
	//setMouseCallback(title, onMouse, &a);
	//imshow(title, image);
	//waitKey();
	//destroyAllWindows();

	//// ex10)
	//Mat image(300, 400, CV_8U, Scalar(255));
	//namedWindow("white window", WINDOW_NORMAL);
	//imshow("white window", image);
	//
	//while (true)
	//{
	//	// delay time : 20ms
	//	int key = waitKeyEx(20);
	//	if (key == 27) // ESC
	//	{
	//		cout << "종료" << endl;
	//		break;
	//	}
	//
	//	switch (key)
	//	{
	//	case 'a': cout << "a 입력" << endl;
	//		break;
	//	case 0x41: cout << "A 입력" << endl;
	//		break;
	//	case 0x250000: cout << "왼쪽 화살표 입력" << endl;
	//		break;
	//	case 0x260000: cout << "위쪽 화살표 입력" << endl;
	//		break;
	//	case 0x270000: cout << "오른쪽 화살표 입력" << endl;
	//		break;
	//	case 0x280000: cout << "아래쪽 화살표 입력" << endl;
	//		break;
	//
	//	}
	//		
	//}
	//waitKey();

	//// ex9)WINDOW_NORMAL : resize 가능
	//Mat image(300, 400, CV_8U, Scalar(255));
	//string title = "white window";
	//
	//namedWindow(title, WINDOW_NORMAL);
	//resizeWindow(title, 500, 200);
	//
	//imshow(title, image);
	//waitKey();
	//destroyAllWindows();
	
	// ex8)
	//// 8bit, 24bit, 32color
	//Mat image1(300, 400, CV_8U, Scalar(255));// 8bit Color
	////Mat image2(300, 400, CV_8U, Scalar(128));// 8bit Color
	//
	//string title1 = "white window";
	////string title2 = "gray window";
	//
	//namedWindow(title1, WINDOW_AUTOSIZE);
	////namedWindow(title2, WINDOW_NORMAL); // 사이즈 변경
	//moveWindow(title1, 100, 200);
	////moveWindow(title2, 400, 200);
	//imshow(title1, image1);
	////imshow(title2, image2);
	//
	//waitKey(); // 종료하지 말고 기다리자
	//destroyAllWindows(); // 윈도우창 파괴(누수 해결)


#pragma region CV 1일차

#pragma region 2d 좌표체계
	//// 3D 공간, 그래픽, 카메라
	//// 욜로 라이브러리.
	//Point_<int> pt1(100, 200);
	////printf("%d %d\n", pt1.x, pt1.y);
	//
	//Point_<float> pt2(10.0f, 20.0f);
	////printf("%.02f %.02f\n", pt2.x, pt2.y);
	//
	//Point_<double> pt3(10.0, 20.0);
	////printf("%.02f %.02f\n", pt3.x, pt3.y);
	//
	//// 구조체 형식
	//Point2i pt4(100, 200);
	//Point2f pt5(100.0f, 200.0f);
	//Point2d pt6(100.0, 200.0);
	////printf("%d %d\n", pt4.x, pt4.y);
	//
	//Point pt7 = pt1 + pt4;
	////Point2i pt7 = pt1 + pt4;
	////printf("%d %d\n", pt7.x, pt7.y);
	//
	//// 스케일한다.
	//Point2f pt8 = pt2 * 3.0f;
	////printf("%.02f %.02f\n", pt8.x, pt8.y);
	//
	////캐스팅
	//Point2i pt9 = pt1 + (Point2i)pt2;
	//
	//Point2f pt10(10.0f, 20.0f);
	//// dot : 내적(각 성분끼리의 곱에 합)
	//// (a.b) (c.d)의 내적
	//// = a * c + b * d
	//// ax + by + cz = 0 <---- 방정식
	//float result = pt5.dot(pt10);
	//printf("%.02f %.02f\n", result, pt5.dot(pt10));
#pragma endregion
#pragma region 3D 좌표체계
////ex2
//Point3_<int> pt1(100, 200, 300);
//Point3_<float> pt2(92.3f, 125.23f, 250.f);
//Point3f pt3(0.3f, 0.f, 15.7f);
//Point3d pt4(0.25f, 0.6f, 33.3f);
//
//Point3i pt5 = pt1 + (Point3i)pt2;
//printf("%.02f %.02f %.02f\n", pt2.x, pt2.y, pt2.z);
//
//Point3f pt6 = pt2 * 3.14f;
//
//Point3d pt7 = ((Point3d)pt3 + pt4) * 10.f;
//float result = pt4.dot(pt7);
//printf("%.02f\n", result);

#pragma endregion
	////Size_<int> sz1(100, 200);
	////Size_<float> sz2(192.3f, 25.3f);
	////Size_<double> sz3(100.2, 30.9);
	////
	////Size sz4(120, 69);
	////Size2f sz5(0.3f, 0.f);
	////Size2d sz6(0.25, 0.6);
	////
	////printf("%d %d\n", sz1.width, sz1.height);
	////printf("%d\n", sz1.area());
	////
	////Point2d pt1(0.25, 0.6);
	////Size2i sz7 = sz1 + (Size2i)sz2;
	////Size2d sz8 = sz3 - (Size2d)sz4;
	//
	//Size2d sz(100.5, 60.6);
	//Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);
	//
	//// (sx,sy, w, h) >> 다를 경우에는 (sx, sy, ex, ey)
	//Rect_<int> rect1(10, 10, 30, 50);
	//Rect_<float> rect2(pt1, pt2);
	//Rect_<double> rect2(Point2d(20.5, 10), sz);
	//
	////시작좌표
	//printf("%d %d\n", rect1.tl().x, rect1.tl().y);
	////끝 좌표
	//printf("%d %d\n", rect1.br().x, rect1.br().y);
	//
	//printf("%d %d\n", rect1.width, rect1.height);
	//printf("%d %d\n", rect1.size().width, rect1.size().height);
	//Size2i result = rect1.size();
	//printf("%d %d\n", rect1.width, result.height);

#pragma region 벡터좌표체계
	//Vec<int, 2> v1(5, 12);
	//Vec<double, 3> v2(40, 130.7, 125.6);
	//Vec2b v3(10, 10);
	//Vec6f v4(40.0f, 230.25f, 252.6f);
	//Vec3i v5(200, 230, 250);
	//Vec3d v6 = v2 + (Vec3d)v5;
	//Vec2b v7 = (Vec2b)v1 + v3;
	//Vec6f v8 = v4 * 20.0f;
	//Point pt1 = v1 + (Vec2i)v7;
	//Point3_<int> pt2 = (Vec3i)v2;
	//
	//
	//cout << "[v1] = " << v1 << endl;
	////printf("%d %d\n",v1.row(0), v1.row(1));
	//cout << "[v3] = " << v3 << endl;
	//cout << "[v7] = " << v7 << endl;
	//cout << "[v3 * v7] = " << v3.mul(v7) << endl;
	//cout << "v8[0] = " << v8[0] << endl;
	//cout << "v8[1] = " << v8[1] << endl;
	//cout << "v8[2] = " << v8[2] << endl;
#pragma endregion
#pragma region 색상 정의 체계
	//Scalar_<uchar> red(0, 0, 255);
	//Scalar_<int> blue(255, 0, 0);
	//Scalar_<double> color1(500);
	//Scalar_<float> color2(100.f, 200.f, 125.9f);
	//
	//Vec3d green(0, 0, 300.5);
	//Scalar green1 = color1 + (Scalar)green;
	//Scalar green2 = color2 + (Scalar_<float>)green;
	//cout << "blue = " << blue[0] << ", " << blue[1];
	//cout << ", " << blue[2] << endl;
	//cout << "red = " << red << endl;;
	//cout << "green = " << green << endl;;
	//cout << "(scalar)green = " << (Scalar)green << endl;
	//cout << "green1 = " << green1 << endl;
	//cout << "green1 = " << green1 << endl;
#pragma endregion

#pragma endregion
#pragma region 매트릭스
//Matx<int, 2, 3> m1(
//	1, 2, 3,
//	4, 5, 6);
//printf("%d %d %d %d %d %d\n",
//	m1(0, 0), m1(0, 1), m1(0, 2)
//	, m1(1, 0), m1(1, 1), m1(1, 2));
//Matx23d m2(
//	1, 2, 3,
//	4, 5, 6);
//printf("%f %f %f %f %f %f\n",
//	m2(0, 0), m2(0, 1), m2(0, 2)
//	, m2(1, 0), m2(1, 1), m2(1, 2));
//// 2행 3열(CV_8U : 8bit Color)
//Mat m3(2, 3, CV_8U);
//cout << m1 << endl;
#pragma endregion	
}