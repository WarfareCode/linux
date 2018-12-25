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

class HYCGF_API CWeaponRecSmpDataStr /*������ҩ��̬��¼���ݽṹ*/
{
public:
	CWeaponRecSmpDataStr();
	~CWeaponRecSmpDataStr();
public:
	
	//{{HDOSE_ATTRIBUTE(CWeaponRecSmpDataStr)
	long	m_WeaponRecID/*������¼��ţ���0��ʼ��*/;
	char	m_Name[MAX_CHARLEN]/*��������*/;
	long	m_Count/*��ǰ����*/;
	bool	m_Available/*�������Ƿ����*/;
	double	m_TimeToFire/*��ǰ����׼��ʱ��(s)*/;
	//}}HDOSE_ATTRIBUTE

CWeaponRecSmpDataStr& operator=(CWeaponRecSmpDataStr val)
{
	m_WeaponRecID = val.m_WeaponRecID	/*������¼��ţ���0��ʼ��*/;
	strcpy(m_Name , val.m_Name)		/*��������*/;
	m_Count = val.m_Count	/*��ǰ����*/;
	m_Available = val.m_Available	/*�������Ƿ����*/;
	m_TimeToFire = val.m_TimeToFire	/*��ǰ����׼��ʱ��(s)*/;

	return *this;
}
};
typedef List<DWORD,DWORD> CWeaponRecSmpDataStrList;
void ReleaseWeaponRecSmpDataStrList(CWeaponRecSmpDataStrList* list);

DECLARE_DA(CWeaponRecSmpDataStr,MAX_WEAPON_REC_NUM);

#endif
