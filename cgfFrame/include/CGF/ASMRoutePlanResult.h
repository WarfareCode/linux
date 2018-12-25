//ASMRoutePlanResult.h: interface for the CASMRoutePlanResult module.
//!!HDOSE_CLASS(CASMRoutePlanResult,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMRoutePlanResult_H)
#define AFX_ASMRoutePlanResult_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CASMRoutePlanResult)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CASMRoutePlanResult /*反舰导弹航路规划结果*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CASMRoutePlanResult();
	virtual ~CASMRoutePlanResult();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetbValid(bool val){m_bValid=val;}
	bool	GetbValid(){return m_bValid;}
	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetFieldName(char* val){SetValueString("FieldName",val);}
	char*	GetFieldName(){return GetValueString("FieldName");}
	void	SetLaunchVehicleNo(long val){m_LaunchVehicleNo=val;}
	long	GetLaunchVehicleNo(){return m_LaunchVehicleNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetTargetName(char* val){SetValueString("TargetName",val);}
	char*	GetTargetName(){return GetValueString("TargetName");}
	void	SetAttackAngle(double val){m_AttackAngle=val;}
	double	GetAttackAngle(){return m_AttackAngle;}
	void	SetSearchStratege(short val){m_SearchStratege=val;}
	short	GetSearchStratege(){return m_SearchStratege;}
	void	SetWayPoints(GeoPt val[]){
		for(int i=0;i<MAX_RP_NUM;i++)
			m_WayPoints[i]=val[i];}
	GeoPt*	GetWayPoints(){return m_WayPoints;}
	void	SetWayPointsCount(long val){m_WayPointsCount=val;}
	long	GetWayPointsCount(){return m_WayPointsCount;}
	void	SetRadarSearchChart(double val[]){
		for(int i=0;i<14;i++)
			m_RadarSearchChart[i]=val[i];}
	double*	GetRadarSearchChart(){return m_RadarSearchChart;}
	void	SetLauncherInterval(double val){m_LauncherInterval=val;}
	double	GetLauncherInterval(){return m_LauncherInterval;}
	void	SetLauncherMaxSalvoCount(long val){m_LauncherMaxSalvoCount=val;}
	long	GetLauncherMaxSalvoCount(){return m_LauncherMaxSalvoCount;}
	void	SetTotalFlyTime(double val){m_TotalFlyTime=val;}
	double	GetTotalFlyTime(){return m_TotalFlyTime;}
	void	SettotalDist(double val){m_totalDist=val;}
	double	GettotalDist(){return m_totalDist;}
	void	SetASMType(int val){m_ASMType=val;}
	int	GetASMType(){return m_ASMType;}
	void	SetASMTrajType(int val){m_ASMTrajType=val;}
	int	GetASMTrajType(){return m_ASMTrajType;}
	void	SetForceSide(long val){m_ForceSide=val;}
	long	GetForceSide(){return m_ForceSide;}

	//{{HDOSE_MEMBER_FUNCTION(CASMRoutePlanResult)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMRoutePlanResult)
	bool	m_bValid/*是否有效*/;
	long	m_FieldNo/*发射平台编号*/;
	char*	m_FieldName/*发射平台名称*/;
	long	m_LaunchVehicleNo/*发射车/架编号*/;
	long	m_TargetNo/*目标编号*/;
	char*	m_TargetName/*目标名称*/;
	double	m_AttackAngle/*攻击角*/;
	short	m_SearchStratege/*搜捕策略，15个short元素的数组*/;
	GeoPt	m_WayPoints[MAX_RP_NUM]/*航路点（10个元素的数组，要修改）*/;
	long	m_WayPointsCount/*航路点个数（最多10个）*/;
	double	m_RadarSearchChart[14]/*雷达搜索图（14个参数的数组）*/;
	double	m_LauncherInterval/*发射系统发射间隔*/;
	long	m_LauncherMaxSalvoCount/*发射系统最大齐射数量*/;
	double	m_TotalFlyTime/*总飞行时间，同时到达模式下的导弹飞行时间,s*/;
	double	m_totalDist/*总航程,km*/;
	int	m_ASMType/*反舰导弹类型*/;
	int	m_ASMTrajType/*反舰导弹弹道类型(指YJ12、YJ91等超音速导弹的弹道类型：1低、2高低混合、3高)*/;
	long	m_ForceSide/*红蓝方*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
