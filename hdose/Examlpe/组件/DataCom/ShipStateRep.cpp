//ShipStateRep.cpp: implementation of the CShipStateRep module.
//!!HDOSE_CLASS(CShipStateRep,CNodeStateRep)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShipStateRep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CShipStateRep,CNodeStateRep,ClassInit);


CShipStateRep::CShipStateRep()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CShipStateRep)
	//}}HDOSE_ATTRIBUTE_INIT
}

CShipStateRep::~CShipStateRep()
{

}

void CShipStateRep::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CShipStateRep)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CShipStateRep::OnInit()
{
	CNodeStateRep::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CShipStateRep)
	if(!(entry->GetParameterValue("Length")==NULL))
		m_Length=atof(entry->GetParameterValue("Length"));
	if(!(entry->GetParameterValue("Width")==NULL))
		m_Width=atof(entry->GetParameterValue("Width"));
	//}}HDOSE_STATIC_PARA_EXTRACT
}


void CShipStateRep::OnSetParameter(char *name,char *value)
{
	CNodeStateRep::OnSetParameter(name,value);
	//{{HDOSE_PARA_EXTRACT(CShipStateRep)
	//}}HDOSE_PARA_EXTRACT
}

void CShipStateRep::OnClose()
{
	CNodeStateRep::OnClose();
}

void CShipStateRep::tick(double lasttime)
{
	CNodeStateRep::tick(lasttime);
}

void CShipStateRep::Simulation(double lasttime)
{
	CNodeStateRep::Simulation(lasttime);
}

void CShipStateRep::Output()
{
	CNodeStateRep::Output();
}



