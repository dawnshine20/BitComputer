#include "framework.h"
#include "LoadBitMap.h"
#include <stdio.h>

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
    LoadStringW(hInstance, IDC_LOADBITMAP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LOADBITMAP));

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

    return (int)msg.wParam;
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

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LOADBITMAP));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LOADBITMAP);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
TCHAR PathFileName[MAX_PATH] = TEXT(""); // 260
TCHAR FileName[MAX_PATH] = TEXT(""); //
TCHAR InitFileName[MAX_PATH] = TEXT(""); // 

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //FILE* fp_in;
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case ID_MENU2:
        {
            //c:\aaaa\bbbbb\ccc\.... 길이가 260을 넘으면 안된다.
            

            // 현재 나의 작업 경로 C:\git\BitComputer\Cprogram\MyProject\FinalWinAPI
            GetCurrentDirectory(MAX_PATH, InitFileName);
            //OutputDebugString(InitFileName);
            OPENFILENAME ofn;
            //memset(&ofn, 0, sizeof(OPENFILENAME));
            //윈도우 프로그램에서는 memset 대신 
            ZeroMemory(&ofn, sizeof(OPENFILENAME));
            ofn.lpstrFilter = TEXT( // 얻고 싶은 목록들 열거
                "Bmp File (.bmp)\0*.bmp\0"
                "Header File (.h)\0*.h\0"// 더블쿼텐션 사이 기링가 너무 길 때 이와 같은 방식으로 나눌 수 있다.
                "Gif File (.gif)\0*.gif\0"
                "JPG File (.jpg)\0*.jpg\0"
                "모든 파일 (*.*)\0*.*\0\0"
            );
            // 파일 경로가 포함된 파일명을 얻기 위한
            // 임시버퍼로 사용
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.lpstrFile = &PathFileName[0];
            ofn.nMaxFile = MAX_PATH; // 경로길이 설정

            // 파일 이름을 얻기 위한 버퍼
            ofn.lpstrFileTitle = &FileName[0];
            //OutputDebugString(FileName);
            ofn.nMaxFileTitle = MAX_PATH;

            //초기 파일을 찾기를 시작할 경로 설정
            ofn.lpstrInitialDir = &InitFileName[0];
            ofn.lpstrTitle = TEXT("열기");
            ofn.Flags = OFN_FILEMUSTEXIST;
            ofn.lpstrDefExt = TEXT("bmp");

            
            
            //파일명을 얻는 것 뿐이다.
            if (GetOpenFileName(&ofn) == 1)
            {
                InvalidateRect(hWnd, NULL, true);
                MessageBox(hWnd, TEXT("1"), TEXT("확인"), MB_OK);
            }
            
            //if (GetSaveFileName(&ofn)) {
            //    MessageBox(hWnd, TEXT("1"), TEXT("확인"), MB_OK);
            //}

            int temp = 0; // 디버깅 용도
            temp++;
        }break;
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
        HBITMAP MyBitmap, OldBitmap;
        HDC MemDC;
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        MemDC = CreateCompatibleDC(hdc);
        OutputDebugString(FileName);

        MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
        MyBitmap = (HBITMAP)LoadImage(NULL, FileName,
            IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        BITMAP bitmap;
        GetObject(MyBitmap, sizeof(BITMAP), &bitmap);
        int m_width = bitmap.bmWidth;
        int m_height = bitmap.bmHeight;
        OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);

        BitBlt(hdc,
            100, 50,
            m_width, m_height,
            MemDC, 0, 0,
            SRCCOPY);
        DeleteObject(OldBitmap); // 반드시 안에 있는 것부터 제거
        DeleteObject(MyBitmap);
        DeleteDC(MemDC);
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
