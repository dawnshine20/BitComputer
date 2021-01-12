//.cpp, .h(컴파일러가 참조할 수 있는 코드)
//헤드파일 안에 들어가는 내용
//1. typedef 문
//2. #define 문
//3. 구조체
//4. 클래스
//5. 함수 원형 : 프로토타입; void f1();
//inline void f1() { // 컴파일 옵션 
//
//}
//6. 프리 프로세스 : 컴파일 옵션
//#ifdef
//	컴파일 옵션코드 // 조건에 맞으면 컴파일 하고 <-> 조건에 맞지 않으면 else 구문 컴파일
//#else
//	컴파일 옵션코드
//#endif
//7.프리 프로세스 : #pragma 
// 
//8. __asm    <- 어셈블러
// 들어갈 수 없는 코드
//i++;

#include "framework.h"
#include "Modal_Modaless.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 핸들 .... 식별번호(주민등록번호)
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//함수가 끝날 때 운영체제가 자동 호출(함수 스스로가 정리)
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
    LoadStringW(hInstance, IDC_MODALMODALESS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
            DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MODALMODALESS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MODALMODALESS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


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

HWND hDlg;
INT_PTR CALLBACK MsgDlg1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_COMMAND: {
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
            {
                DestroyWindow(hDlg);
                return (INT_PTR)TRUE;
            }
            break;
        }
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK MsgDlg2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_COMMAND: {

            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
            {
                DestroyWindow(hDlg);
                return (INT_PTR)TRUE;
            }
            break;
        }
    }
    return (INT_PTR)FALSE;
}

HWND hDlg1 = NULL;
HWND hDlg2 = NULL;
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
            case ID_MENU1:
            {
                if (!IsWindow(hDlg1)) {
                    hDlg1 = CreateDialog(
                        hInst,
                        MAKEINTRESOURCE(IDD_DIALOG1),
                        hWnd,
                        MsgDlg1
                    );
                    // 모달리스 창은 바로 나타나지 않는다.
                    ShowWindow(hDlg1, SW_SHOW);
                }break;
            }
            case ID_MENU2:
            {
                if (!IsWindow(hDlg2)) {
                    hDlg2 = CreateDialog(
                        hInst,
                        MAKEINTRESOURCE(IDD_DIALOG2),
                        hWnd,
                        MsgDlg2
                    );
                    // 모달리스 창은 바로 나타나지 않는다.
                    ShowWindow(hDlg2, SW_SHOW);
                }break;
            }
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

