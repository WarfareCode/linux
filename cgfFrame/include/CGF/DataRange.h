//DataRange.h: interface for the CDataRange module.
//!!HDOSE_CLASS(CDataRange,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DataRange_H)
#define AFX_DataRange_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CDataRange)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CDataRange /*���ݷ�Χ*/
{
public:
	CDataRange();
	~CDataRange();
public:
	
	//{{HDOSE_ATTRIBUTE(CDataRange)
	double	m_Min/*��С*/;
	double	m_Max/*���*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CDataRangeList;
void ReleaseDataRangeList(CDataRangeList* list);

#endif
