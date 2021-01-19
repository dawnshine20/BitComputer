
// MFCApplication2_StockProgramDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2_StockProgram.h"
#include "MFCApplication2_StockProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <locale.h>


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


// CMFCApplication2StockProgramDlg 대화 상자



CMFCApplication2StockProgramDlg::CMFCApplication2StockProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_STOCKPROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2StockProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
}

BEGIN_MESSAGE_MAP(CMFCApplication2StockProgramDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2StockProgramDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2StockProgramDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication2StockProgramDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication2StockProgramDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RIGHTBUTTON, &CMFCApplication2StockProgramDlg::OnBnClickedRightbutton)
	ON_BN_CLICKED(IDC_LEFTBUTTON, &CMFCApplication2StockProgramDlg::OnBnClickedLeftbutton)
	ON_LBN_SELCHANGE(IDC_LEFTLIST, &CMFCApplication2StockProgramDlg::OnLbnSelchangeLeftlist)
	ON_LBN_SELCHANGE(IDC_RIGHTLIST, &CMFCApplication2StockProgramDlg::OnLbnSelchangeRightlist)
	ON_BN_CLICKED(IDC_CALLING_UP_BUTTON, &CMFCApplication2StockProgramDlg::OnBnClickedCallingUpButton)
	ON_COMMAND_RANGE(IDC_RADIO1, IDC_RADIO2, DistincVIP) // 메세지 콜 함수를 만들어줌
END_MESSAGE_MAP()


class CStockProgram {
private:
	int purchasePrice;
	int sellingPrice;
	int number;
	int totalPrice;
	float netProfit;
	float feeRate;
	float feePrice;
	bool checkedFee;
	bool isVIP;

public:
	CStockProgram() {
		isVIP = false;
	}

	void SetCheckedFee(bool IsChecked){
		this->checkedFee = IsChecked;
	}

	void SetPrice(int purchasePrice, int sellingPrice, int number) {
		this->purchasePrice = purchasePrice;
		this->sellingPrice = sellingPrice;
		this->number = number;
	}
	void SetFeeRate(int Rate)
	{
		if (isVIP)
		{
			this->feeRate = (0.3 / 100);// 국가 세금만 적용
			return;
		}

		feeRate = ((float)Rate / 100/ 100) + (0.3 / 100); //증권사별(0.01~0.05%)+ 국가 세금 (0.3%)
	}

	float GetFeeRate()
	{
		return feeRate;
	}

	int CalculTotalPrice() {
		totalPrice = sellingPrice * number;
		return totalPrice;
	}

	float CalculFeePrice() {
		feePrice = totalPrice * feeRate;
		return feePrice;
	}

	float CalculNetProfit() {
		float tempRate;
		if (!checkedFee)
			tempRate = 0;
		else
			tempRate = feeRate;

		this->CalculTotalPrice();
		float temp = (totalPrice * (1 - tempRate)); // 100% - 0.31%
		netProfit = (temp - (float)(purchasePrice * number));
		return netProfit;
	}

	void DistincVIP(bool isVIP)
	{
		this->isVIP = isVIP;
	}
};
CStockProgram* User = new CStockProgram;

void CMFCApplication2StockProgramDlg::DistincVIP(UINT id) {
	
	switch (id) {
	case IDC_RADIO1:
	{
		User->DistincVIP(false);
		//SendMessage(IDC_BUTTON1);
	}break;
	case IDC_RADIO2: {
		User->DistincVIP(true);
		//SendMessage(IDC_BUTTON1);
	}break;
	default:
		User->DistincVIP(false);
		//SendMessage(IDC_BUTTON1);
	}
}

// CMFCApplication2StockProgramDlg 메시지 처리기

