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

class DATASTRUCTCOMPONENTDLL_API CSupressionJammerCtrlOrder /*ѹ�Ƹ���������ָ��*/ : public CEvt 
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
	long	m_TargetNo/*Ŀ����*/;
	long	m_JammerChannelNo/*����ͨ�����*/;
	bool	m_bPowerOn/*����ͨ������ָ�0�ء�1����*/;
	long	m_JammingStyle/*������ʽ��0ѹ�ơ�1��ƭ��*/;
	long	m_JammingWaveform/*���Ų��Σ�0ѹ�ơ�1�������壩*/;
	double	m_JammingPower/*���Ź���*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
