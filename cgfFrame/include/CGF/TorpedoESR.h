//TorpedoESR.h: interface for the CTorpedoESR module.
//!!HDOSE_CLASS(CTorpedoESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoESR_H)
#define AFX_TorpedoESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CTorpedoESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CTorpedoESR /*鱼雷状态池*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CTorpedoESR();
	virtual ~CTorpedoESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetLaunchPlatformId(long val){m_LaunchPlatformId=val;}
	long	GetLaunchPlatformId(){return m_LaunchPlatformId;}
	void	SetTargetId(long val){m_TargetId=val;}
	long	GetTargetId(){return m_TargetId;}
	//{{HDOSE_MEMBER_FUNCTION(CTorpedoESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CTorpedoESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTorpedoESR)
	long	m_LaunchPlatformId/*发射平台Id*/;
	long	m_TargetId/*攻击目标批号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
