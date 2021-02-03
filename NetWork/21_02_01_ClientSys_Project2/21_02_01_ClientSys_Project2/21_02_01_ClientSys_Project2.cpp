// 21_01_28_ClientSys1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#pragma warning(disable:4996)

#include <winsock2.h>
#include <process.h>
#include<atlstr.h>
#include "framework.h"
#include "21_02_01_ClientSys_Project2.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

#define WM_USER_SOCKET ((WM_USER)+1) // 윈도우에서 사용하고 있는 번호 알려줌
HWND hWnd;
SOCKET hClientSocket = 0; // I/O 상황을 체크할 소켓
WORD mx, my, id;

struct FORMAT1 {
    short mx;
    short my;
};
struct FORMAT2 {
    short id;
    short mx;
    short my;
};


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);



bool InitData() {
    SetWindowText(hWnd, L"Start");
    WORD version = MAKEWORD(2, 2); 
    WSADATA wsaData;
    
    int err;
    err = WSAStartup(version, &wsaData);
    if (err) { // 검수작업(만약 안들어왔다면 프로그램 종료시킴)
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

    //소켓 생성
    hClientSocket = socket(AF_INET, SOCK_STREAM, 0); 
    if (hClientSocket == INVALID_SOCKET) {
        SetWindowText(hWnd, L"Error : socket create");
        WSACleanup(); 
        return false;
    }


    WSAAsyncSelect(hClientSocket, hWnd, WM_USER_SOCKET, FD_CONNECT);
    struct sockaddr_in sa;
    ZeroMemory(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("192.168.1.111");
    sa.sin_port = htons(3000);


    err = connect(hClientSocket, (LPSOCKADDR)&sa, sizeof(sa));
    if (err == SOCKET_ERROR) {
        int ErrCode = WSAGetLastError();
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
    LoadStringW(hInstance, IDC_MY210201CLIENTSYSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY210201CLIENTSYSPROJECT2));

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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY210201CLIENTSYSPROJECT2));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY210201CLIENTSYSPROJECT2);
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


//FORMAT1 format1;
int  RecivSize;
int index = 0;
char recvBuffer[4096] = { 0, };
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    
    case WM_USER_SOCKET:
    {
        UINT event = WSAGETSELECTEVENT(lParam);
        switch (event) {
        case FD_CONNECT:
            WSAAsyncSelect(hClientSocket, hWnd, WM_USER_SOCKET, FD_READ);
            break;
        case FD_READ:
            while (true)
            {
                RecivSize = recv(hClientSocket, &recvBuffer[index], 4096, 0);
                if (RecivSize > 0) {
                    index += RecivSize;
                }
                else { break; }
            }

            int pos = 0;
            while (index) {
                int formatNum = *((int*)(recvBuffer + pos));	
                                                           
                pos += sizeof(int);

                switch (formatNum) {
                case 2:
                {
                    id = ((FORMAT2*)(recvBuffer + pos))->id;
                    mx = ((FORMAT2*)(recvBuffer + pos))->mx;
                    my = ((FORMAT2*)(recvBuffer + pos))->my;
                    
                    pos += sizeof(FORMAT2);
                    index -= sizeof(int) + sizeof(FORMAT2);

                    CString strPoint;
                    strPoint.Format(L"client : %d mx : %d my : %d", id, mx, my);
                    SetWindowText(hWnd, strPoint);
                }break;

                }
            }

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
        const char sendBuffer[512] = { 0, };
        int formatNum = 1;
        *((int*)sendBuffer + 0) = formatNum;

        ((FORMAT1*)(sendBuffer + 4))->mx = mx;
        ((FORMAT1*)(sendBuffer + 4))->my = my;
        send(hClientSocket, sendBuffer, 4 + sizeof(FORMAT1), 0);

    }break;
    case WM_RBUTTONDOWN:
    {
        //우클릭을 2번 누를 경우를 방지하기 위해 사용
        if (hClientSocket != 0)
        {
            // 접속 종료 시도
            closesocket(hClientSocket);
            hClientSocket = 0;
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