
// MFCApplication3_21_01_20Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3_21_01_20.h"
#include "MFCApplication3_21_01_20Dlg.h"
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


// CMFCApplication3210120Dlg 대화 상자
CMFCApplication3210120Dlg::CMFCApplication3210120Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_21_01_20_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3210120Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication3210120Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFCApplication3210120Dlg::OnDeltaposSpin1)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_START_BUTTON, &CMFCApplication3210120Dlg::OnBnClickedStartButton)
	ON_BN_CLICKED(IDC_END_BUTTON, &CMFCApplication3210120Dlg::OnBnClickedEndButton)
END_MESSAGE_MAP()


// CMFCApplication3210120Dlg 메시지 처리기

BOOL CMFCApplication3210120Dlg::OnInitDialog()
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
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1))->SetRange(0, 10);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1))->SetPos(5);

	//----------------------------------------------------------
	//((CProgressCtrl*)GetDlgItem(IDC_PROGRESS1))->SetRange(0,100);
	////((CProgressCtrl*)GetDlgItem(IDC_PROGRESS1))->SetPos(50);
	
	//
	//// WM_TIMER
	//SetTimer(10, 1000, NULL); // ID, 1초마다, 내가만든 함수 쪽으로 콜시킴

	//---------------------------------------------------------------
	
	((CEdit*)GetDlgItem(IDC_LEVEL_EDIT))->SetWindowTextW(_T("1"));


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication3210120Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication3210120Dlg::OnPaint()
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
HCURSOR CMFCApplication3210120Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//스핀버튼이 눌리면 들어오는 루트
void CMFCApplication3210120Dlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int result = pNMUpDown->iPos + pNMUpDown->iDelta;
	CString s;
	s.Format(_T("%d\n"), result);
	GetDlgItem(IDC_BUTTON1)->SetWindowTextW(s);
	*pResult = 0;
}

// -----윈도우 창 메세지 중 1 하나-----
class CRpgGame {
private:
	UINT gameExp;

public:
	UINT GetExp() {
		return gameExp;
	}

	void CalcuateExp (int userLevel){
		gameExp = 100 + 30 * (userLevel - 1) * (userLevel + 6);
	}
};

class CUser {
public:
	int userLevel = 1;
};

CRpgGame* game = new CRpgGame;
CUser* user = new CUser;

void CMFCApplication3210120Dlg::OnTimer(UINT_PTR nIDEvent)
{
	srand((signed)time(NULL));

	switch (nIDEvent)
	{
	case 10: {
		static int count = 0;
		
			count += (rand() % 21) + 10;
			
			if (count > game->GetExp()) {
				count = count - game->GetExp();

				user->userLevel += 1;

				//--레벨에 따라 프로그래스 바에 경험치 갱신
				game->CalcuateExp(user->userLevel);
				((CProgressCtrl*)GetDlgItem(IDC_PROGRESS1))->SetRange(0, game->GetExp());

				//---에디트 박스에 레벨 표시---
				CString strLevel;
				strLevel.Format(_T("%d"), user->userLevel);
				((CEdit*)GetDlgItem(IDC_LEVEL_EDIT))->SetWindowTextW(strLevel);
			}

			((CProgressCtrl*)GetDlgItem(IDC_PROGRESS1))->SetPos(count);
		}
		break;
	
	default :
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication3210120Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(10);
}


void CMFCApplication3210120Dlg::OnBnClickedStartButton()
{	
	game->CalcuateExp(user->userLevel);

	((CProgressCtrl*)GetDlgItem(IDC_PROGRESS1))->SetRange(0, game->GetExp());

	SetTimer(10, 200, NULL); 
}


void CMFCApplication3210120Dlg::OnBnClickedEndButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(10);
}
