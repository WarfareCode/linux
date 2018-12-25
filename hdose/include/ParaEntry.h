// ParaEntry.h: interface for the CParaEntry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAENTRY_H__7AD0BF41_1C4D_47E2_9EC3_19987A7ACB63__INCLUDED_)
#define AFX_PARAENTRY_H__7AD0BF41_1C4D_47E2_9EC3_19987A7ACB63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Item.h"

class HDOSE_API CParaEntry : public CItem  
{
	DECLARE_CREATE;
public:
	char *GetParameterValue(const char *Name);
	BOOL SetParameterValue(const char *Name,const char *Value);
	CParaEntry();
	virtual ~CParaEntry();
	CLPArray m_parameters;

};

#endif // !defined(AFX_PARAENTRY_H__7AD0BF41_1C4D_47E2_9EC3_19987A7ACB63__INCLUDED_)
