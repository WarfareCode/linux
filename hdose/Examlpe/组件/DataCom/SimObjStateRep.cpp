//SimObjStateRep.cpp: implementation of the CSimObjStateRep module.
//!!HDOSE_CLASS(CSimObjStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SimObjStateRep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSimObjStateRep,CStateRepository,ClassInit);


CSimObjStateRep::CSimObjStateRep()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSimObjStateRep)
	m_strName=0;//new char[MAX_CHARLEN];
	m_SimObjId=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CSimObjStateRep::~CSimObjStateRep()
{

}

void CSimObjStateRep::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSimObjStateRep)
	AttributeRegister(CSimObjStateRep,char*,strName);
	AttributeRegister(CSimObjStateRep,long,SimObjId);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSimObjStateRep::OnInit()
{
	CStateRepository::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CSimObjStateRep)
	//}}HDOSE_STATIC_PARA_EXTRACT
}


void CSimObjStateRep::OnSetParameter(char *name,char *value)
{
	CStateRepository::OnSetParameter(name,value);
	//{{HDOSE_PARA_EXTRACT(CSimObjStateRep)
	if(strcmp(name,"strName")==0){
		this->SetValueString(name,value);
		//strcpy(m_strName,value);
	}
	else if(strcmp(name,"SimObjId")==0){
		m_SimObjId=atoi(value);
	}
	//}}HDOSE_PARA_EXTRACT
}

void CSimObjStateRep::OnClose()
{
	CStateRepository::OnClose();
}

void CSimObjStateRep::tick(double lasttime)
{
	CStateRepository::tick(lasttime);
}

void CSimObjStateRep::Simulation(double lasttime)
{
	CStateRepository::Simulation(lasttime);
}

void CSimObjStateRep::Output()
{
	CStateRepository::Output();
}



