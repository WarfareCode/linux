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

class HYCGF_API CSensorOper /*����������*/ : public CTask 
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
	char	m_DeviceName[MAX_CHARLEN]/*�豸����*/;
	long	m_OperType/*��������(λ�������и����͵Ĳ���ָ��򽫸�λ��Ϊ1��00000000����8λ�ӵ͵�������Ϊ�����ػ����豸״̬��̽��ģʽ������ģʽ������ָ��)*/;
	bool	m_PowerOn/*���ػ�ָ�0�ء�1����*/;
	long	m_DetectMode/*̽��ģʽ����*/;
	long	m_WorkMode/*����ģʽ����*/;
	long	m_DeviceState/*�豸����״̬������0������1��������2��*/;
	double	m_AntennaAz/*���߷�λ��*/;
	double	m_AntennaEl/*���߸ߵͽ�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
