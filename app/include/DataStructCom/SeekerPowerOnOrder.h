//SeekerPowerOnOrder.h: interface for the CSeekerPowerOnOrder module.
//!!HDOSE_CLASS(CSeekerPowerOnOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SeekerPowerOnOrder_H)
#define AFX_SeekerPowerOnOrder_H


//{{HDOSE_CLS_DES(CSeekerPowerOnOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerPowerOnOrder /*导引头开关机指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSeekerPowerOnOrder();
	virtual ~CSeekerPowerOnOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}

	//{{HDOSE_MEMBER_FUNCTION(CSeekerPowerOnOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSeekerPowerOnOrder)
	bool	m_bPowerOn/*开关机指示(0关机，1开机）*/;
	long	m_TargetNo/*目标编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
