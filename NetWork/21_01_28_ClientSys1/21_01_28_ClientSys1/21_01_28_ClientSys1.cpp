﻿// 21_01_28_ClientSys1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#pragma warning(disable:4996)

#include <winsock2.h>
#include <process.h>
#include<atlstr.h>
#include "framework.h"
#include "21_01_28_ClientSys1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

HWND hWnd;
SOCKET ClientSocket = 0;
WORD mx, my;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

// 0X0401
#define WM_USER_SOCKET ((WM_USER)+1) // 윈도우에서 사용하고 있는 번호 알려줌

bool InitData() {
    SetWindowText(hWnd, L"Start");
    WORD version = MAKEWORD(2, 2); // 첫번째인자 상위 ,부번째인자 하위바이트로 올려주는 역할
    WSADATA wsaData;
    //네트워크와 관련된 (함수)범용 동적 라이브러리를 로드.
    int err;
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

    //소켓 생성
    ClientSocket = socket(AF_INET, SOCK_STREAM, 0); // 실패시 -1 반환
    if (ClientSocket == INVALID_SOCKET) {
        SetWindowText(hWnd, L"Error : socket create");
        WSACleanup(); // 버젼이 틀리면 긁어온 메모리(라이브러리)를 제거하는 역할
        return false;
    }

    
    // WS; windowSocketAsyncro//윈도우 소켓 비동기
    // 어떤 소켓이랑 어떤 윈도우가 통신을 하는지 알립니다.
    // 이벤트 : 하드웨어적인 사건이 일어났을 때.
    // 메세지 : 사건이 일어났을 때 OS가 통지를 하는 것(이벤트가 일어나면 메세지로 알려줌)
    // 해석 : 접속 이벤트가 발생하면 WM_USER_SOCKET이라고 하는 메세지를 발생시키세요.
    WSAAsyncSelect(ClientSocket, hWnd, WM_USER_SOCKET, FD_CONNECT);
    struct sockaddr_in sa;
    ZeroMemory(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("192.168.1.111");//자기 자신이 가지고 있는 통신 IP를 가져온다.
    sa.sin_port = htons(3000);

    
    err = connect(ClientSocket,(LPSOCKADDR)&sa, sizeof(sa));
    if (err == SOCKET_ERROR) {
        int ErrCode = WSAGetLastError();//가장 최근에 일어난 코드 번호를 달라고 요청
        if (ErrCode != WSAEWOULDBLOCK) {
            SetWindowText(hWnd, L"Error : connect Error");
            return false;
        }
    }
    return true;
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
    LoadStringW(hInstance, IDC_MY210128CLIENTSYS1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY210128CLIENTSYS1));

    MSG msg;
    InitData();
    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY210128CLIENTSYS1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY210128CLIENTSYS1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

#pragma region 서버 측으로 보내고자 하는 여러 종류의 포맷형식
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
    long ar[10];
};
#pragma endregion

//FORMAT1 format1;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_USER_SOCKET:
    {
        // FD_READ: 데이터 수신이 가능하면 윈도우 메시지를 발생시킨다. 
        // FD_WRITE: 데이터 송신이 가능하면 윈도우 메시지를 발생시킨다. 
        // FD_CLOSE: 상대가 접속을 종료하면 윈도우 메시지를 발생시킨다. 
        // FD_CONNECT: 접속이 완료되면 윈도우 메시지를 발생시킨다. 
        // FD_OOB: OOB 데이터가 도착하면 윈도우 메시지를 발생시킨다.

        UINT event = WSAGETSELECTEVENT(lParam);//현재 네트워크에서 발생한 이벤트의 종류를 알려줌
        switch (event) {
        case FD_CONNECT:
            WSAAsyncSelect(ClientSocket, hWnd, WM_USER_SOCKET, FD_READ);
            break;
        case FD_READ:
            char recvBuffer[4096] = { 0, };
            recv(ClientSocket, recvBuffer, 4096, 0); // 4096은 버퍼의 크기만 알려주는것
            short sum = (short)*(short*)recvBuffer;

            CString s;
            s.Format(L"sum : %d", sum);
            SetWindowText(hWnd, s);

            break;
        }
    }break;
    case WM_MOUSEMOVE:
    {
        mx = LOWORD(lParam);
        my = HIWORD(lParam);

        CString s;
        s.Format(L"mx:%d my:%d ", mx, my);
        SetWindowText(hWnd, s.GetBuffer());
    }break;
    
    case WM_LBUTTONDOWN:
    {
        //int a; // 0x12 34 56 78
        // 4096 byte
        // 그림파일 보낼때는 FTP 파일 통신 해야하는 규모
        const char sendBuffer[512] = { 0, }; // 마이크로소프트 권장 사양
        int formatNum = 1234;
        *((int*)sendBuffer + 0) = formatNum;

        ((FORMAT1*)(sendBuffer + 4))->mx = mx;//강제적으로 형을 변환시켜서 사용한다(고급문법)
        ((FORMAT1*)(sendBuffer + 4))->my = my;
        send(ClientSocket, sendBuffer, 4 + sizeof(FORMAT1), 0);// 던지려고하는 메모리의 시작 주소
    }break;
    case WM_RBUTTONDOWN:
    {
        //우클릭을 2번 누를 경우를 방지하기 위해 사용
        if (ClientSocket != 0)
        {
            // 접속 종료 시도
            closesocket(ClientSocket);
            ClientSocket = 0;
        }
        
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
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

