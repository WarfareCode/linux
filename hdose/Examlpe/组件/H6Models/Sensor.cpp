#include "stdafx.h"
#include "Sensor.h"
#include "Platform.h"


/////////////////////////////////////
IMPLEMENT_ObjStream(CTrackStream,Track)//注意点

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
	m_power=1;//可以由规则确定是否开机
	if(m_power)
		Detect(time);//把目标信息变为情报信息
}

void CSensor::Detect(double time)
{
	if(m_nu++%m_rate!=0)
		return;
	if(m_tracks==0)
	{
		m_tracks=(CTrackStream*)m_pEngine->CreateObj("CTrackStream",AUTO_RTI);//创建一个航迹流对象
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
	//		continue;///只将对方的信息探测后放入流对象

		Track &info=(*m_tracks)[nu];//注意点

		info.id=pla->GetID();
		info.x=pla->m_longitude+0.00008*((double)rand()/(RAND_MAX-1)-0.5);//加点误差喔
		info.y=pla->m_latitude+0.00008*((double)rand()/(RAND_MAX+1)-0.5);//加点误差喔
		info.z=pla->m_height+100*sin(cos(time));//加点误差喔
		nu++;
		if(nu>=128)
			break;///最多探测128批目标
	}

	if(m_tracks)
	{//更新频率不受autoUpdate的影响
		m_tracks->m_p1=0;//填一个参数
		m_tracks->m_p2=1;//填一个参数
		m_tracks->UpdateData(nu);
		//m_tracks->Record(time);
	}

////////////////////////////////////////////////////////
	CTargetIndicate evt;
	evt.m_pEngine=m_pEngine;
	evt.m_desobjid=1;//RTI_OBJ;

	evt.m_imp=1;
	evt.m_info.m_len=6;//个数一定要指明
	for(int i=0;i<6;i++)
	{
		evt.m_info[i].id=i;
		evt.m_info[i].x=m_nu;
		evt.m_info[i].y=m_nu+1;
	}
	evt.Send();
/////////////////////////////////////////////////////
}

