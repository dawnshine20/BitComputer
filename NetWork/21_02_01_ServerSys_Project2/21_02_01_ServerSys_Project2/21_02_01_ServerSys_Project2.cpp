// 21_01_28_ServerSys1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#pragma warning(disable:4996)

#include <winsock2.h>
#include <process.h>
#include <atlstr.h>
#include "framework.h"
#include "21_02_01_ServerSys_Project2.h"
#include <list>
using namespace std;

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

//SOCKET hSocket[100] = { 0, };
struct USERINFO {
	SOCKET hSocket;
	int id;
};
int hSocketNum = 0;

#define FORMAT_ID1 1
struct FORMAT1 {
	short mx;
	short my;
};
struct FORMAT2 {
	short id;
	short mx;
	short my;
};



list<USERINFO*> li_User;
list<USERINFO*>::iterator userIt;
unsigned _stdcall ClientThread(void* pArg) {
	USERINFO* userInfo = (USERINFO*)pArg;
	li_User.push_back(userInfo);

	static int totalClientNum;
	totalClientNum++;

	WSAEVENT hRecvEvent = WSACreateEvent();

	WSAEventSelect(userInfo->hSocket, hRecvEvent, FD_READ | FD_CLOSE);
	
	//hSocket[hSocketNum++] = userInfo->hSocket; // 클라이언트 소켓번호 기억해두기
	
	while (true) {

		WSAWaitForMultipleEvents(1, &hRecvEvent, false, WSA_INFINITE, false);
		
		WSANETWORKEVENTS WhatEvent;
		WSAEnumNetworkEvents(userInfo->hSocket, hRecvEvent, &WhatEvent);

		int index = 0;
		char recvBuffer[4096] = { 0, };
		int  RecivSize;
		
		
		if ((WhatEvent.lNetworkEvents & FD_READ) == FD_READ) {
			while (true)
			{	
				RecivSize = recv(userInfo->hSocket, &recvBuffer[index], 4096, 0); 
				if (RecivSize > 0) {
					index += RecivSize;
				}
				else { break; }
			}
		}

		//MouseData
		int pos = 0;
		short mx, my;
		while (index) {
			int formatNum = *((int*)(recvBuffer + pos));	
														
			pos += sizeof(int);

			switch (formatNum) {
			case FORMAT_ID1:
			{
				mx = ((FORMAT1*)(recvBuffer + pos))->mx;
				my = ((FORMAT1*)(recvBuffer + pos))->my;
				pos += sizeof(FORMAT1);
				index -= sizeof(int) + sizeof(FORMAT1);

				CString strPoint;
				strPoint.Format(L"TotalClientNum : %d mx : %d my : %d", totalClientNum, mx, my);
				SetWindowText(hWnd, strPoint);


				const char sendBuffer[512] = { 0, };
				
				int formatNum = 2;
				*((int*)sendBuffer + 0) = formatNum;
				((FORMAT2*)(sendBuffer + 4))->id = userInfo->id;
				((FORMAT2*)(sendBuffer + 4))->mx = mx;
				((FORMAT2*)(sendBuffer + 4))->my = my;

				
				//기억해둔 소켓 번호에 FORMAT2에 대한 정보 모두 송신
				list<USERINFO*>::iterator endIt = li_User.end();
				for (userIt = li_User.begin(); userIt != endIt; ++userIt)
				{
					send((*userIt)->hSocket, sendBuffer, sizeof(int) + sizeof(FORMAT2), 0);
				}

			}break;
			}
		}

		list<USERINFO*>::iterator endIt = li_User.end();
		if ((WhatEvent.lNetworkEvents & FD_CLOSE) == FD_CLOSE)
		{
			for (userIt = li_User.begin(); userIt != endIt;)
			{		
				if ((*userIt)->hSocket == userInfo->hSocket) {
					
					closesocket(userInfo->hSocket);// 해당 소켓 제거
					delete(*userIt); // 리스트의 힙영역 메모리 해제
					userIt = li_User.erase(userIt); // 리스트가 가지고 있는 해당  주소 제거
					totalClientNum--;
					MessageBox(hWnd, L"리스트 주소 삭제", L"리스트 주소 삭제", MB_OK);
				}
				else {
					++userIt;
				}
			}
			MessageBox(hWnd, L"클라이언트 접속종료", L"클라이언트 접속종료", MB_OK);
			break;
		}
	}
	_endthreadex(0);
	return true;
}

unsigned _stdcall ConnectThread(void* pArg) {
	SetWindowText(hWnd, L"Start");

	WORD version = MAKEWORD(2, 2);
	WSADATA wsaData;
	int err;
	err = WSAStartup(version, &wsaData);
	if (err) { 
		SetWindowText(hWnd, L"Error : WSAStartup Error");
		return false;
	}
	
	if (LOBYTE(wsaData.wVersion) != 2
		|| HIBYTE(wsaData.wVersion) != 2)
	{
		SetWindowText(hWnd, L"Error : LOBYTE");
		WSACleanup(); 
		return false;
	}
	SetWindowText(hWnd, L"OK !!");

	MainSocket = socket(AF_INET, SOCK_STREAM, 0); 
	if (MainSocket == INVALID_SOCKET) {
		SetWindowText(hWnd, L"Error : socket create");
		WSACleanup(); 
		return false;
	}

	struct sockaddr_in sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(3000);

	err = bind(MainSocket, (struct sockaddr*)&sa, sizeof(struct sockaddr));
	if (err == SOCKET_ERROR) {
		SetWindowText(hWnd, L"Error : Binds Error");
		return false;
	}

	err = listen(MainSocket, 10);
	if (err == SOCKET_ERROR) {
		SetWindowText(hWnd, L"Error : listen Error");
		return false;
	}

	static int clientNum = 0;
	SetWindowText(hWnd, L"OK !!");
	

	while (LoopConnectThread) {
		ZeroMemory(&sa, sizeof(sa));
		int len = sizeof(sa);

		SOCKET hSocket = accept(MainSocket, (struct sockaddr*)&sa, &len);

		USERINFO* userInfo = new USERINFO;
		userInfo->hSocket = hSocket;
		userInfo->id = clientNum++;

		CString s;
		s.Format(L"%d", clientNum);
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
	LoadStringW(hInstance, IDC_MY210201SERVERSYSPROJECT2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY210201SERVERSYSPROJECT2));

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



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY210201SERVERSYSPROJECT2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY210201SERVERSYSPROJECT2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

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



