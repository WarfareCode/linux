//MagSensorModel.h: interface for the CMagSensorModel module.
//!!HDOSE_CLASS(CMagSensorModel,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MagSensorModel_H)
#define AFX_MagSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(CMagSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CMagSensorModel /*´ÅÌ½²â´«¸ÐÆ÷*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CMagSensorModel();
	virtual ~CMagSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CMagSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CMagSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CMagSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMagSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
