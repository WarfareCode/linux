//SonarSensorModel.cpp: implementation of the CSonarSensorModel module.
//!!HDOSE_CLASS(CSonarSensorModel,CSensorModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SonarSensorModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSonarSensorModel,CSensorModel,ClassInit);

BEGIN_EVENTMAP(CSonarSensorModel)
	//{{HDOSE_EVENT_MAP(CSonarSensorModel)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CSonarSensorModel::CSonarSensorModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CSonarSensorModel::~CSonarSensorModel()
{

}

void CSonarSensorModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSonarSensorModel::OnInit()
{
	CSensorModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CSonarSensorModel)
	if(!(entry->GetParameterValue("MaxDist")==NULL))
		m_MaxDist=atof(entry->GetParameterValue("MaxDist"));
	if(!(entry->GetParameterValue("LowestNoise")==NULL))
		m_LowestNoise=atof(entry->GetParameterValue("LowestNoise"));
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CSonarSensorModel::OnClose()
{
	CSensorModel::OnClose();
}

void CSonarSensorModel::tick(double lasttime)
{
	CSensorModel::tick(lasttime);
}

void CSonarSensorModel::Simulation(double lasttime)
{
	CSensorModel::Simulation(lasttime);
}

void CSonarSensorModel::Output()
{
	CSensorModel::Output();
}



