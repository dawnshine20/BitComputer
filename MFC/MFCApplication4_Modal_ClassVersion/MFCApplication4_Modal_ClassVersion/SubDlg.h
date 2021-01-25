#pragma once


// CSubDlg 대화 상자
class CMFCMainDlg;
class CSubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg)

public:
	CSubDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSubDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SubDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMFCMainDlg* pMainDlg;
	afx_msg void OnBnClickedButton1();
};
