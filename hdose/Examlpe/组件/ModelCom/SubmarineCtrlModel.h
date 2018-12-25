//SubmarineCtrlModel.h: interface for the CSubmarineCtrlModel module.
//!!HDOSE_CLASS(CSubmarineCtrlModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubmarineCtrlModel_H)
#define AFX_SubmarineCtrlModel_H

#include "TargetData.h"
#include "Controller.h"
//#include "Controller.h"

//{{HDOSE_CLS_DES(CSubmarineCtrlModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "AntiShipDisplayDlg.h"
class MODELCOM_API CSubmarineCtrlModel /*潜艇控制模型*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSubmarineCtrlModel();
	virtual ~CSubmarineCtrlModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	//{{HDOSE_MEMBER_FUNCTION(CSubmarineCtrlModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSubmarineCtrlModel)
	void	OnTargetIndicatingEvt(CEvt *pevent);
	void	OnEntityMoveTask(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSubmarineCtrlModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubmarineCtrlModel)
	//}}HDOSE_ATTRIBUTE


	int tarCount;	//记录目标个数
	CTargetData tarInfo[10];		//用于记录目标信息

	int TorpedoCount;		//记录潜艇鱼雷发射的数量

};

#endif
