//Environment.h: interface for the CEnvironment module.
//!!HDOSE_CLASS(CEnvironment,CLink)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Environment_H)
#define AFX_Environment_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CEnvironment)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CEnvironment /*��������*/ : public CLink 
{
	DECLARE_CREATE;
public:
	CEnvironment();
	virtual ~CEnvironment();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual void OnSetParameter(char *name,char *value);
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetEnvObjName(char* val){SetValueString("EnvObjName",val);}
	char*	GetEnvObjName(){return GetValueString("EnvObjName");}

	// �ֶ��޸�
// 	void	SetEnvArea(GeoPt4 val){m_EnvArea=val;}
// 	GeoPt4	GetEnvArea(){return m_EnvArea;}

	void	SetEnvArea(char* ptStr)
	{
		this->SetValueString("EnvArea",ptStr);
	}
	void	SetEnvArea(GeoPtList& ptList)
	{
		String ptStr = GeoPtList2GeoPtStr(ptList);
		this->SetValueString("EnvArea",ptStr.GetBuffer(ptStr.GetLength()));
	}
	void	GetEnvArea(GeoPtList& ptList)
	{
		GeoPtStr2GeoPtList(ptList, m_EnvArea);
	}
	char* GetEnvArea(){return GetValueString("EnvArea");}

	void	SetAveragePressure(double val){m_AveragePressure=val;}
	double	GetAveragePressure(){return m_AveragePressure;}
	void	SetAverageTemperature(double val){m_AverageTemperature=val;}
	double	GetAverageTemperature(){return m_AverageTemperature;}
	void	SetAverageHumidity(double val){m_AverageHumidity=val;}
	double	GetAverageHumidity(){return m_AverageHumidity;}

	void	SetRainModelType(long val){m_RainModelType=val;}
	long	GetRainModelType(){return m_RainModelType;}
	void	SetRainDensity(double val){m_RainDensity=val;}
	double	GetRainDensity(){return m_RainDensity;}
	void	SetRainSurfTemperature(double val){m_RainSurfTemperature=val;}
	double	GetRainSurfTemperature(){return m_RainSurfTemperature;}
	void	SetCloudCeliling(double val){m_CloudCeliling=val;}
	double	GetCloudCeliling(){return m_CloudCeliling;}
	void	SetCloudLayerThickness(double val){m_CloudLayerThickness=val;}
	double	GetCloudLayerThickness(){return m_CloudLayerThickness;}
	void	SetCloudTemperature(double val){m_CloudTemperature=val;}
	double	GetCloudTemperature(){return m_CloudTemperature;}
	void	SetCloudLiquidWaterDensity(double val){m_CloudLiquidWaterDensity=val;}
	double	GetCloudLiquidWaterDensity(){return m_CloudLiquidWaterDensity;}
	void	SetAverageVisibility(double val){m_AverageVisibility=val;}
	double	GetAverageVisibility(){return m_AverageVisibility;}

	void	SetWindCou(double val){m_WindCou=val;}
	double	GetWindCou(){return m_WindCou;}
	void	SetWindVel(double val){m_WindVel=val;}
	double	GetWindVel(){return m_WindVel;}

	void	SetAtmosAbsorptionModelType(long val){m_AtmosAbsorptionModelType=val;}
	long	GetAtmosAbsorptionModelType(){return m_AtmosAbsorptionModelType;}
	void	SetAtmosWaterVaporConc(double val){m_AtmosWaterVaporConc=val;}
	double	GetAtmosWaterVaporConc(){return m_AtmosWaterVaporConc;}
	void	SetAtmosSurfTemperature(double val){m_AtmosSurfTemperature=val;}
	double	GetAtmosSurfTemperature(){return m_AtmosSurfTemperature;}

	void	SetSeaStateLevel(long val){m_SeaStateLevel=val;}
	long	GetSeaStateLevel(){return m_SeaStateLevel;}
	void	SetWindWaveDirection(double val){m_WindWaveDirection=val;}
	double	GetWindWaveDirection(){return m_WindWaveDirection;}
	void	SetWindWaveVel(double val){m_WindWaveVel=val;}
	double	GetWindWaveVel(){return m_WindWaveVel;}
	void	SetWindWaveLength(double val){m_WindWaveLength=val;}
	double	GetWindWaveLength(){return m_WindWaveLength;}
	void	SetTideHight(double val){m_TideHight=val;}
	double	GetTideHight(){return m_TideHight;}
	void	SetSurfDirection(double val){m_SurfDirection=val;}
	double	GetSurfDirection(){return m_SurfDirection;}
	void	SetSurfVel(double val){m_SurfVel=val;}
	double	GetSurfVel(){return m_SurfVel;}
	void	SetSurgeLevel(long val){m_SurgeLevel=val;}
	long	GetSurgeLevel(){return m_SurgeLevel;}
	void	SetSurgeDirection(double val){m_SurgeDirection=val;}
	double	GetSurgeDirection(){return m_SurgeDirection;}
	void	SetSurgeVel(double val){m_SurgeVel=val;}
	double	GetSurgeVel(){return m_SurgeVel;}
	void	SetSurgeWaveLength(double val){m_SurgeWaveLength=val;}
	double	GetSurgeWaveLength(){return m_SurgeWaveLength;}

	void	SetAverageWaterDepth(double val){m_AverageWaterDepth=val;}
	double	GetAverageWaterDepth(){return m_AverageWaterDepth;}
	void	SetAverageWaterSalinity(double val){m_AverageWaterSalinity=val;}
	double	GetAverageWaterSalinity(){return m_AverageWaterSalinity;}
	void	SetWaterSurfTemperature(double val){m_WaterSurfTemperature=val;}
	double	GetWaterSurfTemperature(){return m_WaterSurfTemperature;}
	void	SetAverageWaterDensity(double val){m_AverageWaterDensity=val;}
	double	GetAverageWaterDensity(){return m_AverageWaterDensity;}
	void	SetSeaFloorSediments(long val){m_SeaFloorSediments=val;}
	long	GetSeaFloorSediments(){return m_SeaFloorSediments;}
	void	Setextra1(long val){m_extra1=val;}
	long	Getextra1(){return m_extra1;}
	void	Setextra2(long val){m_extra2=val;}
	long	Getextra2(){return m_extra2;}
	void	Setextra3(long val){m_extra3=val;}
	long	Getextra3(){return m_extra3;}
	void	Setextra4(double val){m_extra4=val;}
	double	Getextra4(){return m_extra4;}
	void	Setextra5(double val){m_extra5=val;}
	double	Getextra5(){return m_extra5;}
	void	Setextra6(double val){m_extra6=val;}
	double	Getextra6(){return m_extra6;}
	void	Setextra7(double val){m_extra7=val;}
	double	Getextra7(){return m_extra7;}
	void	Setextra8(double val){m_extra8=val;}
	double	Getextra8(){return m_extra8;}
	void	Setextra9(double val){m_extra9=val;}
	double	Getextra9(){return m_extra9;}
	void	Setextra10(double val){m_extra10=val;}
	double	Getextra10(){return m_extra10;}

	//{{HDOSE_MEMBER_FUNCTION(CEnvironment)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CEnvironment)

	// ��������
	char*	m_EnvObjName/*������������*/;
	char*	m_EnvArea/*��������,4λ�õ�����*/;
	// ��ѹ ���� ʪ��
	double	m_AveragePressure/*ƽ����ѹ,��*/;
	double	m_AverageTemperature/*ƽ������,���϶�*/;
	double	m_AverageHumidity/*ƽ������ʪ��,�ٷֱ�*/;
	// ����
	long	m_RainModelType/*����ģ��,1 ITU-R P618-9, 2 Crane 1985,3 xx*/;
	double	m_RainDensity/*��ˮǿ��,mm/h*/;
	double	m_RainSurfTemperature/*������¶�,���϶�*/;
	// ����
	double	m_CloudCeliling/*�ƶ���,km*/;
	double	m_CloudLayerThickness/*�Ʋ���,km*/;
	double	m_CloudTemperature/*�Ʋ��¶�,���϶�*/;
	double	m_CloudLiquidWaterDensity/*��Һ̬ˮ�ܶ�,g/m^3*/;
	double	m_AverageVisibility/*ƽ���ܼ���,km*/;
	// ��
	double	m_WindCou/*����,(0-360��)*/;
	double	m_WindVel/*����,(m/s)*/;
	// ��������
	long	m_AtmosAbsorptionModelType/*��������ģ��,��ѡ��ģ��*/;
	double	m_AtmosWaterVaporConc/*����ˮ��������,g/m^3*/;
	double	m_AtmosSurfTemperature/*���������¶�,���϶�*/;
	// ����
	long	m_SeaStateLevel/*�����ȼ�*/;
	double	m_WindWaveDirection/*���˷���(0-360��)*/;
	double m_WindWaveVel/*�����ٶ�,m/s*/;
	double m_WindWaveLength/*���˲�����m*/;
	double	m_TideHight/*����,m*/;
	double	m_SurfDirection/*����,(0-360��)*/;
	double	m_SurfVel/*����,m/s*/;
	long	m_SurgeLevel/*ӿ�˵ȼ�*/;
	double	m_SurgeDirection/*ӿ�˷���,(0-360��)*/;
	double	m_SurgeVel/*ӿ���ٶ�,m/s*/;
	double m_SurgeWaveLength/*ӿ�˲���,m*/;
	// ˮ��
	double	m_AverageWaterDepth/*ƽ��ˮ��*/;
	double	m_AverageWaterSalinity/*ƽ����ˮ�ζ�*/;
	double	m_WaterSurfTemperature/*��ˮ�����¶�*/;
	double	m_AverageWaterDensity/*ƽ����ˮ�ܶ�*/;
	long	m_SeaFloorSediments/*���׵�������*/;
	// ����
	long	m_extra1/*���Ӳ���1*/;
	long	m_extra2/*���Ӳ���2*/;
	long	m_extra3/*���Ӳ���3*/;
	double	m_extra4/*���Ӳ���4*/;
	double	m_extra5/*���Ӳ���5*/;
	double	m_extra6/*���Ӳ���6*/;
	double	m_extra7/*���Ӳ���7*/;
	double	m_extra8/*���Ӳ���8*/;
	double	m_extra9/*���Ӳ���9*/;
	double	m_extra10/*���Ӳ���10*/;
	//}}HDOSE_ATTRIBUTE

	String tempPoint;	// ��ʱ�洢WayPoint
};

//////////////////////////////////////////////////////////////////////////
// ����λ�õ㣬��ȡ�õ����ڴ��Ļ��������Ի�ȡ��صĻ�����������
HYCGF_API CEnvironment* GetEnvObj(GeoPt Pos);
//////////////////////////////////////////////////////////////////////////

#endif
