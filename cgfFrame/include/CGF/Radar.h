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

class HYCGF_API CRadar /*雷达(HYCGF)*/ : public CSensor 
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
		if(m_OwnerEntityID>0)		return; // 如果已经设置了参数，则返回

		m_OwnerEntityID = GetStateRepository()->GetID();
		CSensorModelSR* pMdSR =(CSensorModelSR*) GetModelSR();
		if(pMdSR)
		{
			pMdSR->SetOwnerEntityID(m_OwnerEntityID);
			pMdSR->SetDeviceName(m_DeviceName);

			pMdSR->SetPt(m_pt);/*当前功率*/
			pMdSR->SetGt(m_g)/*发射增益*/;
			pMdSR->SetFreq(m_freq)/*当前工作频率*/;
			pMdSR->SetTu(m_Tu)/*当前脉宽*/;
			pMdSR->SetPRF(m_PRF)/*当前重频*/;
			pMdSR->SetPulseModulationType(m_PulseModulationType)/*当前脉内调制类型*/;
			pMdSR->SetWaveType(m_WaveType)/*当前波类型*/;
			pMdSR->SetPolarization(m_PolarizationMode)/*当前极化方式*/;
			pMdSR->SetDetectMode(0)/*当前探测模式*/;
			pMdSR->SetWorkMode(0)/*当前工作模式*/;
			pMdSR->SetAntennaAz(m_AntennaInitialAz)/*当前天线方位角*/;
			pMdSR->SetAntennaEl(m_AntennaInitialEl)/*当前天线高低角*/;
			pMdSR->SetBeamWidthHori(m_BeamHorizonWidth)/*水平波束宽度*/;
			pMdSR->SetBeamWidthVert(m_BeamVerticalWidth)/*垂直波束宽度*/;
			pMdSR->SetScanPeriod(m_AntennaScanPeriod); /*扫描周期*/
			pMdSR->SetPulseDensity(m_PulseDensity);/*脉冲发射密度（个/s）*/
			pMdSR->SetAverageTransTime(m_AverageTransTime);/*平均发射周期*/

		}

	}

protected:
	//{{HDOSE_EVENT_HANDLER(CRadar)
	//}}HDOSE_EVENT_HANDLER

public:
		
	//{{HDOSE_PARAMETER(CRadar)
	long	m_DetectModeCount/*探测模式种类数量*/;
	long	m_DetectMode[MAXLongCount]/*探测模式类型（数组）, ','*/;
	long	m_WorkModeCount/*工作模式种类数量*/;
	long	m_WorkMode[MAXLongCount]/*工作模式类型（数组）, ','*/;
	double	m_DistResolution/*距离分辨率(m)*/;
	double	m_AngleResolution/*角度分辨率（deg）*/;
	double	m_BeamHorizonWidth/*水平波束宽度（deg）*/;
	double	m_BeamVerticalWidth/*垂直波束宽度（deg）*/;
	long	m_FreqBandCount/*工作频段数量*/;
	long	m_FreqBand[MAXLongCount]/*工作频段（数组）, ','*/;
	double	m_pt/*峰值功率KW*/;
	double	m_freq/*工作频率Hz*/;
	double	m_g/*增益dB*/;
	double	m_te/*系统温度K*/;
	double	m_b/*带宽Hz*/;
	double	m_nf/*噪声系数dB*/;
	double	m_loss/*雷达损耗dB*/;
	double	m_Tu/*脉宽(s)*/;
	double	m_PRF/*重频(Hz)*/;
	long	m_PulseModulationType/*脉内调制类型*/;
	long	m_WaveType/*雷达波形（脉冲、连续）*/;
	long	m_PulsIntegrationNum/*脉冲积累数*/;
	double	m_PulseIntegrationEff/*脉冲积累效率*/;
	double	m_PulseDensity/*发射脉冲流密度(个/s)*/;
	double	m_AverageTransTime/*单次发射平均时间（s）*/;
	long	m_AntennaScanType/*天线扫描方式*/;
	double	m_AntennaInitialAz/*天线起始方位角(deg)*/;
	double	m_AntennaInitialEl/*天线起始高低角(deg)*/;
	double	m_AntennaScanPeriod/*天线扫描周期(s)*/;
	double	m_AntennaScaningSpeed/*天线扫描速度(deg/s)*/;
	double	m_AntennaTrackingSpeed/*天线跟踪速度(deg/s)*/;
	long	m_PolarizationMode/*天线极化方式*/;
	double	m_pfa/*虚警率*/;
	long	m_nfa/*虚警数*/;
	double	m_pd/*探测概率*/;
	double	m_dataRate/*数据率s*/;
	double	m_TimeSearch2Track/*搜索转跟踪时间(s)*/;
	double	m_TimeTrackClear/*目标航迹清理时间(s)*/;
	long	m_maxSearchTargetsCount/*最大搜索目标批数*/;
	long	m_maxTrackTargetsCount/*最大跟踪目标批数*/;
	long	m_maxGuideTargetsCount/*最大制导目标批数*/;
	long	m_maxDealTargetsCount/*最大处理目标批数*/;
	long	m_firstBatchNo/*起始批号*/;
	double	m_JamDetectEffect/*被干扰后探测距离下降因子（被压制干扰后，探测距离变为原来的x）*/;
	double	m_JamTrackEffect/*被干扰后跟踪距离下降因子（被压制干扰后，跟踪距离变为原来的x）*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRadar)
	//}}HDOSE_ATTRIBUTE
};

#endif
