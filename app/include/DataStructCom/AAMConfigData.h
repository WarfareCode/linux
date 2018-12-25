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

class DATASTRUCTCOMPONENTDLL_API CAAMConfigData /*防空导弹配置数据*/
{
public:
	CAAMConfigData();
	~CAAMConfigData();
public:
	
	//{{HDOSE_ATTRIBUTE(CAAMConfigData)
	long	m_AAMType/*防空导弹类型*/;
	long	m_AAMCount/*该类型防空导弹的数量*/;
	double	m_RangeMin/*近界,m*/;
	double	m_RangeMax/*远界,m*/;
	double	m_AltMin/*低界,m*/;
	double	m_AltMax/*高界,m*/;
	double	m_CourseShortMax/*最大航路捷径,m*/;
	double m_VelAverage/*平均飞行速度(用于初略估算交汇时间等数据),m/s*/;
	double	m_TargetSpeedMin/*目标速度下限*/;
	double	m_TargetSpeedMax/*目标速度上限*/;
	double	m_KilledProbability/*杀伤概率*/;
	//}}HDOSE_ATTRIBUTE

	CAAMConfigData& operator=(CAAMConfigData val)
	{
		m_AAMType = val.m_AAMType	/*防空导弹类型*/;
		m_AAMCount = val.m_AAMCount	/*该类型防空导弹的数量*/;
		m_RangeMin = val.m_RangeMin	/*近界,km*/;
		m_RangeMax = val.m_RangeMax	/*远界,km*/;
		m_AltMin = val.m_AltMin	/*低界,km*/;
		m_AltMax = val.m_AltMax	/*高界,km*/;
		m_CourseShortMax = val.m_CourseShortMax	/*最大航路捷径,km*/;
		m_VelAverage = val.m_VelAverage	/*平均飞行速度(用于初略估算交汇时间等数据),m/s*/;
		m_TargetSpeedMin = val.m_TargetSpeedMin	/*目标速度下限,m/s*/;
		m_TargetSpeedMax = val.m_TargetSpeedMax	/*目标速度上限,m/s*/;
		m_KilledProbability = val.m_KilledProbability	/*杀伤概率*/;

		return *this;
	}
};
typedef List<DWORD,DWORD> CAAMConfigDataList;
void ReleaseAAMConfigDataList(CAAMConfigDataList* list);

#endif
