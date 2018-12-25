//CreateObjResult.h: interface for the CCreateObjResult module.
//!!HDOSE_CLASS(CCreateObjResult,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateObjResult_H)
#define AFX_CreateObjResult_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CCreateObjResult)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CCreateObjResult /*创建对象结果*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CCreateObjResult();
	virtual ~CCreateObjResult();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetCreateObjResult(long val){m_CreateObjResult=val;}
	long	GetCreateObjResult(){return m_CreateObjResult;}
	void	SetRequestId(long val){m_RequestId=val;}
	long	GetRequestId(){return m_RequestId;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateObjResult)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateObjResult)
	long	m_CreateObjResult/*创建对象结果*/;
	long	m_RequestId/*请求Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
