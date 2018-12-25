//WeaponRecSmpDataStr.h: interface for the CWeaponRecSmpDataStr module.
//!!HDOSE_CLASS(CWeaponRecSmpDataStr,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_WeaponRecSmpDataStr_H)
#define AFX_WeaponRecSmpDataStr_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CWeaponRecSmpDataStr)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponRecSmpDataStr /*武器弹药动态记录数据结构*/
{
public:
	CWeaponRecSmpDataStr();
	~CWeaponRecSmpDataStr();
public:
	
	//{{HDOSE_ATTRIBUTE(CWeaponRecSmpDataStr)
	long	m_WeaponRecID/*武器记录编号（从0开始）*/;
	char	m_Name[MAX_CHARLEN]/*武器名称*/;
	long	m_Count/*当前数量*/;
	bool	m_Available/*该武器是否可用*/;
	double	m_TimeToFire/*当前发射准备时间(s)*/;
	//}}HDOSE_ATTRIBUTE

CWeaponRecSmpDataStr& operator=(CWeaponRecSmpDataStr val)
{
	m_WeaponRecID = val.m_WeaponRecID	/*武器记录编号（从0开始）*/;
	strcpy(m_Name , val.m_Name)		/*武器名称*/;
	m_Count = val.m_Count	/*当前数量*/;
	m_Available = val.m_Available	/*该武器是否可用*/;
	m_TimeToFire = val.m_TimeToFire	/*当前发射准备时间(s)*/;

	return *this;
}
};
typedef List<DWORD,DWORD> CWeaponRecSmpDataStrList;
void ReleaseWeaponRecSmpDataStrList(CWeaponRecSmpDataStrList* list);

DECLARE_DA(CWeaponRecSmpDataStr,MAX_WEAPON_REC_NUM);

#endif
