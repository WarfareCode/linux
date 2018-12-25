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

class DATASTRUCTCOMPONENTDLL_API CFixedWingStateRep /*�̶���ɻ�״̬��*/ : public CStateRepository 
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
	int	m_ASMCount/*������������*/;
	int	m_AirAirMissileCount/*�տյ�������*/;
	int	m_AntiShipMissileType/*������������*/;
	int	m_AntiAirMissileType/*�տյ�������*/;
	double	m_AAMInterceptDist/*�տյ������ؾ��루km��*/;
	double	m_AAMKillProbability/*�տյ������ظ���*/;
	int	m_IsLeader/*�Ƿ��ǳ�����-1��Ч��0��1�ǣ�ս�������ԣ�*/;
	int	m_IsWingman/*�Ƿ����Ż���-1��Ч��0��1�ǣ�ս�������ԣ�*/;
	int	m_MyLeaderNo/*������Ԫ��ţ����Ż����ԣ�>0��ֵ��-1��ʾ��Ч��*/;

	CLaunchVehicleData	m_LauncherInfo[10]/*�������Ϣ*/;
	long	m_LauncherCount/*���������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
