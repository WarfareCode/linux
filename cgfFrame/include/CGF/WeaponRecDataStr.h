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
Descript:	����ÿ������ϵͳ�ϵĵ�ҩװ�ؼ�״̬���
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponRecDataStr /*����ϵͳ��ҩװ�����ݽṹ*/
{
public:
	CWeaponRecDataStr();
	~CWeaponRecDataStr();
public:

	//{{HDOSE_ATTRIBUTE(CWeaponRecDataStr)
	long	m_WeaponRecID/*������¼��ţ���0��ʼ��*/;
	char	m_Name[MAX_CHARLEN]/*��������*/;
	char	m_ClsName[MAX_CHARLEN]/*����ʵ������,�����������������涯̬ʵ�����ʱ��*/;
	long	m_CountMax/*�������������*/;
	long	m_Count/*��ǰ����*/;
	bool	m_Available/*�������Ƿ����*/;
	double	m_TimeToFire/*����׼��ʱ��(s)*/;
	double	m_OffAxisAngleMax/*�������ᷢ�����Ƕ�(deg)*/;
	double	m_KillRangeMin/*ɱ�˽���(Km)*/;
	double	m_KillRangeMax/*ɱ��Զ��(Km)*/;
	double	m_KillAltMin/*ɱ�˵ͽ�(Km)*/;
	double	m_KillAltMax/*ɱ�˸߽�(Km)*/;
	double	m_PltVelMin/*����ƽ̨�ٶ���Сֵ(m/s)*/;
	double	m_PltVelMax/*����ƽ̨�ٶ����ֵ(m/s)*/;
	double	m_PltAltMin/*����ƽ̨�߶���Сֵ(Km)*/;
	double	m_PltAltMax/*����ƽ̨�߶����ֵ(Km)*/;
	double	m_TargetVelMin/*Ŀ���ٶ���Сֵ(m/s)*/;
	double	m_TargetVelMax/*Ŀ���ٶ����ֵ(m/s)*/;
	double	m_VelAverage/*����ƽ���˶��ٶ�,m/s*/;
	double	m_VelMax/*��������˶��ٶ�,m/s*/;
	//}}HDOSE_ATTRIBUTE

	CWeaponRecDataStr& operator=(CWeaponRecDataStr val)
	{
		m_WeaponRecID = val.m_WeaponRecID	/*������¼��ţ���0��ʼ��*/;
		strcpy(m_Name , val.m_Name)		/*��������*/;
		strcpy(m_ClsName , val.m_ClsName)		/*����ʵ������,�����������������涯̬ʵ�����ʱ��*/;
		m_CountMax = val.m_CountMax	/*�������������*/;
		m_Count = val.m_Count	/*��ǰ����*/;
		m_Available = val.m_Available	/*�������Ƿ����*/;
		m_TimeToFire = val.m_TimeToFire	/*����׼��ʱ��(s)*/;
		m_OffAxisAngleMax = val.m_OffAxisAngleMax	/*�������ᷢ�����Ƕ�(deg)*/;
		m_KillRangeMin = val.m_KillRangeMin	/*ɱ�˽���(Km)*/;
		m_KillRangeMax = val.m_KillRangeMax	/*ɱ��Զ��(Km)*/;
		m_KillAltMin = val.m_KillAltMin	/*ɱ�˵ͽ�(Km)*/;
		m_KillAltMax = val.m_KillAltMax	/*ɱ�˸߽�(Km)*/;
		m_PltVelMin = val.m_PltVelMin	/*����ƽ̨�ٶ���Сֵ(m/s)*/;
		m_PltVelMax = val.m_PltVelMax	/*����ƽ̨�ٶ����ֵ(m/s)*/;
		m_PltAltMin = val.m_PltAltMin	/*����ƽ̨�߶���Сֵ(Km)*/;
		m_PltAltMax = val.m_PltAltMax	/*����ƽ̨�߶����ֵ(Km)*/;
		m_TargetVelMin = val.m_TargetVelMin	/*Ŀ���ٶ���Сֵ(m/s)*/;
		m_TargetVelMax = val.m_TargetVelMax	/*Ŀ���ٶ����ֵ(m/s)*/;
		m_VelAverage = val.m_VelAverage;
		m_VelMax = val.m_VelMax;

		return *this;
	}
};
typedef List<DWORD,DWORD> CWeaponRecDataStrList;
void ReleaseWeaponRecDataStrList(CWeaponRecDataStrList* list);

DECLARE_DA(CWeaponRecDataStr,MAX_WEAPON_REC_NUM);

#endif
