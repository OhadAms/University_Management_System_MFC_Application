#pragma once

#include "Feedbeck_base_class.h"


class Creativity : public Feedbeck_base_class, public CObject
{

private:

	int creativity_score;

public:
	DECLARE_SERIAL(Creativity);
	Creativity() {};
	virtual ~Creativity() {};
	void Add_Answer(int);
	int Get_Score() const { return creativity_score; };
	void Serialize(CArchive& archive);

};

class Implementation : public Feedbeck_base_class, public CObject
{

private:

	int implementation_score;
	
public:
	DECLARE_SERIAL(Implementation);
	Implementation() {};
	virtual ~Implementation() {};
	void Add_Answer(int);
	int Get_Score() const { return implementation_score; };
	void Serialize(CArchive& archive);
};

class Professionalism : public Feedbeck_base_class, public CObject
{
private:
	int professionalism_score;
	

public:
	DECLARE_SERIAL(Professionalism);
	Professionalism() {};
	virtual ~Professionalism() {};
	void Add_Answer(int);
	int Get_Score() const { return professionalism_score; };
	void Serialize(CArchive& archive);
};

class Graphic_Design : public Feedbeck_base_class, public CObject
{
private:

	int graphic_Design_score;
	
public:
	DECLARE_SERIAL(Graphic_Design);
	Graphic_Design() {};
	virtual ~Graphic_Design() {};
	void Add_Answer(int);
	int Get_Score() const { return graphic_Design_score; };
	void Serialize(CArchive& archive);
};

class Work_Flow : public Feedbeck_base_class, public CObject
{
private:

	int work_flow_score;
	
public:
	DECLARE_SERIAL(Work_Flow);
	Work_Flow() {};
	virtual ~Work_Flow() {};
	void Add_Answer(int);
	int Get_Score() const { return work_flow_score; };
	void Serialize(CArchive& archive);
};
