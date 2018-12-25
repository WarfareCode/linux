#include "stdafx.h"
#include "plamove.h"
#include "Platform.h"

#define G 9.8

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_CREATE_EX(CPlaMove,CNode,0);
CPlaMove::CPlaMove()
{
	DT=0;
	m_t=-1;
} 
void CPlaMove::tick(double time)
{
	if(!m_pSr)
		return;

	if(!((CPlatform*)m_pSr)->m_hasdes)
	{
		fly(0,-20,1);		
	}
	else
	{
		int s=((CPlatform*)m_pSr)->OrientedtoDes();
		s*=20;
		fly(0,s,1);
		CdoublePoint p(((CPlatform*)m_pSr)->m_desx,((CPlatform*)m_pSr)->m_desy);
		CdoublePoint p1(((CPlatform*)m_pSr)->m_longitude,((CPlatform*)m_pSr)->m_latitude);
		if(p.compare(p1)==0)
			((CPlatform*)m_pSr)->m_hasdes=0;
	}
}
double CPlaMove::getlongitude()
{
	return m_longitude;
}
double CPlaMove::getlatitude()
{
	return m_latitude;
}

double CPlaMove::getpitching()
{
   return m_pitching;
}
double CPlaMove::getyaw()
{
   return m_yaw;
}

double CPlaMove::getz()
{
	return m_z;
}
double CPlaMove::getv()
{
	return m_v;
}
double CPlaMove::gettime()
{
   return m_t;
}
void CPlaMove::OnInit()
{
	DT=m_pEngine->GetLogicClock(this)*m_sample;	
}

void CPlaMove::fly(double nx,double ny,double nz)
{						
	if(m_t==-1)//初始化
	{
		m_t=0.0;

		m_longitude=((CPlatform*)m_pSr)->m_longitude;
		m_latitude=((CPlatform*)m_pSr)->m_latitude;
		m_z=((CPlatform*)m_pSr)->m_height;
		m_v=((CPlatform*)m_pSr)->m_velocity;
		m_pitching=((CPlatform*)m_pSr)->m_pitching;
		m_yaw=((CPlatform*)m_pSr)->m_yaw;
		m_r=6371000+m_z; 
	}
	double dsv,dspitching,dsyaw;
	double dslongitude,dslatitude,dsr;
	
	m_nx=nx;
	m_ny=ny;
	m_nz=nz;
	dsv=m_nx*G;
 	dspitching=(m_nz-cos(m_pitching))*G/m_v;
	dsyaw=m_ny*G/m_v/cos(m_pitching);
	dslatitude=m_v*cos(m_pitching)*sin(m_yaw)/m_r;
	dslongitude=m_v*cos(m_pitching)*cos(m_yaw)/m_r/cos(m_latitude);
	dsr=m_v*sin(m_pitching);
	m_pitching=m_pitching+dspitching*DT;
	m_yaw=m_yaw+dsyaw*DT;
	if(m_yaw>PI)
		m_yaw=m_yaw-2*PI;
	if(m_yaw<-PI)
		m_yaw=m_yaw+2*PI;
	m_r=m_r+dsr*DT;
	m_z=m_r-6371000;
	m_longitude=m_longitude+dslongitude*DT;
	if(m_longitude>PI)
		m_longitude=m_longitude-2*PI;
	if(m_longitude<-PI)
		m_longitude=m_longitude+2*PI;
	m_latitude=m_latitude+dslatitude*DT;
	if(m_latitude>PI/2&&m_latitude<=PI)
		m_latitude=PI-m_latitude;
	if(m_latitude<-PI/2&&m_latitude>=-PI)
		m_latitude=-PI-m_latitude;
	m_v=m_v+dsv*DT;
	m_t=m_t+DT;

	((CPlatform*)m_pSr)->m_longitude=m_longitude;
	((CPlatform*)m_pSr)->m_latitude=m_latitude;
	((CPlatform*)m_pSr)->m_height=m_z;

	((CPlatform*)m_pSr)->m_velocity=m_v;
	((CPlatform*)m_pSr)->m_pitching=m_pitching;
	((CPlatform*)m_pSr)->m_yaw=m_yaw;
/////以上大致相当于300次浮点运算和加法运算
	double temp=0;
	double t=0;
	for(int i=0;i<1700;i++)
		t=t+i*3.14;
	temp=m_t;
	m_t=t;
	m_t=temp;

}
