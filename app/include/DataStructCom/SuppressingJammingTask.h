//SuppressingJammingTask.h: interface for the CSuppressingJammingTask module.
//!!HDOSE_CLASS(CSuppressingJammingTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SuppressingJammingTask_H)
#define AFX_SuppressingJammingTask_H


//{{HDOSE_CLS_DES(CSuppressingJammingTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSuppressingJammingTask /*ѹ�Ƹ�������*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CSuppressingJammingTask();
	virtual ~CSuppressingJammingTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSurfaceNo(long val){m_SurfaceNo=val;}
	long	GetSurfaceNo(){return m_SurfaceNo;}
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
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}

	//{{HDOSE_MEMBER_FUNCTION(CSuppressingJammingTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSuppressingJammingTask)
	long	m_SurfaceNo/*��ͧ���*/;
	long	m_TargetNo/*Ŀ����*/;
	long	m_JammerChannelNo/*����ͨ�����*/;
	bool	m_bPowerOn/*����ͨ������ָ�0�ء�1����*/;
	long	m_JammingStyle/*������ʽ��0ѹ�ơ�1��ƭ��*/;
	long	m_JammingWaveform/*���Ų��Σ�0ѹ�ơ�1�������壩*/;
	double	m_JammingPower/*���Ź���*/;
	long	m_ForceType/*��������ʶ��0����1�죩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
