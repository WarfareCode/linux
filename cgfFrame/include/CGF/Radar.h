//Radar.h: interface for the CRadar module.
//!!HDOSE_CLASS(CRadar,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Radar_H)
#define AFX_Radar_H

#include "Sensor.h"
#include "StateRepository.h"
#include "SensorModelSR.h"

//{{HDOSE_CLS_DES(CRadar)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CRadar /*�״�(HYCGF)*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CRadar();
	virtual ~CRadar();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	long	GetDetectModeCount(){return m_DetectModeCount;}
	//long	GetDetectMode(){return m_DetectMode;}
	long	GetWorkModeCount(){return m_WorkModeCount;}
	//long	GetWorkMode(){return m_WorkMode;}
	double	GetDistResolution(){return m_DistResolution;}
	double	GetAngleResolution(){return m_AngleResolution;}
	double	GetBeamHorizonWidth(){return m_BeamHorizonWidth;}
	double	GetBeamVerticalWidth(){return m_BeamVerticalWidth;}
	long	GetFreqBandCount(){return m_FreqBandCount;}
	//long	GetFreqBand(){return m_FreqBand;}
	double	Getpt(){return m_pt;}
	double	Getfreq(){return m_freq;}
	double	Getg(){return m_g;}
	double	Gette(){return m_te;}
	double	Getb(){return m_b;}
	double	Getnf(){return m_nf;}
	double	Getloss(){return m_loss;}
	double	GetTu(){return m_Tu;}
	double	GetPRF(){return m_PRF;}
	long	GetPulseModulationType(){return m_PulseModulationType;}
	long	GetWaveType(){return m_WaveType;}
	long	GetPulsIntegrationNum(){return m_PulsIntegrationNum;}
	double	GetPulseIntegrationEff(){return m_PulseIntegrationEff;}
	double	GetPulseDensity(){return m_PulseDensity;}
	double	GetAverageTransTime(){return m_AverageTransTime;}
	long	GetAntennaScanType(){return m_AntennaScanType;}
	double	GetAntennaInitialAz(){return m_AntennaInitialAz;}
	double	GetAntennaInitialEl(){return m_AntennaInitialEl;}
	double	GetAntennaScanPeriod(){return m_AntennaScanPeriod;}
	double	GetAntennaScaningSpeed(){return m_AntennaScaningSpeed;}
	double	GetAntennaTrackingSpeed(){return m_AntennaTrackingSpeed;}
	long	GetPolarizationMode(){return m_PolarizationMode;}
	double	Getpfa(){return m_pfa;}
	long	Getnfa(){return m_nfa;}
	double	Getpd(){return m_pd;}
	double	GetdataRate(){return m_dataRate;}
	double	GetTimeSearch2Track(){return m_TimeSearch2Track;}
	double	GetTimeTrackClear(){return m_TimeTrackClear;}
	long	GetmaxSearchTargetsCount(){return m_maxSearchTargetsCount;}
	long	GetmaxTrackTargetsCount(){return m_maxTrackTargetsCount;}
	long	GetmaxGuideTargetsCount(){return m_maxGuideTargetsCount;}
	long	GetmaxDealTargetsCount(){return m_maxDealTargetsCount;}
	long	GetfirstBatchNo(){return m_firstBatchNo;}
	double	GetJamDetectEffect(){return m_JamDetectEffect;}
	double	GetJamTrackEffect(){return m_JamTrackEffect;}

	//{{HDOSE_MEMBER_FUNCTION(CRadar)
	//}}HDOSE_MEMBER_FUNCTION

	virtual void InitSetEntID()
	{
		if(m_OwnerEntityID>0)		return; // ����Ѿ������˲������򷵻�

		m_OwnerEntityID = GetStateRepository()->GetID();
		CSensorModelSR* pMdSR =(CSensorModelSR*) GetModelSR();
		if(pMdSR)
		{
			pMdSR->SetOwnerEntityID(m_OwnerEntityID);
			pMdSR->SetDeviceName(m_DeviceName);

			pMdSR->SetPt(m_pt);/*��ǰ����*/
			pMdSR->SetGt(m_g)/*��������*/;
			pMdSR->SetFreq(m_freq)/*��ǰ����Ƶ��*/;
			pMdSR->SetTu(m_Tu)/*��ǰ����*/;
			pMdSR->SetPRF(m_PRF)/*��ǰ��Ƶ*/;
			pMdSR->SetPulseModulationType(m_PulseModulationType)/*��ǰ���ڵ�������*/;
			pMdSR->SetWaveType(m_WaveType)/*��ǰ������*/;
			pMdSR->SetPolarization(m_PolarizationMode)/*��ǰ������ʽ*/;
			pMdSR->SetDetectMode(0)/*��ǰ̽��ģʽ*/;
			pMdSR->SetWorkMode(0)/*��ǰ����ģʽ*/;
			pMdSR->SetAntennaAz(m_AntennaInitialAz)/*��ǰ���߷�λ��*/;
			pMdSR->SetAntennaEl(m_AntennaInitialEl)/*��ǰ���߸ߵͽ�*/;
			pMdSR->SetBeamWidthHori(m_BeamHorizonWidth)/*ˮƽ�������*/;
			pMdSR->SetBeamWidthVert(m_BeamVerticalWidth)/*��ֱ�������*/;
			pMdSR->SetScanPeriod(m_AntennaScanPeriod); /*ɨ������*/
			pMdSR->SetPulseDensity(m_PulseDensity);/*���巢���ܶȣ���/s��*/
			pMdSR->SetAverageTransTime(m_AverageTransTime);/*ƽ����������*/

		}

	}

