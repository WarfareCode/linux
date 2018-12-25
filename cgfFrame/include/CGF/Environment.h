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

class HYCGF_API CEnvironment /*环境对象*/ : public CLink 
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

	// 手动修改
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

	// 基本描述
	char*	m_EnvObjName/*环境对象名称*/;
	char*	m_EnvArea/*环境区域,4位置点数组*/;
	// 气压 气温 湿度
	double	m_AveragePressure/*平均气压,帕*/;
	double	m_AverageTemperature/*平均气温,摄氏度*/;
	double	m_AverageHumidity/*平均大气湿度,百分比*/;
	// 降雨
	long	m_RainModelType/*降雨模型,1 ITU-R P618-9, 2 Crane 1985,3 xx*/;
	double	m_RainDensity/*降水强度,mm/h*/;
	double	m_RainSurfTemperature/*雨表面温度,摄氏度*/;
	// 云雾
	double	m_CloudCeliling/*云顶高,km*/;
	double	m_CloudLayerThickness/*云层厚度,km*/;
	double	m_CloudTemperature/*云层温度,摄氏度*/;
	double	m_CloudLiquidWaterDensity/*云液态水密度,g/m^3*/;
	double	m_AverageVisibility/*平均能见度,km*/;
	// 风
	double	m_WindCou/*风向,(0-360度)*/;
	double	m_WindVel/*风速,(m/s)*/;
	// 大气吸收
	long	m_AtmosAbsorptionModelType/*大气吸收模型,可选的模型*/;
	double	m_AtmosWaterVaporConc/*大气水蒸气含量,g/m^3*/;
	double	m_AtmosSurfTemperature/*大气表面温度,摄氏度*/;
	// 海况
	long	m_SeaStateLevel/*海况等级*/;
	double	m_WindWaveDirection/*风浪方向，(0-360度)*/;
	double m_WindWaveVel/*风浪速度,m/s*/;
	double m_WindWaveLength/*风浪波长，m*/;
	double	m_TideHight/*潮高,m*/;
	double	m_SurfDirection/*流向,(0-360度)*/;
	double	m_SurfVel/*流速,m/s*/;
	long	m_SurgeLevel/*涌浪等级*/;
	double	m_SurgeDirection/*涌浪方向,(0-360度)*/;
	double	m_SurgeVel/*涌浪速度,m/s*/;
	double m_SurgeWaveLength/*涌浪波长,m*/;
	// 水文
	double	m_AverageWaterDepth/*平均水深*/;
	double	m_AverageWaterSalinity/*平均海水盐度*/;
	double	m_WaterSurfTemperature/*海水表面温度*/;
	double	m_AverageWaterDensity/*平均海水密度*/;
	long	m_SeaFloorSediments/*海底底质类型*/;
	// 附加
	long	m_extra1/*附加参数1*/;
	long	m_extra2/*附加参数2*/;
	long	m_extra3/*附加参数3*/;
	double	m_extra4/*附加参数4*/;
	double	m_extra5/*附加参数5*/;
	double	m_extra6/*附加参数6*/;
	double	m_extra7/*附加参数7*/;
	double	m_extra8/*附加参数8*/;
	double	m_extra9/*附加参数9*/;
	double	m_extra10/*附加参数10*/;
	//}}HDOSE_ATTRIBUTE

	String tempPoint;	// 临时存储WayPoint
};

//////////////////////////////////////////////////////////////////////////
// 根据位置点，获取该点所在处的环境对象，以获取相关的环境属性数据
HYCGF_API CEnvironment* GetEnvObj(GeoPt Pos);
//////////////////////////////////////////////////////////////////////////

#endif
