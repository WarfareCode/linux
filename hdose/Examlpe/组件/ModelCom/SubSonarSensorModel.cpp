//SubSonarSensorModel.cpp: implementation of the CSubSonarSensorModel module.
//!!HDOSE_CLASS(CSubSonarSensorModel,CSonarSensorModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubSonarSensorModel.h"
//自己添加的头文件
#include "EntityStateRep.h"
#include "SubmarineStateRep.h"
#include "TargetIndicatingEvt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSubSonarSensorModel,CSonarSensorModel,ClassInit);

BEGIN_EVENTMAP(CSubSonarSensorModel)
	//{{HDOSE_EVENT_MAP(CSubSonarSensorModel)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CSubSonarSensorModel::CSubSonarSensorModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSubSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_INIT
}

CSubSonarSensorModel::~CSubSonarSensorModel()
{

}

void CSubSonarSensorModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSubSonarSensorModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSubSonarSensorModel::OnInit()
{
	CSonarSensorModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CSubSonarSensorModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CSubSonarSensorModel::OnClose()
{
	CSonarSensorModel::OnClose();
}

void CSubSonarSensorModel::tick(double lasttime)
{
	CSonarSensorModel::tick(lasttime);
	if(!m_bInitiative)		return;

	CSubmarineStateRep* pMySR=(CSubmarineStateRep* )GetStateRepository();		//得到潜艇自身的状态池
	int count=0;
	CTargetData val[10];	
	//探测实体
	CObjList* pList[5];
	int nu = 5;
	GetEngine(GetClsInfo()->m_ver)->LookupAllObjFromClass("CNodeStateRep", pList, nu);/*获取所有装备实体状态池*/
	for(int i =0; i<nu; i++)
	{
		POSITION ListPos=pList[i]->GetHeadPosition();
		while(ListPos)
		{
			CNodeStateRep *TempState=(CNodeStateRep *)pList[i]->GetNext(ListPos);

			if (TempState->GetType()==pMySR->GetType())	continue;//如果是己方目标，不用解算	

			val[count].m_TargetId=TempState->GetSimObjId();		//记录Id
			val[count].m_TargetPos=TempState->GetPos();			//记录目标位置
			count++;
		}
	}

	//向潜艇控制模型发送目标指示信息
	CTargetIndicatingEvt	targetInfoEvt;
	targetInfoEvt.SetTargetCount(count);
	targetInfoEvt.SetTargetInfo(val);
	targetInfoEvt.SetDest("CSubmarineCtrlModel");
	SendEntityEvt(&targetInfoEvt);
	printf("潜艇%s的声纳向潜艇控制模型发送目标信息\n",pMySR->GetstrName());


}

void CSubSonarSensorModel::Simulation(double lasttime)
{
	CSonarSensorModel::Simulation(lasttime);
}

void CSubSonarSensorModel::Output()
{
	CSonarSensorModel::Output();
}



