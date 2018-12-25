//MissileWarheadESR.h: interface for the CMissileWarheadESR module.
//!!HDOSE_CLASS(CMissileWarheadESR,CMissileESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MissileWarheadESR_H)
#define AFX_MissileWarheadESR_H

#include "MissileESR.h"
#include "OrbitData.h"

//{{HDOSE_CLS_DES(CMissileWarheadESR)
/*
Author:		
Version:	1.0
Descript:	专指可分离的空间弹道弹道弹头
*/
//}}HDOSE_CLS_DES

class HYCGF_API CMissileWarheadESR /*导弹弹头状态池*/ : public CMissileESR 
{
	DECLARE_CREATE;
public:
	CMissileWarheadESR();
	virtual ~CMissileWarheadESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetWarheadType(long val){m_WarheadType=val;}
	long	GetWarheadType(){return m_WarheadType;}
	void	SetOrbitInfo(COrbitData val){m_OrbitInfo=val;}
	COrbitData	GetOrbitInfo(){return m_OrbitInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CMissileWarheadESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CMissileWarheadESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMissileWarheadESR)
	long	m_WarheadType/*弹头类型（真弹头、诱饵、...）*/;
	COrbitData	m_OrbitInfo/*轨道参数*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
