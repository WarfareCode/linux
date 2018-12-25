//SupressionJammerPowerOnOrder.h: interface for the CSupressionJammerPowerOnOrder module.
//!!HDOSE_CLASS(CSupressionJammerPowerOnOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SupressionJammerPowerOnOrder_H)
#define AFX_SupressionJammerPowerOnOrder_H


//{{HDOSE_CLS_DES(CSupressionJammerPowerOnOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSupressionJammerPowerOnOrder /*压制干扰器开关指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSupressionJammerPowerOnOrder();
	virtual ~CSupressionJammerPowerOnOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}
	void	SetJammerChannelNo(long val){m_JammerChannelNo=val;}
	long	GetJammerChannelNo(){return m_JammerChannelNo;}

	//{{HDOSE_MEMBER_FUNCTION(CSupressionJammerPowerOnOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSupressionJammerPowerOnOrder)
	bool	m_bPowerOn/*开关指令（0关，1开）*/;
	long	m_JammerChannelNo/*干扰通道编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
