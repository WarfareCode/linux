//TargetData.h: interface for the CTargetData module.
//!!HDOSE_CLASS(CTargetData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetData_H)
#define AFX_TargetData_H

#include "LatLonH.h"

//{{HDOSE_CLS_DES(CTargetData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CTargetData /*目标数据*/
{
public:
	CTargetData();
	~CTargetData();
public:
	
	//{{HDOSE_ATTRIBUTE(CTargetData)
	long	m_TargetId/*目标id*/;
	CLatLonH	m_TargetPos/*目标位置*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CTargetDataList;
void ReleaseTargetDataList(CTargetDataList* list);

#endif
