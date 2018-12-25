//LaunchBomb.h: interface for the CLaunchBomb module.
//!!HDOSE_CLASS(CLaunchBomb,CLaunchWeapon)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchBomb_H)
#define AFX_LaunchBomb_H

#include "LaunchWeapon.h"

//{{HDOSE_CLS_DES(CLaunchBomb)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CLaunchBomb /*投掷炸弹*/ : public CLaunchWeapon 
{
	DECLARE_CREATE;
public:
	CLaunchBomb();
	virtual ~CLaunchBomb();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetCount(long val){m_Count=val;}
	long	GetCount(){return m_Count;}
	void	SetCastIntervel(double val){m_CastIntervel=val;}
	double	GetCastIntervel(){return m_CastIntervel;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchBomb)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchBomb)
	long	m_Count/*数量*/;
	double	m_CastIntervel/*投弹间隔（m）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
