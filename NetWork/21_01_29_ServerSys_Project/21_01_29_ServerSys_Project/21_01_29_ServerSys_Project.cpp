// 21_01_28_ServerSys1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#pragma warning(disable:4996)

#include <winsock2.h>
#include <process.h>
#include <atlstr.h>
#include "framework.h"
#include "21_01_29_ServerSys_Project.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
// SERVER 전역변수
HWND hWnd;
bool LoopConnectThread = true;
SOCKET MainSocket;
// SOCKET hSocket; // client 소켓 핸들

HWND hwndButton1, hwndButton2, hwndButton3, hwndButton4;
#define BTN1 1000
#define BTN2 ((BTN1) + 1)
#define BTN3 ((BTN2) + 1)
#define BTN4 ((BTN3) + 1)


SOCKET hSocket[100];
struct USERINFO {
	SOCKET hSocket;
	int id;
};

#pragma region 클라이언트와 서버의 약속된 문장 형식
struct FORMAT1 {
	short mx;
	short my;
};
struct FORMAT2 {
	short data;
};
struct FORMAT3 {
	short x, y, z;
};
struct FORMAT4 {
	char ar[10];
};
#define FORMAT_ID1 1
#define FORMAT_ID2 2
#define FORMAT_ID3 3
#define FORMAT_ID4 4
#pragma endregion

