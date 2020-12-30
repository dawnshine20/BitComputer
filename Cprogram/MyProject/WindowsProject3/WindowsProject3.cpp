// WindowsProject3.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject3.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 전역 변수:
int mx, my;
//HWND hWnd;

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT3));

    MSG msg;

    // 기본 메시지 루프입니다:
    // WM_QUIT를 만나면 False를 반환하여 프로그램을 종료시킨다.(다른 메세지는 True를 반환함)
    // PeekMessage는 메세지가 있던지 없던지 간에 non-Blocking으로 메세지를 기다리지 않고 계속 넘어감(realtime)
    // GetMessage는 메세지가 있으면 처리하는 Blocking으로 메세지를 올 때까지 계속해서 기다림 == scanf와 동일
    // 메세지가 있으면 true 반환 없으면 false 반환
    while (GetMessage(&msg, nullptr, 0, 0)) 
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }


    //리얼타임으로 메세지 처리하는 법
    //bool done = FALSE;
    //while (!done)
    //{
    //      PM_REMOVE : 메세지 불러오고나면 삭제함
    //      인수가 0이나 NULL이 들어갈때는 해석하는게 의미가 많이 없음(무시하는고 코드 짜는 경우가 대부분)
    //    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // PM_REMOVE를 통해서 GetMessage처럼 메세지를 큐에서 제거한다.
    //    {
    //        if (msg.message == WM_QUIT)
    //            done = TRUE;
    //        else
    //            DispatchMessage(&msg);
    //    }
    //    else {
    //        // Invalidate 함수가 사용될 수 있다.
    //        // 실시간 프로그램과 관련된 코드를 작성한다.
    //          WCHAR Str[32];
    //          static int ct = 0;
    //          wsprintf(Str, TEXT("WM_CHAR: %d\n"), ct++);
    //          OutputDebugString(Str);
    //    }
    //}


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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT3);
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

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) // 윈도우 핸들을 얻는 공간
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
   // 운영체제가 윈도우 핸들러 정보를 계속해서 가지고 있기 때문에 지역 변수로 잡아놓고
   // scope를 벗어나도 지속적으로 사용 가능(핸들러 얻어오는 API도 따로 존재한다.)
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      1500, 0, 400, 300, nullptr, nullptr, hInstance, nullptr);

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
    case WM_MOUSEMOVE:
        {
            my = LOWORD(lParam); // lParam & 0x0000ffff; //lowword
            mx = HIWORD(lParam); //(lParam & 0xffff0000) >> 16;//highword

            //WCHAR ar[32] = {};
            //wsprintf(ar, L"%x mx: %d my:%d", lParam, mx, my); // 마우스 좌표를 무조건 lParam에 넣어주게 되어있음 
            ////  y좌표(HiWord) : 0000   /  x좌표(LowWord) : 0000
            //// x좌표를 얻고 싶다면 ? lParam & 00 00 FF FF
            //// Y좌표를 얻고 싶다면 ? lParam & FF FF 00 00 >> 16 bit(2byte)
            //
            //SetWindowText(hWnd, ar);
        RECT rc;
        rc.left = 10;
        GetClientRect(hWnd, &rc);  // 실제 사용자가 사용할 수 있는 클라이언트 영역의 크기를 알려줌
        //GetWindowRect(hWnd, &rc);  // 실제 윈도우 영역의 크기를 알려줌
        // &rc <-- 메모리 공유하겠다는 의미(rc가 결과값을 받아올 것임을 예상할 수 있음)
        WCHAR ar[32] = { 0, };
        wsprintf(ar,
            L"%d %d %d %d",
            rc.left, rc.top, rc.right, rc.bottom);

        SetWindowText(hWnd, ar);

        //
        InvalidateRect(hWnd, NULL, TRUE);// WM_PAINT 메세지 발생하는 함수
        }break;

    case WM_COMMAND:// 메뉴 선택과 관련있음(하위에 있는 서브메뉴를 누르면 루프로 들어감
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
        }break;
    case WM_PAINT:// 그리기와 관련되어 있음
        {
            PAINTSTRUCT ps;
            // 그리기 시작함을 알림
            HDC hdc = BeginPaint(hWnd, &ps); // 핸들(1개 이상임을 예상 가능) new 연산자 포함

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            // 도형 : 점, 선, 원, 타원, 사각형, 그림.... 텍스트 출력.
            RECT rc;
            GetClientRect(hWnd, &rc);

            WCHAR str[64];
            wsprintf(str, TEXT("mx : %d    my : %d"), mx, my);
            
            TextOut(hdc, 10, 20, str, wcslen(str));
            //horizontal(width) vertical(height)

            //DrawText(hdc, str, wcslen(str), &rc, DT_CENTER); // 그리기 핸들 값을 넣는다.
            //DrawText(hdc, str, wcslen(str), &rc, DT_RIGHT); // 그리기 핸들 값을 넣는다.
            //DrawText(hdc, str, wcslen(str), &rc, DT_SINGLELINE | DT_VCENTER); // 그리기 핸들 값을 넣는다.
            //DrawText(hdc, str, wcslen(str), &rc, DT_SINGLELINE | DT_VCENTER | DT_CENTER); // 그리기 핸들 값을 넣는다.

            // 그리기 끝났음을 알림
            EndPaint(hWnd, &ps); // delete 연산자 포함

                               /*Uincode     범용 함수
            strlen              wcslen;      _tcslen
            strcpy              wcscpy       _tcscpy
            strcat              wcscat;      _tcscat
            strcmp              wcscmp;      _tcscmp*/


        }break;
    case WM_DESTROY:// 윈도우창이 종료될 때 발생하는 메세지
        PostQuitMessage(0); // 메세지를 발생시킨다. --> WM_QUIT
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
