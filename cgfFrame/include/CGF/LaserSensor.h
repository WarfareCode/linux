//LaserSensor.h: interface for the CLaserSensor module.
//!!HDOSE_CLASS(CLaserSensor,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaserSensor_H)
#define AFX_LaserSensor_H

#include "Sensor.h"

//{{HDOSE_CLS_DES(CLaserSensor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CLaserSensor /*¼¤¹â´«¸ÐÆ÷*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CLaserSensor();
	virtual ~CLaserSensor();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CLaserSensor)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CLaserSensor)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CLaserSensor)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CLaserSensor)
	//}}HDOSE_ATTRIBUTE
};

#endif
