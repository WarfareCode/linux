//ShipMoveModel.cpp: implementation of the CShipMoveModel module.
//!!HDOSE_CLASS(CShipMoveModel,CModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShipMoveModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CShipMoveModel,CModel,ClassInit);

BEGIN_EVENTMAP(CShipMoveModel)
	//{{HDOSE_EVENT_MAP(CShipMoveModel)
	ON_HDOSEEVENT("CNodeMoveOrderEvt",OnEntityMoveOrderEvt)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CShipMoveModel::CShipMoveModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CShipMoveModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CShipMoveModel::~CShipMoveModel()
{

}

void CShipMoveModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CShipMoveModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CShipMoveModel::OnInit()
{
	CModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CShipMoveModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CShipMoveModel::OnClose()
{
	CModel::OnClose();
}

void CShipMoveModel::tick(double lasttime)
{
	CModel::tick(lasttime);
}

void CShipMoveModel::Simulation(double lasttime)
{
	CModel::Simulation(lasttime);
}

void CShipMoveModel::Output()
{
	CModel::Output();
}

void CShipMoveModel::OnEntityMoveOrderEvt(CEvt *pevent)
{
}


