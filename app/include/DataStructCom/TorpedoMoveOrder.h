//TorpedoMoveOrder.h: interface for the CTorpedoMoveOrder module.
//!!HDOSE_CLASS(CTorpedoMoveOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoMoveOrder_H)
#define AFX_TorpedoMoveOrder_H


//{{HDOSE_CLS_DES(CTorpedoMoveOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoMoveOrder /*鱼雷运动指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoMoveOrder();
	virtual ~CTorpedoMoveOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetMoveOrder(long val){m_MoveOrder=val;}
	long	GetMoveOrder(){return m_MoveOrder;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoMoveOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoMoveOrder)
	long	m_MoveOrder/*运动指令*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
