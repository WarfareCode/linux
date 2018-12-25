//TorpedoMoveModel.cpp: implementation of the CTorpedoMoveModel module.
//!!HDOSE_CLASS(CTorpedoMoveModel,CModel)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TorpedoMoveModel.h"

//自己添加的头文件
#include "TorpedoStateRep.h"
#include "LatLonH.h"
#include "TorpedoCtrlModel.h"
#include "MainMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CTorpedoMoveModel,CModel,ClassInit);

BEGIN_EVENTMAP(CTorpedoMoveModel)
	//{{HDOSE_EVENT_MAP(CTorpedoMoveModel)
	ON_HDOSEEVENT("CNodeMoveOrderEvt",OnEntityMoveOrderEvt)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

CTorpedoMoveModel::CTorpedoMoveModel()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CTorpedoMoveModel)
	//}}HDOSE_ATTRIBUTE_INIT
	RE= 6371000;//地球半径m
}

CTorpedoMoveModel::~CTorpedoMoveModel()
{

}

void CTorpedoMoveModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CTorpedoMoveModel)
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CTorpedoMoveModel::OnInit()
{
	CModel::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CTorpedoMoveModel)
	//}}HDOSE_STATIC_PARA_EXTRACT
}



void CTorpedoMoveModel::OnClose()
{
	CModel::OnClose();
}

void CTorpedoMoveModel::tick(double lasttime)
{
	CModel::tick(lasttime);
	if(!m_bInitiative)	return;
	CTorpedoStateRep* pMySR=(CTorpedoStateRep* )GetStateRepository();		//得到鱼雷自身的状态池
	CLatLonH curPoint=pMySR->GetPos();	//获取当前位置
	
	CTorpedoCtrlModel *pTorpedoCtrlModel=(CTorpedoCtrlModel *)pMySR->LookupModel("CTorpedoCtrlModel");
	if (!pTorpedoCtrlModel){
		return;
	}

	double dis=SurfaceDistance(curPoint,pTorpedoCtrlModel->tarPos);
	double DS=pMySR->m_Vel*m_pEngine->GetLogicClock()*2;
	bool bmoveToDisPoint=dis<DS?true:false;

	if (bmoveToDisPoint==true)//如果到达目标点，重新获取线对象中的一个目标点作为下一个目标点
	{
		CMainMgr *pScheduler=(CMainMgr *)m_pEngine->LookupObj(1);		//引擎的调度器对象

		CString str;
		str.Format("鱼雷编号:%d,击中编号为10的水面舰艇目标\n",m_parent->GetID());
		pScheduler->m_dlg.OutputText(str);
		
		m_parent->Quit();
		return;
	}
	CLatLonH nextPoint;
	pMySR->m_Head=AzimuthCalculate(curPoint,pTorpedoCtrlModel->tarPos);//计算方位
	MovePosCalculate(curPoint,nextPoint,pMySR->m_Vel,0,pMySR->m_Head,m_pEngine->GetLogicClock());
	nextPoint.m_height=curPoint.m_height;

	pMySR->SetPos(nextPoint);		//设置下一时刻位置
	pMySR->UpdateAllAttributes();		//更新位置

	
}

void CTorpedoMoveModel::Simulation(double lasttime)
{
	CModel::Simulation(lasttime);
}

void CTorpedoMoveModel::Output()
{
	CModel::Output();
}

void CTorpedoMoveModel::OnEntityMoveOrderEvt(CEvt *pevent)
{
}


double CTorpedoMoveModel::AzimuthCalculate(CLatLonH selfPos,CLatLonH targetPos)//
{
	double azimuth;
	double averageLat=(selfPos.m_latitude-targetPos.m_latitude);
	if(selfPos.m_latitude-targetPos.m_latitude==0){
		if(selfPos.m_longitude<targetPos.m_longitude){
			azimuth=90;	
		}
		else{
			azimuth=270;
		}
	}
	else if(selfPos.m_longitude-targetPos.m_longitude==0){
		if(selfPos.m_latitude<targetPos.m_latitude){
			azimuth=0;
		}
		else{
			azimuth=180;
		}
	}
	else{
		azimuth=atan((selfPos.m_longitude-targetPos.m_longitude)*cos(PI*averageLat
			/180)/(selfPos.m_latitude-targetPos.m_latitude))*180/PI;
		if(selfPos.m_latitude>targetPos.m_latitude){
			azimuth=azimuth+180;
		}
		else if(selfPos.m_longitude>targetPos.m_longitude){
			azimuth=360+azimuth;
		}
	}
	return azimuth;
}
void CTorpedoMoveModel::MovePosCalculate(CLatLonH currentPos,CLatLonH & nextPos,double velocity,
							 double pitch,double course,double dT)
{
	double vel_north;//向北运动的速度，向北为正，向南为负
	double vel_east;//向东运动的速度，向东为正，向西为负
	double vel_up;//向上运动的速度，向上为正，向下为负

	double r_longi=RE;//经度圈的半径
	double r_lati=RE*cos(PI*currentPos.m_latitude/180);//所在纬度圈的半径
	double s_Lati=2*PI*r_lati/360;//纬度圈上跨一个经度的距离m
	double s_longi=2*PI*r_longi/360;//经度圈上跨一个纬度的距离m

	if(course>=0 && course <=90)
	{
		vel_north=velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*cos(PI*course/180);//速度向北，为正
		vel_east=velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*sin(PI*course/180);//速度向东，为正
		vel_up=velocity*sin(PI*pitch/180);
	}
	else if(course>90 && course<=180)
	{
		vel_north=-1*velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*cos((180-course)*PI/180);//速度向南，为负
		vel_east=velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*sin((180-course)*PI/180);//速度向东，为正
		vel_up=velocity*sin(PI*pitch/180);
	}
	else if(course>180 && course<270)
	{
		vel_north=-1*velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*cos((course-180)*PI/180);//速度向南，为负
		vel_east=-1*velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*sin((course-180)*PI/180);//速度向西，为负
		vel_up=velocity*sin(PI*pitch/180);
	}
	else
	{
		vel_north=velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*cos((360-course)*PI/180);//速度向北，为正
		vel_east=-1*velocity*cos(PI*pitch/180)*RE/(RE+currentPos.m_height)*sin((360-course)*PI/180);//速度向西，为负
		vel_up=velocity*sin(PI*pitch/180);
	}

	double d_north=vel_north*dT;//向北运动的距离(在当前高度上所对应的一段弧长)，北为正，南为负
	double d_east=vel_east*dT;//向东运动的距离(在当前高度上所对应的一段弧长)，东为正，西为负
	double d_up=vel_up*dT;//向上运动的距离，上为正，下为负


	nextPos.m_latitude=currentPos.m_latitude+(d_north*RE/(RE+currentPos.m_height))/s_longi;
	nextPos.m_longitude=currentPos.m_longitude+(d_east*RE/(RE+currentPos.m_height))/s_Lati;
	nextPos.m_height=currentPos.m_height+d_up;
}

double CTorpedoMoveModel::SurfaceDistance(CLatLonH selfPos,CLatLonH targetPos)
{
	double dist;
	dist=RE*acos(cos(PI*selfPos.m_latitude/180)*cos(PI*targetPos.m_latitude/180)*
		cos(PI*(selfPos.m_longitude-targetPos.m_longitude)/180)+
		sin(PI*selfPos.m_latitude/180)*sin(PI*targetPos.m_latitude/180));
	return dist;
}
