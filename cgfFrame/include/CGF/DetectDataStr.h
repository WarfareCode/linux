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
Descript:	�����ݽṹ���ڱ��̽���Ŀ���������ݣ�
��SensorModel��ʹ�ã���ҪĿ���Ǵ����������ʾ�á�
*/
//}}HDOSE_CLS_DES

class HYCGF_API CDetectDataStr /*̽��Ŀ�����ݽṹ*/
{
public:
	CDetectDataStr();
	~CDetectDataStr();
public:
	
	//{{HDOSE_ATTRIBUTE(CDetectDataStr)
	double	m_UpdateTime/*����ʱ��*/;
	long	m_BatchNo/*Ŀ������*/;
	long	m_TargetID/*Ŀ��ID*/;
	char	m_TargetName[MAX_CHARLEN]/*Ŀ������*/;
	long	m_CID/*Ŀ��ʶ��ȼ�(0δ����,1����,2����,3ʶ��,4����)*/;
	long	m_Side/*��������*/;
	DtEntityType	m_EntityType/*Ŀ������*/;
	long	m_ThreatLevel/*��в�ȼ�*/;
	GeoPt m_Pos/*Ŀ��λ��*/;
	double	m_Velocity/*�ٶȴ�С��m/s��*/;
	double	m_Course/*����(deg,����Ϊ0)*/;
	double	m_Theta/*Ŀ�꺽�����(deg,-90~90)*/;
	double	m_Distance/*Ŀ�����(m)*/;
	double	m_El/*�ߵͽ�(deg)*/;
	double	m_Az/*��λ��(deg)*/;
	long	m_RadiationType/*����Դ����*/;
	double	m_RadiationPt/*����Դ����(KW)*/;
	double	m_RadiationFreq/*����ԴƵ��(Hz)*/;
	double	m_RadiationTu/*����Դ����(s)*/;
	double	m_RadiationPRF/*����Դ��Ƶ(Hz)*/;
	double	m_RadiationSignalType/*����Դ�ź�����*/;
	double	m_RadiationPulseType/*����Դ�ź������������*/;
	//}}HDOSE_ATTRIBUTE

	CDetectDataStr& operator=(CDetectDataStr val)
	{
		m_UpdateTime = val.m_UpdateTime	/*����ʱ��*/;
		m_BatchNo = val.m_BatchNo	/*Ŀ������*/;
		m_TargetID = val.m_TargetID	/*Ŀ��ID*/;
		strcpy(m_TargetName , val.m_TargetName)		/*Ŀ������*/;
		m_CID = val.m_CID	/*Ŀ��ʶ��ȼ�(0δ����,1����,2����,3ʶ��,4����)*/;
		m_Side = val.m_Side	/*��������*/;
		m_EntityType = val.m_EntityType	/*Ŀ������*/;
		m_ThreatLevel = val.m_ThreatLevel	/*��в�ȼ�*/;
		m_Pos = val.m_Pos;
		m_Velocity = val.m_Velocity	/*�ٶȴ�С��m/s��*/;
		m_Course = val.m_Course	/*����(deg,����Ϊ0)*/;
		m_Theta = val.m_Theta		/*Ŀ�꺽�����(deg,-90~90)*/;
		m_Distance = val.m_Distance	/*Ŀ�����(m)*/;
		m_El = val.m_El	/*�ߵͽ�(deg)*/;
		m_Az = val.m_Az	/*��λ��(deg)*/;
		m_RadiationType = val.m_RadiationType	/*����Դ����*/;
		m_RadiationPt = val.m_RadiationPt	/*����Դ����(KW)*/;
		m_RadiationFreq = val.m_RadiationFreq	/*����ԴƵ��(Hz)*/;
		m_RadiationTu = val.m_RadiationTu	/*����Դ����(s)*/;
		m_RadiationPRF = val.m_RadiationPRF	/*����Դ��Ƶ(Hz)*/;
		m_RadiationSignalType = val.m_RadiationSignalType	/*����Դ�ź�����*/;
		m_RadiationPulseType = val.m_RadiationPulseType	/*����Դ�ź������������*/;

		return *this;
	}
};
typedef List<DWORD,DWORD> CDetectDataStrList;
void ReleaseDetectDataStrList(CDetectDataStrList* list);

DECLARE_DA(CDetectDataStr,MAX_SENSOR_DET_NUM);

#endif
