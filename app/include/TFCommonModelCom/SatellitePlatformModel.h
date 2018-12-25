//SatellitePlatformModel.h: interface for the CSatellitePlatformModel module.
//!!HDOSE_CLASS(CSatellitePlatformModel,CPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SatellitePlatformModel_H)
#define AFX_SatellitePlatformModel_H

#include "PlatformModel.h"

//{{HDOSE_CLS_DES(CSatellitePlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CSatellitePlatformModel /*Œ¿–«∆ΩÃ®*/ : public CPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSatellitePlatformModel();
	virtual ~CSatellitePlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSatellitePlatformModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSatellitePlatformModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSatellitePlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSatellitePlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
