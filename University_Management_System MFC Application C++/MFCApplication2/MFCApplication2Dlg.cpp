
// MFCApplication2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "Hub.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg dialog



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, course_name(_T("Enter name"))
	, course_number(1111)
	, left_info_box(_T(""))
	, student_name(_T("Enter name"))
	, student_id(123456789)
	, student_course_number(1111)
	, left_info_box_course_number(0)
	, update_grade_section_id(123456789)
	, new_grade(0)
	, update_grade_section_course_number(1111)
	, new_name(_T("Enter name"))
	, course_number_rename_course(1111)
	, message_box(_T("Message Box"))
	, right_info_box(_T(""))

{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, course_name);
	DDX_Text(pDX, IDC_EDIT2, course_number);
	DDV_MinMaxInt(pDX, course_number, 1, 9999);
	DDX_Text(pDX, IDC_EDIT_LEFT_INFO_BOX, left_info_box);
	DDX_Text(pDX, IDC_EDIT_STUDENT_NAME, student_name);
	DDX_Text(pDX, IDC_EDIT_STUDENT_ID, student_id);
	DDV_MinMaxInt(pDX, student_id, 1, INT_MAX);
	DDX_Text(pDX, IDC_EDIT_STUDENT_COURSE_NUMBER, student_course_number);
	DDV_MinMaxInt(pDX, student_course_number, 1, 9999);
	DDX_Text(pDX, IDC_EDIT_LEFT_INFO_BOX_COURSE_NUMBER, left_info_box_course_number);
	DDV_MinMaxInt(pDX, left_info_box_course_number, 0, 9999);
	DDX_Text(pDX, IDC_EDIT_UPDATE_ID, update_grade_section_id);
	DDV_MinMaxInt(pDX, update_grade_section_id, 1, INT_MAX);
	DDX_Text(pDX, IDC_EDIT_UPDATE_NEW_GRADE, new_grade);
	DDV_MinMaxInt(pDX, new_grade, 0, 100);
	DDX_Text(pDX, IDC_EDIT_UPDATE_COURSE_NUMBER, update_grade_section_course_number);
	DDV_MinMaxInt(pDX, update_grade_section_course_number, 1, 9999);
	DDX_Text(pDX, IDC_EDIT_RENAME_NEW_NAME, new_name);
	DDV_MaxChars(pDX, new_name, 100);
	DDX_Text(pDX, IDC_EDIT_RENAME_COURSE_NUMBER, course_number_rename_course);
	DDV_MinMaxInt(pDX, course_number_rename_course, 1, 9999);
	DDX_Text(pDX, IDC_EDIT_MESSAGE_BOX, message_box);
	DDV_MaxChars(pDX, message_box, 200);
	DDX_Text(pDX, IDC_EDIT_RIGHT_INFO_BOX, right_info_box);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_EXIT, &CMFCApplication2Dlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_ADDORDELETE, &CMFCApplication2Dlg::OnBnClickedAddordelete)
	ON_BN_CLICKED(IDC_GET_LIST, &CMFCApplication2Dlg::OnBnClickedGetList)
	ON_BN_CLICKED(IDC_ADD_OR_DELETE_STUDENT, &CMFCApplication2Dlg::OnBnClickedAddOrDeleteStudent)
	ON_BN_CLICKED(IDC_UPDATE_STUDENT_GRADE, &CMFCApplication2Dlg::OnBnClickedUpdateStudentGrade)
	ON_BN_CLICKED(IDC_RENAME_COURSE, &CMFCApplication2Dlg::OnBnClickedRenameCourse)
	ON_BN_CLICKED(IDC_GET_SCORES, &CMFCApplication2Dlg::OnBnClickedGetScores)
	
	ON_BN_CLICKED(IDC_Feedback, &CMFCApplication2Dlg::OnBnClickedFeedback)
END_MESSAGE_MAP()


// CMFCApplication2Dlg message handlers

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication2Dlg::OnBnClickedExit()
{
	
	exit(1);
	
	// TODO: Add your control notification handler code here
}

//void delay(int a)
//{
//	int add = 0;
//	int time = 0;
//	int i;
//	time = a * 100000000;
//	for (i = 0; i < time; i++)
//	{
//		add *= i;
//		add++;
//		add++;
//	}
//}

