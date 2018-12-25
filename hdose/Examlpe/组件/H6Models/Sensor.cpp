#include "stdafx.h"
#include "Sensor.h"
#include "Platform.h"


/////////////////////////////////////
IMPLEMENT_ObjStream(CTrackStream,Track)//ע���

//////////////////////////////////////////
IMPLEMENT_CREATE_EX(CTargetIndicate,CEvt,ClassInit);

void CTargetIndicate::ClassInit(ClassInfo *clsinfo)
{
	AttributeRegister(CTargetIndicate,int,imp);
	AttributeRegister(CTargetIndicate,DA_Track,info);
}

/////////////////////////////////
IMPLEMENT_CREATE_EX(CSensor,CNode,0);

CSensor::CSensor(void)
{
	m_tracks=0;
	m_power=0;
	m_rate=10;//10*0.03
	m_nu=0;
}

CSensor::~CSensor(void)
{

}
void CSensor::tick(double time)
{
	if(!m_bInitiative)
		return;
///////////////////////////////////////////////////
	m_power=1;//�����ɹ���ȷ���Ƿ񿪻�
	if(m_power)
		Detect(time);//��Ŀ����Ϣ��Ϊ�鱨��Ϣ
}

void CSensor::Detect(double time)
{
	if(m_nu++%m_rate!=0)
		return;
	if(m_tracks==0)
	{
		m_tracks=(CTrackStream*)m_pEngine->CreateObj("CTrackStream",AUTO_RTI);//����һ������������
		if(m_tracks)
			AddAggregateObj(m_tracks);
	}
	int nu=0;
	CObjList *pList=m_pEngine->LookupObjFromClass("CPlatform");
	POSITION pos=pList->GetHeadPosition();
	while(pos)
	{
		CPlatform *pla=(CPlatform *)pList->GetNext(pos);
	//	if(pla->IsInitiative())
	//		continue;///ֻ���Է�����Ϣ̽������������

		Track &info=(*m_tracks)[nu];//ע���

		info.id=pla->GetID();
		info.x=pla->m_longitude+0.00008*((double)rand()/(RAND_MAX-1)-0.5);//�ӵ�����
		info.y=pla->m_latitude+0.00008*((double)rand()/(RAND_MAX+1)-0.5);//�ӵ�����
		info.z=pla->m_height+100*sin(cos(time));//�ӵ�����
		nu++;
		if(nu>=128)
			break;///���̽��128��Ŀ��
	}

	if(m_tracks)
	{//����Ƶ�ʲ���autoUpdate��Ӱ��
		m_tracks->m_p1=0;//��һ������
		m_tracks->m_p2=1;//��һ������
		m_tracks->UpdateData(nu);
		//m_tracks->Record(time);
	}

////////////////////////////////////////////////////////
	CTargetIndicate evt;
	evt.m_pEngine=m_pEngine;
	evt.m_desobjid=1;//RTI_OBJ;

	evt.m_imp=1;
	evt.m_info.m_len=6;//����һ��Ҫָ��
	for(int i=0;i<6;i++)
	{
		evt.m_info[i].id=i;
		evt.m_info[i].x=m_nu;
		evt.m_info[i].y=m_nu+1;
	}
	evt.Send();
/////////////////////////////////////////////////////
}

