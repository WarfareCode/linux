//RemoveObjRequest.h: interface for the CRemoveObjRequest module.
//!!HDOSE_CLASS(CRemoveObjRequest,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RemoveObjRequest_H)
#define AFX_RemoveObjRequest_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CRemoveObjRequest)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CRemoveObjRequest /*删除对象请求*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CRemoveObjRequest();
	virtual ~CRemoveObjRequest();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetObjType(long val){m_ObjType=val;}
	long	GetObjType(){return m_ObjType;}
	void	SetObjId(long val){m_ObjId=val;}
	long	GetObjId(){return m_ObjId;}

	//{{HDOSE_MEMBER_FUNCTION(CRemoveObjRequest)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRemoveObjRequest)
	long	m_ObjType/*删除对象类型（1实体、2控制对象）*/;
	long	m_ObjId/*对象Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
