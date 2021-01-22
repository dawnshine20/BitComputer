

#pragma once
class CDialog1;
// CMFCApplication5ModelessDlg 대화 상자
class CMFCApplication5ModelessDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication5ModelessDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION5_MODELESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CDialog1* Dialog1 = NULL;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
