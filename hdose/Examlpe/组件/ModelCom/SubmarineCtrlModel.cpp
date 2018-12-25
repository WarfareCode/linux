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

	CSubmarineStateRep* pMySR=(CSubmarineStateRep* )GetStateRepository();		//�õ�Ǳͧ�����״̬��
	if (!pMySR)
	{
		return;
	}

	//�������Ŀ��IdΪ10��Ŀ�꣬�������׽��й���
	for(int i=0;i<tarCount;i++)
	{
		if(TorpedoCount==1)		return;		//����Ѿ�������1ö���ף����ٷ���

		if(tarInfo[i].m_TargetId==10)
		{
			
			CString str;
			TorpedoCount++;
			str.Format("RedTorpedo_%d",TorpedoCount+300);	//���ױ�Ŵ�301��ʼ

			CMainMgr *pScheduler=(CMainMgr *)m_pEngine->LookupObj(1);		//����ĵ���������

			

			CNode *pEnt=(CNode *)m_pEngine->CreateObj("CyyTorpedoEntity",AUTO_RTI,str.GetBuffer(str.GetLength()));	//��������
			pScheduler->AddAggregateObj(pEnt);		//�����������������������Ķ�����
			
			//��ȡ����״̬�أ���������д���ʼ����

			CTorpedoStateRep * pTorpedoState=(CTorpedoStateRep *)pEnt->m_pSr;//�õ��������׵�״̬��
			pTorpedoState->SetstrName(str.GetBuffer(str.GetLength()));
			pTorpedoState->SetSimObjId(TorpedoCount+300);
			pTorpedoState->SetType(pMySR->GetType());
			pTorpedoState->SetPos(pMySR->GetPos());
			pTorpedoState->SetVel(150);
			
			str.Format("Ǳͧ���ֱ��Ϊ10��ˮ�潢ͧĿ�꣬�������ױ��:%d\n",pEnt->GetID());

			pScheduler->m_dlg.OutputText(str);
			

			//�����׿���ģ�ͷ�������װ������
			
			CTorpedoBindingParams *pEvt=(CTorpedoBindingParams *)m_pEngine->CreateEvt("CTorpedoBindingParams");		//��̬�����¼�
			if(pEvt)
			{
				printf("������%s�Ŀ���ģ�ͷ���װ������\n",pTorpedoState->GetstrName());

				pEvt->SetRcverId(pTorpedoState->GetSimObjId());//ָ��������Id
				pEvt->SetTargetId(tarInfo[i].m_TargetId);		//Ŀ��Id
				pEvt->SetTargetPos(tarInfo[i].m_TargetPos);		//Ŀ��λ��
				pEvt->Send();		//����ʵ��佻���¼�
				delete pEvt;			//������ɺ�ɾ���¼�
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
	if(!m_bInitiative)		return;	//����������������򷵻�
	CTargetIndicatingEvt* pEvt=(CTargetIndicatingEvt *)pevent;
	tarCount=pEvt->GetTargetCount();		//�õ�Ŀ��ĸ���
	CTargetData*	targetInfos=pEvt->GetTargetInfo();
	for(int i=0;i<tarCount;i++)
	{
		tarInfo[i]=targetInfos[i];		//��¼��Ŀ����Ϣ����
	}
}
void CSubmarineCtrlModel::OnEntityMoveTask(CEvt *pevent)
{
}


