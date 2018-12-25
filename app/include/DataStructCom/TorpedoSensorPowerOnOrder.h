//TorpedoSensorPowerOnOrder.h: interface for the CTorpedoSensorPowerOnOrder module.
//!!HDOSE_CLASS(CTorpedoSensorPowerOnOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoSensorPowerOnOrder_H)
#define AFX_TorpedoSensorPowerOnOrder_H


//{{HDOSE_CLS_DES(CTorpedoSensorPowerOnOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoSensorPowerOnOrder /*鱼雷探测器开关指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoSensorPowerOnOrder();
	virtual ~CTorpedoSensorPowerOnOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPowerOn(bool val){m_PowerOn=val;}
	bool	GetPowerOn(){return m_PowerOn;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoSensorPowerOnOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoSensorPowerOnOrder)
	bool	m_PowerOn/*开机指令（1开，0关）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
