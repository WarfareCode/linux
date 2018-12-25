//ESM.h: interface for the CESM module.
//!!HDOSE_CLASS(CESM,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ESM_H)
#define AFX_ESM_H

#include "Sensor.h"
#include "DataRange.h"

//{{HDOSE_CLS_DES(CESM)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CESM /*电子侦察告警(HYCGF)*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CESM();
	virtual ~CESM();
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
	long	GetFreqBandCount(){return m_FreqBandCount;}
	//CDataRange	GetFreqBand(){return m_FreqBand;}
	long	GetESMSignalTypeCount(){return m_ESMSignalTypeCount;}
	//long	GetESMSignalType(){return m_ESMSignalType;}
	long	GetESMPulseModulationTypeCount(){return m_ESMPulseModulationTypeCount;}
	//long	GetESMPulseModulationType(){return m_ESMPulseModulationType;}
	CDataRange	GetPRFBand(){return m_PRFBand;}
	double	GetB(){return m_B;}
	double	GetG(){return m_G;}
	double	GetBeamWidth(){return m_BeamWidth;}
	double	GetReceiverSensitivity(){return m_ReceiverSensitivity;}
	double	GetSystemSensitivity(){return m_SystemSensitivity;}
	long	GetAntennaPolaritionMode(){return m_AntennaPolaritionMode;}
	long	GetAntennaScanType(){return m_AntennaScanType;}
	double	GetAntennaInitialAz(){return m_AntennaInitialAz;}
	double	GetAntennaInitialEl(){return m_AntennaInitialEl;}
	double	GetAntennaScanPeriod(){return m_AntennaScanPeriod;}
	double	GetAntennaScaningSpeed(){return m_AntennaScaningSpeed;}
	double	GetAntennaTrackingSpeed(){return m_AntennaTrackingSpeed;}
	double	Getpfa(){return m_pfa;}
	double	Getpd(){return m_pd;}
	double	GetdataRate(){return m_dataRate;}
	double	GetTimeSearch2Track(){return m_TimeSearch2Track;}
	double	GetTimeTrackClear(){return m_TimeTrackClear;}
	double	Getpb_TypeRecognition(){return m_pb_TypeRecognition;}
	double	Getpb_UnitRecognition(){return m_pb_UnitRecognition;}
	double	GetMeasureError_Freq(){return m_MeasureError_Freq;}
	double	GetMeasureError_Tu(){return m_MeasureError_Tu;}
	double	GetMeasureError_PRF(){return m_MeasureError_PRF;}
	double	GetSignalDensity(){return m_SignalDensity;}
	double	GetMaxDealCount(){return m_MaxDealCount;}
	double	GetMeasureError_Orient(){return m_MeasureError_Orient;}
	double	GetMeasureError_FastLocation(){return m_MeasureError_FastLocation;}
	double	GetMeasureError_CrossLocation(){return m_MeasureError_CrossLocation;}
	long	GetDataBaseCapacity(){return m_DataBaseCapacity;}
	long	GetmaxSearchTargetsCount(){return m_maxSearchTargetsCount;}
	long	GetmaxTrackTargetsCount(){return m_maxTrackTargetsCount;}
	long	GetmaxDealTargetsCount(){return m_maxDealTargetsCount;}
	long	GetfirstBatchNo(){return m_firstBatchNo;}

	//{{HDOSE_MEMBER_FUNCTION(CESM)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CESM)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CESM)
	long	m_DetectModeCount/*探测模式种类数量*/;
	long	m_DetectMode[MAXLongCount]/*探测模式类型（数组）*/;
	long	m_WorkModeCount/*工作模式种类数量*/;
	long	m_WorkMode[MAXLongCount]/*工作模式类型（数组）*/;
	long	m_FreqBandCount/*检测频段数量*/;
	CDataRange	m_FreqBand[MAXLongCount]/*检测频段[数组]（用最小、最大范围表示）(Hz)*/;
	long	m_ESMSignalTypeCount/*侦察信号类型数量*/;
	long	m_ESMSignalType[MAXLongCount]/*侦察信号类型[数组]（常规脉冲、频率捷变、频率分集、重频抖动、重频参差、脉冲压缩、脉冲多普勒、连续波）*/;
	long	m_ESMPulseModulationTypeCount/*侦察脉内调制类型数量*/;
	long	m_ESMPulseModulationType[MAXLongCount]/*侦察脉内调制类型[数组]（二相码、四机码、线性调频、自动分析）*/;
	CDataRange	m_PRFBand/*重复频率测量范围（Hz）*/;
	double	m_B/*带宽（Hz）*/;
	double	m_G/*接收天线增益（dB）*/;
	double	m_BeamWidth/*接收天线波束宽度(deg)*/;
	double	m_ReceiverSensitivity/*接收机灵敏度（dBW）*/;
	double	m_SystemSensitivity/*系统灵敏度（dBW）*/;
	long	m_AntennaPolaritionMode/*天线极化方式（极化适应性）*/;
	long	m_AntennaScanType/*天线扫描类型*/;
	double	m_AntennaInitialAz/*天线起始方位角(deg)*/;
	double	m_AntennaInitialEl/*天线起始高低角(deg)*/;
	double	m_AntennaScanPeriod/*天线扫描周期(s)*/;
	double	m_AntennaScaningSpeed/*天线扫描速度(deg/s)*/;
	double	m_AntennaTrackingSpeed/*天线跟踪速度(deg/s)*/;
	double	m_pfa/*虚警率*/;
	double	m_pd/*截获概率*/;
	double	m_dataRate/*数据率(s)*/;
	double	m_TimeSearch2Track/*搜索转跟踪时间(s)*/;
	double	m_TimeTrackClear/*目标航迹清理时间(s)*/;
	double	m_pb_TypeRecognition/*型号识别正确率*/;
	double	m_pb_UnitRecognition/*辐射源个体识别正确率*/;
	double	m_MeasureError_Freq/*频率测量精度（Hz）*/;
	double	m_MeasureError_Tu/*脉宽测量精度（us）*/;
	double	m_MeasureError_PRF/*重频测量精度（ns）*/;
	double	m_SignalDensity/*信号密度(个脉冲/秒)*/;
	double	m_MaxDealCount/*最大同时处理数量*/;
	double	m_MeasureError_Orient/*测向精度(deg)*/;
	double	m_MeasureError_FastLocation/*快速定位精度(km)*/;
	double	m_MeasureError_CrossLocation/*交叉定位精度(km)*/;
	long	m_DataBaseCapacity/*数据库容量*/;
	long	m_maxSearchTargetsCount/*最大搜索目标批数*/;
	long	m_maxTrackTargetsCount/*最大跟踪目标批数*/;
	long	m_maxDealTargetsCount/*最大处理目标批数*/;
	long	m_firstBatchNo/*起始批号*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CESM)
	//}}HDOSE_ATTRIBUTE
};

#endif
