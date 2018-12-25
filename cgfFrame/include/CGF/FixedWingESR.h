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

class HYCGF_API CFixedWingESR /*固定翼飞机实体状态池*/ : public CStateRepository 
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
	double	m_Length/*机长(m)*/;
	double	m_WingSpan/*翼展(m)*/;
	double	m_Height/*机高(m)*/;
	double	m_MinTakOffVel/*最小起飞速度(m/s)*/;
	double	m_MinVel/*最小速度(m/s)*/;
	double	m_MaxVel/*最大速度(m/s)*/;
	double	m_CruiseVel/*巡航速度(m/s)*/;
	double	m_CruiseHeight/*巡航高度(m)*/;
	double	m_MaxLandOnVel/*最大降落速度*/;
	double	m_MaxAcc/*最大加速度*/;
	double	m_MaxDec/*最大减速度*/;
	double	m_MinPitchRadius/*最小俯仰半径(m)*/;
	double	m_MinTurnRadius/*最小转弯半径（m）*/;
	double	m_MaxYawRate/*最大偏航角速率（度/s）*/;
	double	m_MaxPitchRate/*最大俯仰角速度（度/s）*/;
	double	m_MaxRollRate/*最大滚转角速率（度/s）*/;
	double	m_MaxYawAcc/*最大偏航角加速度(度/s2)*/;
	double	m_MaxPitchAcc/*最大俯仰角加速度(度/s2)*/;
	double	m_MaxRollAcc/*最大滚转角加速度(度/s2)*/;
	double	m_MaxPitchAngle/*最大俯仰角度(度)*/;
	double	m_MaxRollAngle/*最大滚转角度*/;
	double	m_MinG/*最小过载（负值，g的倍数）*/;
	double	m_MaxG/*最大过载（正值，g的倍数）*/;
	double	m_MaxClimbVel/*最大爬升率（m/s）*/;
	double	m_MaxDescendVel/*最大下降率（m/s）*/;
	double	m_MaxAttackDist/*作战半径（公里）*/;
	double	m_ValidCeiling/*实用升限(m)*/;
	double	m_TakeoffDistance/*起飞距离(m)*/;
	double	m_LandingDistance/*着陆距离*/;
	double	m_EngineThrust/*发动机推力（KN）*/;
	double	m_MaxFuelOilVolume/*最大燃油量（Kg）*/;
	double	m_AverageOilConsumptionKgPH/*平均小时耗油量(Kg/h)*/;
	double	m_DurationTime/*续航时间（h）*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CFixedWingESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
