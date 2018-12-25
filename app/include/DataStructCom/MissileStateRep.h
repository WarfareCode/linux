//MissileStateRep.h: interface for the CMissileStateRep module.
//!!HDOSE_CLASS(CMissileStateRep,CMunitionStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MissileStateRep_H)
#define AFX_MissileStateRep_H

#include "MunitionStateRep.h"
#include "SeekerDisplayData.h"

//{{HDOSE_CLS_DES(CMissileStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMissileStateRep /*导弹状态池-TF*/ : public CMunitionStateRep 
{
	DECLARE_CREATE;
public:
	CMissileStateRep();
	virtual ~CMissileStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetbSeekerPowerOn(bool val){m_bSeekerPowerOn=val;}
	bool	GetbSeekerPowerOn(){return m_bSeekerPowerOn;}
	void	SetSeekerWorkInstruction(long val){m_SeekerWorkInstruction=val;}
	long	GetSeekerWorkInstruction(){return m_SeekerWorkInstruction;}
	void	SetSeekerSearchStratege(long val){m_SeekerSearchStratege=val;}
	long	GetSeekerSearchStratege(){return m_SeekerSearchStratege;}
	void	SetSeekerElecAxisAzimuth(double val){m_SeekerElecAxisAzimuth=val;}
	double	GetSeekerElecAxisAzimuth(){return m_SeekerElecAxisAzimuth;}
	void	SetBeamWidth(double val){m_BeamWidth=val;}
	double	GetBeamWidth(){return m_BeamWidth;}
	void	SetSeekerDetectDistance(double val){m_SeekerDetectDistance=val;}
	double	GetSeekerDetectDistance(){return m_SeekerDetectDistance;}
	void	SetSeekerDetectAngle(double val){m_SeekerDetectAngle=val;}
	double	GetSeekerDetectAngle(){return m_SeekerDetectAngle;}
	void	SetSeekerDetectInfo(CSeekerDisplayData val[10]){
		for(int i=0;i<10;i++)
			m_SeekerDetectInfo[i]=val[i];
	}
	CSeekerDisplayData*	GetSeekerDetectInfo(){return m_SeekerDetectInfo;}
	void	SetSeekerDetectInfoCount(long val){m_SeekerDetectInfoCount=val;}
	long	GetSeekerDetectInfoCount(){return m_SeekerDetectInfoCount;}
	void	SetInitTargetNo(long val){m_InitTargetNo=val;}
	long	GetInitTargetNo(){return m_InitTargetNo;}
	void	SetInitTargetName(char* val){strcpy(m_InitTargetName,val);}
	char*	GetInitTargetName(){return m_InitTargetName;}
	void	SetMissileTargetPlatform(long val){m_MissileTargetPlatform=val;}
	long	GetMissileTargetPlatform(){return m_MissileTargetPlatform;}
	void	SetMissileType(long val){m_MissileType=val;}
	long	GetMissileType(){return m_MissileType;}
	void	SetHitProbability(double val){m_HitProbability=val;}
	double	GetHitProbability(){return m_HitProbability;}
// 	void	SetDist2Target(double val){m_Dist2Target=val;}
// 	double	GetDist2Target(){return m_Dist2Target;}

	double	GetLength(){return m_Length;}
	double	GetDiameter(){return m_Diameter;}
	double	GetWingSpan(){return m_WingSpan;}
	double	GetMaxAttackDist(){return m_MaxAttackDist;}
	double	GetMaxAttackHeight(){return m_MaxAttackHeight;}
	double	GetMinVel(){return m_MinVel;}
	double	GetMaxVel(){return m_MaxVel;}
	double	GetMaxAcc(){return m_MaxAcc;}
	double	GetCruiseHeight(){return m_CruiseHeight;}
	double	GetCruiseVel(){return m_CruiseVel;}
	double	GetMinTurnRadius(){return m_MinTurnRadius;}
	double	GetMaxYawRate(){return m_MaxYawRate;}
	double	GetMaxPitchRate(){return m_MaxPitchRate;}
	double	GetMaxRollRate(){return m_MaxRollRate;}
	double	GetMaxPitchAngle(){return m_MaxPitchAngle;}
	double	GetMaxRollAngle(){return m_MaxRollAngle;}
	double	GetMaxG(){return m_MaxG;}
	double	GetMinG(){return m_MinG;}
	double	GetMaxClimbVel(){return m_MaxClimbVel;}
	double	GetHitAccuracy(){return m_HitAccuracy;}

	//{{HDOSE_MEMBER_FUNCTION(CMissileStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:

	//{{HDOSE_ATTRIBUTE(CMissileStateRep)
	bool	m_bSeekerPowerOn/*导引头是否开机*/;
	long	m_SeekerWorkInstruction/*导引头工作指令（捕捉指令0、航战指令1、高战指令2、俯冲指令3、杂干指令4、3号指令5）*/;
	long	m_SeekerSearchStratege/*导引头搜索搜捕规则（0，1，2....）*/;
	double	m_SeekerElecAxisAzimuth/*导引头电轴方位*/;
	double	m_BeamWidth/*导引头波束宽度*/;
	double	m_SeekerDetectDistance/*导引头当前探测距离*/;
	double	m_SeekerDetectAngle/*导引头当前探测角度范围（雷达天线最大转动角度，从导引头静态参数中获取）*/;
	CSeekerDisplayData	m_SeekerDetectInfo[10]/*导引头探测到的数据信息，送给前台显示的，100个元素的数组，（被导引头探测到的数据信息如防空导弹、舰艇、箔条、干扰）*/;
	long	m_SeekerDetectInfoCount/*导引头探测到的数据信息个数，最多100个*/;
	long	m_InitTargetNo/*设定攻击的目标编号（不变的）*/;
	char		m_InitTargetName[MAX_CHARLEN]/*设定攻击的目标名称*/;
	long	m_MissileTargetPlatform/*导弹攻击平台性质（0反舰、1对空）*/;
	long	m_MissileType/*具体导弹类型（是反舰弹则对应反舰弹类型，是对空弹则对应对空弹类型）*/;
	double	m_HitProbability/*命中概率*/;
//	double	m_Dist2Target/*与所攻击目标的距离*/;
	// 20170318,为了演示需要增加此参数
	long	m_HittedType/*被击毁方式（演示需要，0无、1防空弹拦截、2被箔条弹干扰、3红外弹干扰、4舷外水面有源诱饵干扰ssq95、5舷外空中有源诱饵干扰nulka、6近防炮）*/;
	//}}HDOSE_ATTRIBUTE

	//{{HDOSE_PARAMETER(CMissileStateRep)
	double	m_Length/*弹长(m)*/;
	double	m_Diameter/*直径(m)*/;
	double	m_WingSpan/*翼展(m)*/;
	double	m_MaxAttackDist/*最大射程(公里)*/;
	double	m_MaxAttackHeight/*射高(m)*/;
	double	m_MinVel/*最小速度(Ma）*/;
	double	m_MaxVel/*最大速度（Ma）*/;
	double	m_MaxAcc/*最大加速度*/;
	double	m_CruiseHeight/*巡航高度（m）*/;
	double	m_CruiseVel/*巡航速度（Ma）*/;
	double	m_MinTurnRadius/*最小转弯半径（公里）*/;
	double	m_MaxYawRate/*最大偏航速率（度/s）*/;
	double	m_MaxPitchRate/*最大俯仰速率（度/s）*/;
	double	m_MaxRollRate/*最大滚转速率（度/s）*/;
	double	m_MaxPitchAngle/*最大俯仰角度（度）*/;
	double	m_MaxRollAngle/*最大滚转角度（度）*/;
	double	m_MaxG/*最大过载（正值，g的倍数）*/;
	double	m_MinG/*最小过载（负值，g的倍数）*/;
	double	m_MaxClimbVel/*最大爬升率*/;
	double	m_HitAccuracy/*命中精度（m）*/;
	double	m_MaxFlyTime/*最大飞行时间(min)*/;
	double	m_KillRadius/*杀伤半径,m*/;
	long	m_WarheadType/*弹头类型,1-常规、2-核*/;
	//}}HDOSE_PARAMETER
};

#endif
