#include <opencv2/opencv.hpp>
#include <direct.h>
using namespace cv;
using namespace std;
//opencv 4.5.1���� ��� ���� ����
int main()
{��

#pragma region â���� ����
	//	Mat image1(300, 400, CV_8U, Scalar(255));
//	string title1 = "white window";
//	namedWindow(title1, WINDOW_AUTOSIZE);
//	moveWindow(title1, 100, 200);
//	imshow(title1, image1);
//	waitKey();
//	destroyAllWindows();
//	return 0;
#pragma endregion
#pragma region �׸� �������� ����
	//char curDir[1000] = { 0, };
	//_getcwd(curDir, 1000);
	//printf("%s\n", curDir);
	////string filename = "tiger.jpg";
	//string filename = "./pok.jpg";
	//// string filename = "image/tiger.jpg";
	//Mat color2color = imread(filename, IMREAD_COLOR);
	//// ����
	////cout << color2color << endl;
	//cout << 1 << endl;
	//imshow("color2color", color2color);
	//cout << 2 << endl;
	//waitKey(0);
	//return 0;
#pragma endregion
#pragma region ���콺 �̺�Ʈ ����
	//void onMouse(int event, int x, int y, int flags, void* param)
	//{
	//	switch (event)
	//	{
	//	case EVENT_LBUTTONDOWN:
	//		cout << "���콺 ���ʹ�ư ������--" << *(int*)param << endl;
	//		break;
	//	case EVENT_RBUTTONDOWN:
	//		cout << "���콺 �����ʹ�ư ������" << endl;
	//		break;
	//	case EVENT_RBUTTONUP:
	//		cout << "���콺 �����ʹ�ư ����" << endl;
	//		break;
	//	case EVENT_LBUTTONDBLCLK:
	//		cout << "���콺 ���ʹ�ư ����Ŭ��" << endl;
	//		break;
	//	}
	////////////////////////////////////
	//	Mat image(200, 300, CV_8U);
	//	image.setTo(255);
	//	imshow("���콺 �̺�Ʈ1", image);
	//	imshow("���콺 �̺�Ʈ2", image);
	//	int a = 10;
	//	setMouseCallback("���콺 �̺�Ʈ1", onMouse, &a);
	//	waitKeyEx(0);
	//	return 0;
#pragma endregion
#pragma region Ű���� ����Ű �̺�Ʈ ����
//	Mat image(200, 300, CV_8U, Scalar(255));
//	namedWindow("Ű���� �̺�Ʈ", WINDOW_AUTOSIZE);
//	imshow("Ű���� �̺�Ʈ", image);
//	while (1)
//	{
//		int key = waitKeyEx(20);
//		if (key == 27) // ESC
//			break;
//		switch (key)
//		{
//		case 'a': cout << "a �Է�" << endl;
//			break;
//		case 'b': cout << "b �Է�" << endl;
//			break;
//		case 0x41: cout << "A �Է�" << endl;
//			break;
//		case 66: cout << "B �Է�" << endl;
//			break;
//		case 0x250000: cout << "���� ȭ��ǥ �Է�" << endl;
//			break;
//		case 0x260000: cout << "���� ȭ��ǥ �Է�" << endl;
//			break;
//		case 0x270000: cout << "������ ȭ��ǥ �Է�" << endl;
//			break;
//		case 0x280000: cout << "�Ʒ��� ȭ��ǥ �Է�" << endl;
//			break;
//		}
//	}
//	return 0;
#pragma endregion

	
}
