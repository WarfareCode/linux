//SubSonarSensorModel.cpp: implementation of the CSubSonarSensorModel module.
//!!HDOSE_CLASS(CSubSonarSensorModel,CSonarSensorModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubSonarSensorModel.h"
//�Լ���ӵ�ͷ�ļ�
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

	CSubmarineStateRep* pMySR=(CSubmarineStateRep* )GetStateRepository();		//�õ�Ǳͧ�����״̬��
	int count=0;
	CTargetData val[10];	
	//̽��ʵ��
	CObjList* pList[5];
	int nu = 5;
	GetEngine(GetClsInfo()->m_ver)->LookupAllObjFromClass("CNodeStateRep", pList, nu);/*��ȡ����װ��ʵ��״̬��*/
	for(int i =0; i<nu; i++)
	{
		POSITION ListPos=pList[i]->GetHeadPosition();
		while(ListPos)
		{
			CNodeStateRep *TempState=(CNodeStateRep *)pList[i]->GetNext(ListPos);

			if (TempState->GetType()==pMySR->GetType())	continue;//����Ǽ���Ŀ�꣬���ý���	

			val[count].m_TargetId=TempState->GetSimObjId();		//��¼Id
			val[count].m_TargetPos=TempState->GetPos();			//��¼Ŀ��λ��
			count++;
		}
	}

	//��Ǳͧ����ģ�ͷ���Ŀ��ָʾ��Ϣ
	CTargetIndicatingEvt	targetInfoEvt;
	targetInfoEvt.SetTargetCount(count);
	targetInfoEvt.SetTargetInfo(val);
	targetInfoEvt.SetDest("CSubmarineCtrlModel");
	SendEntityEvt(&targetInfoEvt);
	printf("Ǳͧ%s��������Ǳͧ����ģ�ͷ���Ŀ����Ϣ\n",pMySR->GetstrName());


}

void CSubSonarSensorModel::Simulation(double lasttime)
{
	CSonarSensorModel::Simulation(lasttime);
}

void CSubSonarSensorModel::Output()
{
	CSonarSensorModel::Output();
}



