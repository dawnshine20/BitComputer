
// MFCApplication6_21_01_27Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication6_21_01_27.h"
#include "MFCApplication6_21_01_27Dlg.h"
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


// CMFCApplication6210127Dlg 대화 상자



CMFCApplication6210127Dlg::CMFCApplication6210127Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION6_21_01_27_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6210127Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication6210127Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6210127Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication6210127Dlg::OnBnClickedButton2)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMFCApplication6210127Dlg::OnTcnSelchangeTab1)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB1, &CMFCApplication6210127Dlg::OnTcnSelchangingTab1)
END_MESSAGE_MAP()


// CMFCApplication6210127Dlg 메시지 처리기
#include "Dialog1.h"
#include "Dialog2.h"
#include "Dialog3.h"
BOOL CMFCApplication6210127Dlg::OnInitDialog()
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
	
	((CTabCtrl*)GetDlgItem(IDC_TAB1))->InsertItem(0, L"탭 0");
	((CTabCtrl*)GetDlgItem(IDC_TAB1))->InsertItem(1, L"탭 1");
	((CTabCtrl*)GetDlgItem(IDC_TAB1))->InsertItem(2, L"탭 2");

	// 다이얼로그의 객체 생성
	m_TabDlg[0] = new CDialog1;
	m_TabDlg[1] = new CDialog2;
	m_TabDlg[2] = new CDialog3;

	//UI와 객체를 연결
	m_TabDlg[0]->Create(IDD_DIALOG1, (CTabCtrl*)GetDlgItem(IDC_TAB1));
	m_TabDlg[1]->Create(IDD_DIALOG2, (CTabCtrl*)GetDlgItem(IDC_TAB1));
	m_TabDlg[2]->Create(IDD_DIALOG3, (CTabCtrl*)GetDlgItem(IDC_TAB1));

	CRect TabDlgRect, ItemRect;

	for (int i = 0; i < 3; i++)
	{
		// 0(L), 0(T), 543(R), 354(B)
		m_TabDlg[i]->GetClientRect(&TabDlgRect);

		// ItemRect
		// 0: 2(L),2(T),56(R),25(B)
		// 1: (L),(T),(R),(B)
		// 2: (L),(T),(R),(B)
		((CTabCtrl*)GetDlgItem(IDC_TAB1))->GetItemRect(i, &ItemRect);
		int x1 = TabDlgRect.left;
		int y1 = ItemRect.bottom;
		int x2 = TabDlgRect.right;
		int y2 = TabDlgRect.bottom;
		m_TabDlg[i]->SetWindowPos(
			&wndTop,
			x1, y1, x2, y2,
			SWP_SHOWWINDOW
		);
	}
	m_TabDlg[0]->ShowWindow(SW_SHOW);
	m_TabDlg[1]->ShowWindow(SW_HIDE);
	m_TabDlg[2]->ShowWindow(SW_HIDE);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication6210127Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication6210127Dlg::OnPaint()
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
HCURSOR CMFCApplication6210127Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication6210127Dlg::OnBnClickedButton1()
{
	MessageBox(L"메인다이얼로그", MB_OK);
}


void CMFCApplication6210127Dlg::OnBnClickedButton2()
{
	OnOK();
}

//먼저들어가고
void CMFCApplication6210127Dlg::OnTcnSelchangingTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	int num = ((CTabCtrl*)GetDlgItem(IDC_TAB1))->GetCurSel();
	//CString s;
	//s.Format(L"1 : %d", num);
	//MessageBox(s, MB_OK);
	m_TabDlg[num]->ShowWindow(SW_HIDE); // 0 번 하이드
	*pResult = 0;
}

// 변화 끝나고 나는 시점에 들어간다.
void CMFCApplication6210127Dlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	int num =((CTabCtrl*)GetDlgItem(IDC_TAB1))->GetCurSel();
	//CString s;
	//s.Format(L"2 : %d", num);
	//MessageBox(s, MB_OK);
	m_TabDlg[num]->ShowWindow(SW_SHOW);
	*pResult = 0;
}



