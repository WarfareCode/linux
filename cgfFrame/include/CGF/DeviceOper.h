//DeviceOper.h: interface for the CDeviceOper module.
//!!HDOSE_CLASS(CDeviceOper,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DeviceOper_H)
#define AFX_DeviceOper_H

#include "Task.h"

//{{HDOSE_CLS_DES(CDeviceOper)
/*
Author:		xks
Version:	1.0
Descript:	用于操作设备开关机、工作模式等
*/
//}}HDOSE_CLS_DES

class HYCGF_API CDeviceOper /*设备操作指令*/ : public CTask
{
	DECLARE_CREATE;
public:
	CDeviceOper();
	virtual ~CDeviceOper();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetDeviceName(char* val){SetValueString("DeviceName",val);}
	char*	GetDeviceName(){return GetValueString("DeviceName");}
	void	SetOperType(int val){m_OperType=val;}
	int	GetOperType(){return m_OperType;}
	void	SetPowerOn(bool val){m_PowerOn=val;}
	bool	GetPowerOn(){return m_PowerOn;}
	void	SetDeviceState(int val){m_DeviceState=val;}
	int	GetDeviceState(){return m_DeviceState;}
	void	SetWorkMode(int val){m_WorkMode=val;}
	int	GetWorkMode(){return m_WorkMode;}

	//{{HDOSE_MEMBER_FUNCTION(CDeviceOper)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CDeviceOper)
	char*	m_DeviceName/*设备名称*/;
	int	m_OperType/*操作类型(位操作，有该类型的操作指令，则将该位置为1，00000000，后8位从低到高依次为，开关机、设备状态、工作模式)*/;
	bool	m_PowerOn/*开关机指令（0关、1开）*/;
	int	m_DeviceState/*设备工作状态（良好0，故障1，降功能2）*/;
	int	m_WorkMode/*工作模式类型*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
