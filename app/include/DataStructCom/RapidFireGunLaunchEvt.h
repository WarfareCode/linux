//RapidFireGunLaunchEvt.h: interface for the CRapidFireGunLaunchEvt module.
//!!HDOSE_CLASS(CRapidFireGunLaunchEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RapidFireGunLaunchEvt_H)
#define AFX_RapidFireGunLaunchEvt_H


//{{HDOSE_CLS_DES(CRapidFireGunLaunchEvt)
/*
Author:		xks
Version:	1.0
Descript:	用于模拟速射舰炮发射的交互，由于不能完全模拟所有速射炮弹的运动轨迹，
因此通过这种交互方式告知被攻击目标，并告知其相关的武器参数，
被攻击目标通过模拟一组随机数的方式来进行毁伤判断。

*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CRapidFireGunLaunchEvt /*速射舰炮发射事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CRapidFireGunLaunchEvt();
	virtual ~CRapidFireGunLaunchEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetId(long val){m_TargetId=val;}
	long	GetTargetId(){return m_TargetId;}
	void	SetTargetDis(double val){m_TargetDis=val;}
	double	GetTargetDis(){return m_TargetDis;}
	void	SetDurationTime(double val){m_DurationTime=val;}
	double	GetDurationTime(){return m_DurationTime;}
	void	SetROF(double val){m_ROF=val;}
	double	GetROF(){return m_ROF;}
	void	SetCannonVelInit(double val){m_CannonVelInit=val;}
	double	GetCannonVelInit(){return m_CannonVelInit;}
	void	SetBestKillDist(double val){m_BestKillDist=val;}
	double	GetBestKillDist(){return m_BestKillDist;}

	//{{HDOSE_MEMBER_FUNCTION(CRapidFireGunLaunchEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRapidFireGunLaunchEvt)
	long	m_TargetId/*打击目标编号*/;
	double	m_TargetDis/*发射时与目标的距离,m*/;
	double	m_DurationTime/*发射持续时间,s*/;
	double	m_ROF/*炮弹发射速率,发/min*/;
	double	m_CannonVelInit/*炮弹初始速度,m/s*/;
	double	m_BestKillDist/*炮弹的最佳射程,m*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
