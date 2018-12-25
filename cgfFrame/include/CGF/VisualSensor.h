//VisualSensor.h: interface for the CVisualSensor module.
//!!HDOSE_CLASS(CVisualSensor,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_VisualSensor_H)
#define AFX_VisualSensor_H

#include "Sensor.h"

//{{HDOSE_CLS_DES(CVisualSensor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CVisualSensor /*可视传感器*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CVisualSensor();
	virtual ~CVisualSensor();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CVisualSensor)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CVisualSensor)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CVisualSensor)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CVisualSensor)
	//}}HDOSE_ATTRIBUTE
};

#endif
