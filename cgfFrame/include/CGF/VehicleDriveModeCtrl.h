//VehicleDriveModeCtrl.h: interface for the CVehicleDriveModeCtrl module.
//!!HDOSE_CLASS(CVehicleDriveModeCtrl,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_VehicleDriveModeCtrl_H)
#define AFX_VehicleDriveModeCtrl_H

#include "Task.h"

//{{HDOSE_CLS_DES(CVehicleDriveModeCtrl)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CVehicleDriveModeCtrl /*车辆驾驶模式控制*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CVehicleDriveModeCtrl();
	virtual ~CVehicleDriveModeCtrl();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetManualDriveMode(int val){m_ManualDriveMode=val;}
	int	GetManualDriveMode(){return m_ManualDriveMode;}
	void	SetFireCtrlMode(int val){m_FireCtrlMode=val;}
	int	GetFireCtrlMode(){return m_FireCtrlMode;}

	//{{HDOSE_MEMBER_FUNCTION(CVehicleDriveModeCtrl)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CVehicleDriveModeCtrl)
	int	m_ManualDriveMode/*人工或自动驾驶模式(0自动、1人工，默认为0)*/;
	int	m_FireCtrlMode/*火控模式（0关闭、1开启，默认为0）*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
