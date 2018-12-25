//WeaponSysModelSR.h: interface for the CWeaponSysModelSR module.
//!!HDOSE_CLASS(CWeaponSysModelSR,CModelSR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_WeaponSysModelSR_H)
#define AFX_WeaponSysModelSR_H

#include "ModelSR.h"
#include "WeaponRecSmpDataStr.h"

//{{HDOSE_CLS_DES(CWeaponSysModelSR)
/*
Author:		xks
Version:	1.0
Descript:	���ڼ�¼����ϵͳ�Ķ�̬��Ϣ������ϵͳ��ǰ״̬���������͡�������������״̬
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponSysModelSR /*����ϵͳģ��״̬��*/ : public CModelSR 
{
	DECLARE_CREATE;
public:
	CWeaponSysModelSR();
	virtual ~CWeaponSysModelSR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetWeaponCount(long val){m_WeaponCount=val;}
	long	GetWeaponCount(){return m_WeaponCount;}
	void	SetWeaponRecCount(long val){m_WeaponRecCount=val;}
	long	GetWeaponRecCount(){return m_WeaponRecCount;}
	//void	SetWeaponRecData(CWeaponRecSmpDataStr val){m_WeaponRecData=val;}
	//CWeaponRecSmpDataStr	GetWeaponRecData(){return m_WeaponRecData;}

	//{{HDOSE_MEMBER_FUNCTION(CWeaponSysModelSR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CWeaponSysModelSR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CWeaponSysModelSR)
	long	m_WeaponCount/*��ǰ�ܿ��õ���*/;
	long	m_WeaponRecCount/*��װ����������*/;
	DA_CWeaponRecSmpDataStr	m_WeaponRecData/*װ������*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
