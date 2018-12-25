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
Descript:	�����������صĶ������������Ϣ
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CUnitFireSchedulingInfo /*��Ԫ�ڻ���������Ϣ*/ : public CEvt 
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
	long	m_FieldNo/*��ر��*/;
	long	m_LaunchVehicleNo/*���䳵���(����Ϊ����ܱ��)*/;
	long	m_TargetNo/*Ŀ����*/;
	char*	m_TargetName/*Ŀ������*/;
	double	m_AttackAngle/*������*/;
	long	m_SearchStratege/*�Ѳ����ԣ�0��1��2��3.��*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*��·�㣨10��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_WayPointsCount/*��·����������10����*/;
	double	m_RadarSearchChart[14]/*�״�����ͼ��14�����������飩*/;
	CWXCTime	m_LaunchTime/*����ʱ��*/;
	bool	m_bOK/*�Ƿ�ȷ��*/;
	CNoFlyZoneData	m_NoFlyZoneInfo[10]/*��������Ϣ�����飩*/;
	long	m_NoFlyZoneCount/*����������*/;
	long	m_LaunchCount;/*��������*/

	double m_totalDist;		// ��·�ܳ���km
	double m_totalFlyTime;		// �ܷ���ʱ��
	int m_ASMType;	// ����ķ�����������
	int m_ASMTrajType;	// ���������������ͣ�ָYJ12�ĵ�����1-�͡�2-�ߵ͡�3-�ߣ�

	// 20180315
	int m_RoutePlanMode;	//������·�滮��ʽ��0-��ǰ��滮��Ĭ�ϣ���1-ǰ�õ�滮��2-��3- 
	char m_uuid[MAX_CHARLEN];// ����Ψһ��ʶ
	//}}HDOSE_ATTRIBUTE
};

#endif
