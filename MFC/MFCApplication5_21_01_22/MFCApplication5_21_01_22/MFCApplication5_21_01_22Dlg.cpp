
// MFCApplication5_21_01_22Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5_21_01_22.h"
#include "MFCApplication5_21_01_22Dlg.h"
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


// CMFCApplication5210122Dlg 대화 상자



CMFCApplication5210122Dlg::CMFCApplication5210122Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION5_21_01_22_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication5210122Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication5210122Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication5210122Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication5210122Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication5210122Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication5210122Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication5210122Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMFCApplication5210122Dlg 메시지 처리기

BOOL CMFCApplication5210122Dlg::OnInitDialog()
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
	// 유일하게 m_hWnd는 public 변수이다.(논란이 있음)
	// HWND hWnd = ((CListCtrl*)GetDlgItem(IDC_LIST1))->m_hWnd;

	//막대바와 격자 라인 설정
	ListView_SetExtendedListViewStyle( // style은 외관 껍데기에 관한 세팅
		((CListCtrl*)GetDlgItem(IDC_LIST1))->m_hWnd,
		LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_TRACKSELECT
	);
	// 캡션 공통 속성 설정
	//내가 설정한 변수가 4개인데, 그 4개의 종류를 알려준다.
	LV_COLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;

	// 캡션항목에 대한 개별 설정
	CListCtrl* listCtrl = ((CListCtrl*)GetDlgItem(IDC_LIST1));
	lvColumn.pszText = L"이름";
	lvColumn.iSubItem = 0;
	lvColumn.cx = 60;
	listCtrl->InsertColumn(0, &lvColumn);

	lvColumn.pszText = L"소속학과";
	lvColumn.iSubItem = 1;
	lvColumn.cx = 70;
	listCtrl->InsertColumn(1, &lvColumn);
	
	lvColumn.pszText = L"수업시간";
	lvColumn.iSubItem = 2;
	lvColumn.cx = 80;
	listCtrl->InsertColumn(2, &lvColumn);

	TCHAR data[2][3][16] = {
		{L"홍길동", L"국문학과", L"10-13시"},
		{L"이순신", L"체육학과", L"11-12시" }
	};

	for (int i = 0; i < 2; i++)
	{
		int num = listCtrl->GetItemCount();
		LV_ITEM lvItem;

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = num; // 로우 번호 설정
		lvItem.iSubItem = 0;
		lvItem.pszText = &data[i][0][0];
		listCtrl->InsertItem(&lvItem);

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = num; // 로우 번호 설정
		lvItem.iSubItem = 1;
		lvItem.pszText = &data[i][1][0];
		listCtrl->SetItem(&lvItem);

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = num; // 로우 번호 설정
		lvItem.iSubItem = 2;
		lvItem.pszText = &data[i][2][0];
		listCtrl->SetItem(&lvItem);
	}
	
	//  이름        소속학과        수업시간		>> 캡션(테이블명)
	// 홍길동        국문학과       10-13시		>> row(로우),레코드
	// 홍길동        국문학과       10-13시

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication5210122Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication5210122Dlg::OnPaint()
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
HCURSOR CMFCApplication5210122Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Create or Insert();
void CMFCApplication5210122Dlg::OnBnClickedButton1()
{
	CString* p = new CString(L"호랑이");
	CString s(L"호랑이");
	CString t;
	t = L"무궁화"; // 연산자 재정의에 의해 = 가 사용될 수 있다.
	
	// 가상 데이타, 시뮬레이션 데이타, 모사 데이터
	// 랜덤...
	CString strCount, strName, strClass, strTime;
	static int AddCount = 0;
	AddCount++;

	strCount.Format(L"%d", AddCount);
	strName		= L"A 이름" + strCount;
	strClass	= L"A 학과" + strCount;
	strTime		= L"A 시간" + strCount;

	CListCtrl* ListCtrl = ((CListCtrl*)GetDlgItem(IDC_LIST1));
	int num = ListCtrl->GetItemCount();

	// 최적화와 관련성이 크지 않기 때문에 헷갈리지 않도록 중복되는 곳도 지우지 않는다.
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = num; // 로우 번호 설정
	lvItem.iSubItem = 0;
	lvItem.pszText = strName.GetBuffer(0);// strName의 시작주소 공유
	ListCtrl->InsertItem(&lvItem); // 복사가 되었을 것 memcpy가 일어났다.

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = num; // 로우 번호 설정
	lvItem.iSubItem = 1;
	lvItem.pszText = strClass.GetBuffer(0);
	ListCtrl->SetItem(&lvItem);

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = num; // 로우 번호 설정
	lvItem.iSubItem = 2;
	lvItem.pszText = strTime.GetBuffer(0);
	ListCtrl->SetItem(&lvItem);
	
	//---추가된 곳을 막대바로 보여준다.
	ListCtrl->SetItemState(
		num,
		LVIS_FOCUSED | LVIS_SELECTED,
		LVIS_FOCUSED | LVIS_SELECTED
	);
	ListCtrl->EnsureVisible(num, true);
	ListCtrl->SetFocus();
	//---

}


