// MFCApplication2Dlg.cpp: 구현 파일
//
#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()
// CMFCApplication2Dlg 대화 상자
CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_BUTTON1, m_Btn1);		//첫번째 인수값은 넘어오는 pDX
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangeEdit1)
	ON_EN_SETFOCUS(IDC_EDIT1, &CMFCApplication2Dlg::OnEnSetfocusEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()
// CMFCApplication2Dlg 메시지 처리기
BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}
void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.
void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//버튼을 클릭시 이벤트 발생하는 4가지 정도의 방법
	//1번째
	//dlg.h에 가서 변수 선언 ->
	//CButton m_Btn1;
	//DDX_Control(pDX,IDC_BUTTON1, m_Btn1);
	//m_Btn1.SetWindowTextW(TEXT("호랑이"));
	//m_Btn1.SetState(true);
	//2번째
	//GetDlgItem(IDC_BUTTON1);
	//버튼 객처를 얻어서 사용한다고 하면 앞에 타입케스팅을 해줘야한다.
	//((CButton *))GetDlgItem(IDC_BUTTON1);
	//((CButton*) GetDlgItem(IDC_BUTTON1))->SetWindowTextW(TEXT("호랑이"));

	//3번째  버튼 객체
	CButton* pBtn = ((CButton*)GetDlgItem(IDC_BUTTON1));
	pBtn->SetWindowTextW(TEXT(""));

	//4번째 버튼의 부모 객체	//setsate함수는 사용할수없다. 위에는 다 사용 가능.
	CWnd* pWnd = ((CButton*)GetDlgItem(IDC_BUTTON1));
	pWnd->SetWindowTextW(TEXT(""));

	CWnd* CEdit = ((CButton*)GetDlgItem(IDC_EDIT1));
	CEdit->SetWindowTextW(TEXT("호랑이"));

	//2,3,4번은 getdlg로 받아서 사용하는데 비용면에서는 234이지만 mfc에서 이정도 비용은 생각안한다.
}
void CMFCApplication2Dlg::OnEnChangeEdit1()
{

	//((CEdit*) GetDlgItem(IDC_EDIT1))->
	//	SetWindowTextW(TEXT("호랑이"));
	CString s;
	((CEdit*)GetDlgItem(IDC_EDIT1)) ->	GetWindowTextW(s);

	CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON1);
	pBtn->SetWindowTextW(s);
	//MessageBox(s, s, MB_OK);
}
void CMFCApplication2Dlg::OnEnSetfocusEdit1()
{
	// 에디트 박스를 선택할 경우 동작이 실행된다.
	((CEdit*)GetDlgItem(IDC_EDIT1)) ->
		SetWindowTextW(TEXT("포어커스"));
}

void CMFCApplication2Dlg::OnBnClickedButton2()
{
	//CString s = TEXT(" 기본값 ");
	//s = TEXT("갱신이 되는건가");
	//s += TEXT("호랑이");	//s= s+ TEXT("호랑이");
	//CString s2;
	//s2.Format(TEXT("무궁화 꽃이 피었씁니다람쥐 %d\n%s	%d"),
	//	10,s,s.GetLength());
	//MessageBox(s2, s2, MB_OK);
	//s2.Empty();
	//MessageBox(s2, s2, MB_OK);
	//if (s2.IsEmpty()) {
	//	MessageBox(TEXT("비었습니다."), MB_OK);
	//}

	//값얻기 숫자가 들어가있다는 전제

	//1
	//CString s;
	//((CEdit*)GetDlgItem(IDC_EDIT1))->
	//	GetWindowTextW(s);

	//2
	//int r = GetDlgItemInt(IDC_BUTTON1);
	//int a = r + 100;
	//CString s;
	//GetDlgItemText(IDC_EDIT1, s);

}
void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(TEXT("종료합니다."));
	OnOK();
}

