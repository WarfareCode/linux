//TorpedoSonarSensorModel.cpp: implementation of the CTorpedoSonarSensorModel module.
//!!HDOSE_CLASS(CTorpedoSonarSensorModel,CSonarSensorModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TorpedoSonarSensorModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CTorpedoSonarSensorModel,CSonarSensorModel,ClassInit);

BEGIN_EVENTMAP(CTorpedoSonarSensorModel)
	//{{HDOSE_EVENT_MAP(CTorpedoSonarSensorModel)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CTorpedoSonarSensorModel::CTorpedoSonarSensorModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CTorpedoSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CTorpedoSonarSensorModel::~CTorpedoSonarSensorModel()
{

}

void CTorpedoSonarSensorModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CTorpedoSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CTorpedoSonarSensorModel::OnInit()
{
	CSonarSensorModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CTorpedoSonarSensorModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CTorpedoSonarSensorModel::OnClose()
{
	CSonarSensorModel::OnClose();
}

void CTorpedoSonarSensorModel::tick(double lasttime)
{
	CSonarSensorModel::tick(lasttime);
}

void CTorpedoSonarSensorModel::Simulation(double lasttime)
{
	CSonarSensorModel::Simulation(lasttime);
}

void CTorpedoSonarSensorModel::Output()
{
	CSonarSensorModel::Output();
}



