#pragma once

#include "Slist.h"

class Clist : public CObject, public Slist
{
	
public:
	DECLARE_SERIAL(Clist);

	

	int course_num;
	CString name;
	Slist* student;
	Clist* next;

public:
	
	Clist();
	virtual ~Clist() {};
	Clist* Create_Element(int , CString );
	void Add_Student_To_Course(Clist* ,Slist*, int );
	void Rename_course(CString);
	void Print_All_Coursses_computed_scorse(Slist*, int&, int&, int&, int&, int&);
	Slist* Search_Student(Clist** , int );
	Slist* Search_Student_Help(Slist** , int );
	int Delete_Student(Clist* , int , int );
	void Delete_Student_List(Clist* );
	int Delete_Course(Clist* , int);
	int Search_Course(Clist* , int );
	int Search_Duplicates(Clist* ,int );
	
	void Serialize(CArchive& , Clist*);
};

