//ThermalSensor.h: interface for the CThermalSensor module.
//!!HDOSE_CLASS(CThermalSensor,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ThermalSensor_H)
#define AFX_ThermalSensor_H

#include "Sensor.h"

//{{HDOSE_CLS_DES(CThermalSensor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CThermalSensor /*ÈÈ´«¸ÐÆ÷*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CThermalSensor();
	virtual ~CThermalSensor();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CThermalSensor)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CThermalSensor)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CThermalSensor)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CThermalSensor)
	//}}HDOSE_ATTRIBUTE
};

#endif
