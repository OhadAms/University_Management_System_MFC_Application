#pragma once

class Base_Abstract_system
{
public:
	
	Base_Abstract_system() {
		password = "123456789";
		username = "me";
	}
	
	~Base_Abstract_system() {};
	int Autehorization(CString, CString);
	
private:
	CString password;
	CString username;

};

