//TorpedoSonarSensorModel.h: interface for the CTorpedoSonarSensorModel module.
//!!HDOSE_CLASS(CTorpedoSonarSensorModel,CSonarSensorModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoSonarSensorModel_H)
#define AFX_TorpedoSonarSensorModel_H

#include "SonarSensorModel.h"

//{{HDOSE_CLS_DES(CTorpedoSonarSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CTorpedoSonarSensorModel /*鱼雷声纳传感器模型*/ : public CSonarSensorModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CTorpedoSonarSensorModel();
	virtual ~CTorpedoSonarSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CTorpedoSonarSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CTorpedoSonarSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CTorpedoSonarSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTorpedoSonarSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
