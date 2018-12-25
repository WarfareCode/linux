//StatisticAnalysisParty.h: interface for the CStatisticAnalysisParty module.
//!!HDOSE_CLASS(CStatisticAnalysisParty,CLink)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_StatisticAnalysisParty_H)
#define AFX_StatisticAnalysisParty_H


//{{HDOSE_CLS_DES(CStatisticAnalysisParty)
/*
Author:		20161003
Version:	1.0
Descript:	通过对抗结果，进行统计分析
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CStatisticAnalysisParty /*统计分析者*/ : public CLink 
{
	DECLARE_CREATE;
public:
	CStatisticAnalysisParty();
	virtual ~CStatisticAnalysisParty();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetForceSide(long val){m_ForceSide=val;}
	long	GetForceSide(){return m_ForceSide;}
	void	SetValid(long val){m_Valid=val;}
	long	GetValid(){return m_Valid;}
	void	SetASMTotalNum(long val){m_ASMTotalNum=val;}
	long	GetASMTotalNum(){return m_ASMTotalNum;}
	void	SetPenetrASMNum(long val){m_PenetrASMNum=val;}
	long	GetPenetrASMNum(){return m_PenetrASMNum;}
	void	SetHitNum(long val){m_HitNum=val;}
	long	GetHitNum(){return m_HitNum;}
	void	SetAvePenetrPb(double val){m_AvePenetrPb=val;}
	double	GetAvePenetrPb(){return m_AvePenetrPb;}
	//void	SetAve1HitPb(double val){m_Ave1HitPb=val;}
	//double	GetAve1HitPb(){return m_Ave1HitPb;}
	//void	SetDamTargetNum(long val){m_DamTargetNum=val;}
	//long	GetDamTargetNum(){return m_DamTargetNum;}
	//void	SetActiveJamedASMNum(long val){m_ActiveJamedASMNum=val;}
	//long	GetActiveJamedASMNum(){return m_ActiveJamedASMNum;}
	//void	SetChaffJammedASMNum(long val){m_ChaffJammedASMNum=val;}
	//long	GetChaffJammedASMNum(){return m_ChaffJammedASMNum;}
	//void	SetIntcptedByAAMASMNum(long val){m_IntcptedByAAMASMNum=val;}
	//long	GetIntcptedByAAMASMNum(){return m_IntcptedByAAMASMNum;}
	//void	SetIntcptedByGunASMNum(long val){m_IntcptedByGunASMNum=val;}
	//long	GetIntcptedByGunASMNum(){return m_IntcptedByGunASMNum;}
	//void	SetMinASMDist2Tar(double val){m_MinASMDist2Tar=val;}
	//double	GetMinASMDist2Tar(){return m_MinASMDist2Tar;}
	void	SetDamedShipNum(long val){m_DamedShipNum=val;}
	long	GetDamedShipNum(){return m_DamedShipNum;}
	//void	SetDamedPlaneNum(long val){m_DamedPlaneNum=val;}
	//long	GetDamedPlaneNum(){return m_DamedPlaneNum;}
	//void	SetDamedSubNum(long val){m_DamedSubNum=val;}
	//long	GetDamedSubNum(){return m_DamedSubNum;}
	//void	SetIntcptTarNum(long val){m_IntcptTarNum=val;}
	//long	GetIntcptTarNum(){return m_IntcptTarNum;}
	//void	SetIntcptTarRatio(double val){m_IntcptTarRatio=val;}
	//double	GetIntcptTarRatio(){return m_IntcptTarRatio;}
	//void	SetJamTarNum(long val){m_JamTarNum=val;}
	//long	GetJamTarNum(){return m_JamTarNum;}
	//void	SetJamTarRatio(double val){m_JamTarRatio=val;}
	//double	GetJamTarRatio(){return m_JamTarRatio;}
	//void	SetMaxFdTarDist(double val){m_MaxFdTarDist=val;}
	//double	GetMaxFdTarDist(){return m_MaxFdTarDist;}
	//void	SetTarNum(long val){m_TarNum=val;}
	//long	GetTarNum(){return m_TarNum;}
	//void	SetTarPd(double val){m_TarPd=val;}
	//double	GetTarPd(){return m_TarPd;}
	//void	SetTarClsfiedPb(double val){m_TarClsfiedPb=val;}
	//double	GetTarClsfiedPb(){return m_TarClsfiedPb;}
	//void	SetTarTrackedPb(double val){m_TarTrackedPb=val;}
	//double	GetTarTrackedPb(){return m_TarTrackedPb;}
	//void	SetTarEWTime(double val){m_TarEWTime=val;}
	//double	GetTarEWTime(){return m_TarEWTime;}
	//void	SetC2Time(double val){m_C2Time=val;}
	//double	GetC2Time(){return m_C2Time;}
	//void	SetSM2Num(long val){m_SM2Num=val;}
	//long	GetSM2Num(){return m_SM2Num;}
	//void	SetIntcptedNumBySM2(long val){m_IntcptedNumBySM2=val;}
	//long	GetIntcptedNumBySM2(){return m_IntcptedNumBySM2;}
	//void	SetIntcptedPbBySM2(double val){m_IntcptedPbBySM2=val;}
	//double	GetIntcptedPbBySM2(){return m_IntcptedPbBySM2;}
	//void	SetIntcptedRatioBySM2(double val){m_IntcptedRatioBySM2=val;}
	//double	GetIntcptedRatioBySM2(){return m_IntcptedRatioBySM2;}
	//void	SetESSMNum(long val){m_ESSMNum=val;}
	//long	GetESSMNum(){return m_ESSMNum;}
	//void	SetIntcptedNumByESSM(long val){m_IntcptedNumByESSM=val;}
	//long	GetIntcptedNumByESSM(){return m_IntcptedNumByESSM;}
	//void	SetIntcptedPbByESSM(double val){m_IntcptedPbByESSM=val;}
	//double	GetIntcptedPbByESSM(){return m_IntcptedPbByESSM;}
	//void	SetIntcptedRatioByESSM(double val){m_IntcptedRatioByESSM=val;}
	//double	GetIntcptedRatioByESSM(){return m_IntcptedRatioByESSM;}
	//void	SetMaxIntcptDist(double val){m_MaxIntcptDist=val;}
	//double	GetMaxIntcptDist(){return m_MaxIntcptDist;}
	//void	SetMinIntcptDist(double val){m_MinIntcptDist=val;}
	//double	GetMinIntcptDist(){return m_MinIntcptDist;}
	//void	SetChaffNum(long val){m_ChaffNum=val;}
	//long	GetChaffNum(){return m_ChaffNum;}
	//void	SetTarNumJammedByChaff(long val){m_TarNumJammedByChaff=val;}
	//long	GetTarNumJammedByChaff(){return m_TarNumJammedByChaff;}
	//void	SetTarRatioJammedByChaff(double val){m_TarRatioJammedByChaff=val;}
	//double	GetTarRatioJammedByChaff(){return m_TarRatioJammedByChaff;}
	//void	SetTarNumJammedByActive(long val){m_TarNumJammedByActive=val;}
	//long	GetTarNumJammedByActive(){return m_TarNumJammedByActive;}
	//void	SetTarRatioJammedByActive(double val){m_TarRatioJammedByActive=val;}
	//double	GetTarRatioJammedByActive(){return m_TarRatioJammedByActive;}

	//{{HDOSE_MEMBER_FUNCTION(CStatisticAnalysisParty)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CStatisticAnalysisParty)
	long	m_ForceSide/*红蓝方标识*/;
	long	m_Valid/*是否有效*/;
	// 红方情况
	long	m_ASMTotalNum/*反舰导弹总数*/;
	long	m_PenetrASMNum/*突防导弹数量*/;
	long	m_HitNum/*命中导弹数量*/;
	long	m_IntcptedByAAMASMNum/*被拦截的导弹数量*/;
	long	m_JammedASMNum/*被干扰的导弹数量*/;
	double	m_AvePenetrPb/*平均突防概率*/;
	long m_totalAAMNum/*发射的防空总数量*/;
	double m_IntcptRatio/*拦截成功率*/;
	long	m_DamedShipNum/*舰艇毁伤数量*/;

	//double	m_Ave1HitPb/*平均单发命中概率*/;
	//long	m_DamTargetNum/*毁伤目标数量*/;
	//double	m_MinASMDist2Tar/*导弹最近突防距离*/;
	//long	m_IntcptedByAAMASMNum/*导弹被防空导弹拦截数量*/;
	//long	m_IntcptedByGunASMNum/*导弹被舰炮拦截数量*/;
	// 	long	m_ActiveJamedASMNum/*导弹被有源干扰数量*/;
	// 	long	m_ChaffJammedASMNum/*导弹被箔干扰数量*/;
	//long	m_DamedPlaneNum/*飞机毁伤数量*/;
	//long	m_DamedSubNum/*潜艇毁伤数量*/;
	//long	m_IntcptTarNum/*拦截目标数量*/;
	//double	m_IntcptTarRatio/*拦截目标比例*/;
	//long	m_JamTarNum/*干扰目标数量*/;
	//double	m_JamTarRatio/*干扰目标比例*/;
	//double	m_MaxFdTarDist/*目标最远发现距离*/;
	//long	m_TarNum/*目标发现数量*/;
	//double	m_TarPd/*目标发现概率*/;
	//double	m_TarClsfiedPb/*目标识别概率*/;
	//double	m_TarTrackedPb/*目标跟踪概率*/;
	//double	m_TarEWTime/*目标预警时间*/;
	//double	m_C2Time/*决策响应时间*/;
	//long	m_SM2Num/*标准2发射数量*/;
	//long	m_IntcptedNumBySM2/*标准2拦截目标数量*/;
	//double	m_IntcptedPbBySM2/*标准2拦截目标概率*/;
	//double	m_IntcptedRatioBySM2/*标准2拦截目标比例*/;
	//long	m_ESSMNum/*海麻雀发射数量*/;
	//long	m_IntcptedNumByESSM/*海麻雀拦截目标数量*/;
	//double	m_IntcptedPbByESSM/*海麻雀拦截目标概率*/;
	//double	m_IntcptedRatioByESSM/*海麻雀拦截目标比例*/;
	//double	m_MaxIntcptDist/*最远拦截距离*/;
	//double	m_MinIntcptDist/*最近拦截距离*/;
	//long	m_ChaffNum/*箔条弹发射数量*/;
	//long	m_TarNumJammedByChaff/*箔条弹干扰目标数量*/;
	//double	m_TarRatioJammedByChaff/*箔条弹干扰目标比例*/;
	//long	m_TarNumJammedByActive/*有源干扰目标数量*/;
	//double	m_TarRatioJammedByActive/*有源干扰目标比例*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
