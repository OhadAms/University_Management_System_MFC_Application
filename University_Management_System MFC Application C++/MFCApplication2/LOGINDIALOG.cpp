// LOGINDIALOG.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication2.h"
#include "LOGINDIALOG.h"
#include "afxdialogex.h"
#include "Base_Abstract_system.h"
#include "MFCApplication2Dlg.h"
#include <afxwin.h>

// LOGINDIALOG dialog

IMPLEMENT_DYNAMIC(LOGINDIALOG, CDialogEx)

LOGINDIALOG::LOGINDIALOG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOG_IN_DIALOG, pParent)
	, usern(_T(""))
	, passw(_T(""))
	, phone_number(_T(""))
{

}

LOGINDIALOG::~LOGINDIALOG()
{
}

void LOGINDIALOG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, usern);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, passw);
	DDX_Text(pDX, IDC_EDIT_PHONE_NUMBER, phone_number);
}


BEGIN_MESSAGE_MAP(LOGINDIALOG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONLOGIN, &LOGINDIALOG::OnBnClickedButtonlogin)
	ON_BN_CLICKED(IDC_BUTTONGETHINT, &LOGINDIALOG::OnBnClickedButtongethint)
END_MESSAGE_MAP()


// LOGINDIALOG message handlers


void LOGINDIALOG::OnBnClickedButtonlogin()
{
	UpdateData(TRUE);
	Base_Abstract_system login;
	CMFCApplication2Dlg go;
	if(login.Autehorization(passw, usern))
	{
		go.DoModal();
	}
	else
	{
		AfxMessageBox(_T("Invalid username or password, Try again"));
	}
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void LOGINDIALOG::OnBnClickedButtongethint()
{
	UpdateData(TRUE);

	if (phone_number == "" || phone_number == "")
	{
		phone_number.Format(_T("Username: me\r\n Password: 123456789 \r\n Please type it, don't copy past.."));
		/*phone_number.AppendFormat(_T("Password: 123456789"));*/
		UpdateData(FALSE);
	}
	else
	{
		phone_number.Format(_T("Incorrect phone number.\n"));
		UpdateData(FALSE);
	}

	// TODO: Add your control notification handler code here
}
