//SubmarineStateRep.h: interface for the CSubmarineStateRep module.
//!!HDOSE_CLASS(CSubmarineStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubmarineStateRep_H)
#define AFX_SubmarineStateRep_H

#include "LaunchVehicleData.h"

//{{HDOSE_CLS_DES(CSubmarineStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class CSubmarineStateRep /*潜艇状态池*/ : public CSubSurfaceESR 
{
	DECLARE_CREATE;
public:
	CSubmarineStateRep();
	virtual ~CSubmarineStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetASMCount(long val){m_ASMCount=val;}
	long	GetASMCount(){return m_ASMCount;}
	void	SetTorpedoCount(long val){m_TorpedoCount=val;}
	long	GetTorpedoCount(){return m_TorpedoCount;}
	void	SetLauncherInfo(CLaunchVehicleData val[]){
		for(int i=0;i<4;i++)
			m_LauncherInfo[i]=val[i];
	}
	CLaunchVehicleData*	GetLauncherInfo(){return m_LauncherInfo;}
	void	SetLauncherCount(long val){m_LauncherCount=val;}
	long	GetLauncherCount(){return m_LauncherCount;}
	void	SetTorpedoType(long val){m_TorpedoType=val;}
	long	GetTorpedoType(){return m_TorpedoType;}

	double	GetLength(){return m_Length;}
	double	GetWidth(){return m_Width;}
	double	GetHeight(){return m_Height;}
	double	GetDraft(){return m_Draft;}
	double	GetlfCruiseVel(){return m_lfCruiseVel;}
	float	GetlfMaxAcc(){return m_lfMaxAcc;}
	float	GetlfMaxDecelAcc(){return m_lfMaxDecelAcc;}
	float	GetlfMaxHeight(){return m_lfMaxHeight;}
	float	GetlfMinHeight(){return m_lfMinHeight;}
	float	GetlfCruiseHeight(){return m_lfCruiseHeight;}
	float	GetlfMaxTurnRate(){return m_lfMaxTurnRate;}
	float	GetlfMaxG(){return m_lfMaxG;}

	//{{HDOSE_MEMBER_FUNCTION(CSubmarineStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSubmarineStateRep)
	double	m_Length/*长*/;
	double	m_Width/*宽*/;
	double	m_Height/*深*/;
	double	m_Draft/*吃水深*/;
	double	m_lfCruiseVel/*巡航速度*/;
	float	m_lfMaxAcc/*最大加速度*/;
	float	m_lfMaxDecelAcc/*最小减速度*/;
	float	m_lfMaxHeight/*最大高度，潜艇为0，舰艇为0*/;
	float	m_lfMinHeight/*最小高度，潜艇为负，舰艇为0*/;
	float	m_lfCruiseHeight/*巡航高度，潜艇为负或0，舰艇为0*/;
	float	m_lfMaxTurnRate/*最大转弯速率*/;
	float	m_lfMaxG/*过载*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubmarineStateRep)
	long	m_ASMCount/*反舰导弹数量*/;
	long	m_TorpedoCount/*鱼雷数量*/;
	CLaunchVehicleData	m_LauncherInfo[4]/*发射筒信息*/;
	long	m_LauncherCount/*发射筒数量*/;
	long	m_TorpedoType/*鱼雷类型*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
