#pragma once


// CModalessDlg 대화 상자

class CModalessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModalessDlg)

public:
	CModalessDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CModalessDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

public:
	byte rData;
	byte gData;
	byte bData;
	virtual BOOL OnInitDialog();
};
