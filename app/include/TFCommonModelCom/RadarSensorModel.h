//RadarSensorModel.h: interface for the CRadarSensorModel module.
//!!HDOSE_CLASS(CRadarSensorModel,CRadar)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RadarSensorModel_H)
#define AFX_RadarSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(CRadarSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CRadarSensorModel /*À×´ï´«¸ÐÆ÷*/ : public CRadar
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CRadarSensorModel();
	virtual ~CRadarSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	//{{HDOSE_MEMBER_FUNCTION(CRadarSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CRadarSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CRadarSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRadarSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
