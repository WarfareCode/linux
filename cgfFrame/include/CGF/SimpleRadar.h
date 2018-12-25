//SimpleRadar.h: interface for the CSimpleRadar module.
//!!HDOSE_CLASS(CSimpleRadar,CRadar)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimpleRadar_H)
#define AFX_SimpleRadar_H

#include "Radar.h"

//{{HDOSE_CLS_DES(CSimpleRadar)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSimpleRadar /*���״�(HYCGF)*/ : public CRadar 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSimpleRadar();
	virtual ~CSimpleRadar();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetAntennaHeight(){return m_AntennaHeight;}
	double	GetBeamHorizonWidth(){return m_BeamHorizonWidth;}
	double	GetBeamVerticalWidth(){return m_BeamVerticalWidth;}
	double	GetMaxDetectAngle(){return m_MaxDetectAngle;}
	double	GetSpatialResolution(){return m_SpatialResolution;}
	double	GetScanPeriod(){return m_ScanPeriod;}
	double	GetTransmitterPower(){return m_TransmitterPower;}
	double	GetTransmitterGain(){return m_TransmitterGain;}
	double	GetSNRThreshold(){return m_SNRThreshold;}
	double	GetNoiseFigure(){return m_NoiseFigure;}
	double	GetReceiverAperture(){return m_ReceiverAperture;}
	double	GetCarrierFreq(){return m_CarrierFreq;}
	double	GetPulseWidth(){return m_PulseWidth;}
	double	GetRepetPeriod(){return m_RepetPeriod;}
	double	GetInitBeamPitch(){return m_InitBeamPitch;}
	double	GetInitBeamHeading(){return m_InitBeamHeading;}

	//{{HDOSE_MEMBER_FUNCTION(CSimpleRadar)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSimpleRadar)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSimpleRadar)
	double	m_AntennaHeight/*���߸߶�*/;
	double	m_BeamHorizonWidth/*�״ﲨ��ˮƽ��ȣ��ȣ�*/;
	double	m_BeamVerticalWidth/*�״ﲨ����ֱ��ȣ��ȣ�*/;
	double	m_MaxDetectAngle/*�������Ƕ�*/;
	double	m_SpatialResolution/*�ռ�ֱ���(m)*/;
	double	m_ScanPeriod/*ɨ������*/;
	double	m_TransmitterPower/*���书��*/;
	double	m_TransmitterGain/*��������*/;
	double	m_SNRThreshold/*SNR����ֵ(dB)*/;
	double	m_NoiseFigure/*����ֵ()*/;
	double	m_ReceiverAperture/*����������Ч�׾�*/;
	double	m_CarrierFreq/*��Ƶ*/;
	double	m_PulseWidth/*����*/;
	double	m_RepetPeriod/*�ظ�����*/;
	double	m_InitBeamPitch/*��ʼ��ֱָ�򣨶ȣ�����Ϊ0����˳ʱ�뷽��Ϊ����0-360�ȣ�*/;
	double	m_InitBeamHeading/*��ʼ��λָ�򣨶ȣ��뵱��ˮƽ��ƽ��Ϊ0�ȣ�����Ϊ��������Ϊ����*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSimpleRadar)
	//}}HDOSE_ATTRIBUTE
};

#endif
