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
Descript:	����״ָ̬����������١�����
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerOperationOrder /*����ͷ����״ָ̬��*/ : public CEvt 
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
	long	m_SeekerOperationState/*����ͷ����״̬��0������1���٣�2�����Ӳ�Դ)*/;
	long	m_TargetNo/*Ŀ����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
