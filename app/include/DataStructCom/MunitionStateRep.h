//MunitionStateRep.h: interface for the CMunitionStateRep module.
//!!HDOSE_CLASS(CMunitionStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MunitionStateRep_H)
#define AFX_MunitionStateRep_H

//{{HDOSE_CLS_DES(CMunitionStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMunitionStateRep /*弹药状态池-TF*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CMunitionStateRep();
	virtual ~CMunitionStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetLaunchedTime(double val){m_LaunchedTime=val;}
	double	GetLaunchedTime(){return m_LaunchedTime;}
	void	SetLaunchPlatformNo(long val){m_LaunchPlatformNo=val;}
	long	GetLaunchPlatformNo(){return m_LaunchPlatformNo;}
	void	SetLaunchPlatformName(char* val){strcpy(m_LaunchPlatformName,val);}
	char*	GetLaunchPlatformName(){return m_LaunchPlatformName;}
	void	SetAttackAngle(double val){m_AttackAngle=val;}
	double	GetAttackAngle(){return m_AttackAngle;}

	void	SetDist2Target(double val){m_Dist2Target=val;}
	double	GetDist2Target(){return m_Dist2Target;}
	//{{HDOSE_MEMBER_FUNCTION(CMunitionStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CMunitionStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMunitionStateRep)
	double	m_LaunchedTime/*发射时间*/;
	long	m_LaunchPlatformNo/*发射平台单元编号*/;
	char		m_LaunchPlatformName[MAX_CHARLEN]/*发射平台名称*/;
	double	m_AttackAngle/*攻角*/;
	// 20170407
	double	m_Dist2Target/*与所攻击目标的距离*/; 
	//}}HDOSE_ATTRIBUTE
};

#endif
