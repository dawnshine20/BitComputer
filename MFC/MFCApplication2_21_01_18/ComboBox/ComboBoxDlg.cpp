
// ComboBoxDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ComboBox.h"
#include "ComboBoxDlg.h"
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


// CComboBoxDlg 대화 상자



CComboBoxDlg::CComboBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMBOBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
}

BEGIN_MESSAGE_MAP(CComboBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CComboBoxDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CComboBoxDlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CComboBoxDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_RIGHTBUTTON, &CComboBoxDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_LEFTBUTTON, &CComboBoxDlg::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST2, &CComboBoxDlg::OnLbnSelchangeList2)
END_MESSAGE_MAP()


// CComboBoxDlg 메시지 처리기

BOOL CComboBoxDlg::OnInitDialog()
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

	// 외부에서 텍스트 로딩된다.
	//const char* itemName = { "1", "2" };

	//----------- Init ListBox
	const CString strAry[4] =
	{
		_T("수박"), _T("참외"), _T("오렌지"), _T("자두")
	};
	CComboBox* pComboBox = ((CComboBox*)GetDlgItem(IDC_COMBO1));
	
	const int stringSize = sizeof(strAry) / sizeof(strAry[0]);
	for (int i = 0; i < stringSize; i++) {
		pComboBox->AddString(strAry[i]);
	}

	//((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("수박"));// 부모 함수에서 자식 함수로 캐스팅
	//CComboBox* pComboBox = ((CComboBox*)GetDlgItem(IDC_COMBO1));
	//
	//pComboBox->AddString(_T("참외"));
	//pComboBox->AddString(_T("오렌지"));
	//pComboBox->AddString(_T("자두"));
	
	
	pComboBox->SetItemData(0, 500); // 수박 변수 안에 500이라는 int값을 저장한다.
	pComboBox->SetItemData(1, 1500);
	pComboBox->SetItemData(2, 2500);
	pComboBox->SetItemData(3, 3500);
	
	pComboBox->SetCurSel(2);
	
	//------------ combo ->  editbox
	UINT selNum = m_combo1.GetCurSel();
	CString sn;
	//selNum to string
	m_combo1.GetLBText(selNum, sn);
	
	((CEdit*)GetDlgItem(IDC_EDIT1)) ->
		SetWindowTextW(sn);

	//------------ 리스트 박스
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	pListBox->AddString(_T("참외1"));
	pListBox->AddString(_T("참외2"));
	pListBox->AddString(_T("참외3"));
	pListBox->AddString(_T("참외4"));
	pListBox->SetCurSel(2);
	
	GetDlgItem(IDC_RIGHTBUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_LEFTBUTTON)->EnableWindow(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CComboBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CComboBoxDlg::OnPaint()
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
HCURSOR CComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//------------- 콤보 박스 내부 데이터가 선택될때
void CComboBoxDlg::OnCbnSelchangeCombo1()
{
	////MessageBox(TEXT("test"));
	////셀의 갯수를 얻는다.
	//UINT count = m_combo1.GetCount();
	//UINT selNum = m_combo1.GetCurSel();
	//UINT len = m_combo1.GetLBTextLen(selNum);
	//
	//// 선택된 번호의 해당 과일 이름을 얻어온다.
	//CString sn;
	//m_combo1.GetLBText(selNum,sn);
	//CString result;
	//result.Format(TEXT("%d %d %d %s"), count, selNum, len, sn);
	//
	//((CEdit*)GetDlgItem(IDC_EDIT1)) ->
	//	SetWindowTextW(sn);
	//
	//MessageBox(result);
}

//--------------버튼 클릭시 콤보박스 내부 데이터 삭제된다.
void CComboBoxDlg::OnBnClickedButton1()
{
	int num;
	if (m_combo1.GetCount() != 1)
		num = m_combo1.DeleteString(0);

	//CString s;
	//s.Format(_T("%d"), num);
	//OutputDebugString(s);
}


//-------------- 리스트박스 내부 데이터가 선택될때
void CComboBoxDlg::OnLbnSelchangeList1()
{
	//AddString();
	//GetCount();
	//GetCurSel();
	//SetCurSel();
	//GetText();
	//GetTextLen();
	//DeleteString();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//MessageBox(TEXT("동작"));

	GetDlgItem(IDC_RIGHTBUTTON)->EnableWindow(TRUE);
	
}

//---------- 버튼이 눌리면 리스트 박스 왼쪽->오른쪽으로 이동하는 메커니즘
void CComboBoxDlg::OnBnClickedButton2()
{
	CListBox* ListLeft = ((CListBox*)GetDlgItem(IDC_LIST1));
	CListBox* ListRight = ((CListBox*)GetDlgItem(IDC_LIST2));
	CString fruit;
	// 왼쪽 리스트 박스에서 옮겨질 셀 캡션 저장 후 삭제.
	UINT SelNum = ListLeft->GetCurSel();
	ListLeft->GetText(SelNum, fruit);
	ListLeft->DeleteString(SelNum);
	// 오른쪽 리스트 박스에 옮겨질 셀 생성.
	ListRight->AddString(fruit);
	//버튼 비활성화
	GetDlgItem(IDC_RIGHTBUTTON)->EnableWindow(FALSE);
}

//---------- 버튼이 눌리면 리스트 박스 오른쪽->왼쪽으로 이동하는 메커니즘
void CComboBoxDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CListBox* ListLeft = ((CListBox*)GetDlgItem(IDC_LIST1));
	CListBox* ListRight = ((CListBox*)GetDlgItem(IDC_LIST2));
	CString fruit;
	// 오른쪽 리스트 박스에서 옮겨질 셀 캡션 저장 후 삭제.
	// 선택되지 않았다면 GetCursSel은 -1 반환
	UINT SelNum = ListRight->GetCurSel();
	ListRight->GetText(SelNum, fruit);
	ListRight->DeleteString(SelNum);
	// 왼쪽 리스트 박스에 옮겨질 셀 생성.
	ListLeft->AddString(fruit);
	//버튼 비활성화
	GetDlgItem(IDC_LEFTBUTTON)->EnableWindow(FALSE);
}


void CComboBoxDlg::OnLbnSelchangeList2()
{
	// 1) -1 >> 0 1 2 3 4 5 갯수 (-1일 경우 실패)
	// 2) 0 >> true, false
	// 3) -1, -2, -3, -4: 실패의 이유를 숫자로 설명하는 것(에러 종류)
	GetDlgItem(IDC_LEFTBUTTON)->EnableWindow(TRUE);
}
