
// MFCApplication2Dlg.h : header file
//
#include "Clist.h"
#pragma once


// CMFCApplication2Dlg dialog
class CMFCApplication2Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	Clist* course;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	CString course_name;
	int course_number;
	afx_msg void OnBnClickedAddordelete();
	afx_msg void OnBnClickedGetList();
	CString left_info_box;
	CString student_name;
	int student_id;
	int student_course_number;
	afx_msg void OnBnClickedAddOrDeleteStudent();
	int left_info_box_course_number;
	int update_grade_section_id;
	int new_grade;
	int update_grade_section_course_number;
	afx_msg void OnBnClickedUpdateStudentGrade();
	afx_msg void OnBnClickedRenameCourse();
	CString new_name;
	int course_number_rename_course;
	CString message_box;
	CString right_info_box;
	afx_msg void OnBnClickedGetScores();

	afx_msg void OnBnClickedFeedback();
};
