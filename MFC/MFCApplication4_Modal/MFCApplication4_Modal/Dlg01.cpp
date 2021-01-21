// Dlg01.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication4_Modal.h"
#include "Dlg01.h"
#include "afxdialogex.h"


// CDlg01 대화 상자

IMPLEMENT_DYNAMIC(CDlg01, CDialogEx)

CDlg01::CDlg01(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlg01::~CDlg01()
{
}

void CDlg01::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg01, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg01::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlg01 메시지 처리기


BOOL CDlg01::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemInt(IDC_EDIT4, m_data1);
	SetDlgItemInt(IDC_EDIT5, m_data2);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg01::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_data3 = GetDlgItemInt(IDC_EDIT6) + m_data1 + m_data2;
	OnOK();
}
