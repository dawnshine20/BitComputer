// Dialog1.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication6_21_01_27.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// CDialog1 대화 상자

IMPLEMENT_DYNAMIC(CDialog1, CDialogEx)

CDialog1::CDialog1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDialog1::~CDialog1()
{
}

void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialog1 메시지 처리기


void CDialog1::OnBnClickedButton1()
{
	MessageBox(L"Dialog 1", MB_OK);
}
