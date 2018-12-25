//AAMConfigData.h: interface for the CAAMConfigData module.
//!!HDOSE_CLASS(CAAMConfigData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMConfigData_H)
#define AFX_AAMConfigData_H


//{{HDOSE_CLS_DES(CAAMConfigData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMConfigData /*���յ�����������*/
{
public:
	CAAMConfigData();
	~CAAMConfigData();
public:
	
	//{{HDOSE_ATTRIBUTE(CAAMConfigData)
	long	m_AAMType/*���յ�������*/;
	long	m_AAMCount/*�����ͷ��յ���������*/;
	double	m_RangeMin/*����,m*/;
	double	m_RangeMax/*Զ��,m*/;
	double	m_AltMin/*�ͽ�,m*/;
	double	m_AltMax/*�߽�,m*/;
	double	m_CourseShortMax/*���·�ݾ�,m*/;
	double m_VelAverage/*ƽ�������ٶ�(���ڳ��Թ��㽻��ʱ�������),m/s*/;
	double	m_TargetSpeedMin/*Ŀ���ٶ�����*/;
	double	m_TargetSpeedMax/*Ŀ���ٶ�����*/;
	double	m_KilledProbability/*ɱ�˸���*/;
	//}}HDOSE_ATTRIBUTE

	CAAMConfigData& operator=(CAAMConfigData val)
	{
		m_AAMType = val.m_AAMType	/*���յ�������*/;
		m_AAMCount = val.m_AAMCount	/*�����ͷ��յ���������*/;
		m_RangeMin = val.m_RangeMin	/*����,km*/;
		m_RangeMax = val.m_RangeMax	/*Զ��,km*/;
		m_AltMin = val.m_AltMin	/*�ͽ�,km*/;
		m_AltMax = val.m_AltMax	/*�߽�,km*/;
		m_CourseShortMax = val.m_CourseShortMax	/*���·�ݾ�,km*/;
		m_VelAverage = val.m_VelAverage	/*ƽ�������ٶ�(���ڳ��Թ��㽻��ʱ�������),m/s*/;
		m_TargetSpeedMin = val.m_TargetSpeedMin	/*Ŀ���ٶ�����,m/s*/;
		m_TargetSpeedMax = val.m_TargetSpeedMax	/*Ŀ���ٶ�����,m/s*/;
		m_KilledProbability = val.m_KilledProbability	/*ɱ�˸���*/;

		return *this;
	}
};
typedef List<DWORD,DWORD> CAAMConfigDataList;
void ReleaseAAMConfigDataList(CAAMConfigDataList* list);

#endif
