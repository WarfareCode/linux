//EntityExitEvent.h: interface for the CEntityExitEvent module.
//!!HDOSE_CLASS(CEntityExitEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_EntityExitEvent_H)
#define AFX_EntityExitEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CEntityExitEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CEntityExitEvent /*实体退出事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CEntityExitEvent();
	virtual ~CEntityExitEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetEntityID(long val){m_EntityID=val;}
	long	GetEntityID(){return m_EntityID;}
	void	SetEntityPos(GeoPt val){m_EntityPos=val;}
	GeoPt	GetEntityPos(){return m_EntityPos;}

	//{{HDOSE_MEMBER_FUNCTION(CEntityExitEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CEntityExitEvent)
	long	m_EntityID/*实体ID*/;
	GeoPt	m_EntityPos/*实体位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
