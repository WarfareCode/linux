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

class DATASTRUCTCOMPONENTDLL_API CMissileStateRep /*����״̬��-TF*/ : public CMunitionStateRep 
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
	bool	m_bSeekerPowerOn/*����ͷ�Ƿ񿪻�*/;
	long	m_SeekerWorkInstruction/*����ͷ����ָ���׽ָ��0����սָ��1����սָ��2������ָ��3���Ӹ�ָ��4��3��ָ��5��*/;
	long	m_SeekerSearchStratege/*����ͷ�����Ѳ�����0��1��2....��*/;
	double	m_SeekerElecAxisAzimuth/*����ͷ���᷽λ*/;
	double	m_BeamWidth/*����ͷ�������*/;
	double	m_SeekerDetectDistance/*����ͷ��ǰ̽�����*/;
	double	m_SeekerDetectAngle/*����ͷ��ǰ̽��Ƕȷ�Χ���״��������ת���Ƕȣ��ӵ���ͷ��̬�����л�ȡ��*/;
	CSeekerDisplayData	m_SeekerDetectInfo[10]/*����ͷ̽�⵽��������Ϣ���͸�ǰ̨��ʾ�ģ�100��Ԫ�ص����飬��������ͷ̽�⵽��������Ϣ����յ�������ͧ�����������ţ�*/;
	long	m_SeekerDetectInfoCount/*����ͷ̽�⵽��������Ϣ���������100��*/;
	long	m_InitTargetNo/*�趨������Ŀ���ţ�����ģ�*/;
	char		m_InitTargetName[MAX_CHARLEN]/*�趨������Ŀ������*/;
	long	m_MissileTargetPlatform/*��������ƽ̨���ʣ�0������1�Կգ�*/;
	long	m_MissileType/*���嵼�����ͣ��Ƿ��������Ӧ���������ͣ��ǶԿյ����Ӧ�Կյ����ͣ�*/;
	double	m_HitProbability/*���и���*/;
//	double	m_Dist2Target/*��������Ŀ��ľ���*/;
	// 20170318,Ϊ����ʾ��Ҫ���Ӵ˲���
	long	m_HittedType/*�����ٷ�ʽ����ʾ��Ҫ��0�ޡ�1���յ����ء�2�����������š�3���ⵯ���š�4����ˮ����Դ�ն�����ssq95��5���������Դ�ն�����nulka��6�����ڣ�*/;
	//}}HDOSE_ATTRIBUTE

	//{{HDOSE_PARAMETER(CMissileStateRep)
	double	m_Length/*����(m)*/;
	double	m_Diameter/*ֱ��(m)*/;
	double	m_WingSpan/*��չ(m)*/;
	double	m_MaxAttackDist/*������(����)*/;
	double	m_MaxAttackHeight/*���(m)*/;
	double	m_MinVel/*��С�ٶ�(Ma��*/;
	double	m_MaxVel/*����ٶȣ�Ma��*/;
	double	m_MaxAcc/*�����ٶ�*/;
	double	m_CruiseHeight/*Ѳ���߶ȣ�m��*/;
	double	m_CruiseVel/*Ѳ���ٶȣ�Ma��*/;
	double	m_MinTurnRadius/*��Сת��뾶�����*/;
	double	m_MaxYawRate/*���ƫ�����ʣ���/s��*/;
	double	m_MaxPitchRate/*��������ʣ���/s��*/;
	double	m_MaxRollRate/*����ת���ʣ���/s��*/;
	double	m_MaxPitchAngle/*������Ƕȣ��ȣ�*/;
	double	m_MaxRollAngle/*����ת�Ƕȣ��ȣ�*/;
	double	m_MaxG/*�����أ���ֵ��g�ı�����*/;
	double	m_MinG/*��С���أ���ֵ��g�ı�����*/;
	double	m_MaxClimbVel/*���������*/;
	double	m_HitAccuracy/*���о��ȣ�m��*/;
	double	m_MaxFlyTime/*������ʱ��(min)*/;
	double	m_KillRadius/*ɱ�˰뾶,m*/;
	long	m_WarheadType/*��ͷ����,1-���桢2-��*/;
	//}}HDOSE_PARAMETER
};

#endif