void CMFCApplication2Dlg::OnBnClickedAddordelete()
{
	UpdateData(TRUE);
	
	Clist* head = course;
	Clist* curr = head;
	Clist* check_duplicate = curr;


	if ((course_name != "Enter name" && course_name != "") && course_number > 0)
	{
		if ((check_duplicate->Search_Duplicates(check_duplicate, course_number)))
		{
			message_box.Format(_T(" Course alrady in system.\n"));
			UpdateData(FALSE);

			return;
		}

		if (course == NULL)
		{
			course = course->Create_Element(course_number, course_name);
			curr = course;
		}
		else
		{
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = course->Create_Element(course_number, course_name);
		}

		message_box.Format(_T(" Course added.\n"));
		UpdateData(FALSE);

	}
	else if (curr != NULL)
	{
		if (curr == course && course_number == course->course_num)
		{
			course = course->next;
			curr->Delete_Course(curr, course_number);
			message_box.Format(_T(" Course Deleted.\n"));
			UpdateData(FALSE);
		}
		else
		{
			curr->Delete_Course(curr, course_number);

			message_box.Format(_T(" Course Deleted.\n"));
			UpdateData(FALSE);
		}
	}
	else
	{

		message_box.Format(_T("No course in system.\n"));
		UpdateData(FALSE);
	}

	// TODO: Add your control notification handler code here
}



void CMFCApplication2Dlg::OnBnClickedGetList()
{
	UpdateData(TRUE);
	message_box.Format(_T(""));
	UpdateData(FALSE);

	UpdateData(TRUE);
	Clist* head = course;
	Clist* curr = head;
	Slist* student = NULL;

	if (left_info_box_course_number != 0)
	{
		while (curr != NULL)
		{
			if (left_info_box_course_number == curr->course_num)
			{
				if (student == NULL)
				{
					student = curr->student;
				}

				left_info_box.Format(_T(""));
				while (student != NULL)
				{
					//UpdateData(TRUE);

					left_info_box.AppendFormat(_T("Student name: %s, Student id: %d, grade: %d \r\n"), student->Get_Student_Name(), student->Get_Student_Id(), student->Get_Student_Grade());
					student = student->Go_Next(student);

					UpdateData(FALSE);
				}
			}
			curr = curr->next;
		}
	}
	else
	{
		
		left_info_box.Format(_T(""));
		while (curr != NULL)
		{
			left_info_box.AppendFormat(_T("Course name: %s, course number: %d \r"), curr->name, curr->course_num);
			left_info_box.AppendFormat(_T("\n"));

			curr = curr->next;
			UpdateData(FALSE);
		}
	}
	UpdateData(FALSE);

	// TODO: Add your control notification handler code here
}


