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

class DATASTRUCTCOMPONENTDLL_API CAAMLauncherData /*���յ�������ܲ���*/
{
public:
	CAAMLauncherData();
	~CAAMLauncherData();
public:
	
	//{{HDOSE_ATTRIBUTE(CAAMLauncherData)
	char 	m_LauncherNo/*����ܱ��*/;
	long	m_LauncherState/*�����״̬��0���á�1δ׼���á�2���ϣ�*/;
	long	m_MaxLoadingAAMCount/*���ط��յ���������һ�ο�װ��������յ�������*/;
	double	m_TimeIntervalBtw2AAM/*��ö����ķ���ʱ����(s)*/;
	double	m_FillingTime/*��װ��ʱ����*/;
	long	m_AAMDataCount/*�����÷��յ��������������¼AAMData�ĸ��������5����*/;
	CAAMConfigData	m_AAMData[5]/*�����÷��յ����ͺ������������ݣ����5����*/;
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
