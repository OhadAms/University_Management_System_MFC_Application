#include "pch.h"
#include "Comments.h"
#include <iostream>
#include "Feedbeck_base_class.h"
using namespace std;

IMPLEMENT_SERIAL(Creativity, CObject, 1);
IMPLEMENT_SERIAL(Implementation, CObject, 1);
IMPLEMENT_SERIAL(Professionalism, CObject, 1);
IMPLEMENT_SERIAL(Graphic_Design, CObject, 1);
IMPLEMENT_SERIAL(Work_Flow, CObject, 1);

void Creativity:: Add_Answer(int creativity_score)
{
	this->creativity_score = creativity_score;
}
void Creativity::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);

	if (archive.IsStoring())
	{
		archive << creativity_score;
	}
	else
	{
		archive >> creativity_score;
	}
}

void Implementation::Add_Answer(int implementation_score)
{
	this->implementation_score = implementation_score;
}
void Implementation::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << implementation_score;
	}
	else
	{
		archive >> implementation_score;
	}
}

void Professionalism::Add_Answer(int professionalism_score)
{
	this->professionalism_score = professionalism_score;
}
void Professionalism::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << professionalism_score;
	}
	else
	{
		archive >> professionalism_score;
	}
}

void Graphic_Design::Add_Answer(int graphic_Design_score)
{
	this->graphic_Design_score = graphic_Design_score;
}
void Graphic_Design::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << graphic_Design_score;
	}
	else
	{
		archive >> graphic_Design_score;
	}
}

void Work_Flow::Add_Answer(int work_flow_score)
{
	this->work_flow_score = work_flow_score;
}
void Work_Flow::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << work_flow_score;
	}
	else
	{
		archive >> work_flow_score;
	}
}
