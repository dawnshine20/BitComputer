// WindowsProject5.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject5.h"
#include <corecrt_math.h>

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT5));

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
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT5);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
    static float ct = 0.0f;
    #define PI 3.14159265
    #define DegreeToRadian(degree)  (((degree) * PI) / 180)
    #define btnNumber 1000
    #define btnNumber1 ((btnNumber) + 1)
    #define TIMERID 100
    #define TIMERID1 ((TIMERID) + 1)

    switch (message)
    {
    case WM_CREATE:
    {
        HWND hwndButton1, hwndButton2;
        hwndButton1 =
            CreateWindowW(TEXT("BUTTON"), TEXT("회전"),       
                WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 10, 50, 30,
                hWnd, (HMENU)btnNumber, hInst, NULL);
        //HWND hwndButton2  전역변수화
        hwndButton2 =
            CreateWindowW(TEXT("BUTTON"), TEXT("정지"),      
                WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 60, 50, 40,
                hWnd, (HMENU)btnNumber1, hInst, NULL);
    }
    case WM_TIMER:
    {
        switch (wParam)
        {
        case TIMERID:
        {
            ct += DegreeToRadian(0.3);
            InvalidateRect(hWnd, NULL, true);
        }
        break;
        
        }
    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case btnNumber: //wParam==1000 - ID가 1000인 버튼0
        {
            HANDLE hTimer = (HANDLE)SetTimer(
                hWnd,
                TIMERID,      //Timer ID
                32,   //1000ms= 1s 한번 메세지 WM_TIMER 발생
                NULL    // 속성
            );
        }
        break;
        case btnNumber1: //wParam==1001 - ID가 1001인 버튼1
        {
            KillTimer(hWnd, TIMERID);// 핸들, ID
        }
        break;
        }
    }
    break;


    case WM_PAINT:
        {

            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            RECT rc;
            GetClientRect(hWnd, &rc);
            

            int setPointNumber = 6;

            POINT* pts = new POINT[setPointNumber];
            const int count = setPointNumber;
            const int radius = 150;
            const int startDegree = 360 - 90;
            
            const float dx = rc.right / 2.0f;             // client 창의 x 중심
            const float dy = rc.bottom / 2.0f;            // client 창의 y 중심

            //각도 >> 라디안 공식 (degree * PI / 180)
            pts[0].x = radius * cosf((float)DegreeToRadian(startDegree)) + dx;// x의 startpoint(각도 >> 라디안)
            pts[0].y = radius * sinf((float)DegreeToRadian(startDegree)) + dy; // y의 startpoint(각도 >> 라디안)

            MoveToEx(hdc, pts[0].x, pts[0].y, NULL); // 시작점

            
            for (int i = 0; i < count; i++)
            {
                int degree = (i * ((360 * 2 / 5) ) + startDegree) % 720;
                pts[i].x = radius * cosf((float)(DegreeToRadian(degree))+ct) + dx;
                pts[i].y = radius * sinf((float)(DegreeToRadian(degree))+ct) + dy;
            }
            

            Polyline(hdc, pts, setPointNumber);  // 점의 갯수

            delete[] pts;

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
