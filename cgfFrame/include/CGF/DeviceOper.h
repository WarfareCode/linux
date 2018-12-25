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
Descript:	���ڲ����豸���ػ�������ģʽ��
*/
//}}HDOSE_CLS_DES

class HYCGF_API CDeviceOper /*�豸����ָ��*/ : public CTask
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
	char*	m_DeviceName/*�豸����*/;
	int	m_OperType/*��������(λ�������и����͵Ĳ���ָ��򽫸�λ��Ϊ1��00000000����8λ�ӵ͵�������Ϊ�����ػ����豸״̬������ģʽ)*/;
	bool	m_PowerOn/*���ػ�ָ�0�ء�1����*/;
	int	m_DeviceState/*�豸����״̬������0������1��������2��*/;
	int	m_WorkMode/*����ģʽ����*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
