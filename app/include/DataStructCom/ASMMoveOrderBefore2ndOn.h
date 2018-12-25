//ASMMoveOrderBefore2ndOn.h: interface for the CASMMoveOrderBefore2ndOn module.
//!!HDOSE_CLASS(CASMMoveOrderBefore2ndOn,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMMoveOrderBefore2ndOn_H)
#define AFX_ASMMoveOrderBefore2ndOn_H


//{{HDOSE_CLS_DES(CASMMoveOrderBefore2ndOn)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMMoveOrderBefore2ndOn /*二次开机前导弹运动指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CASMMoveOrderBefore2ndOn();
	virtual ~CASMMoveOrderBefore2ndOn();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetMoveOrderBefore2ndOn(long val){m_MoveOrderBefore2ndOn=val;}
	long	GetMoveOrderBefore2ndOn(){return m_MoveOrderBefore2ndOn;}

	//{{HDOSE_MEMBER_FUNCTION(CASMMoveOrderBefore2ndOn)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMMoveOrderBefore2ndOn)
	long	m_MoveOrderBefore2ndOn/*二次开机前导弹运动指令（0，1，2）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
