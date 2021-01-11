// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
// 콘솔창 사용하기 위해 사용하는 코드
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include "framework.h"      //<> <=표준헤더파일,  ""<=프로젝트에서 만든것
#include "WindowsProject1.h"

#include <stdio.h>

#define MAX_LOADSTRING 100

// 전역 변수:
// handle은 고유 식별 번호(ex. 주민등록번호)
HINSTANCE hInst;                                // 현재 인스턴스입니다. // h로 출발하는 타입 : h:handle 약어
//WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szTitle[MAX_LOADSTRING] = TEXT("호랑이");                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance); // 코드의 가독성을 위해 구조체로 자료형 이름 변경시킴
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); //콜백함수(어셈블러로 보면 개인이 함수 처리하도록 1줄 더 추가)
INT_PTR CALLBACK    MyAbout(HWND, UINT, WPARAM, LPARAM);

//API == 함수 == window 함수
//진입점 : 콜백함수란? OS가 호출하는 함수(자기가 어떤 조건이 되면 스스로 호출함)
// cntl + f10 : 원하는 위치까지 디버깅 진행
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 운영체제가 핸들 인스턴스 전달(운영체제가 )
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    //LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); // 윈도우 등록

    /*int result = MessageBox(NULL, _T("포맷하시겠습니까?"), _T("알림1"), MB_OKCANCEL);
    MessageBox(NULL, (result == IDOK) ? _T("Ok") : _T("Ng"), _T("알림1"), MB_OKCANCEL);*/
    
    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow)) // 윈도우 생성(--->초기화가 성공한것이 !(아니라면))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

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
ATOM MyRegisterClass(HINSTANCE hInstance) // 윈도우 생성시 필요한 기본 초기값을 설정하는 것
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); // 미리 사이즈를 구해놓아야 최적화에 유리해짐

    wcex.style          = CS_HREDRAW | CS_VREDRAW; // 응용 가능
    wcex.lpfnWndProc    = WndProc; // 윈도우 프로시저 등록하는 코드(응용 안됨)
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance; // 값이 고정되어서 응용될 수 없는 코드
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
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
   int width = GetSystemMetrics(SM_CXSCREEN);
   int height = GetSystemMetrics(SM_CYSCREEN);

   printf("%d %d \n", width, height);
   int num = 8;
   int x = num % 4; 
   int y = num / 4;
   
   //hWnd 전역 변수가 맞다.
   HWND hWnd = CreateWindowW( // 실질적인 윈도우 창을 생성하는 코드
        szWindowClass, 
        szTitle, //_T("호랑이")
        WS_OVERLAPPEDWINDOW,
        //(width/2)- (800/2), (height/2)- (600/2),//CW_USEDEFAULT, 0, // 초기 윈도우가 나타날 좌표
        0+(width/4 * x), 0+(height/3 * y),
        width/4, height/3,//CW_USEDEFAULT, 0, // 윈도우 해상도
        nullptr, nullptr, hInstance, nullptr);
   
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   
   // 메인 윈도우가 부모가 된다.
   //MessageBox(hWnd, _T("무궁화 꽃이 피었습니다."), _T("무궁화 꽃이 피었습니다."), MB_OKCANCEL);

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
    case WM_LBUTTONDOWN: // 마우스 왼쪽 버튼을 눌렀을 때 ...
        printf("test\n");
        break;
    case WM_COMMAND: // 메뉴 기능과 관련된 메세지
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, MyAbout); //About함수 등록 구문
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
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK MyAbout(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