protected:
	//{{HDOSE_EVENT_HANDLER(CRadar)
	//}}HDOSE_EVENT_HANDLER

public:
		
	//{{HDOSE_PARAMETER(CRadar)
	long	m_DetectModeCount/*̽��ģʽ��������*/;
	long	m_DetectMode[MAXLongCount]/*̽��ģʽ���ͣ����飩, ','*/;
	long	m_WorkModeCount/*����ģʽ��������*/;
	long	m_WorkMode[MAXLongCount]/*����ģʽ���ͣ����飩, ','*/;
	double	m_DistResolution/*����ֱ���(m)*/;
	double	m_AngleResolution/*�Ƕȷֱ��ʣ�deg��*/;
	double	m_BeamHorizonWidth/*ˮƽ������ȣ�deg��*/;
	double	m_BeamVerticalWidth/*��ֱ������ȣ�deg��*/;
	long	m_FreqBandCount/*����Ƶ������*/;
	long	m_FreqBand[MAXLongCount]/*����Ƶ�Σ����飩, ','*/;
	double	m_pt/*��ֵ����KW*/;
	double	m_freq/*����Ƶ��Hz*/;
	double	m_g/*����dB*/;
	double	m_te/*ϵͳ�¶�K*/;
	double	m_b/*����Hz*/;
	double	m_nf/*����ϵ��dB*/;
	double	m_loss/*�״����dB*/;
	double	m_Tu/*����(s)*/;
	double	m_PRF/*��Ƶ(Hz)*/;
	long	m_PulseModulationType/*���ڵ�������*/;
	long	m_WaveType/*�״ﲨ�Σ����塢������*/;
	long	m_PulsIntegrationNum/*���������*/;
	double	m_PulseIntegrationEff/*�������Ч��*/;
	double	m_PulseDensity/*�����������ܶ�(��/s)*/;
	double	m_AverageTransTime/*���η���ƽ��ʱ�䣨s��*/;
	long	m_AntennaScanType/*����ɨ�跽ʽ*/;
	double	m_AntennaInitialAz/*������ʼ��λ��(deg)*/;
	double	m_AntennaInitialEl/*������ʼ�ߵͽ�(deg)*/;
	double	m_AntennaScanPeriod/*����ɨ������(s)*/;
	double	m_AntennaScaningSpeed/*����ɨ���ٶ�(deg/s)*/;
	double	m_AntennaTrackingSpeed/*���߸����ٶ�(deg/s)*/;
	long	m_PolarizationMode/*���߼�����ʽ*/;
	double	m_pfa/*�龯��*/;
	long	m_nfa/*�龯��*/;
	double	m_pd/*̽�����*/;
	double	m_dataRate/*������s*/;
	double	m_TimeSearch2Track/*����ת����ʱ��(s)*/;
	double	m_TimeTrackClear/*Ŀ�꺽������ʱ��(s)*/;
	long	m_maxSearchTargetsCount/*�������Ŀ������*/;
	long	m_maxTrackTargetsCount/*������Ŀ������*/;
	long	m_maxGuideTargetsCount/*����Ƶ�Ŀ������*/;
	long	m_maxDealTargetsCount/*�����Ŀ������*/;
	long	m_firstBatchNo/*��ʼ����*/;
	double	m_JamDetectEffect/*�����ź�̽������½����ӣ���ѹ�Ƹ��ź�̽������Ϊԭ����x��*/;
	double	m_JamTrackEffect/*�����ź���پ����½����ӣ���ѹ�Ƹ��ź󣬸��پ����Ϊԭ����x��*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRadar)
	//}}HDOSE_ATTRIBUTE
};

#endif
