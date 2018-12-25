//SubMoveModel.cpp: implementation of the CSubMoveModel module.
//!!HDOSE_CLASS(CSubMoveModel,CModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubMoveModel.h"
//自己添加的头文件
#include "SubmarineStateRep.h"
#include "LatLonH.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSubMoveModel,CModel,ClassInit);

BEGIN_EVENTMAP(CSubMoveModel)
	//{{HDOSE_EVENT_MAP(CSubMoveModel)
	ON_HDOSEEVENT("CNodeMoveOrderEvt",OnEntityMoveOrderEvt)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CSubMoveModel::CSubMoveModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSubMoveModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CSubMoveModel::~CSubMoveModel()
{

}

void CSubMoveModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSubMoveModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSubMoveModel::OnInit()
{
	CModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CSubMoveModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CSubMoveModel::OnClose()
{
	CModel::OnClose();
}

void CSubMoveModel::tick(double lasttime)
{
	CModel::tick(lasttime);
	if(!m_bInitiative)	return;
	CSubmarineStateRep* pMySR=(CSubmarineStateRep* )GetStateRepository();		//得到潜艇自身的状态池
	CLatLonH lastpos=pMySR->GetPos();	//获取当前位置
	CLatLonH newpos=lastpos;
	//运动位置变化
	newpos.m_latitude+=0.000001;
	newpos.m_longitude+=0.0000001;
	newpos.m_height+=0.0000002;

	pMySR->SetPos(newpos);		//设置下一时刻位置

	pMySR->UpdateAllAttributes();		//更新位置

}

void CSubMoveModel::Simulation(double lasttime)
{
	CModel::Simulation(lasttime);
}

void CSubMoveModel::Output()
{
	CModel::Output();
}

void CSubMoveModel::OnEntityMoveOrderEvt(CEvt *pevent)
{
}


