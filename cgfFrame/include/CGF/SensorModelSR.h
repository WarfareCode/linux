//SensorModelSR.h: interface for the CSensorModelSR module.
//!!HDOSE_CLASS(CSensorModelSR,CModelSR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SensorModelSR_H)
#define AFX_SensorModelSR_H

#include "ModelSR.h"
#include "DetectDataStr.h"

//{{HDOSE_CLS_DES(CSensorModelSR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSensorModelSR /*������ģ��״̬��*/ : public CModelSR 
{
	DECLARE_CREATE;
public:
	CSensorModelSR();
	virtual ~CSensorModelSR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetPt(double val){m_Pt=val;}
	double	GetPt(){return m_Pt;}
	void	SetGt(double val){m_Gt=val;}
	double	GetGt(){return m_Gt;}
	void	SetFreq(double val){m_Freq=val;}
	double	GetFreq(){return m_Freq;}
	void	SetTu(double val){m_Tu=val;}
	double	GetTu(){return m_Tu;}
	void	SetPRF(double val){m_PRF=val;}
	double	GetPRF(){return m_PRF;}
	void	SetPulseModulationType(long val){m_PulseModulationType=val;}
	long	GetPulseModulationType(){return m_PulseModulationType;}
	void	SetWaveType(long val){m_WaveType=val;}
	long	GetWaveType(){return m_WaveType;}
	void	SetPolarization(long val){m_Polarization=val;}
	long	GetPolarization(){return m_Polarization;}
	void	SetDetectMode(long val){m_DetectMode=val;}
	long	GetDetectMode(){return m_DetectMode;}
	void	SetWorkMode(long val){m_WorkMode=val;}
	long	GetWorkMode(){return m_WorkMode;}
	void	SetAntennaAz(double val){m_AntennaAz=val;}
	double	GetAntennaAz(){return m_AntennaAz;}
	void	SetAntennaEl(double val){m_AntennaEl=val;}
	double	GetAntennaEl(){return m_AntennaEl;}
	void	SetBeamWidthHori(double val){m_BeamWidthHori=val;}
	double	GetBeamWidthHori(){return m_BeamWidthHori;}
	void	SetBeamWidthVert(double val){m_BeamWidthVert=val;}
	double	GetBeamWidthVert(){return m_BeamWidthVert;}
	void	SetScanPeriod(double val){m_ScanPeriod=val;}
	double	GetScanPeriod(){return m_ScanPeriod;}
	void	SetPulseDensity(double val){m_PulseDensity=val;}
	double	GetPulseDensity(){return m_PulseDensity;}
	void	SetAverageTransTime(double val){m_AverageTransTime=val;}
	double	GetAverageTransTime(){return m_AverageTransTime;}

	//{{HDOSE_MEMBER_FUNCTION(CSensorModelSR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSensorModelSR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSensorModelSR)
	double	m_Pt/*��ǰ����(KW)*/;
	double	m_Gt/*��������(dB)*/;
	double	m_Freq/*��ǰ����Ƶ��(Hz)*/;
	double	m_Tu/*��ǰ����(s)*/;
	double	m_PRF/*��ǰ��Ƶ(Hz)*/;
	long	m_PulseModulationType/*��ǰ���ڵ�������*/;
	long	m_WaveType/*��ǰ������*/;
	long	m_Polarization/*��ǰ������ʽ*/;
	long	m_DetectMode/*��ǰ̽��ģʽ*/;
	long	m_WorkMode/*��ǰ����ģʽ*/;
	double	m_AntennaAz/*��ǰ���߷�λ��(deg)*/;
	double	m_AntennaEl/*��ǰ���߸ߵͽ�(deg)*/;
	double	m_BeamWidthHori/*ˮƽ�������(deg)*/;
	double	m_BeamWidthVert/*��ֱ�������(deg)*/;
	double	m_ScanPeriod/*ɨ������(s)*/;
	double	m_PulseDensity/*�����������ܶ�(��/s)*/;
	double	m_AverageTransTime/*���η���ƽ��ʱ��(s)*/;

	bool	m_DetDataUpdate;// ������̽�����ݸ��£�0��1�ǣ�
	DA_CDetectDataStr m_DetData; // �����������̽������
	//}}HDOSE_ATTRIBUTE
};

#endif
