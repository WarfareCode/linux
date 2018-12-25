//LaunchTorpedo.h: interface for the CLaunchTorpedo module.
//!!HDOSE_CLASS(CLaunchTorpedo,CLaunchWeapon)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchTorpedo_H)
#define AFX_LaunchTorpedo_H

#include "LaunchWeapon.h"

//{{HDOSE_CLS_DES(CLaunchTorpedo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CLaunchTorpedo /*发射鱼雷*/ : public CLaunchWeapon 
{
	DECLARE_CREATE;
public:
	CLaunchTorpedo();
	virtual ~CLaunchTorpedo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetId(long val){m_TargetId=val;}
	long	GetTargetId(){return m_TargetId;}
	void	SetCount(long val){m_Count=val;}
	long	GetCount(){return m_Count;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchTorpedo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchTorpedo)
	long	m_TargetId/*目标Id*/;
	long	m_Count/*发射数量*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
