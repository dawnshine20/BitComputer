
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

class CUserInform 
{
private:
	int cardNumber1;
	int cardNumber2;
	int btnId1;
	int btnId2;

public:
	
	CUserInform() {
		cardNumber1 = 0;
		cardNumber2 = 0;
	}
	void SetBtnId1(int btnId) {
		this->btnId1 = btnId;
	}
	void SetBtnId2(int btnId) {
		this->btnId2 = btnId;
	}
	int GetBtnId1() {
		return btnId1;
	}
	int GetBtnId2() {
		return btnId2;
	}

	void SetCardNumber1(int cardNum) {
		this->cardNumber1 = cardNum;
	}
	void SetCardNumber2(int cardNum) {
		this->cardNumber2 = cardNum;
	}
	int GetCardNumber1() {
		return cardNumber1;
	}
	int GetCardNumber2() {
		return cardNumber2;
	}

	bool CompareCard()
	{
		if (this->cardNumber1 == this->cardNumber2)
			return true;
		else
			return false;
	}

	void RegisterCard(CWnd* pWnd,int btnId) {
		CString strBtnNum;

		HWND hWnd = pWnd->m_hWnd;
		CButton* t = (CButton*)GetDlgItem(hWnd, btnId);
		t->GetWindowTextW(strBtnNum);

		int cardNumber = _ttoi(strBtnNum); // btn to int

		if (clickedCnt == 0) // 클릭 횟수가 짝수라면
		{
			isEven = true;
			this->SetCardNumber2(cardNumber);
			this->SetBtnId2(btnId);
		}
		else
		{
			isEven = false;
			this->SetCardNumber1(cardNumber);
			this->SetBtnId1(btnId);
		}
	}
	void RecordNumOfClicked() {
		CString strBtnNum;
		clickedCnt++;
		clickedCnt %= 2;
	}
};

CUserInform* User = new CUserInform;

