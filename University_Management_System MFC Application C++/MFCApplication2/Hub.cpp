// Hub.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication2.h"
#include "Hub.h"
#include "afxdialogex.h"
#include "Feedbeck_base_class.h"
#include "Comments.h"
#include <iostream>
#include <list>
using namespace std;



// Hub dialog

IMPLEMENT_DYNAMIC(Hub, CDialog)

Hub::Hub(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_HUB_DIALOG, pParent)
	, creativity(1)
	, implementation(1)
	, professionalism(1)
	, graphic_design(1)
	, work_flow(1)
	, other_notes_box(_T(""))
{

}

Hub::~Hub()
{
}

void Hub::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CREATIVITY, creativity);
	DDV_MinMaxInt(pDX, creativity, 1, 10);
	DDX_Text(pDX, IDC_EDIT_IMPLEMENTATION, implementation);
	DDV_MinMaxInt(pDX, implementation, 1, 10);
	DDX_Text(pDX, IDC_EDIT_PROFFESIONALISM, professionalism);
	DDV_MinMaxInt(pDX, professionalism, 1, 10);
	DDX_Text(pDX, IDC_EDIT_GRAPHIC_DESIGN, graphic_design);
	DDV_MinMaxInt(pDX, graphic_design, 1, 10);
	DDX_Text(pDX, IDC_EDIT_WORK_FLOW, work_flow);
	DDV_MinMaxInt(pDX, work_flow, 1, 10);
	DDX_Text(pDX, IDC_EDIT_OTHER_NOTES, other_notes_box);
}


BEGIN_MESSAGE_MAP(Hub, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SUBMIT, &Hub::OnBnClickedButtonSubmit)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_LAST_FEEDBACK, &Hub::OnBnClickedButtonLoadLastFeedback)
END_MESSAGE_MAP()


// Hub message handlers


void Hub::OnBnClickedButtonSubmit()
{
	UpdateData(TRUE);
	/*list<int> submit_list;
	
	static int size = 0;*/

	Feedbeck_base_class* scores[5];
	Creativity cre;
	Implementation imp;
	Professionalism pr;
	Graphic_Design gd;
	Work_Flow wf;
	
	scores[0] = &cre;
	scores[1] = &imp;
	scores[2] = &pr;
	scores[3] = &gd;
	scores[4] = &wf;

	scores[0]->Add_Answer(creativity);
	scores[1]->Add_Answer(implementation);
	scores[2]->Add_Answer(professionalism);
	scores[3]->Add_Answer(graphic_design);
	scores[4]->Add_Answer(work_flow);
	
	/*size += 5;*/

	/*for (int i = 0; i < size; i++)
	{
		submit_list.push_back(i);
	}*/


	CFileDialog dlg(FALSE, _T(".comment"), NULL, 0, _T("Comment (*.comment)|*.comment|All Files (*.*)|*.*||"));

	CString filename;


	if ((dlg.DoModal() == IDOK))
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		

		cre.Serialize(ar);
		imp.Serialize(ar);
		pr.Serialize(ar);
		gd.Serialize(ar);
		wf.Serialize(ar);
		

		ar.Close();
		file.Close();
	}

	UpdateData(TRUE);

	//CString other_notes_box;



	// TODO: Add your control notification handler code here
}


void Hub::OnBnClickedButtonLoadLastFeedback()
{
	

	CFileDialog dlg(TRUE, _T(".comment"), NULL, 0, _T("Comment (*.comment)|*.comment|All Files (*.*)|*.*||"));

	
	Creativity cre;
	Implementation imp;
	Professionalism pr;
	Graphic_Design gd;
	Work_Flow wf;

	CString filename;

	if ((dlg.DoModal() == IDOK))
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);


		cre.Serialize(ar);
		imp.Serialize(ar);
		pr.Serialize(ar);
		gd.Serialize(ar);
		wf.Serialize(ar);


		ar.Close();
		file.Close();
	}
	

	other_notes_box.Format(_T("Creativity was: %d \r\n Implemintation was: %d \r\n Professionalism was: %d \r\n Graphic_design was: %d \r\n Work_flow was: %d \r\n"),
		cre.Get_Score(), imp.Get_Score(), pr.Get_Score(), gd.Get_Score(), wf.Get_Score());

	UpdateData(FALSE);

	// TODO: Add your control notification handler code here
}
