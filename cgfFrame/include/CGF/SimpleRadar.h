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

class HYCGF_API CSimpleRadar /*简单雷达(HYCGF)*/ : public CRadar 
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
	double	m_AntennaHeight/*天线高度*/;
	double	m_BeamHorizonWidth/*雷达波束水平宽度（度）*/;
	double	m_BeamVerticalWidth/*雷达波束垂直宽度（度）*/;
	double	m_MaxDetectAngle/*最大扇面角度*/;
	double	m_SpatialResolution/*空间分辨率(m)*/;
	double	m_ScanPeriod/*扫描周期*/;
	double	m_TransmitterPower/*发射功率*/;
	double	m_TransmitterGain/*发射增益*/;
	double	m_SNRThreshold/*SNR门限值(dB)*/;
	double	m_NoiseFigure/*噪声值()*/;
	double	m_ReceiverAperture/*接收天线有效孔径*/;
	double	m_CarrierFreq/*载频*/;
	double	m_PulseWidth/*脉宽*/;
	double	m_RepetPeriod/*重复周期*/;
	double	m_InitBeamPitch/*初始垂直指向（度，正北为0，沿顺时针方向为正，0-360度）*/;
	double	m_InitBeamHeading/*初始方位指向（度，与当地水平面平行为0度，向下为负，向上为正）*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSimpleRadar)
	//}}HDOSE_ATTRIBUTE
};

#endif
