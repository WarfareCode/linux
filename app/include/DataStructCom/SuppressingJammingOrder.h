//SuppressingJammingOrder.h: interface for the CSuppressingJammingOrder module.
//!!HDOSE_CLASS(CSuppressingJammingOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SuppressingJammingOrder_H)
#define AFX_SuppressingJammingOrder_H


//{{HDOSE_CLS_DES(CSuppressingJammingOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSuppressingJammingOrder /*ѹ�Ƹ���ָ��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSuppressingJammingOrder();
	virtual ~CSuppressingJammingOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSurfaceNo(long val){m_SurfaceNo=val;}
	long	GetSurfaceNo(){return m_SurfaceNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetJammingStyle(bool val){m_JammingStyle=val;}
	bool	GetJammingStyle(){return m_JammingStyle;}
	void	SetJammerChannelNo(long val){m_JammerChannelNo=val;}
	long	GetJammerChannelNo(){return m_JammerChannelNo;}
	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}
	void	SetJammingWaveform(long val){m_JammingWaveform=val;}
	long	GetJammingWaveform(){return m_JammingWaveform;}
	void	SetJammingPower(double val){m_JammingPower=val;}
	double	GetJammingPower(){return m_JammingPower;}

	//{{HDOSE_MEMBER_FUNCTION(CSuppressingJammingOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSuppressingJammingOrder)
	long	m_SurfaceNo/*��ͧ���*/;
	long	m_TargetNo/*Ŀ����*/;
	bool	m_JammingStyle/*������ʽ��0ѹ�ơ�1��ƭ��*/;
	long	m_JammerChannelNo/*����ͨ�����*/;
	bool	m_bPowerOn/*����ͨ������ָ�0�ء�1����*/;
	long	m_JammingWaveform/*���Ų��Σ�0ѹ�ơ�1�������壩*/;
	double	m_JammingPower/*���Ź���*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
