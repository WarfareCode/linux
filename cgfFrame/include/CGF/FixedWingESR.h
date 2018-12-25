//FixedWingESR.h: interface for the CFixedWingESR module.
//!!HDOSE_CLASS(CFixedWingESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FixedWingESR_H)
#define AFX_FixedWingESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CFixedWingESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CFixedWingESR /*�̶���ɻ�ʵ��״̬��*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CFixedWingESR();
	virtual ~CFixedWingESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetLength(){return m_Length;}
	double	GetWingSpan(){return m_WingSpan;}
	double	GetHeight(){return m_Height;}
	double	GetMinTakOffVel(){return m_MinTakOffVel;}
	double	GetMinVel(){return m_MinVel;}
	double	GetMaxVel(){return m_MaxVel;}
	double	GetCruiseVel(){return m_CruiseVel;}
	double	GetCruiseHeight(){return m_CruiseHeight;}
	double	GetMaxLandOnVel(){return m_MaxLandOnVel;}
	double	GetMaxAcc(){return m_MaxAcc;}
	double	GetMaxDec(){return m_MaxDec;}
	double	GetMinPitchRadius(){return m_MinPitchRadius;}
	double	GetMinTurnRadius(){return m_MinTurnRadius;}
	double	GetMaxYawRate(){return m_MaxYawRate;}
	double	GetMaxPitchRate(){return m_MaxPitchRate;}
	double	GetMaxRollRate(){return m_MaxRollRate;}
	double	GetMaxYawAcc(){return m_MaxYawAcc;}
	double	GetMaxPitchAcc(){return m_MaxPitchAcc;}
	double	GetMaxRollAcc(){return m_MaxRollAcc;}
	double	GetMaxPitchAngle(){return m_MaxPitchAngle;}
	double	GetMaxRollAngle(){return m_MaxRollAngle;}
	double	GetMinG(){return m_MinG;}
	double	GetMaxG(){return m_MaxG;}
	double	GetMaxClimbVel(){return m_MaxClimbVel;}
	double	GetMaxDescendVel(){return m_MaxDescendVel;}
	double	GetMaxAttackDist(){return m_MaxAttackDist;}
	double	GetValidCeiling(){return m_ValidCeiling;}
	double	GetTakeoffDistance(){return m_TakeoffDistance;}
	double	GetLandingDistance(){return m_LandingDistance;}
	double	GetEngineThrust(){return m_EngineThrust;}
	double	GetMaxFuelOilVolume(){return m_MaxFuelOilVolume;}
	double	GetAverageOilConsumptionKgPH(){return m_AverageOilConsumptionKgPH;}
	double	GetDurationTime(){return m_DurationTime;}

	//{{HDOSE_MEMBER_FUNCTION(CFixedWingESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CFixedWingESR)
	double	m_Length/*����(m)*/;
	double	m_WingSpan/*��չ(m)*/;
	double	m_Height/*����(m)*/;
	double	m_MinTakOffVel/*��С����ٶ�(m/s)*/;
	double	m_MinVel/*��С�ٶ�(m/s)*/;
	double	m_MaxVel/*����ٶ�(m/s)*/;
	double	m_CruiseVel/*Ѳ���ٶ�(m/s)*/;
	double	m_CruiseHeight/*Ѳ���߶�(m)*/;
	double	m_MaxLandOnVel/*������ٶ�*/;
	double	m_MaxAcc/*�����ٶ�*/;
	double	m_MaxDec/*�����ٶ�*/;
	double	m_MinPitchRadius/*��С�����뾶(m)*/;
	double	m_MinTurnRadius/*��Сת��뾶��m��*/;
	double	m_MaxYawRate/*���ƫ�������ʣ���/s��*/;
	double	m_MaxPitchRate/*��������ٶȣ���/s��*/;
	double	m_MaxRollRate/*����ת�����ʣ���/s��*/;
	double	m_MaxYawAcc/*���ƫ���Ǽ��ٶ�(��/s2)*/;
	double	m_MaxPitchAcc/*������Ǽ��ٶ�(��/s2)*/;
	double	m_MaxRollAcc/*����ת�Ǽ��ٶ�(��/s2)*/;
	double	m_MaxPitchAngle/*������Ƕ�(��)*/;
	double	m_MaxRollAngle/*����ת�Ƕ�*/;
	double	m_MinG/*��С���أ���ֵ��g�ı�����*/;
	double	m_MaxG/*�����أ���ֵ��g�ı�����*/;
	double	m_MaxClimbVel/*��������ʣ�m/s��*/;
	double	m_MaxDescendVel/*����½��ʣ�m/s��*/;
	double	m_MaxAttackDist/*��ս�뾶�����*/;
	double	m_ValidCeiling/*ʵ������(m)*/;
	double	m_TakeoffDistance/*��ɾ���(m)*/;
	double	m_LandingDistance/*��½����*/;
	double	m_EngineThrust/*������������KN��*/;
	double	m_MaxFuelOilVolume/*���ȼ������Kg��*/;
	double	m_AverageOilConsumptionKgPH/*ƽ��Сʱ������(Kg/h)*/;
	double	m_DurationTime/*����ʱ�䣨h��*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CFixedWingESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
