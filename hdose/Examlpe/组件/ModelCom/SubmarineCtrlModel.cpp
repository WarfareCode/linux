//SubmarineCtrlModel.cpp: implementation of the CSubmarineCtrlModel module.
//!!HDOSE_CLASS(CSubmarineCtrlModel,CController)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmarineCtrlModel.h"
#include "TargetIndicatingEvt.h"
#include "EntityMoveTask.h"
#include "SubmarineStateRep.h"
#include "TorpedoStateRep.h"
#include "TorpedoBindingParams.h"
#include "MainMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CSubmarineCtrlModel,CController,ClassInit);

BEGIN_EVENTMAP(CSubmarineCtrlModel)
	//{{HDOSE_EVENT_MAP(CSubmarineCtrlModel)
	ON_HDOSEEVENT("CTargetIndicatingEvt",OnTargetIndicatingEvt)
	ON_HDOSEEVENT("CNodeMoveTask",OnEntityMoveTask)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CSubmarineCtrlModel::CSubmarineCtrlModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CSubmarineCtrlModel)
	//}}HDOSE_ATTRIBUTE_INIT

	tarCount=0;
	TorpedoCount=0;
}

CSubmarineCtrlModel::~CSubmarineCtrlModel()
{

}

void CSubmarineCtrlModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CSubmarineCtrlModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CSubmarineCtrlModel::OnInit()
{
	CController::OnInit();



	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;


	//{{HDOSE_STATIC_PARA_EXTRACT(CSubmarineCtrlModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CSubmarineCtrlModel::OnClose()
{
	CController::OnClose();
}

void CSubmarineCtrlModel::tick(double lasttime)
{
	CController::tick(lasttime);
	if(!m_bInitiative)		return;

	CSubmarineStateRep* pMySR=(CSubmarineStateRep* )GetStateRepository();		//得到潜艇自身的状态池
	if (!pMySR)
	{
		return;
	}

	//如果发现目标Id为10的目标，则发射鱼雷进行攻击
	for(int i=0;i<tarCount;i++)
	{
		if(TorpedoCount==1)		return;		//如果已经发射了1枚鱼雷，则不再发射

		if(tarInfo[i].m_TargetId==10)
		{
			
			CString str;
			TorpedoCount++;
			str.Format("RedTorpedo_%d",TorpedoCount+300);	//鱼雷编号从301开始

			CMainMgr *pScheduler=(CMainMgr *)m_pEngine->LookupObj(1);		//引擎的调度器对象

			

			CNode *pEnt=(CNode *)m_pEngine->CreateObj("CyyTorpedoEntity",AUTO_RTI,str.GetBuffer(str.GetLength()));	//创建鱼雷
			pScheduler->AddAggregateObj(pEnt);		//加入引擎调度器对象所管理的对象中
			
			//获取鱼雷状态池，并向其中写入初始数据

			CTorpedoStateRep * pTorpedoState=(CTorpedoStateRep *)pEnt->m_pSr;//得到上述鱼雷的状态池
			pTorpedoState->SetstrName(str.GetBuffer(str.GetLength()));
			pTorpedoState->SetSimObjId(TorpedoCount+300);
			pTorpedoState->SetType(pMySR->GetType());
			pTorpedoState->SetPos(pMySR->GetPos());
			pTorpedoState->SetVel(150);
			
			str.Format("潜艇发现编号为10的水面舰艇目标，发射鱼雷编号:%d\n",pEnt->GetID());

			pScheduler->m_dlg.OutputText(str);
			

			//向鱼雷控制模型发送鱼雷装订参数
			
			CTorpedoBindingParams *pEvt=(CTorpedoBindingParams *)m_pEngine->CreateEvt("CTorpedoBindingParams");		//动态创建事件
			if(pEvt)
			{
				printf("向鱼雷%s的控制模型发送装订参数\n",pTorpedoState->GetstrName());

				pEvt->SetRcverId(pTorpedoState->GetSimObjId());//指定接收者Id
				pEvt->SetTargetId(tarInfo[i].m_TargetId);		//目标Id
				pEvt->SetTargetPos(tarInfo[i].m_TargetPos);		//目标位置
				pEvt->Send();		//发送实体间交互事件
				delete pEvt;			//发送完成后，删除事件
			}
		}
	}

}

void CSubmarineCtrlModel::Simulation(double lasttime)
{
	CController::Simulation(lasttime);
}

void CSubmarineCtrlModel::Output()
{
	CController::Output();
}

void CSubmarineCtrlModel::OnTargetIndicatingEvt(CEvt *pevent)
{
	if(!m_bInitiative)		return;	//如果不是主动对象，则返回
	CTargetIndicatingEvt* pEvt=(CTargetIndicatingEvt *)pevent;
	tarCount=pEvt->GetTargetCount();		//得到目标的个数
	CTargetData*	targetInfos=pEvt->GetTargetInfo();
	for(int i=0;i<tarCount;i++)
	{
		tarInfo[i]=targetInfos[i];		//记录下目标信息数组
	}
}
void CSubmarineCtrlModel::OnEntityMoveTask(CEvt *pevent)
{
}


