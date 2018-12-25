//EntityMoveOrderEvt.h: interface for the CNodeMoveOrderEvt module.
//!!HDOSE_CLASS(CNodeMoveOrderEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_EntityMoveOrderEvt_H)
#define AFX_EntityMoveOrderEvt_H


//{{HDOSE_CLS_DES(CNodeMoveOrderEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CNodeMoveOrderEvt /*实体运动事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CNodeMoveOrderEvt();
	virtual ~CNodeMoveOrderEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetMoveType(short val){m_MoveType=val;}
	short	GetMoveType(){return m_MoveType;}
	void	SetRouteId(long val){m_RouteId=val;}
	long	GetRouteId(){return m_RouteId;}

	//{{HDOSE_MEMBER_FUNCTION(CNodeMoveOrderEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CNodeMoveOrderEvt)
	short	m_MoveType/*运动类型*/;
	long	m_RouteId/*线对象Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
