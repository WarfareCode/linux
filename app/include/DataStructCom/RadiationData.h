//RadiationData.h: interface for the CRadiationData module.
//!!HDOSE_CLASS(CRadiationData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RadiationData_H)
#define AFX_RadiationData_H


//{{HDOSE_CLS_DES(CRadiationData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CRadiationData /*����Դ����*/
{
public:
	CRadiationData();
	~CRadiationData();
public:
	
	//{{HDOSE_ATTRIBUTE(CRadiationData)
	double	m_Frequency/*Ƶ��*/;
	double	m_PulseWidth/*����*/;
	double	m_MultiPulse/*��Ƶ*/;
	double	m_Power/*����*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CRadiationDataList;
void ReleaseRadiationDataList(CRadiationDataList* list);

#endif