void CMFCApplication2Dlg::OnBnClickedAddOrDeleteStudent()
{
	UpdateData(TRUE);
	Clist* runner = course;

	left_info_box.Format(_T(""));
	while (runner != NULL)
	{
		if ((runner->course_num == student_course_number))
		{
			break;
		}
		if (runner->next == NULL)
		{
			message_box.Format(_T(" Course not found.\n"));
			UpdateData(FALSE);
			return;
		}
		runner = runner->next;
	}


	if ((student_name != "Enter name" && student_name != "") && student_course_number > 0)
	{
		Clist* head = course;
		Clist* curr = head;
		Slist* student = course->Create_student(student_name, student_id);


		runner = course;
		Slist* check = NULL;		

		while (runner != NULL)
		{
			if ((runner->Search_Student(&runner, student_id)))
			{
				check = runner->Search_Student(&runner, student_id);
				break;
			}
			runner = runner->next;
		}
		
		runner = course;
		while (runner->course_num != student_course_number)
		{
			runner = runner->next;
			if (runner == NULL)
				break;
		}
		if ((runner->Search_Student(&runner, student_id)))
		{
			message_box.Format(_T(" student already exist.\n"));
			UpdateData(FALSE);
			return;
		}
		if (check != NULL)
		if ( (check->Get_Student_Id() == student_id) && (check->Get_Student_Name() != student_name))
		{
			message_box.Format(_T(" Name doesn't match to existing ID .\n"));
			UpdateData(FALSE);
			return;
		}



		curr->Add_Student_To_Course(curr, student, student_course_number);

		left_info_box.Format(_T(""));
		message_box.Format(_T(" Student added.\n"));
		UpdateData(FALSE);
	}
	else if ((student_name == "Enter name" || student_name == "") && student_course_number > 0 && student_id > 0)
	{
		// delete student

		Clist* head = course;
		Clist* curr = head;
		int stats;
		stats = curr->Delete_Student(curr, student_id, student_course_number);	

		message_box.AppendFormat(_T(" Student Deleted.\n"));
		UpdateData(FALSE);
	}

	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CMFCApplication2Dlg::OnBnClickedUpdateStudentGrade()
{
	UpdateData(TRUE);
	left_info_box.Format(_T(""));
	UpdateData(FALSE);

	Clist* head = course;
	Clist* curr = head;
	Slist* student = NULL;
	
	message_box.Format(_T(""));

	while (curr != NULL)
	{
		if (curr->course_num == update_grade_section_course_number)
		{
			student = curr->student;
			break;
		}
		curr = curr->next;
	}

	if (curr == NULL)             // course not in list.
	{
		message_box.Format(_T(" Course not found.\n"));
		UpdateData(FALSE);
		return;
	}

	while (student != NULL)
	{
		if (student->Get_Student_Id() == update_grade_section_id)
		{
			student->Set_Grade(student, new_grade);

			message_box.Format(_T("Grade updated."));
			UpdateData(FALSE);
			break;
		}
		student = student->Go_Next(student);
	}

	if (student == NULL)     // student not in list.
	{
		message_box.Format(_T(" Student not found.\n"));
		UpdateData(FALSE);
	}
	

	UpdateData(FALSE);
	
	
	// TODO: Add your control notification handler code here
}


void CMFCApplication2Dlg::OnBnClickedRenameCourse()
{
	UpdateData(TRUE);
	left_info_box.Format(_T(""));
	UpdateData(FALSE);

	Clist* head = course;
	Clist* curr = head;
	
	while (curr != NULL)
	{
		if (curr->course_num == course_number_rename_course)
		{
			curr->Rename_course(new_name);
		
			message_box.Format(_T(" Course name updated.\n"));	
			UpdateData(FALSE);
			break;
		}
		curr = curr->next;
	}
	
	if (curr == NULL)
	{
		message_box.Format(_T(" Course not found.\n"));
	}

	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CMFCApplication2Dlg::OnBnClickedGetScores()
{
	UpdateData(TRUE);

	Clist* course_head = course;
	Clist* course_current = course_head;
	Slist* student = NULL;
	int Average_course_score, minimum_grade_in_course, maximum_grade_in_course, grade_sum, number_of_students;
	
	right_info_box.Format(_T(""));
	UpdateData(FALSE);

	message_box.Format(_T(""));
	UpdateData(FALSE);

	while (course_current != NULL)
	{
		
		student = course_current->student;
		course_current->Print_All_Coursses_computed_scorse(student, Average_course_score, minimum_grade_in_course, maximum_grade_in_course, grade_sum, number_of_students);
		
		right_info_box.AppendFormat(_T(" Course Number: %d ---- Course name: %s \r\n ----------------------------------------------------------\r\n Computed scores: \r\n A. Average score: %d \r\n B. Minimum score: %d \r\n C. Maximum score: %d \r\n D. Grades sum: %d \r\n E. Number of students: %d \r\n  =========================================\r\n"),
			course_current->course_num, course_current->name, Average_course_score, minimum_grade_in_course, maximum_grade_in_course, grade_sum, number_of_students);
		
		course_current = course_current->next;
		
		UpdateData(FALSE);
			
	}
	UpdateData(FALSE);
	


	// TODO: Add your control notification handler code here
}





void CMFCApplication2Dlg::OnBnClickedFeedback()
{


	UpdateData(TRUE);
	
	Hub go;
	go.DoModal();
	
	UpdateData(FALSE);


	// TODO: Add your control notification handler code here
}
