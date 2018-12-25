//ClutterData.h: interface for the CClutterData module.
//!!HDOSE_CLASS(CClutterData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ClutterData_H)
#define AFX_ClutterData_H

#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CClutterData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CClutterData /*�Ӳ���������*/
{
public:
	CClutterData();
	~CClutterData();
public:
	
	//{{HDOSE_ATTRIBUTE(CClutterData)
	CAzimuth3D	m_SuppressingJamingAzimuth/*ѹ�Ƹ��ŷ�λ*/;
	double	m_Distance/*����km*/;
	long	m_JammingWaveform/*���Ų��Σ���������Ϊѹ�Ƹ���ʱ���������д��0ѹ�Ʋ��Σ�1�������壩*/;
	double	m_JammingPower/*���Ź��ʣ���������Ϊѹ�Ƹ���ʱ���������д*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CClutterDataList;
void ReleaseClutterDataList(CClutterDataList* list);

#endif
