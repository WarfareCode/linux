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

class HYCGF_API CESM /*�������澯(HYCGF)*/ : public CSensor 
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
	long	m_DetectModeCount/*̽��ģʽ��������*/;
	long	m_DetectMode[MAXLongCount]/*̽��ģʽ���ͣ����飩*/;
	long	m_WorkModeCount/*����ģʽ��������*/;
	long	m_WorkMode[MAXLongCount]/*����ģʽ���ͣ����飩*/;
	long	m_FreqBandCount/*���Ƶ������*/;
	CDataRange	m_FreqBand[MAXLongCount]/*���Ƶ��[����]������С�����Χ��ʾ��(Hz)*/;
	long	m_ESMSignalTypeCount/*����ź���������*/;
	long	m_ESMSignalType[MAXLongCount]/*����ź�����[����]���������塢Ƶ�ʽݱ䡢Ƶ�ʷּ�����Ƶ��������Ƶ�β����ѹ������������ա���������*/;
	long	m_ESMPulseModulationTypeCount/*������ڵ�����������*/;
	long	m_ESMPulseModulationType[MAXLongCount]/*������ڵ�������[����]�������롢�Ļ��롢���Ե�Ƶ���Զ�������*/;
	CDataRange	m_PRFBand/*�ظ�Ƶ�ʲ�����Χ��Hz��*/;
	double	m_B/*����Hz��*/;
	double	m_G/*�����������棨dB��*/;
	double	m_BeamWidth/*�������߲������(deg)*/;
	double	m_ReceiverSensitivity/*���ջ������ȣ�dBW��*/;
	double	m_SystemSensitivity/*ϵͳ�����ȣ�dBW��*/;
	long	m_AntennaPolaritionMode/*���߼�����ʽ��������Ӧ�ԣ�*/;
	long	m_AntennaScanType/*����ɨ������*/;
	double	m_AntennaInitialAz/*������ʼ��λ��(deg)*/;
	double	m_AntennaInitialEl/*������ʼ�ߵͽ�(deg)*/;
	double	m_AntennaScanPeriod/*����ɨ������(s)*/;
	double	m_AntennaScaningSpeed/*����ɨ���ٶ�(deg/s)*/;
	double	m_AntennaTrackingSpeed/*���߸����ٶ�(deg/s)*/;
	double	m_pfa/*�龯��*/;
	double	m_pd/*�ػ����*/;
	double	m_dataRate/*������(s)*/;
	double	m_TimeSearch2Track/*����ת����ʱ��(s)*/;
	double	m_TimeTrackClear/*Ŀ�꺽������ʱ��(s)*/;
	double	m_pb_TypeRecognition/*�ͺ�ʶ����ȷ��*/;
	double	m_pb_UnitRecognition/*����Դ����ʶ����ȷ��*/;
	double	m_MeasureError_Freq/*Ƶ�ʲ������ȣ�Hz��*/;
	double	m_MeasureError_Tu/*����������ȣ�us��*/;
	double	m_MeasureError_PRF/*��Ƶ�������ȣ�ns��*/;
	double	m_SignalDensity/*�ź��ܶ�(������/��)*/;
	double	m_MaxDealCount/*���ͬʱ��������*/;
	double	m_MeasureError_Orient/*���򾫶�(deg)*/;
	double	m_MeasureError_FastLocation/*���ٶ�λ����(km)*/;
	double	m_MeasureError_CrossLocation/*���涨λ����(km)*/;
	long	m_DataBaseCapacity/*���ݿ�����*/;
	long	m_maxSearchTargetsCount/*�������Ŀ������*/;
	long	m_maxTrackTargetsCount/*������Ŀ������*/;
	long	m_maxDealTargetsCount/*�����Ŀ������*/;
	long	m_firstBatchNo/*��ʼ����*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CESM)
	//}}HDOSE_ATTRIBUTE
};

#endif
