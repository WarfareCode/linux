//TorpedoStateRep.cpp: implementation of the CTorpedoStateRep module.
//!!HDOSE_CLASS(CTorpedoStateRep,CNodeStateRep)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TorpedoStateRep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CTorpedoStateRep,CNodeStateRep,ClassInit);


CTorpedoStateRep::CTorpedoStateRep()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CTorpedoStateRep)
	//}}HDOSE_ATTRIBUTE_INIT
}

CTorpedoStateRep::~CTorpedoStateRep()
{

}

void CTorpedoStateRep::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CTorpedoStateRep)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CTorpedoStateRep::OnInit()
{
	CNodeStateRep::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CTorpedoStateRep)
	if(!(entry->GetParameterValue("Length")==NULL))
		m_Length=atof(entry->GetParameterValue("Length"));
	if(!(entry->GetParameterValue("MaxRadius")==NULL))
		m_MaxRadius=atof(entry->GetParameterValue("MaxRadius"));
	if(!(entry->GetParameterValue("MaxG")==NULL))
		m_MaxG=atof(entry->GetParameterValue("MaxG"));
	//}}HDOSE_STATIC_PARA_EXTRACT
}


void CTorpedoStateRep::OnSetParameter(char *name,char *value)
{
	CNodeStateRep::OnSetParameter(name,value);
	//{{HDOSE_PARA_EXTRACT(CTorpedoStateRep)
	//}}HDOSE_PARA_EXTRACT
}

void CTorpedoStateRep::OnClose()
{
	CNodeStateRep::OnClose();
}

void CTorpedoStateRep::tick(double lasttime)
{
	CNodeStateRep::tick(lasttime);
}

void CTorpedoStateRep::Simulation(double lasttime)
{
	CNodeStateRep::Simulation(lasttime);
}

void CTorpedoStateRep::Output()
{
	CNodeStateRep::Output();
}



