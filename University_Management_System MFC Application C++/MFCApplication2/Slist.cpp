#include "pch.h"
#include "Slist.h"
#include <iostream>






Slist::Slist()
{
	 next = NULL;
}


Slist* Slist::Create_student(CString student_name, int stud_id)
{
	Slist* new_student = new Slist[sizeof(Slist)];
	new_student->student_id = stud_id;
	new_student->student_grade = 0;
	new_student->next = NULL;
	new_student->student_name = student_name;
	
	return new_student;
}

Slist* Slist::Go_Next(Slist* curr_student)
{
	curr_student = curr_student->next;
	return curr_student;
}

Slist* Slist::Get_Next(Slist* student)
{
	return student->next;
}

void Slist::Place_Student(Slist* student, Slist* place_new_student)
{
	if (student == NULL)
	{
		student = place_new_student;
	}
	else
	{
		student->next = place_new_student;
	}
}

void Slist::Set_Next(Slist* curr_student, Slist* next_student)
{
	curr_student->next = next_student;
}

void Slist::Set_Grade(Slist* student,int new_grade)
{
	student->student_grade = new_grade;
}


