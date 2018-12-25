//CommStateEvent.h: interface for the CCommStateEvent module.
//!!HDOSE_CLASS(CCommStateEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CommStateEvent_H)
#define AFX_CommStateEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CCommStateEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CCommStateEvent /*通信状态事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCommStateEvent();
	virtual ~CCommStateEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetIsConnected(bool val){m_IsConnected=val;}
	bool	GetIsConnected(){return m_IsConnected;}
	void	SetSourceEntityID(long val){m_SourceEntityID=val;}
	long	GetSourceEntityID(){return m_SourceEntityID;}
	void	SetDesEntityID(long val){m_DesEntityID=val;}
	long	GetDesEntityID(){return m_DesEntityID;}
	void	SetSrcEntExId(long val){m_SrcEntExId=val;}
	long	GetSrcEntExId(){return m_SrcEntExId;}
	void	SetDesEntExId(long val){m_DesEntExId=val;}
	long	GetDesEntExId(){return m_DesEntExId;}

	//{{HDOSE_MEMBER_FUNCTION(CCommStateEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCommStateEvent)
	bool	m_IsConnected/*通/断状态(true通、false断)*/;
	long	m_SourceEntityID/*起始实体ID*/;
	long	m_DesEntityID/*目的实体ID*/;
	long	m_SrcEntExId/*起始实体扩展Id*/;
	long	m_DesEntExId/*目的实体扩展Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
