// 21_01_27_NetWorkStudy1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "21_01_27_NetWorkStudy1.h"

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

#include <process.h>
#include <atlstr.h>

HWND hWnd;
bool MainThread = true;
bool NewThread = false;
int num = 0;
int ClientCount[10] = { 0, };
int MainLoopingCount = 0;
unsigned __stdcall ClientThread(void* pArg) { // 인수전달 1개 이상일 경우 구조체 사용
    while (true) {
        ClientCount[0]++;
        if (ClientCount[0] == INT_MAX) { // 0x7fffffff
            MessageBox(hWnd, L"", L"", MB_OK);
            ClientCount[0] = 0;
            break;
        }
    }
    _endthreadex(0);// 자기가 돌고있는 스레드를 파괴시킴
    return true;
}
unsigned __stdcall ConnectThread(void* pArg) { // 인수전달 1개 이상일 경우 구조체 사용
    SetWindowText(hWnd, L"Start Main thread ");
    while (MainThread)
    {
        if (NewThread) {
            NewThread = !NewThread;
            
            CString s;
            s.Format(L"%d", num);
            SetWindowText(hWnd, s);
            num++;

            _beginthreadex(NULL, 0, ClientThread, NULL, 0, NULL);
        }
    }
    SetWindowText(hWnd, L"End Main thread ");
    _endthreadex(0);// 자기가 돌고있는 스레드를 파괴시킴
    return true;
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    #pragma region thread 함수설명

    // 1. 세월이 지나서 버젼업이 되고 사용이 안될 때 널 넣음
    // 2. 널조차도 필요한 옵션일떄((EX)널을 넣으면 기본 옵션 버튼이 만들어짐)
    // f1(NULL,) 
/*
    //스레드 생성 함수
    unsigned int _beginthreadex(
        void*           _Security,      // 윈도우에서는 통상적으로 NULL(보안설정하지 않음)
        unsigned        _StackSize,     // 0(기본 10Kbyte 메모리 확보)
        unsigned        _StartAddress,  // 스레드로 작동할 함수 이름.
        void*           _ArgList,       // 인수 전달이 필요할 때
        unsigned        _InitFlag,      // 스레드 대기 시간을 설정(0 넣으면 즉시 실행)
        unsigned*       _ThrdAddr       // Id를 얻는다.
    );
    _beginthreadex(NULL, 0, f1, NULL, 0, &id);
    _endthreadex();
*/
#pragma endregion
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY210127NETWORKSTUDY1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY210127NETWORKSTUDY1));

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    // 기본 메시지 루프입니다:
    //_가 붙어 있으면 윈도우,리눅스 등등 다른 운영체제에서도 사용 가능
    // ex가 붙어있는 함수는 이전버전보다 업그레이드 된 함수
    _beginthreadex(NULL, 0, ConnectThread, NULL, 0, NULL);
    //_beginthread(deprecate된 함수_결점이 발견되었음)
    
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))// non blocking
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            MainLoopingCount++;
            InvalidateRect(hWnd, NULL, false);
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY210127NETWORKSTUDY1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY210127NETWORKSTUDY1);
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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
    case WM_RBUTTONDOWN:
    {
        NewThread = true;
    }break;
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
            
            CString s;
            s.Format(L"%d %d", ClientCount[0], MainLoopingCount);
            TextOut(hdc, 0, 0, s.GetBuffer(), s.GetLength());

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        MainThread = false;
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
