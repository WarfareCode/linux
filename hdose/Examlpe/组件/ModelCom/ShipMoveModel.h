//ShipMoveModel.h: interface for the CShipMoveModel module.
//!!HDOSE_CLASS(CShipMoveModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ShipMoveModel_H)
#define AFX_ShipMoveModel_H

#include "model.h"

//{{HDOSE_CLS_DES(CShipMoveModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CShipMoveModel /*舰艇运动模型*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CShipMoveModel();
	virtual ~CShipMoveModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CShipMoveModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CShipMoveModel)
	void	OnEntityMoveOrderEvt(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CShipMoveModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CShipMoveModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
