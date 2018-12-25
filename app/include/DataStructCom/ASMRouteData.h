//ASMRouteData.h: interface for the CASMRouteData module.
//!!HDOSE_CLASS(CASMRouteData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMRouteData_H)
#define AFX_ASMRouteData_H


#include "WXCTime.h"

//{{HDOSE_CLS_DES(CASMRouteData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMRouteData /*����������·����*/
{
public:
	CASMRouteData();
	~CASMRouteData();
public:
	
	//{{HDOSE_ATTRIBUTE(CASMRouteData)
	int	m_BatchNo/*����*/;
	char		m_FieldName[32]/*����ƽ̨����*/;	//20151023����
	int	m_FieldNo/*����ƽ̨���*/;
	int	m_LaunchVehicleNo/*���䳵��ţ���ͧΪ����ܱ�ţ�*/;
	char		m_TargetName[32]/*Ŀ������*/;	//20151023����
	int	m_TargetNo/*Ŀ����*/;
	double	m_AttackAngle/*����*/;
	int	m_SearchStrategy/*�Ѳ�����*/;

	bool m_AutoCalcRoute;// �Զ����㺽·/�˹����뺽·���˹���·--����Ҫ���㺽·����ʱ����Ҫ���㣩

	double	m_RadarSearchChart[14]/*�״�����ͼ������14�����������飬Ҫ�޸ģ�*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*��·�㣨10��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_WayPointsCount/*��·����������10����*/;
	int	m_LaunchCount/*��������*/;

	double	m_LauncherInterval;//����ϵͳ������������ϵͳ�Ĳ����������˹����룩
	int	m_LauncherMaxSalvoCount;//����ϵͳ�����������

	CWXCTime	m_LaunchTime/*����ʱ��*/;
	bool	m_IsPlaned/*�Ƿ��ѽ����˺�·�滯*/;
	bool	m_IsLaunched/*�Ƿ��ѷ���*/;

	double	m_TotalFlyTime/*�ܷ���ʱ�䣬ͬʱ����ģʽ�µĵ�������ʱ��*/;

	int	m_RoutePlanMode;	//��·�滮Ŀ���ѡ��ʽ��0-��ǰ��滮��Ĭ�ϣ���1-ǰ�õ�滮��2-��3-, 4-, 5-����Ǳ���ʵ��Ŀ�꣨��Ŀ�ꡢ��Ŀ��ȣ� 

	// 20160219����
	double	m_totalDist;/*�ܺ���*/
	int		m_ASMType;/*������������*/
	int		m_ASMTrajType;/*����������������(ָYJ12��YJ91�ȳ����ٵ����ĵ������ͣ�1�͡�2�ߵͻ�ϡ�3��)*/
	double	m_FlyTimeofAttackMode2;//ͬʱͻ��ģʽ�¶�Ӧ�ĸõ�������ʱ��

	char m_uuid[MAX_CHARLEN];// ����Ψһ��ʶ
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CASMRouteDataList;
void ReleaseASMRouteDataList(CASMRouteDataList* list);

#endif
