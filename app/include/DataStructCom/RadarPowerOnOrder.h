//RadarPowerOnOrder.h: interface for the CRadarPowerOnOrder module.
//!!HDOSE_CLASS(CRadarPowerOnOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RadarPowerOnOrder_H)
#define AFX_RadarPowerOnOrder_H


//{{HDOSE_CLS_DES(CRadarPowerOnOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CRadarPowerOnOrder /*雷达开关指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CRadarPowerOnOrder();
	virtual ~CRadarPowerOnOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}

	//{{HDOSE_MEMBER_FUNCTION(CRadarPowerOnOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRadarPowerOnOrder)
	bool	m_bPowerOn/*雷达开关机指令（0关机，1开机）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
