//MagneticSensor.h: interface for the CMagneticSensor module.
//!!HDOSE_CLASS(CMagneticSensor,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MagneticSensor_H)
#define AFX_MagneticSensor_H

#include "Sensor.h"

//{{HDOSE_CLS_DES(CMagneticSensor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CMagneticSensor /*´Å´«¸ÐÆ÷*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CMagneticSensor();
	virtual ~CMagneticSensor();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CMagneticSensor)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CMagneticSensor)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CMagneticSensor)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMagneticSensor)
	//}}HDOSE_ATTRIBUTE
};

#endif
