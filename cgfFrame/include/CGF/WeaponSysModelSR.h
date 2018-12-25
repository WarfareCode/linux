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
Descript:	用于记录武器系统的动态信息，包括系统当前状态、武器类型、数量及武器的状态
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponSysModelSR /*武器系统模型状态池*/ : public CModelSR 
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
	long	m_WeaponCount/*当前总可用弹量*/;
	long	m_WeaponRecCount/*总装弹种类数量*/;
	DA_CWeaponRecSmpDataStr	m_WeaponRecData/*装弹数据*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
