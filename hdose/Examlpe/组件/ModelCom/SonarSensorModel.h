//SonarSensorModel.h: interface for the CSonarSensorModel module.
//!!HDOSE_CLASS(CSonarSensorModel,CSensorModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SonarSensorModel_H)
#define AFX_SonarSensorModel_H

#include "SensorModel.h"

//{{HDOSE_CLS_DES(CSonarSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CSonarSensorModel /*声纳传感器模型*/ : public CSensorModel 
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

	double	GetMaxDist(){return m_MaxDist;}
	double	GetLowestNoise(){return m_LowestNoise;}

	//{{HDOSE_MEMBER_FUNCTION(CSonarSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSonarSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSonarSensorModel)
	double	m_MaxDist/*最大探测距离*/;
	double	m_LowestNoise/*可探测噪声下限*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSonarSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
