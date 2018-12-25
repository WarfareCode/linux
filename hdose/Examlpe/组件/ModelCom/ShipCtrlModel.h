//ShipCtrlModel.h: interface for the CShipCtrlModel module.
//!!HDOSE_CLASS(CShipCtrlModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ShipCtrlModel_H)
#define AFX_ShipCtrlModel_H

#include "Controller.h"

//{{HDOSE_CLS_DES(CShipCtrlModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CShipCtrlModel /*½¢Í§¿ØÖÆÄ£ÐÍ*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CShipCtrlModel();
	virtual ~CShipCtrlModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CShipCtrlModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CShipCtrlModel)
	void	OnTargetIndicatingEvt(CEvt *pevent);
	void	OnEntityMoveTask(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CShipCtrlModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CShipCtrlModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
