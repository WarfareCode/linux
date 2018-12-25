//VehiclePlatformModel.h: interface for the CVehiclePlatformModel module.
//!!HDOSE_CLASS(CVehiclePlatformModel,CPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_VehiclePlatformModel_H)
#define AFX_VehiclePlatformModel_H

#include "PlatformModel.h"

//{{HDOSE_CLS_DES(CVehiclePlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CVehiclePlatformModel /*³µÁ¾Æ½Ì¨*/ : public CPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CVehiclePlatformModel();
	virtual ~CVehiclePlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CVehiclePlatformModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CVehiclePlatformModel)
	void	OnVehicleMoveCtrlParams(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CVehiclePlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CVehiclePlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
