// SubDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication4_Modal_ClassVersion.h"
#include "SubDlg.h"
#include "afxdialogex.h"
#include "MFCApplication4_Modal_ClassVersionDlg.h"
#include "MyClass1.h"

// CSubDlg 대화 상자

IMPLEMENT_DYNAMIC(CSubDlg, CDialogEx)

CSubDlg::CSubDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SubDlg, pParent)
{
	this->pMainDlg = (CMFCMainDlg*)pParent;
}

CSubDlg::~CSubDlg()
{
}

void CSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSubDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSubDlg 메시지 처리기


BOOL CSubDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int data1 = pMainDlg->myClass->GetData1();
	int data2 = pMainDlg->myClass->GetData2();
	CString strData1;
	CString strData2;
	strData1.Format(L"%d", data1);
	strData2.Format(L"%d", data2);

	((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(strData1);
	((CEdit*)GetDlgItem(IDC_EDIT5))->SetWindowTextW(strData2);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSubDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pMainDlg->myClass->SetData3(GetDlgItemInt(IDC_EDIT6));
	OnOK();
}
