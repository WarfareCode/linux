//SimStart.cpp: implementation of the CSimStart module.
//!!HDOSE_CLASS(CSimStart,CEvt)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SimStart.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSimStart,CEvt,ClassInit);


CSimStart::CSimStart()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSimStart)
	//}}HDOSE_ATTRIBUTE_INIT
}

CSimStart::~CSimStart()
{

}

void CSimStart::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSimStart)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSimStart::OnInit()
{
	//CEvt::OnInit();
}






