// WindowsProject4.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject4.h"
#include <corecrt_math.h>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
int Count = 0;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MyAbout(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT4));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT4);
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
#define BTN1 1000
#define BTN2 ((BTN1) + 1)
HWND hwndButton1, hwndButton2;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:     //윈도우 생성시 발생되는 message
    {   //초기화시 사용
        //MessageBox(hWnd, TEXT("윈도우 생성"), TEXT("알림"), MB_OK);
        /*
        //HWND hwndButton1  전역변수화
        hwndButton =  //생략가능하지만 나중에 버튼의 설정을 하기위해 사용
            CreateWindowW(          //창 생성
                TEXT("BUTTON"),     //컨트롤의 종류
                TEXT("버튼"),       //캡션
                WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //버튼의 모양 설정
                10, 10, 100, 50,    //버튼 위치와 사이즈
                hWnd,               //부모 윈도우 설정
                (HMENU)1000,        //버튼의 고유ID 설정, HMENU-메뉴처럼 WM_COMMAN 사용
                                    // 이거 클릭시  WM_COMMAND 발생
                                    // wParam에 1000입력
                hInst,              //인스턴스 핸들이 저장된 전역변수
                NULL
            );
        */
        Count = 0;
        // HWND hwndButton1  전역변수화
        hwndButton1 =
            CreateWindowW(TEXT("BUTTON"), TEXT("회전"),       //캡션
                WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 10, 50, 30,
                hWnd, (HMENU)1000, hInst, NULL);
        //HWND hwndButton2  전역변수화
        hwndButton2 =
            CreateWindowW(TEXT("BUTTON"), TEXT("정지"),       //캡션
                WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                10, 60, 50, 40,
                hWnd, (HMENU)2000, hInst, NULL);
        //많은 버튼생성시 반복문 사용가능, TEXT, 좌표, ID등을 배열에 저장하여 사용가능
    }break;
    case WM_TIMER:
    {
        switch (wParam)
        {
        case 99:
        {
            InvalidateRect(hWnd, NULL, true);
            //f5를 통해서 디버깅 시 출력창 출력
        }
        break;
        case 88:
        {
            WCHAR str[32] = { 0, };
            static int count = 0;
            wsprintf(str, TEXT("timer2 개수%d \n"), count++);
            OutputDebugString(str);
            //f5를 통해서 디버깅 시 출력창 출력
        }
        break;
        }
    }
    break;
    case WM_COMMAND:
    {
        switch (wParam)
        {
        case 1000: //wParam==1000 - ID가 1000인 버튼1
        {
            //ShowWindow(hwndButton1, FALSE);    // hwndButton1로 저장된 윈도우 숨기기
            //EnableWindow(hwndButton1, false);   //누를 수 없게 비활성화
            //SetWindowText(hwndButton1, TEXT("고양이"));  //내용 변경
            HANDLE hTimer = (HANDLE)SetTimer(
                hWnd,
                99,      //Timer ID
                1000,   //1000ms= 1s 한번 메세지 WM_TIMER 발생
                NULL    // 속성
            );
            HANDLE hTime1r1 = (HANDLE)SetTimer(hWnd, 99, 50, NULL);
            //wParam ==99
            HANDLE hTime1r2 = (HANDLE)SetTimer(hWnd, 88, 700, NULL);
            //wParam ==88
        }
        break;
        case 2000: //wParam==2000 - ID가 2000인 버튼2
        {
            //ShowWindow(hwndButton1, TRUE);    // hwndButton1로 저장된 윈도우 숨기기
            //EnableWindow(hwndButton1, true);    //활성화
            //SetWindowText(hwndButton2, TEXT("활"));  //내용 변경
            KillTimer(hWnd, 99);// 핸들, ID
        }
        break;
        }
    }
    break;
    #define ANGULAR 5
    #define _PI 3.141592f
    
    case WM_PAINT:
    {
    #pragma region 조계성 draw
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        //RECT rc;
        //GetClientRect(hWnd, &rc);
        //int CenterclientX = rc.right / 2;             // client 창의 x 중심
        //int CenterclientY = rc.bottom / 2;            // client 창의 y 중심
        //                                              // 오각형의 무게중심 좌표
        //int Radius = 100;                               // 정오각형에 외접하는 원의 반지름 정의 즉, 오각형의 크기를 지정
        //float angle = (2.0f * _PI) / ANGULAR;      // 무게중심을 기준으로 각의 크기 마다 변하는 각도 라디안 계산 ex) 정오각형 : 72도
        //int StartDrawX = CenterclientX + sinf(Count) * Radius;
        //int StartDrawY = CenterclientY + cosf(Count) * Radius;        // 정오각형 아래 꼭지점을 시작으로 정의
        //MoveToEx(hdc, StartDrawX, StartDrawY, NULL); // 정오각형 시작점
        //int pointX, pointY;                             // 각 꼭지점들의 좌표를 변수로 선언
        //for (int i = 0; i < ANGULAR; i++)                     // 각의 개수만큼 반복
        //{
        //    pointX = CenterclientX + sinf(angle * (i + 1) + Count) * Radius; // angle의 값을 변화 시켜주면서 sinf를 통해 x 좌표
        //    pointY = CenterclientY + cosf(angle * (i + 1) + Count) * Radius; // angle의 값을 변화 시켜주면서 cosf를 통해 y 좌표
        //    LineTo(hdc, pointX, pointY);                            // 구한 꼭지점의 x,y좌표를 찍어 도형을 그림
        //}
        //Count += 30;
#pragma endregion

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        
        POINT pts[] = {
            {60,10}, {160,10}, {210,60}, {210,160}, {160,210},
            {60,210}, {10,160}, {10,60}, {60,10}
        };
        Polyline(hdc, pts, 9);  // 점의 갯수

        //1. sinf(각도 >> 하는 함수 라디안)
        //2. sinf(라디안)

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
