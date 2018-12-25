//DetectDataStr.h: interface for the CDetectDataStr module.
//!!HDOSE_CLASS(CDetectDataStr,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DetectDataStr_H)
#define AFX_DetectDataStr_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CDetectDataStr)
/*
Author:		xks
Version:	1.0
Descript:	此数据结构用于表达探测的目标数据内容，
在SensorModel中使用，主要目的是传输给界面显示用。
*/
//}}HDOSE_CLS_DES

class HYCGF_API CDetectDataStr /*探测目标数据结构*/
{
public:
	CDetectDataStr();
	~CDetectDataStr();
public:
	
	//{{HDOSE_ATTRIBUTE(CDetectDataStr)
	double	m_UpdateTime/*更新时间*/;
	long	m_BatchNo/*目标批号*/;
	long	m_TargetID/*目标ID*/;
	char	m_TargetName[MAX_CHARLEN]/*目标名称*/;
	long	m_CID/*目标识别等级(0未发现,1发现,2分类,3识别,4掌握)*/;
	long	m_Side/*敌我属性*/;
	DtEntityType	m_EntityType/*目标类型*/;
	long	m_ThreatLevel/*威胁等级*/;
	GeoPt m_Pos/*目标位置*/;
	double	m_Velocity/*速度大小（m/s）*/;
	double	m_Course/*航向(deg,正北为0)*/;
	double	m_Theta/*目标航迹倾角(deg,-90~90)*/;
	double	m_Distance/*目标距离(m)*/;
	double	m_El/*高低角(deg)*/;
	double	m_Az/*方位角(deg)*/;
	long	m_RadiationType/*辐射源类型*/;
	double	m_RadiationPt/*辐射源功率(KW)*/;
	double	m_RadiationFreq/*辐射源频率(Hz)*/;
	double	m_RadiationTu/*辐射源脉宽(s)*/;
	double	m_RadiationPRF/*辐射源重频(Hz)*/;
	double	m_RadiationSignalType/*辐射源信号类型*/;
	double	m_RadiationPulseType/*辐射源信号脉冲调制类型*/;
	//}}HDOSE_ATTRIBUTE

	CDetectDataStr& operator=(CDetectDataStr val)
	{
		m_UpdateTime = val.m_UpdateTime	/*更新时间*/;
		m_BatchNo = val.m_BatchNo	/*目标批号*/;
		m_TargetID = val.m_TargetID	/*目标ID*/;
		strcpy(m_TargetName , val.m_TargetName)		/*目标名称*/;
		m_CID = val.m_CID	/*目标识别等级(0未发现,1发现,2分类,3识别,4掌握)*/;
		m_Side = val.m_Side	/*敌我属性*/;
		m_EntityType = val.m_EntityType	/*目标类型*/;
		m_ThreatLevel = val.m_ThreatLevel	/*威胁等级*/;
		m_Pos = val.m_Pos;
		m_Velocity = val.m_Velocity	/*速度大小（m/s）*/;
		m_Course = val.m_Course	/*航向(deg,正北为0)*/;
		m_Theta = val.m_Theta		/*目标航迹倾角(deg,-90~90)*/;
		m_Distance = val.m_Distance	/*目标距离(m)*/;
		m_El = val.m_El	/*高低角(deg)*/;
		m_Az = val.m_Az	/*方位角(deg)*/;
		m_RadiationType = val.m_RadiationType	/*辐射源类型*/;
		m_RadiationPt = val.m_RadiationPt	/*辐射源功率(KW)*/;
		m_RadiationFreq = val.m_RadiationFreq	/*辐射源频率(Hz)*/;
		m_RadiationTu = val.m_RadiationTu	/*辐射源脉宽(s)*/;
		m_RadiationPRF = val.m_RadiationPRF	/*辐射源重频(Hz)*/;
		m_RadiationSignalType = val.m_RadiationSignalType	/*辐射源信号类型*/;
		m_RadiationPulseType = val.m_RadiationPulseType	/*辐射源信号脉冲调制类型*/;

		return *this;
	}
};
typedef List<DWORD,DWORD> CDetectDataStrList;
void ReleaseDetectDataStrList(CDetectDataStrList* list);

DECLARE_DA(CDetectDataStr,MAX_SENSOR_DET_NUM);

#endif
