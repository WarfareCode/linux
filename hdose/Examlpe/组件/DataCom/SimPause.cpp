//SimPause.cpp: implementation of the CSimPause module.
//!!HDOSE_CLASS(CSimPause,CEvt)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SimPause.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSimPause,CEvt,ClassInit);


CSimPause::CSimPause()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSimPause)
	//}}HDOSE_ATTRIBUTE_INIT
}

CSimPause::~CSimPause()
{

}

void CSimPause::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSimPause)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSimPause::OnInit()
{
	//CEvt::OnInit();
}






