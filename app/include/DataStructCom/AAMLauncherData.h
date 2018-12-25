//AAMLauncherData.h: interface for the CAAMLauncherData module.
//!!HDOSE_CLASS(CAAMLauncherData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMLauncherData_H)
#define AFX_AAMLauncherData_H

#include "AAMConfigData.h"

//{{HDOSE_CLS_DES(CAAMLauncherData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMLauncherData /*防空导弹发射架参数*/
{
public:
	CAAMLauncherData();
	~CAAMLauncherData();
public:
	
	//{{HDOSE_ATTRIBUTE(CAAMLauncherData)
	char 	m_LauncherNo/*发射架编号*/;
	long	m_LauncherState/*发射架状态（0可用、1未准备好、2故障）*/;
	long	m_MaxLoadingAAMCount/*满载防空弹数量（即一次可装填的最大防空弹数量）*/;
	double	m_TimeIntervalBtw2AAM/*两枚弹间的发射时间间隔(s)*/;
	double	m_FillingTime/*再装填时间间隔*/;
	long	m_AAMDataCount/*所配置防空弹种类的数量（记录AAMData的个数，最多5个）*/;
	CAAMConfigData	m_AAMData[5]/*所配置防空弹类型和数量基本数据（最多5个）*/;
	//}}HDOSE_ATTRIBUTE

	CAAMLauncherData& operator=(CAAMLauncherData val)
	{
		m_LauncherNo = val.m_LauncherNo;
		m_LauncherState = val.m_LauncherState;
		m_MaxLoadingAAMCount = val.m_MaxLoadingAAMCount;
		m_TimeIntervalBtw2AAM = val.m_TimeIntervalBtw2AAM;
		m_FillingTime = val.m_FillingTime;
		m_AAMDataCount = val.m_AAMDataCount;
		for(int i = 0; i<m_AAMDataCount; i++)
		{
			m_AAMData[i] = val.m_AAMData[i];
		}

		return *this;
	}
};
typedef List<DWORD,DWORD> CAAMLauncherDataList;
void ReleaseAAMLauncherDataList(CAAMLauncherDataList* list);

#endif
