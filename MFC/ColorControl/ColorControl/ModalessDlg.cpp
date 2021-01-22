// ModalessDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ColorControl.h"
#include "ModalessDlg.h"
#include "afxdialogex.h"


// CModalessDlg 대화 상자

IMPLEMENT_DYNAMIC(CModalessDlg, CDialogEx)

CModalessDlg::CModalessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CModalessDlg::~CModalessDlg()
{
}

void CModalessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModalessDlg, CDialogEx)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CModalessDlg 메시지 처리기


void CModalessDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (nSBCode == SB_ENDSCROLL)
		return;

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

	rData = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED))->GetPos();
	gData = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN))->GetPos();
	bData = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE))->GetPos();

}


BOOL CModalessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
