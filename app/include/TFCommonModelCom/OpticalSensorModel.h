//OpticalSensorModel.h: interface for the COpticalSensorModel module.
//!!HDOSE_CLASS(COpticalSensorModel,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_OpticalSensorModel_H)
#define AFX_OpticalSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(COpticalSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API COpticalSensorModel /*光学传感器*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	COpticalSensorModel();
	virtual ~COpticalSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(COpticalSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(COpticalSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(COpticalSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(COpticalSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
