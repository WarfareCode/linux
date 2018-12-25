//Communication.h: interface for the CCommunication module.
//!!HDOSE_CLASS(CCommunication,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hdose.h>
class CCommunication : public CEvt 
{
	DECLARE_CREATE;
public:
	//{{HDOSE_ATTRIBUTE(CCommunication)
	char*	m_Sender	/*参数1*/; 
	char*	m_Message	/*参数2*/; 
	//}}HDOSE_ATTRIBUTE

	CCommunication();
	virtual ~CCommunication();

	static	void ClassInit(ClassInfo *clsinfo);


private:
};