// SERVER 프로그램
unsigned _stdcall ClientThread(void* pArg) {
	//메모리 해제할 수 있는 근거를 만들기 위해서 포인터 형으로 받는다.
	USERINFO* userInfo = (USERINFO*)pArg;
	//MessageBox(hWnd,L"ClientThread", L"ClientThread", MB_OK);

	// 이벤트를 관리할 이벤트 핸들 생성
	WSAEVENT hRecvEvent = WSACreateEvent();
	//감지할 이벤트를 설정한다.(어떤 이벤트를 설정 할 것인가...)
	//FD_READ 혹은 상대가 접속을 끊으면 발생하는 이벤트이면 감지해라..
	WSAEventSelect(userInfo->hSocket, hRecvEvent, FD_READ | FD_CLOSE);


	while (true) {
		// 이 함수는 블록킹 함수이다.(scanf)
		// WSAEventSelect << 함수에서 설정한 이벤트가 발생하면 블록킹이 풀린다.
		//client에서 send를 보내서 받으면 블로킹이 풀린다.
		WSAWaitForMultipleEvents(1, &hRecvEvent, false, WSA_INFINITE, false);// 다중 이벤트가 뜨는 것을 기다려라
		// 블록킹을 푼 이벤트가 어떤 이벤트인지 확인... 
		WSANETWORKEVENTS WhatEvent;
		WSAEnumNetworkEvents(userInfo->hSocket, hRecvEvent, &WhatEvent);
		//MessageBox(hWnd, L"WSAEventSelect", L"WSAEventSelect", MB_OK);


		int index = 0;
		char recvBuffer[4096] = { 0, };
		int  RecivSize;
		// 데이터를 보내면서 close도 날라올 수 있기 때문에 읽은 데이터만 분리하는 과정
		if ((WhatEvent.lNetworkEvents & FD_READ) == FD_READ) {
			//MessageBox(hWnd, L"FD_READ", L"FD_READ", MB_OK);
			while (true)
			{	//recv : 4byte 보냈음에도 4byte 모두 수신한다는 보장이 없다. 
				//때문에 while을 통해서 남은 사이즈가 0이 나올때까지 계속 수신하도록 루프문 걸어준것
				// 실제로 읽은 데이터의 크기를 받는다.(받는 데이터가 없어지면 else 구문으로 빠진다.)
				//0번지부터 데이터 수신했다가 전부 못받으면 인덱스부터 받게하기 위해서 &로 인자 전달해주는 구조
				RecivSize = recv(userInfo->hSocket, &recvBuffer[index], 4096, 0); // 4096은 버퍼의 크기만 알려주는것
				if (RecivSize > 0) {
					index += RecivSize;
				}
				else { break; }
			}
		}

		//MouseData mouseData;
		int pos = 0;
		short mx, my;
		int data;
		short x, y, z;
		while (index) {
			int formatNum = *((int*)(recvBuffer + pos));	// 1. send 한번으로 받을 수도 있고
														// 2. send 한번 이상으로 받을 수도 있다.
			pos += sizeof(int);

			switch (formatNum) {
			case FORMAT_ID1:
			{
				mx = ((FORMAT1*)(recvBuffer + pos))->mx;//강제적으로 형을 변환시켜서 사용한다(고급문법)
				my = ((FORMAT1*)(recvBuffer + pos))->my;
				pos += sizeof(FORMAT1);
				index -= sizeof(int) + sizeof(FORMAT1);
				
				CString strPoint;
				strPoint.Format(L"mx : %d my : %d", mx, my);
				SetWindowText(hwndButton1, strPoint);

			}break;
			case FORMAT_ID2:
			{
				data = ((FORMAT2*)(recvBuffer + pos))->data;

				pos += sizeof(FORMAT2);
				index -= sizeof(int) + sizeof(FORMAT2);

				CString strSum;

				strSum.Format(L"sum : %d ", data);
				SetWindowText(hwndButton2, strSum);
			}break;
			case FORMAT_ID3:
			{
				
				x = ((FORMAT3*)(recvBuffer + pos))->x;//강제적으로 형을 변환시켜서 사용한다(고급문법)
				y = ((FORMAT3*)(recvBuffer + pos))->y;
				z = ((FORMAT3*)(recvBuffer + pos))->z;
				pos += sizeof(FORMAT3);
				index -= sizeof(int) + sizeof(FORMAT3);

				CString strMultiple;
				strMultiple.Format(L"x : %d y : %d z : %d", x, y, z);
				SetWindowText(hwndButton3, strMultiple);
			}break;
			case FORMAT_ID4:
			{
				char pAry[10] = { 0, };
				strcpy(pAry, ((FORMAT4*)(recvBuffer + pos))->ar);
				//pAry = ((FORMAT4*)(recvBuffer + pos))->ar;//강제적으로 형을 변환시켜서 사용한다(고급문법)
				
				pos += sizeof(FORMAT4);
				index -= sizeof(int) + sizeof(FORMAT4);

				CString strAllButton;
				strAllButton = pAry;
				SetWindowText(hwndButton4, strAllButton);
			}break;
			}
		}


		if ((WhatEvent.lNetworkEvents & FD_CLOSE) == FD_CLOSE)
		{
			closesocket(userInfo->hSocket);// 클라이언트 소켓 제거
			//메모리 해제 코드.
			delete userInfo;
			//접속자 수를 한명 감소시킨다.
			MessageBox(hWnd, L"클라이언트 접속종료", L"클라이언트 접속종료", MB_OK);
			break;
		}
	}
	_endthreadex(0);
	return true;
}
// SERVER 프로그램
unsigned _stdcall ConnectThread(void* pArg) {
	//OutputDebugString();
	SetWindowText(hWnd, L"Start");

	// 네트워크 관련 초기화 작업
	// 0x0202
	// ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
	// (1,2,3,4) = 0x01020304 (네트워크버전을 알리도록 설정해줌)

	WORD version = MAKEWORD(2, 2); // 첫번째 인자 상위 ,두번째 인자 하위바이트로 올려주는 역할
	WSADATA wsaData;
	int err;
	//네트워크와 관련된 (함수)범용 동적 라이브러리를 로드.
	err = WSAStartup(version, &wsaData);
	if (err) { // 검수작업(만약 안들어왔다면 프로그램 종료시킴)
		SetWindowText(hWnd, L"Error : WSAStartup Error");
		return false;
	}
	// 예) 0x3456;-> LOBYTE << 56뽑아주는 역할
	// 하위, 상위 바이트 2인지 확인하는작업
	// wsaData.wVersion != 0x0202
	if (LOBYTE(wsaData.wVersion) != 2
		|| HIBYTE(wsaData.wVersion) != 2)
	{
		SetWindowText(hWnd, L"Error : LOBYTE");
		WSACleanup(); // 버젼이 틀리면 긁어온 메모리(라이브러리)를 제거하는 역할
		return false;
	}
	SetWindowText(hWnd, L"OK !!");

	// 소켓 생성.
	// TCP(데이타 손실 없음), UDP(손실있을 수 있음)
	MainSocket = socket(AF_INET, SOCK_STREAM, 0); // 실패시 -1 반환
	if (MainSocket == INVALID_SOCKET) {
		SetWindowText(hWnd, L"Error : socket create");
		WSACleanup(); // 버젼이 틀리면 긁어온 메모리(라이브러리)를 제거하는 역할
		return false;
	}

	// 윈도우에게 현재 시스템의 통신 상태를 등록한다.
	struct sockaddr_in sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);//자기 자신이 가지고 있는 통신 IP를 가져온다.
	sa.sin_port = htons(3000);

	// 바인딩.
	err = bind(MainSocket, (struct sockaddr*)&sa, sizeof(struct sockaddr));// 소켓 번호

	if (err == SOCKET_ERROR) {
		SetWindowText(hWnd, L"Error : Binds Error");
		return false;
	}

	// 대기 인원을 설정한다.
	err = listen(MainSocket, 10);

	if (err == SOCKET_ERROR) {
		SetWindowText(hWnd, L"Error : listen Error");
		return false;
	}


	SetWindowText(hWnd, L"OK !!");
	static int num = 0;

	while (LoopConnectThread) {
		//각 클라이언트 소켓 정보 할당을 위해 초기화한다.
		ZeroMemory(&sa, sizeof(sa));
		int len = sizeof(sa);

		// 클라이언트의 접속을 기다린다.
		// 블록킹 함수이다. scanf()함수와 같다.
		// 프로그램이 진행하지 않는다.
		// 누군가가 접속하면 풀린다.
		// 통신할 수 있는 소켓번호 반환
		//SetWindowText(hWnd, L"100");
		//SetWindowText(hWnd, L"200");
		SOCKET hSocket = accept(MainSocket, (struct sockaddr*)&sa, &len);
		// 유저 한명이 생성이 되고 있다.


		USERINFO* userInfo = new USERINFO;
		userInfo->hSocket = hSocket;
		userInfo->id = num;

		num++;
		CString s;
		s.Format(L"%d", num);
		SetWindowText(hWnd, s.GetBuffer());

		UINT threadID;
		_beginthreadex(NULL, 0, ClientThread, userInfo, 0, &threadID);
	}

	_endthreadex(0);
	return true;
}

