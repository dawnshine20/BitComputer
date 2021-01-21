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

}

CSubDlg::~CSubDlg()
{
}

void CSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubDlg, CDialogEx)
END_MESSAGE_MAP()


// CSubDlg 메시지 처리기


BOOL CSubDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMFCMainDlg* pMain = new CMFCMainDlg;

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW();
	//((CEdit*)GetDlgItem(IDC_EDIT5))->SetWindowTextW();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
