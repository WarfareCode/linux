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

class HYCGF_API CVehicleDriveModeCtrl /*������ʻģʽ����*/ : public CTask 
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
	int	m_ManualDriveMode/*�˹����Զ���ʻģʽ(0�Զ���1�˹���Ĭ��Ϊ0)*/;
	int	m_FireCtrlMode/*���ģʽ��0�رա�1������Ĭ��Ϊ0��*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
