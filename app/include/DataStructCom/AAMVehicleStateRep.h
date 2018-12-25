//AAMVehicleStateRep.h: interface for the CAAMVehicleStateRep module.
//!!HDOSE_CLASS(CAAMVehicleStateRep,CGroundVehicleESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMVehicleStateRep_H)
#define AFX_AAMVehicleStateRep_H

#include "CGF/GroundVehicleESR.h"
#include "AAMConfigData.h"

//{{HDOSE_CLS_DES(CAAMVehicleStateRep)
/*
Author:		xks
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMVehicleStateRep /*防空导弹发射车状态池*/ : public CGroundVehicleESR 
{
	DECLARE_CREATE;
public:
	CAAMVehicleStateRep();
	virtual ~CAAMVehicleStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetType(long val){m_Type=val;}
	long	GetType(){return m_Type;}
	void	SetLauncherState(long val){m_LauncherState=val;}
	long	GetLauncherState(){return m_LauncherState;}
	void	SetMaxLoadingAAMCount(long val){m_MaxLoadingAAMCount=val;}
	long	GetMaxLoadingAAMCount(){return m_MaxLoadingAAMCount;}
	void	SetTimeIntervalBtw2AAM(double val){m_TimeIntervalBtw2AAM=val;}
	double	GetTimeIntervalBtw2AAM(){return m_TimeIntervalBtw2AAM;}
	void	SetFillingTime(double val){m_FillingTime=val;}
	double	GetFillingTime(){return m_FillingTime;}
	void	SetAAMDataCount(long val){m_AAMDataCount=val;}
	long	GetAAMDataCount(){return m_AAMDataCount;}
	void	SetAAMData(CAAMConfigData val[]){
		for (int i =0; i<10; i++)
		{
			m_AAMData[i]=val[i];
		}
	}
	CAAMConfigData*	GetAAMData(){return m_AAMData;}
	void	SetMatchFCRadarType(long val){m_MatchFCRadarType=val;}
	long	GetMatchFCRadarType(){return m_MatchFCRadarType;}
	void	SetMatchFCRadarID(long val){m_MatchFCRadarID=val;}
	long	GetMatchFCRadarID(){return m_MatchFCRadarID;}
	void	SetsSelfAutoAntiAir(bool val){m_SelfAutoAntiAir=val;}
	bool	GetsSelfAutoAntiAir(){return m_SelfAutoAntiAir;}
	void	SetSelfInterceptStratege(long val){m_SelfInterceptStratege=val;}
	long	GetSelfInterceptStratege(){return m_SelfInterceptStratege;}
	void	SetOODACycleTime(double val){m_OODACycleTime=val;}
	double	GetOODACycleTime(){return m_OODACycleTime;}
	//{{HDOSE_MEMBER_FUNCTION(CAAMVehicleStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CAAMVehicleStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CAAMVehicleStateRep)
	long	m_Type/*类别，1/2/3*/;
	long	m_LauncherState/*状态，（0可用、1未准备好、2故障）*/;
	long	m_MaxLoadingAAMCount/*满载防空弹数量（即一次可装填的最大防空弹数量）*/;
	double	m_TimeIntervalBtw2AAM/*两枚弹间的发射时间间隔(s)*/;
	double	m_FillingTime/*再装填时间间隔*/;
	long	m_AAMDataCount/*所配置防空弹种类的数量（记录AAMData的个数，最多10个）*/;
	CAAMConfigData	m_AAMData[10]/*所配置防空弹类型和数量基本数据（最多10个）*/;
	long	m_MatchFCRadarType/*匹配的火控雷达类型*/;
	long	m_MatchFCRadarID/*匹配的火控雷达编号*/;
	bool	m_SelfAutoAntiAir/*是否自动防空，0否，1是*/;
	long	m_SelfInterceptStratege/*防空拦截策略，1/2/3,几枚弹拦截一个目标*/;
	double	m_OODACycleTime/*OODA环时间*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
