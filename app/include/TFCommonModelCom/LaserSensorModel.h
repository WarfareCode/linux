//LaserSensorModel.h: interface for the CLaserSensorModel module.
//!!HDOSE_CLASS(CLaserSensorModel,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaserSensorModel_H)
#define AFX_LaserSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(CLaserSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CLaserSensorModel /*¼¤¹âÖ¸Ê¾Æ÷*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CLaserSensorModel();
	virtual ~CLaserSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CLaserSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CLaserSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CLaserSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CLaserSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
