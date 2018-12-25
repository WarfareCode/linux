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

class HYCGF_API CESMTrackDataStruct /*�������Ŀ�����ݽṹ*/
{
public:
	CESMTrackDataStruct();
	~CESMTrackDataStruct();
public:
	
	//{{HDOSE_ATTRIBUTE(CESMTrackDataStruct)
	long	m_InfoSourceType/*��Ϣ��Դ��ʽ��1��Դ̽�⡢2��Դ̽�⡢3�鱨ͨ�ţ�*/;
	long	m_InfoSourceSide/*��Ϣ��Դ��*/;
	long	m_InfoSourceEntId/*��Ϣ��Դʵ�����Id*/;
	char	m_InfoSourceEntName[MAX_CHARLEN]/*��Ϣ��Դʵ���������*/;
	long	m_InfoSourceModelId/*��Ϣ��Դģ�Ͷ���Id*/;
	char	m_InfoSourceModelName[MAX_CHARLEN]/*��Ϣ��Դģ�Ͷ�������*/;
	double	m_UpdateTime/*����ʱ��*/;
	bool	m_isTracking;/*�Ƿ����ڱ�����*/
	long	m_BatchNo/*Ŀ������*/;
	long	m_TargetID/*Ŀ��ID*/;
	char	m_TargetName[MAX_CHARLEN]/*Ŀ������*/;
	long	m_CID/*Ŀ��ʶ��ȼ�(0δ����,1����,2����,3ʶ��,4����)*/;
	long	m_Side/*��������*/;
	DtEntityType	m_EntityType/*Ŀ������*/;
	long	m_RadiationType/*����Դ����*/;
	long	m_ThreatLevel/*��в�ȼ�*/;
	double	m_Distance/*Ŀ�����(m)*/;
	GeoPt	m_Position/*Ŀ��λ��*/;
	double	m_El/*�ߵͽ�(deg)*/;
	double	m_Az/*��λ��(deg)*/;
	long	m_ContinueCount/*����̽�����*/;
	double	m_ContinueTime/*����̽��ʱ��(s)*/;
	double	m_RadiationPt/*����Դ����(KW)*/;
	double	m_RadiationFreq/*����ԴƵ��(Hz)*/;
	double	m_RadiationTu/*����Դ����(s)*/;
	double	m_RadiationPRF/*����Դ��Ƶ(Hz)*/;
	double	m_RadiationSignalType/*����Դ�ź�����*/;
	double	m_RadiationPulseType/*����Դ�ź������������*/;
	double	m_RadiationAngleOfArrival/*����Դ����ǣ�deg��*/;
	//}}HDOSE_ATTRIBUTE

	CESMTrackDataStruct& operator=(CESMTrackDataStruct val)
	{
		m_InfoSourceType = val.m_InfoSourceType/*��Ϣ��Դ��ʽ��1��Դ̽�⡢2��Դ̽�⡢3�鱨ͨ�ţ�*/;
		m_InfoSourceSide = val.m_InfoSourceSide/*��Ϣ��Դ��*/;
		m_InfoSourceEntId = val.m_InfoSourceEntId/*��Ϣ��Դʵ�����Id*/;
		strcpy(m_InfoSourceEntName, val.m_InfoSourceEntName)/*��Ϣ��Դʵ���������*/;
		m_InfoSourceModelId = val.m_InfoSourceModelId/*��Ϣ��Դģ�Ͷ���Id*/;
		strcpy(m_InfoSourceModelName,val.m_InfoSourceModelName)/*��Ϣ��Դģ�Ͷ�������*/;
		m_UpdateTime = val.m_UpdateTime/*����ʱ��*/;
		m_isTracking = val.m_isTracking;
		m_BatchNo = val.m_BatchNo/*Ŀ������*/;
		m_TargetID = val.m_TargetID/*Ŀ��ID*/;
		strcpy(m_TargetName,val.m_TargetName)/*Ŀ������*/;
		m_CID = val.m_CID/*Ŀ��ʶ��ȼ�(0δ����,1����,2����,3ʶ��,4����)*/;
		m_Side = val.m_Side/*��������*/;
		m_EntityType = val.m_EntityType/*Ŀ������*/;
		m_RadiationType = val.m_RadiationType/*����Դ����*/;
		m_ThreatLevel = val.m_ThreatLevel/*��в�ȼ�*/;
		m_Distance = val.m_Distance/*Ŀ�����(m)*/;
		m_Position = val.m_Position/*Ŀ��λ��*/;
		m_El = val.m_El/*�ߵͽ�(deg)*/;
		m_Az = val.m_Az/*��λ��(deg)*/;
		m_ContinueCount = val.m_ContinueCount;/*����̽�����*/
		m_ContinueTime = val.m_ContinueTime/*����̽��ʱ��(s)*/;
		m_RadiationPt = val.m_RadiationPt/*����Դ����(KW)*/;
		m_RadiationFreq = val.m_RadiationFreq/*����ԴƵ��(Hz)*/;
		m_RadiationTu = val.m_RadiationTu/*����Դ����(s)*/;
		m_RadiationPRF = val.m_RadiationPRF/*����Դ��Ƶ(Hz)*/;
		m_RadiationSignalType = val.m_RadiationSignalType/*����Դ�ź�����*/;
		m_RadiationPulseType = val.m_RadiationPulseType/*����Դ�ź������������*/;
		m_RadiationAngleOfArrival = val.m_RadiationAngleOfArrival/*����Դ����ǣ�deg��*/;
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
