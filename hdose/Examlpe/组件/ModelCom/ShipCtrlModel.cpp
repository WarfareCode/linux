//ShipCtrlModel.cpp: implementation of the CShipCtrlModel module.
//!!HDOSE_CLASS(CShipCtrlModel,CController)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShipCtrlModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CShipCtrlModel,CController,ClassInit);

BEGIN_EVENTMAP(CShipCtrlModel)
	//{{HDOSE_EVENT_MAP(CShipCtrlModel)
	ON_HDOSEEVENT("CTargetIndicatingEvt",OnTargetIndicatingEvt)
	ON_HDOSEEVENT("CNodeMoveTask",OnEntityMoveTask)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CShipCtrlModel::CShipCtrlModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CShipCtrlModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CShipCtrlModel::~CShipCtrlModel()
{

}

void CShipCtrlModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CShipCtrlModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CShipCtrlModel::OnInit()
{
	CController::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CShipCtrlModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CShipCtrlModel::OnClose()
{
	CController::OnClose();
}

void CShipCtrlModel::tick(double lasttime)
{
	CController::tick(lasttime);
}

void CShipCtrlModel::Simulation(double lasttime)
{
	CController::Simulation(lasttime);
}

void CShipCtrlModel::Output()
{
	CController::Output();
}

void CShipCtrlModel::OnTargetIndicatingEvt(CEvt *pevent)
{
}
void CShipCtrlModel::OnEntityMoveTask(CEvt *pevent)
{
}


