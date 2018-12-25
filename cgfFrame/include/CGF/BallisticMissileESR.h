//BallisticMissileESR.h: interface for the CBallisticMissileESR module.
//!!HDOSE_CLASS(CBallisticMissileESR,CMissileESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_BallisticMissileESR_H)
#define AFX_BallisticMissileESR_H

#include "MissileESR.h"
#include "OrbitData.h"

//{{HDOSE_CLS_DES(CBallisticMissileESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CBallisticMissileESR /*��������״̬��*/ : public CMissileESR 
{
	DECLARE_CREATE;
public:
	CBallisticMissileESR();
	virtual ~CBallisticMissileESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetFlyStage(long val){m_FlyStage=val;}
	long	GetFlyStage(){return m_FlyStage;}
	void	SetOrbitInfo(COrbitData val){m_OrbitInfo=val;}
	COrbitData	GetOrbitInfo(){return m_OrbitInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CBallisticMissileESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CBallisticMissileESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CBallisticMissileESR)
	long	m_FlyStage/*���н׶Σ�һ�����롢�������롢�������룩*/;
	COrbitData	m_OrbitInfo/*�������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
