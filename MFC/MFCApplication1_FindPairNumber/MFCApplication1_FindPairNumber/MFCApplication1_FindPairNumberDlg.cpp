
// MFCApplication1_FindPairNumberDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1_FindPairNumber.h"
#include "MFCApplication1_FindPairNumberDlg.h"
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


// CMFCApplication1FindPairNumberDlg 대화 상자



CMFCApplication1FindPairNumberDlg::CMFCApplication1FindPairNumberDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_FINDPAIRNUMBER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1FindPairNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1FindPairNumberDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication1FindPairNumberDlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// CMFCApplication1FindPairNumberDlg 메시지 처리기

BOOL CMFCApplication1FindPairNumberDlg::OnInitDialog()
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

void CMFCApplication1FindPairNumberDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1FindPairNumberDlg::OnPaint()
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
HCURSOR CMFCApplication1FindPairNumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//----------------------------------------------------------
int clickedCnt = 0;
bool isEven = false;

class CPairGame {
private:
	int cardNumber1;
	int cardNumber2;

public:
	CPairGame() {
		cardNumber1 = 0;
		cardNumber2 = 0;
	}

	void SetCardNumber1(int number){
		this->cardNumber1 = number;
		//MessageBox(NULL,TEXT("0X01"), TEXT("알림"), MB_OK);
	}
	
	void SetCardNumber2(int number){
		this->cardNumber2 = number;
		//MessageBox(NULL, TEXT("0X10"), TEXT("알림"), MB_OK);
	}

	int GetCardNumber1() {
		return cardNumber1;
	}

	int GetCardNumber2(){
		return cardNumber2;
	}

	bool CompareCard() 
	{
		if (!isEven)
			return false;

		if (isEven && (cardNumber1 == cardNumber2))
		{
			return true;
		}
	}
};

CPairGame* User= new CPairGame;


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString  strTest;
	int cardNumber;

	clickedCnt++;
	clickedCnt %= 2;

	if (clickedCnt == 0)
		isEven = true;
	else
		isEven = false;

	CButton* t = (CButton*)GetDlgItem(IDC_BUTTON1);
	t->GetWindowTextW(strTest);

	cardNumber = _ttoi(strTest);

	if (!isEven)
	{
		User->SetCardNumber1(cardNumber);
		MessageBox(TEXT("1회 클릭"), TEXT("알림"), MB_OK);
	}
	else {
		User->SetCardNumber2(cardNumber);
		MessageBox(TEXT("2회 클릭"), TEXT("알림"), MB_OK);
	}


	if (User->CompareCard() && (isEven))
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	}

	

}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString  strTest;
	int cardNumber;

	clickedCnt++;
	clickedCnt %= 2;

	if (clickedCnt == 0)
		isEven = true;
	else
		isEven = false;

	CButton* t = (CButton*)GetDlgItem(IDC_BUTTON2);
	t->GetWindowTextW(strTest);

	cardNumber = _ttoi(strTest);

	if (clickedCnt == 0)
	{
		User->SetCardNumber1(cardNumber);
		MessageBox(TEXT("1회 클릭"), TEXT("알림"), MB_OK);
	}
	else {
		User->SetCardNumber2(cardNumber);
		MessageBox(TEXT("2회 클릭"), TEXT("알림"), MB_OK);
	}


	if (User->CompareCard() && (isEven))
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	}



}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString  strTest;
	int cardNumber;

	clickedCnt++;
	clickedCnt %= 2;

	if (clickedCnt == 0)
		isEven = true;
	else
		isEven = false;

	CButton* t = (CButton*)GetDlgItem(IDC_BUTTON3);
	t->GetWindowTextW(strTest);

	cardNumber = _ttoi(strTest);

	if (!isEven)
	{
		User->SetCardNumber1(cardNumber);
		MessageBox(TEXT("1회 클릭"), TEXT("알림"), MB_OK);
	}
	else {
		User->SetCardNumber2(cardNumber);
		MessageBox(TEXT("2회 클릭"), TEXT("알림"), MB_OK);
	}


	if (User->CompareCard() && (isEven))
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	}
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