void CMFCApplication1FindPairNumberDlg::OnBnClickedButton1()
{	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CWnd* pWnd = AfxGetMainWnd();

	User->RecordNumOfClicked();
	User->RegisterCard(pWnd, IDC_BUTTON1);

	if (isEven) // 클릭횟수가 짝수인 경우
	{
		if (User->CompareCard()) // 선택된 두개의 카드가 같은 경우
		{
			GetDlgItem(User->GetBtnId1())->EnableWindow(false);
			GetDlgItem(User->GetBtnId2())->EnableWindow(false);
		}
		else // 선택된 두개의 카드가 같지 않은 경우
		{
			// 이전에 넣었던 cardNumber1의 홀수 버튼 id 복원 시켜야함
			GetDlgItem(User->GetBtnId1())->EnableWindow(true);
			GetDlgItem(User->GetBtnId2())->EnableWindow(true);
		}
	}
	else
		GetDlgItem(User->GetBtnId1())->EnableWindow(false);
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1FindPairNumberDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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


///-------------------지원씨 코드----------------
//ON_COMMAND_RANGE(IDC_CARD1_1, IDC_CARD6_2, &CCardGameDlg::SpareBtn)
//...
//CWnd* BeforeCardObjt;		// 이전 버튼의 객체 주소를 저장하기 위한 변수.
//// 같은 번호를 가지는 카드인지 체크하는 함수.
//// 이전 버튼 객체의 주소와 현재 버튼 객체의 주소를 비교한다.
//// 인수 ->  ID1 : 현재 버튼 ID, ID2 : 같은 번호의 버튼 ID.
//void CCardGameDlg::SameCardCheck(INT ID1, INT ID2)
//{
//	// 버튼의 활성화, visible 제어를 위한 변수.
//	static BOOL state = FALSE;
//	// 재시작을 위한 변수.
//	static WORD FindNum = 0;
//	// 버튼 클릭 횟수.
//	static WORD cnt = 0;
//	++cnt;
//	// 현재 버튼의 객체 주소 저장, 클릭 시 비활성화.
//	CWnd* CardObjt = GetDlgItem(ID1);
//	CardObjt->EnableWindow(state);
//	// 이전 버튼의 객체 주소와 현재 버튼의 객채 주소가 같고, 버튼 클릭 횟수가 짝수일 경우.
//	if (BeforeCardObjt == GetDlgItem(ID2) && cnt % 2 == 0)
//	{
//		// 이전 버튼과 현재 버튼 비활성화/invisible.
//		CardObjt->EnableWindow(state);
//		BeforeCardObjt->EnableWindow(state);
//		CardObjt->ShowWindow(state);
//		BeforeCardObjt->ShowWindow(state);
//		++FindNum;
//	}
//	// 버튼 클릭 횟수가 짝수일 경우.
//	if (cnt % 2 == 0)
//	{
//		// 이전 버튼과 현재 버튼 활성화.
//		state = TRUE;
//		BeforeCardObjt->EnableWindow(state);
//		CardObjt->EnableWindow(state);
//	}
//	// 모든 카드 세트를 찾을 경우 재시작.
//	if (FindNum == CARDSET)
//	{
//		state = TRUE;
//		CardObjt = GetDlgItem(IDC_START);
//		CardObjt->EnableWindow(state);
//		CardObjt->ShowWindow(state);
//		FindNum = 0;
//	}
//	// 다음 버튼 클릭 시 비교를 위해 이전 카드 객체 주소에 현재 객체 주소를 저장.
//	BeforeCardObjt = CardObjt;
//	state = FALSE;
//}
//// 버튼 이벤트 발생 시 각 버튼 ID에 따라 SameCardCheck() 함수를 실행.
//void CCardGameDlg::SpareBtn(UINT BTNID)
//{
//	switch (BTNID)
//	{
//	case IDC_CARD1_1:
//		SameCardCheck(IDC_CARD1_1, IDC_CARD1_2);
//		break;
//	case IDC_CARD1_2:
//		SameCardCheck(IDC_CARD1_2, IDC_CARD1_1);
//		break;
//	case IDC_CARD2_1:
//		SameCardCheck(IDC_CARD2_1, IDC_CARD2_2);
//		break;
//	case IDC_CARD2_2:
//		SameCardCheck(IDC_CARD2_2, IDC_CARD2_1);
//		break;
//	case IDC_CARD3_1:
//		SameCardCheck(IDC_CARD3_1, IDC_CARD3_2);
//		break;
//	case IDC_CARD3_2:
//		SameCardCheck(IDC_CARD3_2, IDC_CARD3_1);
//		break;
//	case IDC_CARD4_1:
//		SameCardCheck(IDC_CARD4_1, IDC_CARD4_2);
//		break;
//	case IDC_CARD4_2:
//		SameCardCheck(IDC_CARD4_2, IDC_CARD4_1);
//		break;
//	case IDC_CARD5_1:
//		SameCardCheck(IDC_CARD5_1, IDC_CARD5_2);
//		break;
//	case IDC_CARD5_2:
//		SameCardCheck(IDC_CARD5_2, IDC_CARD5_1);
//		break;
//	case IDC_CARD6_1:
//		SameCardCheck(IDC_CARD6_1, IDC_CARD6_2);
//		break;
//	case IDC_CARD6_2:
//		SameCardCheck(IDC_CARD6_2, IDC_CARD6_1);
//		break;
//	}
//}
//// 게임 시작 버튼.
//// 버튼을 누르면 게임 시작 버튼을 비활성화, invisible 상태로 만들고
//// 보이지 않던 모든 카드를 활성화, visible 상태로 만든다.
//void CCardGameDlg::OnBnClickedStart()
//{
//	// 버튼의 활성화, visible 제어를 위한 변수.
//	static BOOL state = FALSE;
//	// START GAME 버튼의 객채 주소를 얻고 비활성화, invisible 상태로 만든다.
//	CWnd* CardObjt;
//	CardObjt = GetDlgItem(IDC_START);
//	CardObjt->EnableWindow(state);
//	CardObjt->ShowWindow(state);
//	// 카드에 해당하는 각각의 버튼을 활성화, visible 상태로 만든다.
//	state = !state;
//	for (int i = 0; i < CARDNUM; i++)
//	{
//		CardObjt = GetDlgItem(IDC_CARD1_1 + i);
//		CardObjt->ShowWindow(state);
//		CardObjt->EnableWindow(state);
//	}
//	// 이전 버튼 객체 주소에 START GAME 버튼의 객체 주소를 저장한다.
//	BeforeCardObjt = GetDlgItem(IDC_START);
//}
//
////----------------------지훈씨 코드
//
//BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
//	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
//	ON_COMMAND_RANGE(IDC_BTN01, IDC_BTN88, Onbutton1)
//	ON_BN_CLICKED(IDC_RESET, &CMFCApplication2Dlg::OnBnClickedReset)
//END_MESSAGE_MAP()
//// 전 버튼의 ID
//int firstID = 0;
//// 현재 누른 버튼의ID
//int secondID = 0;
//// 짝수번으로 선택한 버튼인 상황에서 이전 버튼과 다를경우를 세기위해.
//int even = 0, check = 1;
//// 버튼 비활성화, 사라짐
//void CMFCApplication2Dlg::ClikBTN(int IDsecond, int IDfirst, int num) {
//	GetDlgItem(IDsecond)->EnableWindow(false);
//	// 현재 id가 1007 이하일때
//	int id1 = IDsecond + 8;
//	if (IDsecond < 1008) {
//		if (IDfirst == id1) {
//			GetDlgItem(IDfirst)->ShowWindow(false);
//			GetDlgItem(IDsecond)->ShowWindow(false);
//		}
//		if (IDfirst != id1 && num == 0) {
//			GetDlgItem(IDfirst)->EnableWindow(true);
//			GetDlgItem(IDsecond)->EnableWindow(true);
//		}
//	}
//	// 현재 id가 1008이상 1015 이하일때
//	int id2 = IDsecond - 8;
//	if (IDsecond < 1016 && IDsecond > 1007) {
//		if (IDfirst == id2) {
//			GetDlgItem(IDfirst)->ShowWindow(false);
//			GetDlgItem(IDsecond)->ShowWindow(false);
//		}
//		if (IDfirst != id2 && num == 0) {
//			GetDlgItem(IDfirst)->EnableWindow(true);
//			GetDlgItem(IDsecond)->EnableWindow(true);
//		}
//	}
//}
//// 버튼 클릭시
//void CMFCApplication2Dlg::Onbutton1(UINT ID) {
//	even = check % 2;
//	firstID = secondID;
//	secondID = ID;
//	ClikBTN(secondID, firstID, even);
//	check++;
//}
//// 리셋
//void CMFCApplication2Dlg::OnBnClickedReset()
//{
//	for (int i = 0; i < 16; i++) {
//		GetDlgItem(IDC_BTN01 + i)->ShowWindow(true);
//		GetDlgItem(IDC_BTN01 + i)->EnableWindow(true);
//	}
//	check = 1;
//	even = 0;
//	firstID = 0;
//	secondID = 0;
//}