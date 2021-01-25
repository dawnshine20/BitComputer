// Dialog1.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication5_Modeless.h"
#include "Dialog1.h"
#include "afxdialogex.h"
#include "MFCApplication5_ModelessDlg.h"

// CDialog1 대화 상자

IMPLEMENT_DYNAMIC(CDialog1, CDialogEx)

CDialog1::CDialog1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	this->pParent = (CMFCApplication5ModelessDlg*)pParent;
}

CDialog1::~CDialog1()
{
}

void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialog1::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CDialog1 메시지 처리기


void CDialog1::OnBnClickedButton2()
{
	MessageBox(L"1", MB_OK);
	DestroyWindow();
	
}


//완전히 파괴되기 일보직전
void CDialog1::PostNcDestroy()
{
	MessageBox(L"2", MB_OK);
	pParent->Dialog1 = NULL;
	delete this;// 현재 모달리스창 메모리 해제

	CDialogEx::PostNcDestroy();
}

//위에 x표 누르면 wm_close 발생
void CDialog1::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnClose();
	MessageBox(L"3", MB_OK);
	DestroyWindow();
}

BOOL CDialog1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CSliderCtrl* sliderRed = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED));
	CSliderCtrl* sliderGreen = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN));
	CSliderCtrl* sliderBlue = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE));
	
	sliderRed->SetRange(0, 255, true);
	sliderRed->SetPos(127);
	sliderRed->SetTicFreq(10);
	sliderRed->SetLineSize(20);

	sliderGreen->SetRange(0, 255, true);
	sliderGreen->SetPos(127);
	sliderGreen->SetTicFreq(10);
	sliderGreen->SetLineSize(20);

	sliderBlue->SetRange(0, 255, true);
	sliderBlue->SetPos(127);
	sliderBlue->SetTicFreq(10);
	sliderBlue->SetLineSize(20);

	pParent->SetBackgroundColor(RGB(127, 127, 127));
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDialog1::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nSBCode == SB_ENDSCROLL) {
		return;
	}
	
	static UINT r, g, b;

	switch (pScrollBar->GetDlgCtrlID())
	{
		case IDC_SLIDER_RED:
			r = nPos;
			break;
		case IDC_SLIDER_GREEN:
			g = nPos;
			break;
		case IDC_SLIDER_BLUE:
			b = nPos;
			break;
	}
		
	pParent->SetBackgroundColor(RGB(r, g, b));
		

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}



