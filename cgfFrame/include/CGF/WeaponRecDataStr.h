//WeaponRecDataStr.h: interface for the CWeaponRecDataStr module.
//!!HDOSE_CLASS(CWeaponRecDataStr,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_WeaponRecDataStr_H)
#define AFX_WeaponRecDataStr_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CWeaponRecDataStr)
/*
Author:		xks
Version:	1.0
Descript:	描述每个武器系统上的弹药装载及状态情况
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponRecDataStr /*武器系统弹药装载数据结构*/
{
public:
	CWeaponRecDataStr();
	~CWeaponRecDataStr();
public:

	//{{HDOSE_ATTRIBUTE(CWeaponRecDataStr)
	long	m_WeaponRecID/*武器记录编号（从0开始）*/;
	char	m_Name[MAX_CHARLEN]/*武器名称*/;
	char	m_ClsName[MAX_CHARLEN]/*武器实体类名,仅用于在引擎中生存动态实体对象时用*/;
	long	m_CountMax/*武器的最大容量*/;
	long	m_Count/*当前数量*/;
	bool	m_Available/*该武器是否可用*/;
	double	m_TimeToFire/*发射准备时间(s)*/;
	double	m_OffAxisAngleMax/*武器离轴发射最大角度(deg)*/;
	double	m_KillRangeMin/*杀伤近界(Km)*/;
	double	m_KillRangeMax/*杀伤远界(Km)*/;
	double	m_KillAltMin/*杀伤低界(Km)*/;
	double	m_KillAltMax/*杀伤高界(Km)*/;
	double	m_PltVelMin/*发射平台速度最小值(m/s)*/;
	double	m_PltVelMax/*发射平台速度最大值(m/s)*/;
	double	m_PltAltMin/*发射平台高度最小值(Km)*/;
	double	m_PltAltMax/*发射平台高度最大值(Km)*/;
	double	m_TargetVelMin/*目标速度最小值(m/s)*/;
	double	m_TargetVelMax/*目标速度最大值(m/s)*/;
	double	m_VelAverage/*武器平均运动速度,m/s*/;
	double	m_VelMax/*武器最大运动速度,m/s*/;
	//}}HDOSE_ATTRIBUTE

	CWeaponRecDataStr& operator=(CWeaponRecDataStr val)
	{
		m_WeaponRecID = val.m_WeaponRecID	/*武器记录编号（从0开始）*/;
		strcpy(m_Name , val.m_Name)		/*武器名称*/;
		strcpy(m_ClsName , val.m_ClsName)		/*武器实体类名,仅用于在引擎中生存动态实体对象时用*/;
		m_CountMax = val.m_CountMax	/*武器的最大容量*/;
		m_Count = val.m_Count	/*当前数量*/;
		m_Available = val.m_Available	/*该武器是否可用*/;
		m_TimeToFire = val.m_TimeToFire	/*发射准备时间(s)*/;
		m_OffAxisAngleMax = val.m_OffAxisAngleMax	/*武器离轴发射最大角度(deg)*/;
		m_KillRangeMin = val.m_KillRangeMin	/*杀伤近界(Km)*/;
		m_KillRangeMax = val.m_KillRangeMax	/*杀伤远界(Km)*/;
		m_KillAltMin = val.m_KillAltMin	/*杀伤低界(Km)*/;
		m_KillAltMax = val.m_KillAltMax	/*杀伤高界(Km)*/;
		m_PltVelMin = val.m_PltVelMin	/*发射平台速度最小值(m/s)*/;
		m_PltVelMax = val.m_PltVelMax	/*发射平台速度最大值(m/s)*/;
		m_PltAltMin = val.m_PltAltMin	/*发射平台高度最小值(Km)*/;
		m_PltAltMax = val.m_PltAltMax	/*发射平台高度最大值(Km)*/;
		m_TargetVelMin = val.m_TargetVelMin	/*目标速度最小值(m/s)*/;
		m_TargetVelMax = val.m_TargetVelMax	/*目标速度最大值(m/s)*/;
		m_VelAverage = val.m_VelAverage;
		m_VelMax = val.m_VelMax;

		return *this;
	}
};
typedef List<DWORD,DWORD> CWeaponRecDataStrList;
void ReleaseWeaponRecDataStrList(CWeaponRecDataStrList* list);

DECLARE_DA(CWeaponRecDataStr,MAX_WEAPON_REC_NUM);

#endif
