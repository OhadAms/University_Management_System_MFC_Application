#pragma once



class Feedbeck_base_class
{
	
public:

	Feedbeck_base_class() {};
	virtual ~Feedbeck_base_class() {};
	virtual int Get_Score() const = 0;
    virtual void Serialize(CArchive& archive) = 0;
    virtual void Add_Answer(int) = 0;

};

