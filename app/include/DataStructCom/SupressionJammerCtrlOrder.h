//SupressionJammerCtrlOrder.h: interface for the CSupressionJammerCtrlOrder module.
//!!HDOSE_CLASS(CSupressionJammerCtrlOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SupressionJammerCtrlOrder_H)
#define AFX_SupressionJammerCtrlOrder_H


//{{HDOSE_CLS_DES(CSupressionJammerCtrlOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSupressionJammerCtrlOrder /*压制干扰器控制指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSupressionJammerCtrlOrder();
	virtual ~CSupressionJammerCtrlOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetJammerChannelNo(long val){m_JammerChannelNo=val;}
	long	GetJammerChannelNo(){return m_JammerChannelNo;}
	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}
	void	SetJammingStyle(long val){m_JammingStyle=val;}
	long	GetJammingStyle(){return m_JammingStyle;}
	void	SetJammingWaveform(long val){m_JammingWaveform=val;}
	long	GetJammingWaveform(){return m_JammingWaveform;}
	void	SetJammingPower(double val){m_JammingPower=val;}
	double	GetJammingPower(){return m_JammingPower;}

	//{{HDOSE_MEMBER_FUNCTION(CSupressionJammerCtrlOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSupressionJammerCtrlOrder)
	long	m_TargetNo/*目标编号*/;
	long	m_JammerChannelNo/*干扰通道编号*/;
	bool	m_bPowerOn/*干扰通道开关指令（0关、1开）*/;
	long	m_JammingStyle/*干扰样式（0压制、1欺骗）*/;
	long	m_JammingWaveform/*干扰波形（0压制、1杂乱脉冲）*/;
	double	m_JammingPower/*干扰功率*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
