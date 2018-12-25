//TorpedoCtrlModel.h: interface for the CTorpedoCtrlModel module.
//!!HDOSE_CLASS(CTorpedoCtrlModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoCtrlModel_H)
#define AFX_TorpedoCtrlModel_H

#include "LatLonH.h"
#include "Controller.h"

//#include "Controller.h"

//{{HDOSE_CLS_DES(CTorpedoCtrlModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CTorpedoCtrlModel /*鱼雷控制模型*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CTorpedoCtrlModel();
	virtual ~CTorpedoCtrlModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CTorpedoCtrlModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CTorpedoCtrlModel)
	void	OnTargetIndicatingEvt(CEvt *pevent);
	void	OnTorpedoBindingParams(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CTorpedoCtrlModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTorpedoCtrlModel)
	//}}HDOSE_ATTRIBUTE

	CLatLonH tarPos;		//目标初始位置
	int TarId;		//目标编号
};

#endif
