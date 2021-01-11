// WindowsProject6.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject6.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT6));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT6));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT6);
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
#define WM_MYMESSAGE (WM_USER + 1)
#define WM_APPLE (WM_USER + 2)
#include "Resource.h"
#define TIMERID 100

typedef struct 
{
    int left;
    int top;
    int right;
    int bottom;
    //도형의 중점
    int px;
    int py;
    //도형의 가로, 세로크기
    int width;
    int height;

    int leftside;
    int rightside;
    int topside;
    int bottomside;
}RECTPOINT;

RECTPOINT* point;
int pxFlag = 0;
int pyFlag = 0;

void ChangeRectPoint(HWND hWnd,RECTPOINT* point)
{ 
    RECT rc;
    GetClientRect(hWnd, &rc);
    point->leftside = point->px - (point->right - point->left) / 2;
    point->rightside = point->px + (point->right - point->left) / 2;

    if (point->leftside == 0)
        pxFlag |= 0x00000001; // 우측으로 px 좌표 움직이도록 플래그 비트 설정

    if (point->rightside == rc.right)
        pxFlag &= 0x00000000; // 좌측으로 px 좌표 움직이도록 플래그 비트 설정


    //사각형 py (중점) 이동시 >> 그에 맞게 top,bottom 위치 대입
    //top : 100, bottom : 200 <- 총 가로 길이 100
    point->topside = point->py - (point->bottom - point->top) / 2;
    point->bottomside = point->py + (point->bottom - point->top) / 2;

    if (point->topside == 0)
        pyFlag |= 0x00000001;

    if (point->bottomside == rc.bottom)
        pyFlag &= 0x00000000;



    if (pxFlag == 0)
        point->px--;
    else
        point->px++;

    if (pyFlag == 0)
        point->py--;
    else
        point->py++;

    point->left =   point->px - point->width;
    point->right =  point->px + point->width;
    point->top =    point->py - point->height;
    point->bottom = point->py + point->height;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{    
    switch (message)
    {
    case WM_CREATE:
    {
        point = new RECTPOINT;
        point->left = 100;
        point->top = 100;
        point->right = 200;
        point->bottom = 200;

        point->width = (point->right - point->left) / 2;
        point->height = (point->bottom - point->top) / 2;

        point->px = point -> width; // px 초기 좌표
        point->py = point -> height; // py 초기 좌표

        HANDLE hTimer = (HANDLE)SetTimer(
            hWnd,
            TIMERID,      //Timer ID
            3,   //1000ms= 1s 한번 메세지 WM_TIMER 발생
            NULL    // 속성
        );
    }break;

    /*case WM_MYMESSAGE:
    {
        WCHAR Str[32];
        wsprintf(Str, TEXT("%d %d"), wParam, lParam);
        MessageBox(hWnd, Str, TEXT("캡션"), MB_OK);
    }break;*/
    
    //case WM_LBUTTONDOWN:
    //{
    //    //프로그래머가 직접 메세지를 만들고 발생 시킬 때 사용
    //    //SendMessage(hWnd, WM_MYMESSAGE, 10, 20);
    //    SendMessage(hWnd, WM_TIMER, 0, 0);
    //}break;

    case WM_TIMER:
    {
        switch (wParam)
        {
        case TIMERID:
            {
                
                InvalidateRect(hWnd, NULL, true);
            }break;
        }
    }break;
    
    
    case WM_COMMAND:
    {
        
    }
    break;
    case WM_PAINT:
    {
        HDC hdc, MemDC;
        HBITMAP MyBitmap, OldBitmap;

        PAINTSTRUCT ps;
        hdc = BeginPaint(hWnd, &ps);

            
        HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(0xff, 0x00, 0x00));
        HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);// 새로운 펜 설정하고 옛날 펜 반환한다.

        HBRUSH hNewBrush = CreateSolidBrush(RGB(0x00, 0x00, 0xff));
        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);// 새로운 브러쉬 설정하고 옛날 브러쉬 반환한다.

        //사각형 px (중점) 이동시 >> 그에 맞게 left,right 위치 반환하는 함수 작성
        //left : 100, right : 200 <- 총 가로 길이 100
        ChangeRectPoint(hWnd, point);

        Rectangle(hdc, point->left, point->top, point->right, point->bottom);
        
       
        SelectObject(hdc, hOldPen); // 과거정보 다시 불러 온다.(복구) 후에 가장 최근펜을 반환한다.
        SelectObject(hdc, hOldBrush); // 과거정보 다시 불러 온다.(복구) 후에 가장 최근브러쉬를 반환한다.

        DeleteObject(hNewPen); // 다 사용했기 때문에 메모리 해제한다.
        DeleteObject(hNewBrush); // 다 사용했기 때문에 메모리 해제한다.
        

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        delete point;
        KillTimer(hWnd, TIMERID);// 핸들, ID
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

#pragma region 비트맵 예제(paint)
//MemDC = CreateCompatibleDC(hdc);
//
//    // 처음부터 .exe실행파일이 전부 관리하기 때문에 메모리 손해를 많이보며 그림 지울 수 없음
//    //MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
//    //이미지를 별도로 관리하기 때문에 위의 방법보다 훨씬 좋음
//    MyBitmap = (HBITMAP)LoadImage(NULL, TEXT("joy.bmp"),
//        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
//    {
//        BITMAP bitmap;
//        GetObject(MyBitmap, sizeof(BITMAP), &bitmap);
//        int m_width = bitmap.bmHeight;
//        int m_height = bitmap.bmWidth;

//        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
//        OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);

//        BitBlt(hdc,
//            100, 50, // 시작 좌표
//            600, 600,//가로길이 - 세로길이
//            MemDC, 0, 0,
//            SRCCOPY);
//        //StretchBlt(hdc,
//        //    100, 50, // 시작 좌표
//        //    600, 600,//가로길이 - 세로길이
//        //    MemDC, 50, 100,
//        //    100, 200, SRCCOPY);


//        SelectObject(MemDC, OldBitmap);
//    }
//    DeleteObject(MyBitmap);
//}
//DeleteDC(MemDC);
#pragma endregion
#pragma region pen, brush 예제(paint)
        //{
        //    HPEN hNewPen = CreatePen(PS_SOLID, 1, RGB(0xff, 0x00, 0x00));
        //    HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);// 새로운 펜 설정하고 옛날 펜 반환한다.

        //    HBRUSH hNewBrush = CreateSolidBrush(RGB(0x00, 0x00, 0xff));
        //    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);// 새로운 브러쉬 설정하고 옛날 브러쉬 반환한다.

        //    Rectangle(hdc, 100, 100, 200, 200);
        //    Ellipse(hdc, 300, 300, 500, 400);

        //    SelectObject(hdc, hOldPen); // 과거정보 다시 불러 온다.(복구) 후에 가장 최근펜을 반환한다.
        //    SelectObject(hdc, hOldBrush); // 과거정보 다시 불러 온다.(복구) 후에 가장 최근브러쉬를 반환한다.

        //    DeleteObject(hNewPen); // 다 사용했기 때문에 메모리 해제한다.
        //    DeleteObject(hNewBrush); // 다 사용했기 때문에 메모리 해제한다.
        //}
#pragma endregion
// 정보 대화 상자의 메시지 처리기입니다.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
