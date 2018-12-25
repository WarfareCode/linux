//LaunchWeapon.h: interface for the CLaunchWeapon module.
//!!HDOSE_CLASS(CLaunchWeapon,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchWeapon_H)
#define AFX_LaunchWeapon_H


//{{HDOSE_CLS_DES(CLaunchWeapon)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CLaunchWeapon /*∑¢…‰Œ‰∆˜*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CLaunchWeapon();
	virtual ~CLaunchWeapon();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetWeaponSystemId(long val){m_WeaponSystemId=val;}
	long	GetWeaponSystemId(){return m_WeaponSystemId;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchWeapon)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchWeapon)
	long	m_WeaponSystemId/*Œ‰∆˜œµÕ≥Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
