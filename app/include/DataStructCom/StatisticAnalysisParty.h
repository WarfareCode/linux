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
Descript:	ͨ���Կ����������ͳ�Ʒ���
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CStatisticAnalysisParty /*ͳ�Ʒ�����*/ : public CLink 
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
	long	m_ForceSide/*��������ʶ*/;
	long	m_Valid/*�Ƿ���Ч*/;
	// �췽���
	long	m_ASMTotalNum/*������������*/;
	long	m_PenetrASMNum/*ͻ����������*/;
	long	m_HitNum/*���е�������*/;
	long	m_IntcptedByAAMASMNum/*�����صĵ�������*/;
	long	m_JammedASMNum/*�����ŵĵ�������*/;
	double	m_AvePenetrPb/*ƽ��ͻ������*/;
	long m_totalAAMNum/*����ķ���������*/;
	double m_IntcptRatio/*���سɹ���*/;
	long	m_DamedShipNum/*��ͧ��������*/;

	//double	m_Ave1HitPb/*ƽ���������и���*/;
	//long	m_DamTargetNum/*����Ŀ������*/;
	//double	m_MinASMDist2Tar/*�������ͻ������*/;
	//long	m_IntcptedByAAMASMNum/*���������յ�����������*/;
	//long	m_IntcptedByGunASMNum/*������������������*/;
	// 	long	m_ActiveJamedASMNum/*��������Դ��������*/;
	// 	long	m_ChaffJammedASMNum/*����������������*/;
	//long	m_DamedPlaneNum/*�ɻ���������*/;
	//long	m_DamedSubNum/*Ǳͧ��������*/;
	//long	m_IntcptTarNum/*����Ŀ������*/;
	//double	m_IntcptTarRatio/*����Ŀ�����*/;
	//long	m_JamTarNum/*����Ŀ������*/;
	//double	m_JamTarRatio/*����Ŀ�����*/;
	//double	m_MaxFdTarDist/*Ŀ����Զ���־���*/;
	//long	m_TarNum/*Ŀ�귢������*/;
	//double	m_TarPd/*Ŀ�귢�ָ���*/;
	//double	m_TarClsfiedPb/*Ŀ��ʶ�����*/;
	//double	m_TarTrackedPb/*Ŀ����ٸ���*/;
	//double	m_TarEWTime/*Ŀ��Ԥ��ʱ��*/;
	//double	m_C2Time/*������Ӧʱ��*/;
	//long	m_SM2Num/*��׼2��������*/;
	//long	m_IntcptedNumBySM2/*��׼2����Ŀ������*/;
	//double	m_IntcptedPbBySM2/*��׼2����Ŀ�����*/;
	//double	m_IntcptedRatioBySM2/*��׼2����Ŀ�����*/;
	//long	m_ESSMNum/*����ȸ��������*/;
	//long	m_IntcptedNumByESSM/*����ȸ����Ŀ������*/;
	//double	m_IntcptedPbByESSM/*����ȸ����Ŀ�����*/;
	//double	m_IntcptedRatioByESSM/*����ȸ����Ŀ�����*/;
	//double	m_MaxIntcptDist/*��Զ���ؾ���*/;
	//double	m_MinIntcptDist/*������ؾ���*/;
	//long	m_ChaffNum/*��������������*/;
	//long	m_TarNumJammedByChaff/*����������Ŀ������*/;
	//double	m_TarRatioJammedByChaff/*����������Ŀ�����*/;
	//long	m_TarNumJammedByActive/*��Դ����Ŀ������*/;
	//double	m_TarRatioJammedByActive/*��Դ����Ŀ�����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
