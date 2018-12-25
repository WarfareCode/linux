//AcousticSensor.h: interface for the CAcousticSensor module.
//!!HDOSE_CLASS(CAcousticSensor,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AcousticSensor_H)
#define AFX_AcousticSensor_H

#include "Sensor.h"

//{{HDOSE_CLS_DES(CAcousticSensor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CAcousticSensor /*Éù´«¸ÐÆ÷*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CAcousticSensor();
	virtual ~CAcousticSensor();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CAcousticSensor)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CAcousticSensor)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CAcousticSensor)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CAcousticSensor)
	//}}HDOSE_ATTRIBUTE
};

#endif
