//TorpedoCtrlModel.cpp: implementation of the CTorpedoCtrlModel module.
//!!HDOSE_CLASS(CTorpedoCtrlModel,CController)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TorpedoCtrlModel.h"
//�Լ���ӵ�ͷ�ļ�
#include	 "TorpedoBindingParams.h"
#include "TorpedoStateRep.h"
#include "Controller.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CTorpedoCtrlModel,CController,ClassInit);

BEGIN_EVENTMAP(CTorpedoCtrlModel)
	//{{HDOSE_EVENT_MAP(CTorpedoCtrlModel)
	ON_HDOSEEVENT("CTargetIndicatingEvt",OnTargetIndicatingEvt)
	ON_HDOSEEVENT("CTorpedoBindingParams",OnTorpedoBindingParams)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CTorpedoCtrlModel::CTorpedoCtrlModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CTorpedoCtrlModel)
	//}}HDOSE_ATTRIBUTE_INIT
	TarId=0;
}

CTorpedoCtrlModel::~CTorpedoCtrlModel()
{

}

void CTorpedoCtrlModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CTorpedoCtrlModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CTorpedoCtrlModel::OnInit()
{
	CController::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CTorpedoCtrlModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CTorpedoCtrlModel::OnClose()
{
	CController::OnClose();
}

void CTorpedoCtrlModel::tick(double lasttime)
{
	CController::tick(lasttime);
}

void CTorpedoCtrlModel::Simulation(double lasttime)
{
	CController::Simulation(lasttime);
}

void CTorpedoCtrlModel::Output()
{
	CController::Output();
}

void CTorpedoCtrlModel::OnTargetIndicatingEvt(CEvt *pevent)
{
}
void CTorpedoCtrlModel::OnTorpedoBindingParams(CEvt *pevent)
{

	if(!m_bInitiative)	return;

	CTorpedoBindingParams* pEvt=(CTorpedoBindingParams*)pevent;

	//������յ������Լ��Ĳ����������
	if(pEvt->GetRcverId()==((CTorpedoStateRep*)GetStateRepository())->GetSimObjId())
	{
		printf("����_%d,���յ�����Ǳͧ����ģ�͵�����װ������\n",pEvt->GetRcverId());

		//��ȡĿ��ĳ�ʼ��Ϣ
		tarPos=pEvt->m_TargetPos;
		TarId=pEvt->GetTargetId();
	}

}


