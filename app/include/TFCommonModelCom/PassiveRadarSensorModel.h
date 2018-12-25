//PassiveRadarSensorModel.h: interface for the CPassiveRadarSensorModel module.
//!!HDOSE_CLASS(CPassiveRadarSensorModel,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_PassiveRadarSensorModel_H)
#define AFX_PassiveRadarSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(CPassiveRadarSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CPassiveRadarSensorModel /*被动雷达模型*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CPassiveRadarSensorModel();
	virtual ~CPassiveRadarSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CPassiveRadarSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CPassiveRadarSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CPassiveRadarSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CPassiveRadarSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
