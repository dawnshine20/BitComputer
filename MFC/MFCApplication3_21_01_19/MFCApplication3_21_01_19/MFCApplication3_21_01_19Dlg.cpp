
// MFCApplication3_21_01_19Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3_21_01_19.h"
#include "MFCApplication3_21_01_19Dlg.h"
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


// CMFCApplication3210119Dlg 대화 상자



CMFCApplication3210119Dlg::CMFCApplication3210119Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_21_01_19_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3210119Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

// 컨트롤과 메세지를 짝지어주는 역할
BEGIN_MESSAGE_MAP(CMFCApplication3210119Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication3210119Dlg::OnBnClickedCheck1)
	
	//IDC_RADIO1~IDC_RADIO3 중 하나 클릭되면 F1함수로 들어가세요.
	ON_COMMAND_RANGE(IDC_RADIO1, IDC_RADIO3, f1)
	//ON_COMMAND_RANGE(IDC_RADIO4, IDC_RADIO5, f1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

void CMFCApplication3210119Dlg::f1(UINT id) {
	CString s = L"td";
	s.Format(L"%d", id);
	OutputDebugString(s);
	switch (id) {
	case IDC_RADIO1:
	case IDC_RADIO2:
	case IDC_RADIO3:
		break;
	}
}

// CMFCApplication3210119Dlg 메시지 처리기

BOOL CMFCApplication3210119Dlg::OnInitDialog()
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
	//((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(true);
	//((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(true);

	//-------범위(구간) 설정-----------
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->SetRange(0,255, true);
	// --포인터의 초기 위치 설정--
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->SetPos(50);
	//--눈금의 배치 간격 설정--
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->SetTicFreq(10);
	//--방향키 이동 간격설정--
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->SetLineSize(20);
	//--클릭시 움직이는 위치 간격 설정(방향키 up,down 사용할경우 동일 적용)--
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->SetPageSize(10);

	
	return TRUE;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication3210119Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication3210119Dlg::OnPaint()
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
HCURSOR CMFCApplication3210119Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#define	BTN_UNCHECKED	0X0000
#define	BTN_CHECKED		0X0001

void CMFCApplication3210119Dlg::OnBnClickedCheck1()
{
	//-----Auto가 true일 경우-----
	// 자동으로 직접 on off 시켜준다..
	CButton* pCheckBtn= (CButton*)GetDlgItem(IDC_CHECK1);// CheckBox는 버튼 소속
	//--Setcheck, GetCheck
	int state = pCheckBtn->GetCheck();
	
	CButton* pBtn1 = (CButton*)GetDlgItem(IDC_BUTTON1);// CheckBox는 버튼 소속
	
	//--체크 된 후 또 체크클릭하게 되면 if문 내부로 진입
	if (state == BTN_CHECKED)
	{
		//pCheckBtn->SetCheck(true); //자동으로 해주기 때문에 필요 없는 구문
		pBtn1->EnableWindow(true);
	}
	if (state == BTN_UNCHECKED)
	{
		//pCheckBtn->SetCheck(false); //자동으로 해주기 때문에 필요 없는 구문
		pBtn1->EnableWindow(false);
	}

	//----Auto가 false일 경우---
	//수동으로 직접 check box on, off 시켜준다..
	//BOOL state = IsDlgButtonChecked(IDC_CHECK1); // 대문자 BOOL이 있다면 그냥 TRUE, FALSE 이상의 개념을 갖는다.(좀 더 확장된 개념)
	////bool state = IsDlgButtonChecked(IDC_CHECK1);
	//CheckDlgButton(IDC_CHECK1, state ? false : true);
	//
	//int ct = 0;
	//ct++;
}

//컨트롤에 국한되어있지 않고 윈도우메세지로 설정해야하는 구문->
//이벤트로 설정xxxx 윈도우 창의 메세지 구문에서 WM_HSCROLL 설정
void CMFCApplication3210119Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	//디버깅 시 2번씩 들어오는 데이터 중 1번은 날려버리기 위해 작성하는 코드
	if (nSBCode == SB_ENDSCROLL)
		return;

	////현재 슬라이더 위치값을 계속해서 얻어오고자 할때 사용
	//UINT value = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->GetPos();
	//// 유효범위를 조정하여 설정하고자 할 때 사용하는 기법
	//// (총 범위가 얼마나 크던지 간에 0 ~ 1 사이 값으로 치환 할 수 있다.)
	//// 255는 색깔로 사용하게 되고 다른예로 파이 라디안 작업에 응용할 수 있다.
	//float fvalue = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->GetPos()/255.0f;
	//
	//
	//CString s;
	//s.Format(L"%d %.02f\n", value, fvalue);
	//OutputDebugString(s);
	//
	//CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	UINT value = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER1))->GetPos();

	CEdit* pDecEdit = ((CEdit*)GetDlgItem(IDC_DECIMAL_EDIT));
	CEdit* pPerEdit = ((CEdit*)GetDlgItem(IDC_PERCENTAGE_EDIT));
	CEdit* pHexEdit = ((CEdit*)GetDlgItem(IDC_HEX_EDIT));

	CString strDec, strPer, strHex;

	strDec.Format(_T("%d"), value);
	strPer.Format(_T("%.1f"), value/255.0f);
	strHex.Format(_T("0x%x"), value);

	pDecEdit->SetWindowTextW(strDec);
	pPerEdit->SetWindowTextW(strPer);
	pHexEdit->SetWindowTextW(strHex);

}
