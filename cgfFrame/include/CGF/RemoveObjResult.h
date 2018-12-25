//RemoveObjResult.h: interface for the CRemoveObjResult module.
//!!HDOSE_CLASS(CRemoveObjResult,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RemoveObjResult_H)
#define AFX_RemoveObjResult_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CRemoveObjResult)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CRemoveObjResult /*删除对象结果*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CRemoveObjResult();
	virtual ~CRemoveObjResult();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetRemoveObjResult(long val){m_RemoveObjResult=val;}
	long	GetRemoveObjResult(){return m_RemoveObjResult;}
	void	SetRequestId(long val){m_RequestId=val;}
	long	GetRequestId(){return m_RequestId;}

	//{{HDOSE_MEMBER_FUNCTION(CRemoveObjResult)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRemoveObjResult)
	long	m_RemoveObjResult/*删除对象结果*/;
	long	m_RequestId/*请求Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
