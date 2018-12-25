//CmdEntityStateRep.h: interface for the CCmdEntityStateRep module.
//!!HDOSE_CLASS(CCmdEntityStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CmdEntityStateRep_H)
#define AFX_CmdEntityStateRep_H

#include "ASMRouteData.h"

//{{HDOSE_CLS_DES(CCmdEntityStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCmdEntityStateRep /*指挥实体状态池*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CCmdEntityStateRep();
	virtual ~CCmdEntityStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetIsAutoPlan(int val){m_IsAutoPlan=val;}
	int	GetIsAutoPlan(){return m_IsAutoPlan;}
// 	void	SetASMPlanData(CASMRouteData val[]){
// 		for(int i=0;i<30;i++)
// 			m_ASMPlanData[i]=val[i];}
// 	CASMRouteData*	GetASMPlanData(){return m_ASMPlanData;}
	void	SetASMPlanDataCount(int val){m_ASMPlanDataCount=val;}
	int	GetASMPlanDataCount(){return m_ASMPlanDataCount;}
	void	SetGroupIntptStrategy(int val){m_GroupIntptStrategy=val;}
	int	GetGroupIntptStrategy(){return m_GroupIntptStrategy;}
	void	SetisAutoGroupAntiAir(int val){m_isAutoGroupAntiAir=val;}
	int	GetisAutoGroupAntiAir(){return m_isAutoGroupAntiAir;}
	void	SetisEWPlaneSupport(int val){m_isEWPlaneSupport=val;}
	int	GetisEWPlaneSupport(){return m_isEWPlaneSupport;}

	void	SetASMCoopAttackMode(int val){m_ASMCoopAttackMode=val;}
	int	GetASMCoopAttackMode(){return m_ASMCoopAttackMode;}

	void	SetRoutePlanTime(long val){m_RoutePlanTime=val;}
	long	GetRoutePlanTime(){return m_RoutePlanTime;}
	void	Set1stLaunchTime(long val){m_1stLaunchTime=val;}
	long	Get1stLaunchTime(){return m_1stLaunchTime;}
	void	SetRoutePlanMode(int val){m_RoutePlanMode=val;}
	int	GetRoutePlanMode(){return m_RoutePlanMode;}
	void	SetBatchCount(int val){m_BatchCount=val;}
	int	GetBatchCount(){return m_BatchCount;}
	void	SetBatchInterval(double val){m_BatchInterval=val;}
	double	GetBatchInterval(){return m_BatchInterval;}

	//{{HDOSE_MEMBER_FUNCTION(CCmdEntityStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CCmdEntityStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCmdEntityStateRep)
	int	m_IsAutoPlan/*是否自动进行反舰导弹航路规化（默认为-1（无意义）,0-人工规划，1-自动规划、2-按照给定的时刻规划航路）*/;
	bool m_AutoTime;//自动时序/人工时序（0-人工时序--不需要进行任何计算了，按时序发射导弹即可，1-自动进行排序，并确定发射时刻）
	//CASMRouteData	m_ASMPlanData[10]/*反舰导弹规划信息(最多30个)*/;
	int	m_ASMPlanDataCount/*反舰导弹规划信息个数*/;

	int	m_GroupIntptStrategy/*反导方编队的防空拦截策略*/;
	int	m_isAutoGroupAntiAir/*反导方是否编队自动防空（默认为-1,0否，1是）*/;
	int m_isEWPlaneSupport/*反导方是否有预警机支持(-1无效，0否，1是)*/; 

	// 2015/10/02新增,临时
	//char m_ScnName[128]; /*记录该想定的名称-为根据想定名称进行自动记录存储想定名称*/
	int	m_isAccompanySuppress;/*红方是否有伴随压制，0否，1是*/

	// 2016/02/18新增,区分两种不同的突防方式：
	// 同时到达--所有导弹同时到达目标
	// 同时突防--所有导弹同时进入各自的被拦截圈，如根据各自的弹道高度，分别同时进入各自的被拦截圈
	int	m_ASMCoopAttackMode/*反舰导弹协同攻击方式(1-同时到达,2-同时突防)*/;
	int m_AttackSingleOrGroup;/*攻击单舰还是编队,1-单舰,2-编队*/

	// 2017/02/08,新增开始进行航路规划的时刻(s)和第一枚反舰导弹发射时刻(s)
	double	m_RoutePlanTime;	//开始进行航路规划的时刻(s)
	double	m_1stLaunchTime;	//第一枚反舰导弹发射时刻(s)
	// 20171030
	int	m_GroupAAMLaunchMode; // 编队防空导弹发射模式，默认0-连续发射、1-连续发射模式、2-发射-观察-发射模式
	// 20180301
	int	m_RoutePlanMode/*航路规划目标点选择方式，-1（默认值，说明此参数无效，如果此值>=0表示要使用全局的规划方式规划所有航路，否则按每条航路自己的方式规划航路），0-当前点规划，1-前置点规划，2-，3-*/;
	int	m_BatchCount/*批次数量*/;
	double	m_BatchInterval/*反舰导弹攻击批次间隔时间，s*/;

	//}}HDOSE_ATTRIBUTE


	CASMRouteData m_routPlanData[200];	// 导弹航路数据数组
	int m_routPlanDataCount;	// 导弹航路数量
};

#endif
