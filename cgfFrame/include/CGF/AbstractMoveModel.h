//AbstractMoveModel.h: interface for the CAbstractMoveModel module.
//!!HDOSE_CLASS(CAbstractMoveModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AbstractMoveModel_H)
#define AFX_AbstractMoveModel_H

#include "Model.h"

#include "MoveTo.h"
#include "MoveAlong.h"
#include "Patrol.h"
#include "Wait.h"
#include "Follow.h"
#include "Cruise.h"
#include "ReturnBase.h"
#include "LandingOn.h"
#include "TakeOff.h"
#include "ThrottleCtrlOper.h"
#include "AttitudeCtrlOper.h"
#include "VehicleDriveModeCtrl.h"

//{{HDOSE_CLS_DES(CAbstractMoveModel)
/*
Author:		
Version:	1.0
Descript:	无实际功能,只定义公共的响应接口。MoveTo,MoveAlong,Patrol,Follow,Cruise,Wait,LandingOn,TakeOff
*/
//}}HDOSE_CLS_DES

class HYCGF_API CAbstractMoveModel /*抽象运动模型*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CAbstractMoveModel();
	virtual ~CAbstractMoveModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetCurrentMoveTask(long val){m_CurrentMoveTask=val;}
	long	GetCurrentMoveTask(){return m_CurrentMoveTask;}
	void	SetLastMoveTask(long val){m_LastMoveTask=val;}
	long	GetLastMoveTask(){return m_LastMoveTask;}
	void	SetLastMoveTaskHoldOn(bool val){m_LastMoveTaskHoldOn=val;}
	bool	GetLastMoveTaskHoldOn(){return m_LastMoveTaskHoldOn;}

	//{{HDOSE_MEMBER_FUNCTION(CAbstractMoveModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CAbstractMoveModel)
	virtual void OnMoveTo(CMoveTo *pevent);
	virtual void OnMoveAlong(CMoveAlong *pevent);
	virtual void OnPatrol(CPatrol *pevent);
	virtual void OnWait(CWait *pevent);
	virtual void OnFollow(CFollow *pevent);
	virtual void OnCruise(CCruise *pevent);
	virtual void OnReturnBase(CReturnBase *pevent);
	virtual void OnLandingOn(CLandingOn *pevent);
	virtual void OnTakeOff(CTakeOff *pevent);
	virtual void OnThrottleCtrlOper(CThrottleCtrlOper *pevent);
	virtual void OnAttitudeCtrlOper(CAttitudeCtrlOper *pevent);
	virtual void OnVehicleDriveModeCtrl(CVehicleDriveModeCtrl *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CAbstractMoveModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CAbstractMoveModel)
	long	m_CurrentMoveTask/*当前运动任务类型*/;
	long	m_LastMoveTask/*上一个运动任务类型*/;
	bool	m_LastMoveTaskHoldOn/*上一个运动任务是否挂起*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
