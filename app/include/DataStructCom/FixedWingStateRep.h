//FixedWingStateRep.h: interface for the CFixedWingStateRep module.
//!!HDOSE_CLASS(CFixedWingStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FixedWingStateRep_H)
#define AFX_FixedWingStateRep_H

#include "LaunchVehicleData.h"

//{{HDOSE_CLS_DES(CFixedWingStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CFixedWingStateRep /*固定翼飞机状态池*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CFixedWingStateRep();
	virtual ~CFixedWingStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetASMCount(int val){m_ASMCount=val;}
	int	GetASMCount(){return m_ASMCount;}
	void	SetAirAirMissileCount(int val){m_AirAirMissileCount=val;}
	int	GetAirAirMissileCount(){return m_AirAirMissileCount;}
	void	SetAntiShipMissileType(int val){m_AntiShipMissileType=val;}
	int	GetAntiShipMissileType(){return m_AntiShipMissileType;}
	void	SetAntiAirMissileType(int val){m_AntiAirMissileType=val;}
	int	GetAntiAirMissileType(){return m_AntiAirMissileType;}
	void	SetAAMInterceptDist(double val){m_AAMInterceptDist=val;}
	double	GetAAMInterceptDist(){return m_AAMInterceptDist;}
	void	SetAAMKillProbability(double val){m_AAMKillProbability=val;}
	double	GetAAMKillProbability(){return m_AAMKillProbability;}
	void	SetIsLeader(int val){m_IsLeader=val;}
	int	GetIsLeader(){return m_IsLeader;}
	void	SetIsWingman(int val){m_IsWingman=val;}
	int	GetIsWingman(){return m_IsWingman;}
	void	SetMyLeaderNo(int val){m_MyLeaderNo=val;}
	int	GetMyLeaderNo(){return m_MyLeaderNo;}

	void	SetLauncherInfo(CLaunchVehicleData val[]){
		for(int i=0;i<10;i++)
			m_LauncherInfo[i]=val[i];
	}
	CLaunchVehicleData*	GetLauncherInfo(){return m_LauncherInfo;}
	void	SetLauncherCount(long val){m_LauncherCount=val;}
	long	GetLauncherCount(){return m_LauncherCount;}
	//{{HDOSE_MEMBER_FUNCTION(CFixedWingStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CFixedWingStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CFixedWingStateRep)
	int	m_ASMCount/*反舰导弹数量*/;
	int	m_AirAirMissileCount/*空空导弹数量*/;
	int	m_AntiShipMissileType/*反舰导弹类型*/;
	int	m_AntiAirMissileType/*空空导弹类型*/;
	double	m_AAMInterceptDist/*空空导弹拦截距离（km）*/;
	double	m_AAMKillProbability/*空空导弹拦截概率*/;
	int	m_IsLeader/*是否是长机（-1无效，0否，1是，战斗机而言）*/;
	int	m_IsWingman/*是否是僚机（-1无效，0否，1是，战斗机而言）*/;
	int	m_MyLeaderNo/*长机单元编号（对僚机而言，>0的值，-1表示无效）*/;

	CLaunchVehicleData	m_LauncherInfo[10]/*发射架信息*/;
	long	m_LauncherCount/*发射架数量*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
