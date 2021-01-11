// WindowsProject7.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h" // 외부에서 참조해야할 파일
#include "WindowProject7_HeaderFile.h"

#define MAX_LOADSTRING 100

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


// 전역 변수:
HINSTANCE hInst;                                // 핸들 .... 식별번호(주민등록번호)
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MyAbout(HWND, UINT, WPARAM, LPARAM);
//함수가 끝날 때 운영체제가 자동 호출(함수 스스로가 정리)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	// hPrevInstance를 선언하고 사용하지 않았지만->안쓰이는 것을 알고있기 때문에 워닝 표시 하지 말라고 알려주는것
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_TIGER, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT7, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
        return FALSE;
    

    //HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT7)); (단축키 사용시 필요)

    MSG msg;

    // 기본 메시지 루프입니다:
	// 시간 출력하자. 오전/ 오후 ?? 시 ?? 분 ?? 초
	// winapi win api 시간 얻는 방법, 얻기.

    while (GetMessage(&msg, nullptr, 0, 0))
    {
            DispatchMessage(&msg);
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT7));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT7);
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
HWND hWnd;
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, TEXT("호랑이"), WS_OVERLAPPEDWINDOW,
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

INT_PTR CALLBACK MsgDlg1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	
	case WM_INITDIALOG: // 초기화와 관련된 함수
	{
		//MessageBox(hDlg, TEXT("Hello,WM_INITDIALOG Dialog1"), TEXT("First"), MB_OK);
		//
		//RECT rc,rc3;
		//GetClientRect(hDlg, &rc);
		//GetClientRect(hWnd, &rc3);
		//
		//int cx = (GetSystemMetrics(SM_CXSCREEN)); // 해상도 총 가로 size
		//int cy = (GetSystemMetrics(SM_CYSCREEN)); // 해상도 총 세로 size
		//
		//SetWindowPos( // 윈도우 위치 및 크기 재설정, 재보정
		//	hDlg,
		//	HWND_NOTOPMOST,
		//	(cx - (cx - rc3.right) - rc3.left)/2 + rc3.left, //윈도우의 새로운 좌상단 좌표를 지정한다. (픽셀단위)
		//	(cy - (cy - rc3.bottom) - rc3.top)/2 + rc3.top,
		//
		//	(rc.right - rc.left), // 윈도우의 새로운 폭과 높이를 지정한다. (픽셀단위)
		//	(rc.bottom - rc.top),
		//	SWP_SHOWWINDOW //위치와 크기 변경에 대한 여러가지 옵션을 지정한다.
		//);
#pragma region 윈도우 정 중앙에 새로운 dialog 위치시키기(조계성)
		RECT rc2, rc4;
		GetWindowRect(hDlg, &rc2);
		GetWindowRect(hWnd, &rc4);
		SetWindowPos(hDlg, HWND_NOTOPMOST,
			((rc4.left + rc4.right) - (rc2.right - rc2.left)) / 2,
			((rc4.top + rc4.bottom) - (rc2.bottom - rc2.top)) / 2,
			rc2.right - rc2.left,
			rc2.bottom - rc2.top
			, SWP_SHOWWINDOW);//윈도우의 위치,크기 재설정 재보정
#pragma endregion

		return (INT_PTR)TRUE;
	}break;

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

HWND hDlg2 = NULL;
INT_PTR CALLBACK MsgDlg2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND: {
			int wmId = LOWORD(wParam);
			switch (wmId)
			{
			case ID_MENU1:  // IDD_DIALOG1
				if (!IsWindow(hDlg2)) {
					hDlg2 = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, MsgDlg2);
					ShowWindow(hDlg2, SW_SHOW);
				}
			}break;
		}
	}
	return FALSE;
}

#define btnNumber 1000
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
		case WM_CREATE:
		{
			HWND hwndButton1;
			hwndButton1 =
				CreateWindowW(TEXT("BUTTON"), TEXT("클릭"),
					WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
					100, 100, 100, 150,
					hWnd, (HMENU)btnNumber, hInst, NULL);
		}break;
		
		
		case WM_COMMAND: // 메뉴, 컨트롤과 관련되어 있음...버튼, 에디트 박스, 콤보 박스, 라디오 버튼, 체크박스
		{
			HWND hDlg1 = NULL;
		    int wmId = LOWORD(wParam);
		    // 메뉴 선택을 구문 분석합니다:
		    switch (wmId)
		    {
			case ID_MENU1 :
			{
				//MessageBox(hWnd, TEXT("Hello,API"), TEXT("First"), MB_OK); 
				//DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)MsgDlg1);// 4번째 인자 ( 새로운 다이얼로그 메세지 처리 루틴 생성)
				if (!IsWindow(hDlg1)) // 존재하지 않는다면 다이얼로그 핸들을 생성하라는 의미
					hDlg1 = CreateDialog(
						hInst,
						MAKEINTRESOURCE(IDD_DIALOG1),
						hWnd,
						MsgDlg1
					);
			}break;

			case ID_MENU2:
				//MessageBox(hWnd, TEXT("Hello,API"), TEXT("First"), MB_OK); 
				if (!IsWindow(hDlg2)) {
					hDlg2 = CreateDialog(
						hInst, 
						MAKEINTRESOURCE(IDD_DIALOG1), 
						hWnd, 
						MsgDlg2
					);
					// 모달리스 창은 바로 나타나지 않는다.
					ShowWindow(hDlg2, SW_SHOW);
				
			}break;
			case btnNumber: //wParam==1000 - ID가 1000인 버튼0
			{
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)MsgDlg1);// 4번째 인자 ( 새로운 다이얼로그 메세지 처리 루틴 생성)
			}break;

		    case IDM_ABOUT:
				// 1. 박스, 메세지
		        DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, MyAbout);
		        break;
				
		    case IDM_EXIT:
		        DestroyWindow(hWnd);
		        break;
		    default:
		        return DefWindowProc(hWnd, message, wParam, lParam);
		    }
		}break;

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
