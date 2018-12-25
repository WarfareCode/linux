// Platform.cpp: implementation of the CPlatform class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Platform.h"
#include "plamove.h"
#include "omp.h"
#include "H6Ginit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_CREATE_EX(CPlatform,CNode,ClassInit);

BEGIN_EVENTMAP(CPlatform) 
 
END_EVENTMAP

// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//##ModelId=3AC98B1C00D9
void CPlatform::ClassInit(ClassInfo *clsinfo)
{
	AttributeRegister(CPlatform,double,longitude);
	AttributeRegister(CPlatform,double,latitude);
	AttributeRegister(CPlatform,double,height);

	AttributeRegister(CPlatform,double,velocity);
	AttributeRegister(CPlatform,double,pitching);
	AttributeRegister(CPlatform,double,yaw);//7

	AttributeRegister(CPlatform,char[10],dat);//固定数据或复杂结构体数据类型
	AttributeRegister(CPlatform,char*,ph);/////字符串
	AttributeRegister(CPlatform,DA_double,doubleda);//双精度动态数组
	AttributeRegister(CPlatform,DataBlock,block);////任意长度数据块

}

CPlatform::CPlatform()
{ 
	strcpy(m_dat,"abcdefgh");

	m_ph=0;//字符串,必须置0

	m_longitude=119.95*PI/180;
	m_latitude=30*PI/180;
	m_height=10000;//高度

	m_velocity=580;//速度

	m_pitching=0;//俯仰角
	m_yaw=0;//偏航角

	m_desx=0;
	m_desy=0;
	m_hasdes=0;



}

//##ModelId=3AC98B1C00D5
CPlatform::~CPlatform()
{
	m_ph=0;
}
void CPlatform::OnInit()
{
	m_ph=0;
	SetValueString("ph","ph=qqqqq");

	H6Ginit init;//静态模板
	init.m_longitude=m_longitude*PI/180;
	init.m_latitude=m_latitude*PI/180;
	init.m_height=m_height;
	init.m_velocity=m_velocity;
	init.m_yaw=m_yaw*PI/180;
	init.m_roll=m_pitching*PI/180;

	//	init.m_desobjid=RTI_OBJ;//指定目的地，到RTI
	init.m_scope=SCOPE_FEDERATION;//指定范围
	init.SetDest("CMainMgr");//指定联邦中的CmainMgr接收处理
	init.Send();//发送到联邦中

	init.SendToMdb();	//并将事件发送到共享内存区，供DisPlay获取

}

//##ModelId=3AC98B1C00A6
void CPlatform::Simulation(double lasttime)
{
	if(m_bInitiative)
	{
		if(m_lasttime>=lasttime) return;
		m_lasttime=lasttime;
	}

}
//##ModelId=3AC98B1C00A0
void CPlatform::Output()
{

}

///采样或预测并发送
//##ModelId=3AC98B1C00A3

void CPlatform::tick(double time)
{
	if(!m_bInitiative)
	{
		return;
	}

	strcpy(m_dat,"123456789");

	double dd=time;
	//for(int i=0;i<10000;i++)
	{
		dd=122222;//dd*sin(time);
	}
	m_block.Set(8,(char*)&dd);


	SetValueString("ph","qh=qqqqqqqq");
////////////////////////////
	for(int i=0;i<2;i++)
		m_doubleda[i]=2222;
	m_doubleda.m_len=2;
///////////////////////////////

}

void CPlatform::DestineTo(double x,double y)
{
	m_desx=x; 
	m_desy=y;
	m_hasdes=1;
	return;
}

int CPlatform::OrientedtoDes()
{
	double y=m_desy-m_latitude;
	double x=m_desx-m_longitude;
	double t=atan2(y,x);
	t-=m_yaw;

	if(fabs(t)<0.01)
		return 0;
	else if(((t>0)&&(t<PI))||(t<-PI))
		return 1;
	else
		return -1;
} 
void CPlatform::OnReflect(char *Para)
{
}
