#pragma once


// Hub dialog

class Hub : public CDialog
{
	DECLARE_DYNAMIC(Hub)

public:
	Hub(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Hub();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HUB_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int creativity;
	int implementation;
	int professionalism;
	int graphic_design;
	int work_flow;
	CString other_notes_box;
	afx_msg void OnBnClickedButtonSubmit();
	afx_msg void OnBnClickedButtonLoadLastFeedback();
};
