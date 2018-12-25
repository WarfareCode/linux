//SubmarineStateRep.cpp: implementation of the CSubmarineStateRep module.
//!!HDOSE_CLASS(CSubmarineStateRep,CNodeStateRep)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmarineStateRep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSubmarineStateRep,CNodeStateRep,ClassInit);


CSubmarineStateRep::CSubmarineStateRep()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSubmarineStateRep)
	//}}HDOSE_ATTRIBUTE_INIT
}

CSubmarineStateRep::~CSubmarineStateRep()
{

}

void CSubmarineStateRep::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSubmarineStateRep)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSubmarineStateRep::OnInit()
{
	CNodeStateRep::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CSubmarineStateRep)
	if(!(entry->GetParameterValue("Length")==NULL))
		m_Length=atof(entry->GetParameterValue("Length"));
	if(!(entry->GetParameterValue("MaxRadius")==NULL))
		m_MaxRadius=atof(entry->GetParameterValue("MaxRadius"));
	if(!(entry->GetParameterValue("MaxVel")==NULL))
		m_MaxVel=atof(entry->GetParameterValue("MaxVel"));
	//}}HDOSE_STATIC_PARA_EXTRACT
}


void CSubmarineStateRep::OnSetParameter(char *name,char *value)
{
	CNodeStateRep::OnSetParameter(name,value);
	//{{HDOSE_PARA_EXTRACT(CSubmarineStateRep)
	//}}HDOSE_PARA_EXTRACT
}

void CSubmarineStateRep::OnClose()
{
	CNodeStateRep::OnClose();
}

void CSubmarineStateRep::tick(double lasttime)
{
	CNodeStateRep::tick(lasttime);
}

void CSubmarineStateRep::Simulation(double lasttime)
{
	CNodeStateRep::Simulation(lasttime);
}

void CSubmarineStateRep::Output()
{
	CNodeStateRep::Output();
}



