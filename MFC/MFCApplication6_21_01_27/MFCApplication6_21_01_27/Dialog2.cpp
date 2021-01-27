// Dialog2.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication6_21_01_27.h"
#include "Dialog2.h"
#include "afxdialogex.h"


// CDialog2 대화 상자

IMPLEMENT_DYNAMIC(CDialog2, CDialogEx)

CDialog2::CDialog2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CDialog2::~CDialog2()
{
}

void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialog2 메시지 처리기


void CDialog2::OnBnClickedButton1()
{
	MessageBox(L"다이얼로그2", MB_OK);
}
