//DragSonarSensorModel.cpp: implementation of the CDragSonarSensorModel module.
//!!HDOSE_CLASS(CDragSonarSensorModel,CSonarSensorModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DragSonarSensorModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CDragSonarSensorModel,CSonarSensorModel,ClassInit);

BEGIN_EVENTMAP(CDragSonarSensorModel)
	//{{HDOSE_EVENT_MAP(CDragSonarSensorModel)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CDragSonarSensorModel::CDragSonarSensorModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CDragSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CDragSonarSensorModel::~CDragSonarSensorModel()
{

}

void CDragSonarSensorModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CDragSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CDragSonarSensorModel::OnInit()
{
	CSonarSensorModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CDragSonarSensorModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CDragSonarSensorModel::OnClose()
{
	CSonarSensorModel::OnClose();
}

void CDragSonarSensorModel::tick(double lasttime)
{
	CSonarSensorModel::tick(lasttime);
}

void CDragSonarSensorModel::Simulation(double lasttime)
{
	CSonarSensorModel::Simulation(lasttime);
}

void CDragSonarSensorModel::Output()
{
	CSonarSensorModel::Output();
}



