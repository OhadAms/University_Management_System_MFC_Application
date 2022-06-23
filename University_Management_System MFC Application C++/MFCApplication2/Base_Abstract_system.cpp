#include "pch.h"
#include "Base_Abstract_system.h"
 
//IMPLEMENT_SERIAL(Base_Abstract_system,CObject,1);
 
int Base_Abstract_system::Autehorization(CString password, CString username)
{
	if (password == this->password && username == this->username)
	{
		return TRUE;
	}
	else
		return FALSE;
}

//void Base_Abstract_system::Serialize(CArchive& archive)
//{
//	CObject::Serialize(archive);
//
//	//for
//	    //for
//
//	if (archive.IsStoring())
//		archive << username << password;
//	else
//		archive >> username >> username;
//	
//}

