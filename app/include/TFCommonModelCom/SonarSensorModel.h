//SonarSensorModel.h: interface for the CSonarSensorModel module.
//!!HDOSE_CLASS(CSonarSensorModel,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SonarSensorModel_H)
#define AFX_SonarSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(CSonarSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CSonarSensorModel /*声纳传感器*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSonarSensorModel();
	virtual ~CSonarSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetMaxDetectDistance(){return m_MaxDetectDistance;}

	//{{HDOSE_MEMBER_FUNCTION(CSonarSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSonarSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSonarSensorModel)
	double	m_MaxDetectDistance/*最大探测距离（公里）*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSonarSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
