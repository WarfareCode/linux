//SensorData.h: interface for the CSensorData module.
//!!HDOSE_CLASS(CSensorData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SensorData_H)
#define AFX_SensorData_H


#include "WXCTime.h"
#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CSensorData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSensorData /*探测信息数据结构*/
{
public:
	CSensorData();
	~CSensorData();
public:
	
	//{{HDOSE_ATTRIBUTE(CSensorData)
	long	m_TargetNo/*目标编号*/;
	long	m_Type/*类别（敌0、我1、中立2、不明3）*/;
	long	m_Country/*国家地区（0中、日1、台2）*/;
	long	m_PlatformCategory/*平台性质（0空中、1水面、2水下、3岸基）*/;
	long	m_Kind/*目标属性（0驱逐舰、1防空导弹、2岸导阵地（岸基）、3预警机、4反舰导弹、5箔条、6指挥所、7卫星、8潜艇（水下）、9鱼雷（水下）、10歼击机、11歼击轰炸机、12轰炸机、13反潜直升机、14雷达阵地、15导弹艇、16护卫舰、17有源诱饵弹（水面）、18无人机、19侦察机、20电子干扰机…….、29控制对象、30海洋环境实体)*/;
	long	m_SideNo/*机/舷号（0、1、2...）*/;
	GeoPt	m_TargetPosition/*目标位置*/;
	double	m_TargetVelocity/*目标航速*/;
	double	m_TargetCourse/*目标航向*/;
	double m_TargetPitch/*目标航迹倾角*/;
	double	m_SpeedPrecision/*航速精度*/;
	double	m_CoursePrecision/*航向精度*/;
	double	m_DataCredibility/*数据可信度*/;
	CWXCTime	m_UpdateTime/*更新时间*/;
	long	m_InfoSource/*来源（预警机0、卫星1、其它2）*/;
	char	m_TargetName[128]/*目标名称*/;
	
	//20161109扩展
	long	m_TargetAttributeType/*属性类型（0舰艇、1防空导弹、2岸导阵地、3飞机、4反舰导弹、5箔条、6指挥所、7卫星、…、11压制干扰）*/;
	DtEntityType m_TargetType; // 目标对象类型，20160627
	double	m_TargetDistance/*目标距离m*/;
	CAzimuth3D	m_TargetAzimuth/*目标方位（以自身为原点）*/;
	long	m_TargetExId;// 扩展Id号
	int	m_Side; // 目标敌我属性


	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CSensorDataList;
void ReleaseSensorDataList(CSensorDataList* list);

#endif
