// Ship.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "Tank.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_CREATE_EX(CTank,CNode,ClassInit);

BEGIN_EVENTMAP(CTank)

END_EVENTMAP


////////////////////////////////////////////////

CTank::CTank()
{ 
	m_pointIndex=0;
	m_bmoveToDisPoint=true;
	
	m_latitude=23;
	m_longitude=123.00;
	m_velocity=30.00;
	m_heading=50.00;
	RE= 6371000;//地球半径m
	
	
}
CTank::~CTank()
{
	m_dlg.DestroyWindow();
}


void CTank::ClassInit(ClassInfo *clsinfo)
{
	AttributeRegister(CTank,double,latitude);
	AttributeRegister(CTank,double,longitude);
	AttributeRegister(CTank,double,velocity);
	AttributeRegister(CTank,double,heading);

}

void CTank::OnInit()
{
	if(!m_bInitiative)
		return;
	CNode::OnInit();
	m_dlg.Create(IDD_TANKDISPLAYDIALOG);
	m_dlg.ShowWindow(SW_SHOW);
	m_dlg.m_pEng=m_pEngine;

}
void CTank::OnSetParameter(char *name,char *value)
{
	CNode::OnSetParameter(name,value);

	if(strcmp(name,"latitude")==0){
		m_latitude=atof(value);
	}
	else if(strcmp(name,"longitude")==0){
		m_longitude=atof(value);
	}
	else if(strcmp(name,"velocity")==0){
		m_velocity=atof(value);
	}
	else if(strcmp(name,"heading")==0){
		m_heading=atof(value);
	}

	m_disPoint.m_latitude=m_latitude;//将当前点作为沿航线运动的起始点
	m_disPoint.m_longitude=m_longitude;
}
void CTank::tick(double lasttime)
{
	if(!m_bInitiative)
		return;
	CNode::tick(lasttime);

	CLatLonH curPoint(m_latitude,m_longitude,0);//当前目标点
	double dis=SurfaceDistance(curPoint,m_disPoint);
	double DS=m_velocity*m_pEngine->GetLogicClock()*2;
	m_bmoveToDisPoint=dis<DS?true:false;
	
	if (m_bmoveToDisPoint==true)//如果到达目标点，重新获取线对象中的一个目标点作为下一个目标点
	{
		CString str;

		CLineObj *pLineObj=(CLineObj *)m_pEngine->LookupObj("CLineObj");
		if (pLineObj)
		{

			if (m_pointIndex<pLineObj->GetPointsCount())
			{
				str.Format("坦克运动到点：%0.2f°，%0.2f°",m_disPoint.m_longitude,m_disPoint.m_latitude);
				m_dlg.OutputText(str);
				CLatLonH* pPoints=pLineObj->GetPoints();
				m_disPoint=pPoints[m_pointIndex];
				m_pointIndex++;
			}
			else{//如果已经到达最后一个点，则原地不动
				str.Format("坦克运动到终点：%0.2f°，%0.2f°",m_disPoint.m_longitude,m_disPoint.m_latitude);
				m_dlg.OutputText(str);
				m_velocity = 0;
				return;
			}

		}
		

	}
	CLatLonH nextPoint;
	m_heading=AzimuthCalculate(curPoint,m_disPoint);//计算方位
	MovePosCalculate(curPoint,nextPoint,m_velocity,0,m_heading,m_pEngine->GetLogicClock());
	m_latitude=nextPoint.m_latitude;
	m_longitude=nextPoint.m_longitude;

	m_dlg.plotObjData(m_longitude,m_latitude);

}
void CTank::Simulation(double lasttime)
{	
	if(!m_bInitiative)
		return;
	CNode::Simulation(lasttime);

}
void CTank::Output()
{
	if(!m_bInitiative)
		return;
	
	CNode::Output();
}
double CTank::AzimuthCalculate(CLatLonH selfPos,CLatLonH targetPos)//
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
void CTank::MovePosCalculate(CLatLonH currentPos,CLatLonH & nextPos,double velocity,
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

double CTank::SurfaceDistance(CLatLonH selfPos,CLatLonH targetPos)
{
	double dist;
	dist=RE*acos(cos(PI*selfPos.m_latitude/180)*cos(PI*targetPos.m_latitude/180)*
		cos(PI*(selfPos.m_longitude-targetPos.m_longitude)/180)+
		sin(PI*selfPos.m_latitude/180)*sin(PI*targetPos.m_latitude/180));
	return dist;
}
