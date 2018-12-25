//ESMTrackDataStruct.h: interface for the CESMTrackDataStruct module.
//!!HDOSE_CLASS(CESMTrackDataStruct,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ESMTrackDataStruct_H)
#define AFX_ESMTrackDataStruct_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CESMTrackDataStruct)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CESMTrackDataStruct /*电子侦察目标数据结构*/
{
public:
	CESMTrackDataStruct();
	~CESMTrackDataStruct();
public:
	
	//{{HDOSE_ATTRIBUTE(CESMTrackDataStruct)
	long	m_InfoSourceType/*信息来源形式（1有源探测、2无源探测、3情报通信）*/;
	long	m_InfoSourceSide/*信息来源方*/;
	long	m_InfoSourceEntId/*信息来源实体对象Id*/;
	char	m_InfoSourceEntName[MAX_CHARLEN]/*信息来源实体对象名称*/;
	long	m_InfoSourceModelId/*信息来源模型对象Id*/;
	char	m_InfoSourceModelName[MAX_CHARLEN]/*信息来源模型对象名称*/;
	double	m_UpdateTime/*更新时间*/;
	bool	m_isTracking;/*是否正在被跟踪*/
	long	m_BatchNo/*目标批号*/;
	long	m_TargetID/*目标ID*/;
	char	m_TargetName[MAX_CHARLEN]/*目标名称*/;
	long	m_CID/*目标识别等级(0未发现,1发现,2分类,3识别,4掌握)*/;
	long	m_Side/*敌我属性*/;
	DtEntityType	m_EntityType/*目标类型*/;
	long	m_RadiationType/*辐射源类型*/;
	long	m_ThreatLevel/*威胁等级*/;
	double	m_Distance/*目标距离(m)*/;
	GeoPt	m_Position/*目标位置*/;
	double	m_El/*高低角(deg)*/;
	double	m_Az/*方位角(deg)*/;
	long	m_ContinueCount/*持续探测次数*/;
	double	m_ContinueTime/*持续探测时间(s)*/;
	double	m_RadiationPt/*辐射源功率(KW)*/;
	double	m_RadiationFreq/*辐射源频率(Hz)*/;
	double	m_RadiationTu/*辐射源脉宽(s)*/;
	double	m_RadiationPRF/*辐射源重频(Hz)*/;
	double	m_RadiationSignalType/*辐射源信号类型*/;
	double	m_RadiationPulseType/*辐射源信号脉冲调制类型*/;
	double	m_RadiationAngleOfArrival/*辐射源到达角（deg）*/;
	//}}HDOSE_ATTRIBUTE

	CESMTrackDataStruct& operator=(CESMTrackDataStruct val)
	{
		m_InfoSourceType = val.m_InfoSourceType/*信息来源形式（1有源探测、2无源探测、3情报通信）*/;
		m_InfoSourceSide = val.m_InfoSourceSide/*信息来源方*/;
		m_InfoSourceEntId = val.m_InfoSourceEntId/*信息来源实体对象Id*/;
		strcpy(m_InfoSourceEntName, val.m_InfoSourceEntName)/*信息来源实体对象名称*/;
		m_InfoSourceModelId = val.m_InfoSourceModelId/*信息来源模型对象Id*/;
		strcpy(m_InfoSourceModelName,val.m_InfoSourceModelName)/*信息来源模型对象名称*/;
		m_UpdateTime = val.m_UpdateTime/*更新时间*/;
		m_isTracking = val.m_isTracking;
		m_BatchNo = val.m_BatchNo/*目标批号*/;
		m_TargetID = val.m_TargetID/*目标ID*/;
		strcpy(m_TargetName,val.m_TargetName)/*目标名称*/;
		m_CID = val.m_CID/*目标识别等级(0未发现,1发现,2分类,3识别,4掌握)*/;
		m_Side = val.m_Side/*敌我属性*/;
		m_EntityType = val.m_EntityType/*目标类型*/;
		m_RadiationType = val.m_RadiationType/*辐射源类型*/;
		m_ThreatLevel = val.m_ThreatLevel/*威胁等级*/;
		m_Distance = val.m_Distance/*目标距离(m)*/;
		m_Position = val.m_Position/*目标位置*/;
		m_El = val.m_El/*高低角(deg)*/;
		m_Az = val.m_Az/*方位角(deg)*/;
		m_ContinueCount = val.m_ContinueCount;/*持续探测次数*/
		m_ContinueTime = val.m_ContinueTime/*持续探测时间(s)*/;
		m_RadiationPt = val.m_RadiationPt/*辐射源功率(KW)*/;
		m_RadiationFreq = val.m_RadiationFreq/*辐射源频率(Hz)*/;
		m_RadiationTu = val.m_RadiationTu/*辐射源脉宽(s)*/;
		m_RadiationPRF = val.m_RadiationPRF/*辐射源重频(Hz)*/;
		m_RadiationSignalType = val.m_RadiationSignalType/*辐射源信号类型*/;
		m_RadiationPulseType = val.m_RadiationPulseType/*辐射源信号脉冲调制类型*/;
		m_RadiationAngleOfArrival = val.m_RadiationAngleOfArrival/*辐射源到达角（deg）*/;
		return *this;
	}

	void clear()
	{
		CESMTrackDataStruct nullEle;
		(*this) = nullEle;
	}
};
typedef List<DWORD,DWORD> CESMTrackDataStructList;
void ReleaseESMTrackDataStructList(CESMTrackDataStructList* list);

#endif
