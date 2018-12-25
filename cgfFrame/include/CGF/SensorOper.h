//SensorOper.h: interface for the CSensorOper module.
//!!HDOSE_CLASS(CSensorOper,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SensorOper_H)
#define AFX_SensorOper_H


//{{HDOSE_CLS_DES(CSensorOper)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CSensorOper /*传感器操作*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CSensorOper();
	virtual ~CSensorOper();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetDeviceName(char* val){strcpy(m_DeviceName,val);}
	char*	GetDeviceName(){return m_DeviceName;}
	void	SetOperType(long val){m_OperType=val;}
	long	GetOperType(){return m_OperType;}
	void	SetPowerOn(bool val){m_PowerOn=val;}
	bool	GetPowerOn(){return m_PowerOn;}
	void	SetDetectMode(long val){m_DetectMode=val;}
	long	GetDetectMode(){return m_DetectMode;}
	void	SetWorkMode(long val){m_WorkMode=val;}
	long	GetWorkMode(){return m_WorkMode;}
	void	SetDeviceState(long val){m_DeviceState=val;}
	long	GetDeviceState(){return m_DeviceState;}
	void	SetAntennaAz(double val){m_AntennaAz=val;}
	double	GetAntennaAz(){return m_AntennaAz;}
	void	SetAntennaEl(double val){m_AntennaEl=val;}
	double	GetAntennaEl(){return m_AntennaEl;}

	//{{HDOSE_MEMBER_FUNCTION(CSensorOper)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSensorOper)
	char	m_DeviceName[MAX_CHARLEN]/*设备名称*/;
	long	m_OperType/*操作类型(位操作，有该类型的操作指令，则将该位置为1，00000000，后8位从低到高依次为，开关机、设备状态、探测模式、工作模式、天线指向)*/;
	bool	m_PowerOn/*开关机指令（0关、1开）*/;
	long	m_DetectMode/*探测模式类型*/;
	long	m_WorkMode/*工作模式类型*/;
	long	m_DeviceState/*设备工作状态（良好0，故障1，降功能2）*/;
	double	m_AntennaAz/*天线方位角*/;
	double	m_AntennaEl/*天线高低角*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
