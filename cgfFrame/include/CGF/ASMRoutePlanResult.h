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

class HYCGF_API CASMRoutePlanResult /*����������·�滮���*/ : public CEvt 
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
	bool	m_bValid/*�Ƿ���Ч*/;
	long	m_FieldNo/*����ƽ̨���*/;
	char*	m_FieldName/*����ƽ̨����*/;
	long	m_LaunchVehicleNo/*���䳵/�ܱ��*/;
	long	m_TargetNo/*Ŀ����*/;
	char*	m_TargetName/*Ŀ������*/;
	double	m_AttackAngle/*������*/;
	short	m_SearchStratege/*�Ѳ����ԣ�15��shortԪ�ص�����*/;
	GeoPt	m_WayPoints[MAX_RP_NUM]/*��·�㣨10��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_WayPointsCount/*��·����������10����*/;
	double	m_RadarSearchChart[14]/*�״�����ͼ��14�����������飩*/;
	double	m_LauncherInterval/*����ϵͳ������*/;
	long	m_LauncherMaxSalvoCount/*����ϵͳ�����������*/;
	double	m_TotalFlyTime/*�ܷ���ʱ�䣬ͬʱ����ģʽ�µĵ�������ʱ��,s*/;
	double	m_totalDist/*�ܺ���,km*/;
	int	m_ASMType/*������������*/;
	int	m_ASMTrajType/*����������������(ָYJ12��YJ91�ȳ����ٵ����ĵ������ͣ�1�͡�2�ߵͻ�ϡ�3��)*/;
	long	m_ForceSide/*������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
