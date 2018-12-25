//SubSonarSensorModel.h: interface for the CSubSonarSensorModel module.
//!!HDOSE_CLASS(CSubSonarSensorModel,CSonarSensorModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubSonarSensorModel_H)
#define AFX_SubSonarSensorModel_H

#include "SonarSensorModel.h"

//{{HDOSE_CLS_DES(CSubSonarSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CSubSonarSensorModel /*潜艇声纳传感器模型*/ : public CSonarSensorModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSubSonarSensorModel();
	virtual ~CSubSonarSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSubSonarSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSubSonarSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSubSonarSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubSonarSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