void CMFCApplication5210122Dlg::OnBnClickedButton2()
{
	CListCtrl* ListCtrl = ((CListCtrl*)GetDlgItem(IDC_LIST1));

	// 번호가 선택이 안되어있으면 -1이 반환된다.
	int num = ListCtrl->GetNextItem(-1, LVNI_SELECTED);
	if (num == -1) {
		MessageBox(L"수정할 항목을 선택하세요", MB_OK);
		return;
	}

	CString ModStr, NameStr, ClassStr, TimeStr;
	ModStr.Format(L"%d", num);
	NameStr		= L"A 이름" + ModStr;
	ClassStr	= L"A 학과" + ModStr;
	TimeStr		= L"A 시간" + ModStr;

	ListCtrl->SetItemText(num, 0, NameStr.GetBuffer(0));
	ListCtrl->SetItemText(num, 1, ClassStr.GetBuffer(0));
	ListCtrl->SetItemText(num, 2, TimeStr.GetBuffer(0));

}


void CMFCApplication5210122Dlg::OnBnClickedButton3()
{
	CListCtrl* ListCtrl = ((CListCtrl*)GetDlgItem(IDC_LIST1));

	// 번호가 선택이 안되어있으면 -1이 반환된다.
	int num = ListCtrl->GetNextItem(-1, LVNI_SELECTED);
	if (num == -1) {
		MessageBox(L"삭제할 항목을 선택하세요", MB_OK);
		return;
	}

	ListCtrl->DeleteItem(num);
}


void CMFCApplication5210122Dlg::OnBnClickedButton4()
{
	CListCtrl* ListCtrl = ((CListCtrl*)GetDlgItem(IDC_LIST1));

	LVFINDINFO fi;
	fi.flags = LVFI_STRING; // 문자열 검색
	fi.psz = L"홍길동";
	fi.vkDirection = VK_DOWN;
	// -1 인수는 처음부터 찾으라는 Start Position 알려주는것
	int num = ListCtrl->FindItem(&fi, -1); 
	if (num == -1) {
		MessageBox(L"검색실패", MB_OK); return;
	}

	ListCtrl->SetItemState(
		num,
		LVIS_FOCUSED | LVIS_SELECTED,
		LVIS_FOCUSED | LVIS_SELECTED
	);
	ListCtrl->EnsureVisible(num, true);
	ListCtrl->SetFocus();

}

// select
void CMFCApplication5210122Dlg::OnBnClickedButton5()
{
	CListCtrl* ListCtrl = ((CListCtrl*)GetDlgItem(IDC_LIST1));

	int selectIndex = 1;
	CString s1 = ListCtrl->GetItemText(selectIndex, 0);
	CString s2 = ListCtrl->GetItemText(selectIndex, 1);
	CString s3 = ListCtrl->GetItemText(selectIndex, 2);

	CString s4;
	s4.Format(L"%s %s %s", s1, s2, s3);

	MessageBox(s4, MB_OK);
}


//class CTiger {
//	~CTiger() {
//		delete this;
//	}
//};
//void f1() {
//	CTiger* p = new CTiger();
//	// 사용...
//}