//LaunchMissile.h: interface for the CLaunchMissile module.
//!!HDOSE_CLASS(CLaunchMissile,CLaunchWeapon)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchMissile_H)
#define AFX_LaunchMissile_H

#include "LaunchWeapon.h"

//{{HDOSE_CLS_DES(CLaunchMissile)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CLaunchMissile /*发射导弹*/ : public CLaunchWeapon 
{
	DECLARE_CREATE;
public:
	CLaunchMissile();
	virtual ~CLaunchMissile();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetId(long val){m_TargetId=val;}
	long	GetTargetId(){return m_TargetId;}
	void	SetTargetPos(GeoPt val){m_TargetPos=val;}
	GeoPt	GetTargetPos(){return m_TargetPos;}
	void	SetCount(long val){m_Count=val;}
	long	GetCount(){return m_Count;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchMissile)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchMissile)
	long	m_TargetId/*目标Id*/;
	GeoPt	m_TargetPos/*目标位置*/;
	long	m_Count/*发射数量*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
