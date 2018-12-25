//UnitFireSchedulingInfo.h: interface for the CUnitFireSchedulingInfo module.
//!!HDOSE_CLASS(CUnitFireSchedulingInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_UnitFireSchedulingInfo_H)
#define AFX_UnitFireSchedulingInfo_H


#include "WXCTime.h"
#include "NoFlyZoneData.h"

//{{HDOSE_CLS_DES(CUnitFireSchedulingInfo)
/*
Author:		
Version:	1.0
Descript:	分配给岸导阵地的多个导弹火力信息
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CUnitFireSchedulingInfo /*单元内火力分配信息*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CUnitFireSchedulingInfo();
	virtual ~CUnitFireSchedulingInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetLaunchVehicleNo(long val){m_LaunchVehicleNo=val;}
	long	GetLaunchVehicleNo(){return m_LaunchVehicleNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetTargetName(char* val){SetValueString("TargetName",val);}
	char*	GetTargetName(){return GetValueString("TargetName");}
	void	SetAttackAngle(double val){m_AttackAngle=val;}
	double	GetAttackAngle(){return m_AttackAngle;}
	void	SetSearchStratege(long val){m_SearchStratege=val;}
	long	GetSearchStratege(){return m_SearchStratege;}
	void	SetWayPoints(DtWayPoint val[]){
		for(int i=0;i<MAX_RP_NUM;i++)
			m_WayPoints[i]=val[i];
	}
	DtWayPoint*	GetWayPoints(){return m_WayPoints;}
	void	SetWayPointsCount(long val){m_WayPointsCount=val;}
	long	GetWayPointsCount(){return m_WayPointsCount;}
	void	SetRadarSearchChart(double val[14]){
		for(int i=0;i<14;i++)
			m_RadarSearchChart[i]=val[i];
	}
	double*	GetRadarSearchChart(){return m_RadarSearchChart;}
	void	SetLaunchTime(CWXCTime val){m_LaunchTime=val;}
	CWXCTime	GetLaunchTime(){return m_LaunchTime;}
	void	SetbOK(bool val){m_bOK=val;}
	bool	GetbOK(){return m_bOK;}
	void	SetNoFlyZoneInfo(CNoFlyZoneData val[]){
		for(int i=0;i<10;i++)
			m_NoFlyZoneInfo[i]=val[i];
	}
	CNoFlyZoneData*	GetNoFlyZoneInfo(){return m_NoFlyZoneInfo;}
	void	SetNoFlyZoneCount(long val){m_NoFlyZoneCount=val;}
	long	GetNoFlyZoneCount(){return m_NoFlyZoneCount;}
	void	SetLaunchCount(long val){m_LaunchCount=val;}
	long	GetLaunchCount(){return m_LaunchCount;}
	//{{HDOSE_MEMBER_FUNCTION(CUnitFireSchedulingInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CUnitFireSchedulingInfo)
	long	m_FieldNo/*阵地编号*/;
	long	m_LaunchVehicleNo/*发射车编号(船上为发射架编号)*/;
	long	m_TargetNo/*目标编号*/;
	char*	m_TargetName/*目标名称*/;
	double	m_AttackAngle/*攻击角*/;
	long	m_SearchStratege/*搜捕策略（0，1，2，3.）*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*航路点（10个元素的数组，要修改）*/;
	long	m_WayPointsCount/*航路点个数（最多10个）*/;
	double	m_RadarSearchChart[14]/*雷达搜索图（14个参数的数组）*/;
	CWXCTime	m_LaunchTime/*发射时间*/;
	bool	m_bOK/*是否确认*/;
	CNoFlyZoneData	m_NoFlyZoneInfo[10]/*禁飞区信息（数组）*/;
	long	m_NoFlyZoneCount/*禁飞区数量*/;
	long	m_LaunchCount;/*发射数量*/

	double m_totalDist;		// 航路总长度km
	double m_totalFlyTime;		// 总飞行时间
	int m_ASMType;	// 发射的反舰导弹类型
	int m_ASMTrajType;	// 反舰导弹弹道类型（指YJ12的弹道，1-低、2-高低、3-高）

	// 20180315
	int m_RoutePlanMode;	//本条航路规划方式，0-当前点规划（默认），1-前置点规划，2-，3- 
	char m_uuid[MAX_CHARLEN];// 导弹唯一标识
	//}}HDOSE_ATTRIBUTE
};

#endif
