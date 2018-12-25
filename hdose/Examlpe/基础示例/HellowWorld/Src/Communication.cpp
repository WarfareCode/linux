//Communication.cpp: implementation of the CCommunication module.
//!!HDOSE_CLASS(CCommunication,CEvt)
//////////////////////////////////////////////////////////////////////


#include "Communication.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_CREATE_EX(CCommunication,CEvt,ClassInit);


void CCommunication::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CCommunication)
	AttributeRegister(CCommunication,char*,Sender);
	AttributeRegister(CCommunication,char*,Message);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

CCommunication::CCommunication()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CCommunication)
	m_Sender=0;
	m_Message=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CCommunication::~CCommunication()
{

}





