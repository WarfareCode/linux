//ModelSR.h: interface for the CModelSR module.
//!!HDOSE_CLASS(CModelSR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ModelSR_H)
#define AFX_ModelSR_H

//{{HDOSE_CLS_DES(CModelSR)
/*
Author:		
Version:	1.0
Descript:	��״̬����ģ����ά�������𷢲�������ģ�͵Ķ�̬����
*/
//}}HDOSE_CLS_DES

#include "StateRepository.h"

class HYCGF_API CModelSR /*ģ��״̬��*/ : public CNode 
{
	DECLARE_CREATE;
public:
	CModelSR();
	virtual ~CModelSR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetOwnerEntityID(long val){m_OwnerEntityID=val;}
	long	GetOwnerEntityID(){return m_OwnerEntityID;}
	void	SetDeviceName(char* val){strcpy(m_DeviceName,val);}
	char*	GetDeviceName(){return m_DeviceName;}
	void	SetDeviceState(long val){m_DeviceState=val;}
	long	GetDeviceState(){return m_DeviceState;}
	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}

	//{{HDOSE_MEMBER_FUNCTION(CModelSR)
	//}}HDOSE_MEMBER_FUNCTION

	// xks,20161129
	CStateRepository* GetEntSR()
	{
		CStateRepository* pEntSR = (CStateRepository*) ((CNode*) ( (CNode*)m_parent)->m_parent)->m_pSr;
		if(pEntSR)
		{
			return pEntSR;
		}
		return NULL;
	}

public:
		
	//{{HDOSE_PARAMETER(CModelSR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CModelSR)
	long	m_OwnerEntityID/*������ʵ��ID*/;
	char	m_DeviceName[MAX_CHARLEN]/*ģ���豸����*/;
	long	m_DeviceState/*ģ���豸״̬��0���á�1���ϡ�2��*/;
	bool	m_bPowerOn/*���ػ���0/1��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
