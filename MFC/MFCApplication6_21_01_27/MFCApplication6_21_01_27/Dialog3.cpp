// Dialog3.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication6_21_01_27.h"
#include "Dialog3.h"
#include "afxdialogex.h"


// CDialog3 대화 상자

IMPLEMENT_DYNAMIC(CDialog3, CDialogEx)

CDialog3::CDialog3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CDialog3::~CDialog3()
{
}

void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialog3 메시지 처리기


void CDialog3::OnBnClickedButton1()
{
	MessageBox(L"다이얼로그3", MB_OK);
}
