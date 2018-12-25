//EntityCreateEvent.h: interface for the CEntityCreateEvent module.
//!!HDOSE_CLASS(CEntityCreateEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_EntityCreateEvent_H)
#define AFX_EntityCreateEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CEntityCreateEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CEntityCreateEvent /*ʵ�崴���¼�*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CEntityCreateEvent();
	virtual ~CEntityCreateEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetEntityID(long val){m_EntityID=val;}
	long	GetEntityID(){return m_EntityID;}
	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetEntityPos(GeoPt val){m_EntityPos=val;}
	GeoPt	GetEntityPos(){return m_EntityPos;}
	void	SetEntitySide(long val){m_EntitySide=val;}
	long	GetEntitySide(){return m_EntitySide;}
	void	SetEntityType(DtEntityType val){m_EntityType=val;}
	DtEntityType	GetEntityType(){return m_EntityType;}

	//{{HDOSE_MEMBER_FUNCTION(CEntityCreateEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CEntityCreateEvent)
	long	m_EntityID/*ʵ��ID*/;
	char*	m_EntityName/*ʵ������*/;
	GeoPt	m_EntityPos/*ʵ�����λ��*/;
	long	m_EntitySide/*ʵ���������*/;
	DtEntityType	m_EntityType/*ʵ������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
