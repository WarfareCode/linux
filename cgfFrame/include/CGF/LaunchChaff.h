//LaunchChaff.h: interface for the CLaunchChaff module.
//!!HDOSE_CLASS(CLaunchChaff,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchChaff_H)
#define AFX_LaunchChaff_H


//{{HDOSE_CLS_DES(CLaunchChaff)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CLaunchChaff /*发射箔条弹*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CLaunchChaff();
	virtual ~CLaunchChaff();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetOrientation(double val){m_Orientation=val;}
	double	GetOrientation(){return m_Orientation;}
	void	SetCount(long val){m_Count=val;}
	long	GetCount(){return m_Count;}
	void	SetLaunchType(long val){m_LaunchType=val;}
	long	GetLaunchType(){return m_LaunchType;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchChaff)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchChaff)
	double	m_Orientation/*方位*/;
	long	m_Count/*数量*/;
	long	m_LaunchType/*发射样式*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