BOOL CMFCApplication2StockProgramDlg::OnInitDialog()
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
	const CString strAry[3] = { // 증권사 설정
		_T("대신증권"),
		_T("LG증권"),
		_T("삼성증권")
	};
	const int feeRateAry[3] = { // 증권사별 수수료 설정
		1, 3, 5 //0.001%, 0.003%...
	};
	CComboBox* pComboBox = ((CComboBox*)GetDlgItem(IDC_COMBO1));

	int strSize = sizeof(strAry) / sizeof(strAry[0]);
	for (int i = 0; i < strSize; i++)
	{
		pComboBox->AddString(strAry[i]);
		pComboBox->SetItemData(i, feeRateAry[i]);
	}
	pComboBox->SetCurSel(0);

	//-----선택된 콤보박스 내 데이터 -> 수수료율로 전환------
	UINT selectedNum = m_combo1.GetCurSel();
	CString strSelectedNum;

	int feeData = m_combo1.GetItemData(selectedNum);
	User->SetFeeRate(feeData);
	
	CString strFeeData;
	strFeeData.Format(_T("%.2f %%"), User->GetFeeRate() * 100);
	SetDlgItemText(IDC_STATIC1, strFeeData);

	//-----수수료 적용여부 확인-----
	bool state = IsDlgButtonChecked(IDC_CHECK1);
	User->SetCheckedFee(state ? true : false);

	//----- 초기 버튼 비활성화시키기 -----
	((CButton*)GetDlgItem(IDC_LEFTBUTTON))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_RIGHTBUTTON))->EnableWindow(false);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication2StockProgramDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication2StockProgramDlg::OnPaint()
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
HCURSOR CMFCApplication2StockProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2StockProgramDlg::OnBnClickedButton1()
{
	CString strPurchasePrice, strSellingasePrice, strNumber;

	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowTextW(strPurchasePrice);
	int PurchasePrice = _ttoi(strPurchasePrice);
	((CEdit*)GetDlgItem(IDC_EDIT2))->GetWindowTextW(strSellingasePrice);
	int SellingasePrice = _ttoi(strSellingasePrice);
	((CEdit*)GetDlgItem(IDC_EDIT3))->GetWindowTextW(strNumber);
	int number = _ttoi(strNumber);

	User->SetPrice(PurchasePrice, SellingasePrice, number);
	

	int totalPrice;
	float netProfit;
	float feePrice;
	totalPrice = User->CalculTotalPrice();
	netProfit = User->CalculNetProfit();
	feePrice = User->CalculFeePrice();
	
	CString strTotalPrice, strNetProfit, strFeePrice;

	strTotalPrice.Format(_T("%d 원"), totalPrice);
	strNetProfit.Format(_T("%.1f 원"), netProfit);
	strFeePrice.Format(_T("%.1f 원"), feePrice);
	
	
	((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(strTotalPrice);
	((CEdit*)GetDlgItem(IDC_EDIT5))->SetWindowTextW(strNetProfit);
	((CEdit*)GetDlgItem(IDC_EDIT6))->SetWindowTextW(strFeePrice);
}


void CMFCApplication2StockProgramDlg::OnBnClickedButton2()
{
	MessageBox(TEXT("종료합니다."));
	OnOK();
}


void CMFCApplication2StockProgramDlg::OnCbnSelchangeCombo1()
{
	//SetFeeRate()
	UINT selectedNum = m_combo1.GetCurSel();
	//selNum to string

	int feeData = m_combo1.GetItemData(selectedNum);
	User->SetFeeRate(feeData);

	CString strFeeData;
	strFeeData.Format(_T("%.2f %%"), User->GetFeeRate()*100);
	SetDlgItemText(IDC_STATIC1, strFeeData);
}

void CMFCApplication2StockProgramDlg::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bool state = IsDlgButtonChecked(IDC_CHECK1);

	User->SetCheckedFee(state ? true : false);
}

//----- 우측 이동 버튼 클릭시 오른쪽 리스트에 데이터 넣고 버튼 비활성화-----
void CMFCApplication2StockProgramDlg::OnBnClickedRightbutton()
{
	CListBox* pLeftListBox = (CListBox*)GetDlgItem(IDC_LEFTLIST);
	CListBox* pRightListBox = (CListBox*)GetDlgItem(IDC_RIGHTLIST);

	CString strCompanyName;

	UINT index = pLeftListBox->GetCurSel();
	pLeftListBox->GetText(index, strCompanyName);
	pLeftListBox->DeleteString(index);

	pRightListBox->AddString(strCompanyName);

	((CButton*)GetDlgItem(IDC_RIGHTBUTTON))->EnableWindow(false);
}

//----- 좌측 이동 버튼 클릭시 좌측 리스트에 데이터 넣고 버튼 비활성화-----
void CMFCApplication2StockProgramDlg::OnBnClickedLeftbutton()
{
	CListBox* pLeftListBox = (CListBox*)GetDlgItem(IDC_LEFTLIST);
	CListBox* pRightListBox = (CListBox*)GetDlgItem(IDC_RIGHTLIST);

	CString strCompanyName;

	UINT index = pRightListBox->GetCurSel();
	pRightListBox->GetText(index, strCompanyName);
	pRightListBox->DeleteString(index);

	pLeftListBox->AddString(strCompanyName);

	((CButton*)GetDlgItem(IDC_LEFTBUTTON))->EnableWindow(false);
}

// ----- (방어적 코드) 리스트박스 안에 데이터가 선택되었을때만 이동 가능하도록 버튼 활성화시킨다.-----
void CMFCApplication2StockProgramDlg::OnLbnSelchangeRightlist()
{
	((CButton*)GetDlgItem(IDC_LEFTBUTTON))->EnableWindow(true);
}

// -----(방어적 코드) 리스트박스 안에 데이터가 선택되었을때만 이동 가능하도록 버튼 활성화시킨다.-----
void CMFCApplication2StockProgramDlg::OnLbnSelchangeLeftlist()
{
	((CButton*)GetDlgItem(IDC_RIGHTBUTTON))->EnableWindow(true);
}





void CMFCApplication2StockProgramDlg::OnBnClickedCallingUpButton()
{
	//-----리스트박스 초기화-----
	((CListBox*)GetDlgItem(IDC_LEFTLIST))->ResetContent();
	((CListBox*)GetDlgItem(IDC_RIGHTLIST))->ResetContent();

	//-----txt파일 읽어오기--------
	CStdioFile readFile;
	CString m_strPath;
	CFileException ex;
	CFileDialog dlg(TRUE, _T("*.txt"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("TXT Files(*.txt)|*.txt|"), NULL);
	CString str, getFileString;

	setlocale(LC_ALL, "korean");
	if (dlg.DoModal() == IDOK)
	{
		m_strPath = dlg.GetPathName();
		readFile.Open(m_strPath, CFile::modeReadWrite | CFile::typeText, &ex);

		CListBox* pListBoxLeft = (CListBox*)GetDlgItem(IDC_LEFTLIST);

		while (readFile.ReadString(str))
		{
			//주의!) 메모장 ansi 파일로 저장할 것
			//--txt파일에서 읽어온 문자열 버퍼, 리스트 박스에 쓰기 및 저장--
			getFileString += (str + _T('\n'));
			pListBoxLeft->AddString(getFileString);
		}

		readFile.Close();

		//--txt파일에서 읽어온 긴 문자열을 'n' 기준으로 쪼개서  -> 배열 내에 저장하기--
		CString companyList[3];
		for (int i = 0; i < 3; i++)
		{
			AfxExtractSubString(companyList[i], getFileString, i, '\n');
		}
		//
		//CListBox* pListBoxLeft = (CListBox*)GetDlgItem(IDC_LEFTLIST);
		//
		//for (int i = 0; i < 3; i++)
		//{
		//	pListBoxLeft->AddString(companyList[i]);
		//}
	}
}
