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

class DATASTRUCTCOMPONENTDLL_API CASMRouteData /*反舰导弹航路数据*/
{
public:
	CASMRouteData();
	~CASMRouteData();
public:
	
	//{{HDOSE_ATTRIBUTE(CASMRouteData)
	int	m_BatchNo/*批次*/;
	char		m_FieldName[32]/*发射平台名称*/;	//20151023新增
	int	m_FieldNo/*发射平台编号*/;
	int	m_LaunchVehicleNo/*发射车编号（舰艇为发射架编号）*/;
	char		m_TargetName[32]/*目标名称*/;	//20151023新增
	int	m_TargetNo/*目标编号*/;
	double	m_AttackAngle/*攻角*/;
	int	m_SearchStrategy/*搜捕规则*/;

	bool m_AutoCalcRoute;// 自动计算航路/人工输入航路（人工航路--不需要计算航路，但时序需要计算）

	double	m_RadarSearchChart[14]/*雷达搜索图（包含14个参数的数组，要修改）*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*航路点（10个元素的数组，要修改）*/;
	long	m_WayPointsCount/*航路点个数（最多10个）*/;
	int	m_LaunchCount/*发射数量*/;

	double	m_LauncherInterval;//发射系统发射间隔（发射系统的参数，无需人工输入）
	int	m_LauncherMaxSalvoCount;//发射系统最大齐射数量

	CWXCTime	m_LaunchTime/*发射时间*/;
	bool	m_IsPlaned/*是否已进行了航路规化*/;
	bool	m_IsLaunched/*是否已发射*/;

	double	m_TotalFlyTime/*总飞行时间，同时到达模式下的导弹飞行时间*/;

	int	m_RoutePlanMode;	//航路规划目标点选择方式，0-当前点规划（默认），1-前置点规划，2-，3-, 4-, 5-打击非兵力实体目标（点目标、面目标等） 

	// 20160219新增
	double	m_totalDist;/*总航程*/
	int		m_ASMType;/*反舰导弹类型*/
	int		m_ASMTrajType;/*反舰导弹弹道类型(指YJ12、YJ91等超音速导弹的弹道类型：1低、2高低混合、3高)*/
	double	m_FlyTimeofAttackMode2;//同时突防模式下对应的该导弹飞行时间

	char m_uuid[MAX_CHARLEN];// 导弹唯一标识
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CASMRouteDataList;
void ReleaseASMRouteDataList(CASMRouteDataList* list);

#endif
