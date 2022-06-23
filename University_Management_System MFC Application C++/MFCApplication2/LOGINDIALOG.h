#pragma once


// LOGINDIALOG dialog

class LOGINDIALOG : public CDialogEx
{
	DECLARE_DYNAMIC(LOGINDIALOG)

public:
	LOGINDIALOG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~LOGINDIALOG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOG_IN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString usern;
	CString passw;
	afx_msg void OnBnClickedButtonlogin();
	CString phone_number;
	afx_msg void OnBnClickedButtongethint();
};
