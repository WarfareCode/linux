//SupressionJammerWorkParams.h: interface for the CSupressionJammerWorkParams module.
//!!HDOSE_CLASS(CSupressionJammerWorkParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SupressionJammerWorkParams_H)
#define AFX_SupressionJammerWorkParams_H


//{{HDOSE_CLS_DES(CSupressionJammerWorkParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSupressionJammerWorkParams /*压制干扰器工作参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSupressionJammerWorkParams();
	virtual ~CSupressionJammerWorkParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetJammerChannelNo(long val){m_JammerChannelNo=val;}
	long	GetJammerChannelNo(){return m_JammerChannelNo;}
	void	SetJammingStyle(long val){m_JammingStyle=val;}
	long	GetJammingStyle(){return m_JammingStyle;}
	void	SetJammingWaveform(long val){m_JammingWaveform=val;}
	long	GetJammingWaveform(){return m_JammingWaveform;}
	void	SetJammingPower(double val){m_JammingPower=val;}
	double	GetJammingPower(){return m_JammingPower;}

	//{{HDOSE_MEMBER_FUNCTION(CSupressionJammerWorkParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSupressionJammerWorkParams)
	long	m_TargetNo/*目标编号*/;
	long	m_JammerChannelNo/*干扰通道编号*/;
	long	m_JammingStyle/*干扰样式（0压制、1欺骗）*/;
	long	m_JammingWaveform/*干扰波形（0压制、1杂乱脉冲）*/;
	double	m_JammingPower/*干扰功率*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
