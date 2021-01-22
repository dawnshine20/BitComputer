#pragma once
//클래스 안에 클래스를 사용하기 위해서 헤더파일이 헤더파일을 거는 유일한 경우 사용
//클래스 안에 클래스를 사용하는 경우가 아니면 헤더파일 사용하지 않는편이 좋음
class CMFCApplication5ModelessDlg;

// CDialog1 대화 상자
class CDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog1)

public:
	CDialog1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDialog1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	virtual void PostNcDestroy();

public:
	CMFCApplication5ModelessDlg* pParent;
	afx_msg void OnClose();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
};
