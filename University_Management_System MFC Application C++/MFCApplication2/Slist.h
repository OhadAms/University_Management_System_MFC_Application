#pragma once


class Slist 
{
	

private:

	CString student_name;
	int student_id;
	int student_grade;
	Slist* next;


public:

	Slist();
	virtual ~Slist() {};
	Slist* Create_student(CString, int);
	Slist* Go_Next(Slist*);
	Slist* Get_Next(Slist*);
	void Set_Next(Slist* , Slist* );
	void Place_Student(Slist*, Slist*);
	CString Get_Student_Name() { return student_name; };
	int Get_Student_Id() { return student_id; };
	int Get_Student_Grade() { return student_grade; };
	void Set_Grade(Slist*, int);
	
	
};

