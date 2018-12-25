//MissileESR.h: interface for the CMissileESR module.
//!!HDOSE_CLASS(CMissileESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MissileESR_H)
#define AFX_MissileESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CMissileESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CMissileESR /*����״̬��*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CMissileESR();
	virtual ~CMissileESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetLaunchPlatformId(long val){m_LaunchPlatformId=val;}
	long	GetLaunchPlatformId(){return m_LaunchPlatformId;}
	void	SetTargetId(long val){m_TargetId=val;}
	long	GetTargetId(){return m_TargetId;}
	double	GetLength(){return m_Length;}
	double	GetWingSpan(){return m_WingSpan;}
	double	GetMaxVel(){return m_MaxVel;}
	double	GetCruiseVel(){return m_CruiseVel;}
	double	GetMaxHeight(){return m_MaxHeight;}
	double	GetMaxDist(){return m_MaxDist;}

	//{{HDOSE_MEMBER_FUNCTION(CMissileESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CMissileESR)
	double	m_Length/*����m*/;
	double	m_WingSpan/*��չm*/;
	double	m_MaxVel/*����ٶ�ma*/;
	double	m_CruiseVel/*Ѳ���ٶ�ma*/;
	double	m_MaxHeight/*���km*/;
	double	m_MaxDist/*���km*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMissileESR)
	long	m_LaunchPlatformId/*����ƽ̨Id*/;
	long	m_TargetId/*����Ŀ������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
