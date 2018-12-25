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

class DATASTRUCTCOMPONENTDLL_API CSupressionJammerWorkParams /*ѹ�Ƹ�������������*/ : public CEvt 
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
	long	m_TargetNo/*Ŀ����*/;
	long	m_JammerChannelNo/*����ͨ�����*/;
	long	m_JammingStyle/*������ʽ��0ѹ�ơ�1��ƭ��*/;
	long	m_JammingWaveform/*���Ų��Σ�0ѹ�ơ�1�������壩*/;
	double	m_JammingPower/*���Ź���*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
