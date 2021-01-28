// 21_01_28_ServerSys1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#pragma warning(disable:4996)

#include <winsock2.h>
#include <process.h>
#include <atlstr.h>
#include "framework.h"
#include "21_01_28_ServerSys1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
// SERVER 전역변수
HWND hWnd;
bool LoopConnectThread = true;
SOCKET MainSocket;
SOCKET hSocket; // client 소켓 핸들
// SERVER 프로그램
unsigned _stdcall ClientThread(void* pArg) {
	//MessageBox(hWnd,L"ClientThread", L"ClientThread", MB_OK);

	// 이벤트를 관리할 이벤트 핸들 생성
	WSAEVENT hRecvEvent = WSACreateEvent();
	//감지할 이벤트를 설정한다.(어떤 이벤트를 설정 할 것인가...)
	//FD_READ 혹은 상대가 접속을 끊으면 발생하는 이벤트이면 감지해라..
	WSAEventSelect(hSocket, hRecvEvent, FD_READ | FD_CLOSE);
		
		
	while (true) {
		// 이 함수는 블록킹 함수이다.(scanf)
		// WSAEventSelect << 함수에서 설정한 이벤트가 발생하면 블록킹이 풀린다.
		//client에서 send를 보내서 받으면 블로킹이 풀린다.
		WSAWaitForMultipleEvents(1, &hRecvEvent, false, WSA_INFINITE, false);// 다중 이벤트가 뜨는 것을 기다려라
		// 블록킹을 푼 이벤트가 어떤 이벤트인지 확인... 
		WSANETWORKEVENTS WhatEvent;
		WSAEnumNetworkEvents(hSocket, hRecvEvent, &WhatEvent);
		//MessageBox(hWnd, L"WSAEventSelect", L"WSAEventSelect", MB_OK);
		
		char recvBuffer[4096] = { 0, };

		// 데이터를 보내면서 close도 날라올 수 있기 때문에 읽은 데이터만 분리하는 과정
		if ((WhatEvent.lNetworkEvents & FD_READ) == FD_READ) { 
			//MessageBox(hWnd, L"FD_READ", L"FD_READ", MB_OK);
			
			recv(hSocket, recvBuffer, 4096,0); // 4096은 버퍼의 크기만 알려주는것
		}
		struct MouseData {
			short mx;
			short my;
		};
		//MouseData mouseData;
		// 데이타를 가공한다.
		short mx = ((MouseData*)recvBuffer)->mx;//강제적으로 형을 변환시켜서 사용한다(고급문법)
		short my = ((MouseData*)recvBuffer)->my;

		CString s;
		s.Format(L"mx : %d my : %d", mx, my);
		SetWindowText(hWnd, s);
		struct PACKDATA {
			short sum;
		};
		PACKDATA packData;
		packData.sum = mx + my;

		char sendBuffer[512] = { 0, }; // 마이크로소프트 권장 사양
		((PACKDATA*)sendBuffer)->sum = packData.sum;
		
		send(hSocket, sendBuffer, 2, 0);// 던지려고하는 메모리의 시작 주소, 2byte
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
		ZeroMemory(&sa, sizeof(sa));
		int len = sizeof(sa);

		// 클라이언트의 접속을 기다린다.
		// 블록킹 함수이다. scanf()함수와 같다.
		// 프로그램이 진행하지 않는다.
		// 누군가가 접속하면 풀린다.
		// 통신할 수 있는 소켓번호 반환
		//SetWindowText(hWnd, L"100");
		//SetWindowText(hWnd, L"200");
		hSocket = accept(MainSocket, (struct sockaddr*)&sa, &len);
		num++;
		CString s;
		s.Format(L"%d", num);
		SetWindowText(hWnd, s.GetBuffer());

		UINT threadID;
		_beginthreadex(NULL, 0, ClientThread, NULL, 0, &threadID);
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
	LoadStringW(hInstance, IDC_MY210128SERVERSYS1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY210128SERVERSYS1));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY210128SERVERSYS1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY210128SERVERSYS1);
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
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
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

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