void DataInit() {
	UINT threadID;
	_beginthreadex(NULL, 0, ConnectThread, NULL, 0, &threadID);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY210129SERVERSYSPROJECT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY210129SERVERSYSPROJECT));

	MSG msg;

	// 기본 메시지 루프입니다:
	DataInit();

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY210129SERVERSYSPROJECT));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY210129SERVERSYSPROJECT);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		0, 0, 400, 300, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: // 윈도우가 생성될 때 발생하는 메세지( 초기화가 필요한 프로그램 )
	{
		hwndButton1 = CreateWindowW(TEXT("BUTTON"), TEXT("BT1"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 20, 200, 40, hWnd, (HMENU)BTN1, hInst, NULL);
		hwndButton2 = CreateWindowW(TEXT("BUTTON"), TEXT("BT2"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 80, 200, 40, hWnd, (HMENU)BTN2, hInst, NULL);
		hwndButton3 = CreateWindowW(TEXT("BUTTON"), TEXT("BT3"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 140, 200, 40, hWnd, (HMENU)BTN3, hInst, NULL);
		hwndButton4 = CreateWindowW(TEXT("BUTTON"), TEXT("BT4"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 200, 200, 40, hWnd, (HMENU)BTN4, hInst, NULL);
	}break;

	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		LoopConnectThread = false;
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



