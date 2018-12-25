//SeekerOperationOrder.h: interface for the CSeekerOperationOrder module.
//!!HDOSE_CLASS(CSeekerOperationOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SeekerOperationOrder_H)
#define AFX_SeekerOperationOrder_H


//{{HDOSE_CLS_DES(CSeekerOperationOrder)
/*
Author:		
Version:	1.0
Descript:	工作状态指令，搜索、跟踪、跟杂
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerOperationOrder /*导引头工作状态指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSeekerOperationOrder();
	virtual ~CSeekerOperationOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSeekerOperationState(long val){m_SeekerOperationState=val;}
	long	GetSeekerOperationState(){return m_SeekerOperationState;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}

	//{{HDOSE_MEMBER_FUNCTION(CSeekerOperationOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSeekerOperationOrder)
	long	m_SeekerOperationState/*导引头工作状态（0搜索，1跟踪，2跟踪杂波源)*/;
	long	m_TargetNo/*目标编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
