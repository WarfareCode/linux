//SensorModel.cpp: implementation of the CSensorModel module.
//!!HDOSE_CLASS(CSensorModel,CModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SensorModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSensorModel,CModel,ClassInit);

BEGIN_EVENTMAP(CSensorModel)
	//{{HDOSE_EVENT_MAP(CSensorModel)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CSensorModel::CSensorModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSensorModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CSensorModel::~CSensorModel()
{

}

void CSensorModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSensorModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSensorModel::OnInit()
{
	CModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CSensorModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CSensorModel::OnClose()
{
	CModel::OnClose();
}

void CSensorModel::tick(double lasttime)
{
	CModel::tick(lasttime);
}

void CSensorModel::Simulation(double lasttime)
{
	CModel::Simulation(lasttime);
}

void CSensorModel::Output()
{
	CModel::Output();
}



