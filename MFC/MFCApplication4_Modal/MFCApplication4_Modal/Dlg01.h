#pragma once


// CDlg01 대화 상자

class CDlg01 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg01)

public:
	CDlg01(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg01();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();

public:
	int m_data1;
	int m_data2;
	int m_data3;

};


