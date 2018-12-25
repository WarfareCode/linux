//LaunchCanon.h: interface for the CLaunchCanon module.
//!!HDOSE_CLASS(CLaunchCanon,CLaunchWeapon)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchCanon_H)
#define AFX_LaunchCanon_H

#include "LaunchWeapon.h"

//{{HDOSE_CLS_DES(CLaunchCanon)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CLaunchCanon /*发射舰炮*/ : public CLaunchWeapon 
{
	DECLARE_CREATE;
public:
	CLaunchCanon();
	virtual ~CLaunchCanon();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetDuringTime(double val){m_DuringTime=val;}
	double	GetDuringTime(){return m_DuringTime;}
	void	SetOrientation(double val){m_Orientation=val;}
	double	GetOrientation(){return m_Orientation;}
	void	SetCount(long val){m_Count=val;}
	long	GetCount(){return m_Count;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchCanon)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchCanon)
	double	m_DuringTime/*持续时间*/;
	double	m_Orientation/*发射方位*/;
	long	m_Count/*数量*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
