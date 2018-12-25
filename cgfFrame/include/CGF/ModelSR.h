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
Descript:	此状态池由模型来维护，负责发布、更新模型的动态数据
*/
//}}HDOSE_CLS_DES

#include "StateRepository.h"

class HYCGF_API CModelSR /*模型状态池*/ : public CNode 
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
	long	m_OwnerEntityID/*所有者实体ID*/;
	char	m_DeviceName[MAX_CHARLEN]/*模型设备名称*/;
	long	m_DeviceState/*模型设备状态（0良好、1故障、2）*/;
	bool	m_bPowerOn/*开关机（0/1）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
