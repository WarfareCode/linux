//EntityMoveTask.h: interface for the CNodeMoveTask module.
//!!HDOSE_CLASS(CNodeMoveTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_EntityMoveTask_H)
#define AFX_EntityMoveTask_H

#include "task.h"

//{{HDOSE_CLS_DES(CNodeMoveTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CNodeMoveTask /*实体运动任务*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CNodeMoveTask();
	virtual ~CNodeMoveTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetRecieverId(long val){m_RecieverId=val;}
	long	GetRecieverId(){return m_RecieverId;}
	void	SetMoveType(short val){m_MoveType=val;}
	short	GetMoveType(){return m_MoveType;}
	void	SetRouteId(long val){m_RouteId=val;}
	long	GetRouteId(){return m_RouteId;}

	//{{HDOSE_MEMBER_FUNCTION(CNodeMoveTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CNodeMoveTask)
	long	m_RecieverId/*接收者Id*/;
	short	m_MoveType/*运动类型（按点、线等运动）*/;
	long	m_RouteId/*路线Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
