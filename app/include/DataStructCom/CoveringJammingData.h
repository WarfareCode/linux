//CoveringJammingData.h: interface for the CCoveringJammingData module.
//!!HDOSE_CLASS(CCoveringJammingData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CoveringJammingData_H)
#define AFX_CoveringJammingData_H


//{{HDOSE_CLS_DES(CCoveringJammingData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCoveringJammingData /*�ڸ�ʽ��Դ��������*/
{
public:
	CCoveringJammingData();
	~CCoveringJammingData();
public:
	
	//{{HDOSE_ATTRIBUTE(CCoveringJammingData)
	double	m_Power/*���书��*/;
	double	m_DelayDist/*�ӳپ��루m��*/;
	double	m_CoveringRange/*�ڸǿ��(m)*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CCoveringJammingDataList;
void ReleaseCoveringJammingDataList(CCoveringJammingDataList* list);

#endif
