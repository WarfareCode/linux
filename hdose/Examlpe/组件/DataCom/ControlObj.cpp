//ControlObj.cpp: implementation of the CControlObj module.
//!!HDOSE_CLASS(CControlObj,CSimObjStateRep)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ControlObj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CControlObj,CSimObjStateRep,ClassInit);


CControlObj::CControlObj()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CControlObj)
	//}}HDOSE_ATTRIBUTE_INIT
}

CControlObj::~CControlObj()
{

}

void CControlObj::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CControlObj)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CControlObj::OnInit()
{
	CSimObjStateRep::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CControlObj)
	//}}HDOSE_STATIC_PARA_EXTRACT
}


void CControlObj::OnSetParameter(char *name,char *value)
{
	CSimObjStateRep::OnSetParameter(name,value);
	//{{HDOSE_PARA_EXTRACT(CControlObj)
	//}}HDOSE_PARA_EXTRACT
}

void CControlObj::OnClose()
{
	CSimObjStateRep::OnClose();
}

void CControlObj::tick(double lasttime)
{
	CSimObjStateRep::tick(lasttime);
}

void CControlObj::Simulation(double lasttime)
{
	CSimObjStateRep::Simulation(lasttime);
}

void CControlObj::Output()
{
	CSimObjStateRep::Output();
}



