#include "pch.h"
#include "Clist.h"
#include <iostream>



IMPLEMENT_SERIAL(Clist, CObject, 1);

using namespace std;

Clist::Clist()
{
	
}
Clist* Clist:: Create_Element(int num, CString name)
{
	int temp = name.GetLength();
	Clist* item = new Clist[sizeof(Clist)];  
	item->course_num = num;
	item->next = NULL;
	item->student = NULL;
	item->name = name;

	return item;
}


void Clist::Add_Student_To_Course(Clist* coursses_head ,Slist* student, int course_number)
{
	Clist* head = coursses_head;
	Clist* curr = head;
	Slist* temp = curr->student;

	while (curr->course_num != course_number)
	{
		curr = curr->next;
	}
	if (curr->student == NULL)
	{
		curr->student = student;
	}
	else
	{
		temp = curr->student;
		curr->student = student;
		curr->student->Set_Next(curr->student, temp);
	}
}

void Clist::Rename_course(CString new_name)
{
	this->name = new_name;
}

void Clist::Print_All_Coursses_computed_scorse(Slist* student_head, int& Average_course_score, int& minimum_grade_in_course, int& maximum_grade_in_course, int& grade_sum, int& number_of_students)
{
	Slist* head = student_head;
	Slist* current = head;
	 Average_course_score = 0;
	 number_of_students = 0;
	 grade_sum = 0;
	 minimum_grade_in_course = 100;
	 maximum_grade_in_course = 0;

	while (current != NULL)
	{
		grade_sum += current->Get_Student_Grade();
		number_of_students++;
		current = current->Go_Next(current);
	}
	if (number_of_students == 0)
	{
		number_of_students = 1;
	}
	Average_course_score = grade_sum / number_of_students;

	current = head;

	while (current != NULL)
	{
		if (current->Get_Student_Grade() < minimum_grade_in_course)
		{
			minimum_grade_in_course = current->Get_Student_Grade();
		}
		if (current->Get_Student_Grade() > maximum_grade_in_course)
		{
			maximum_grade_in_course = current->Get_Student_Grade();
		}
		current = current->Go_Next(current);
	}
	if (head == NULL)
	{
		minimum_grade_in_course = 0;
		maximum_grade_in_course = 0;
		number_of_students = 0;
	}
}

Slist* Clist:: Search_Student_Help(Slist** student, int id)
{
	Slist* head = *student;
	Slist* current = head;

	if (head == NULL)
	{
		return 0;
	}
	while (current != NULL)
	{
		if (current->Get_Student_Id() == id)
		{
			return current;
		}
		current = current->Go_Next(current);
	}
	return 0;
}

Slist* Clist:: Search_Student(Clist** courses, int id)
{
	Clist* current = *courses;
	Slist* student = NULL;
	if (current == NULL)
	{
		return 0;
	}
	student = Search_Student_Help(&current->student, id);

	return student;
}

int Clist::Delete_Student(Clist* courses, int id_in, int course_number_in )
{
	Clist* head = courses;
	Clist* current_course = head;
	Slist* curr_stud = NULL;
	Slist* runner = NULL;
	Slist* temp = NULL;
	Slist* temp_2 = NULL;
	int id = id_in;
	int coures_number = course_number_in;

	if (courses == NULL)
	{
		return 0;
	}

	while (current_course != NULL)
	{
		if (current_course->course_num == coures_number)
		{
			break;
		}
		current_course = current_course->next;
	}
	if (current_course == NULL)
	{
		//printf(" Error, Course not found.\n");
		return 0;
	}

	curr_stud = Search_Student(&(current_course), id);

	if (curr_stud == NULL)
	{
		//printf(" Error, Student not found.\n");
		return 0;
	}

	runner = current_course->student;
	temp = runner->Go_Next(runner);

	if (runner->Get_Student_Id() == id && runner->Go_Next(runner) == NULL)
	{
		delete [] runner;
		current_course->student = NULL;
		return 1;
	}
	else if (runner->Get_Student_Id() == id && runner->Go_Next(runner) != NULL)
	{
		temp_2 = current_course->student;
		runner = runner->Go_Next(runner);
		temp = runner->Go_Next(runner);
		delete [] temp_2;
		current_course->student = runner;
		return 1;
	}

	while ((runner != NULL) && (temp != NULL))
	{
		if ((temp->Go_Next(temp) == NULL) && (temp->Get_Student_Id() == curr_stud->Get_Student_Id()))
		{
			delete [] temp;
			runner->Set_Next(runner, NULL);
			return 1;
		}
		else if ((temp->Get_Student_Id() == curr_stud->Get_Student_Id()))
		{
			temp = temp->Go_Next(temp);
			
			delete [] runner->Go_Next(runner);
			runner->Set_Next(runner, temp);   
			return 1;
		}
		else
		{
			temp = temp->Go_Next(temp);
			runner = runner->Go_Next(runner);
		}
	}
	return 0;
}


void Clist:: Delete_Student_List(Clist* courses)
{
	if (courses->student == NULL)
	{
		return;
	}

	while (courses->student != NULL)
	{
		Slist* temp = courses->student;
		courses->student = Go_Next(temp);
		delete[] temp;
	}
}


int Clist:: Delete_Course(Clist* courses, int course_num)
{

	if (courses == NULL)
	{
		return 0;
	}

	if (courses->course_num == course_num)  // bug with one element in list, null is not updated in main button.
	{
		Clist* temp = courses;
		courses = courses->next;
		Delete_Student_List(temp);
		delete[] temp;
	}
	else
	{
		Clist* curr = courses;
		while (curr->next != NULL && curr->next->course_num != course_num)
			curr = curr->next;

		if (curr->next == NULL)
		{
			return 0;
		}

		Clist* temp = curr->next;
		curr->next = temp->next;
		Delete_Student_List(temp);
		delete[] temp;
	}

	return 1;
}

int Clist::Search_Course(Clist* courses, int course_number)
{
	Clist* head = courses;
	Clist* current = head;

	if (head == NULL)
	{
		return 0;
	}
	while (current != NULL)
	{
		if (current->course_num == course_number)
		{
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int Clist::Search_Duplicates(Clist* course, int course_number)
{
	Clist* head = course;

	if ((head->Search_Course(head, course_number)))
		return 1;

	return 0;
}

void Clist::Serialize(CArchive& archive, Clist* course_head)
{
	Clist* runner = course_head;
	Slist* stud_runner = runner->student;
	
	CObject::Serialize(archive);

	if (archive.IsStoring())
	{
		archive << course_head;
	}
	else
	{
		archive >> course_head;
	}



















	/*if (archive.IsStoring())
	{
		while (runner != NULL)
		{
			archive << runner->course_num << runner->name << runner->student << runner->next;

			while (stud_runner != NULL)
			{
				archive << stud_runner->Get_Student_Name() << stud_runner->Get_Student_Id() << stud_runner->Get_Student_Grade() << stud_runner->Get_Next(stud_runner);

				stud_runner = stud_runner->Go_Next(stud_runner);
			}
			runner = runner->next;
		}
	}
	else
	{
		while (runner != NULL)
		{
			archive >> runner->course_num >> runner->name >> runner->student >> runner->next;

			while (stud_runner != NULL)
			{
				archive >> stud_runner->Get_Student_Name() >> stud_runner->Get_Student_Id() >> stud_runner->Get_Student_Grade() >> stud_runner->Get_Next(stud_runner);

				stud_runner = stud_runner->Go_Next(stud_runner);
			}
			runner = runner->next;
		}
	}*/
}