
// MFCApplication2_StockProgramDlg.h: 헤더 파일
//

#pragma once


// CMFCApplication2StockProgramDlg 대화 상자
class CMFCApplication2StockProgramDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication2StockProgramDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_STOCKPROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	CComboBox m_combo1;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRightbutton();
	afx_msg void OnBnClickedLeftbutton();
	afx_msg void OnLbnSelchangeLeftlist();
	afx_msg void OnLbnSelchangeRightlist();
	afx_msg void OnBnClickedCallingUpButton();
	afx_msg void DistincVIP(UINT id);
};
