//DragSonarSensorModel.h: interface for the CDragSonarSensorModel module.
//!!HDOSE_CLASS(CDragSonarSensorModel,CSonarSensorModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DragSonarSensorModel_H)
#define AFX_DragSonarSensorModel_H

#include "SonarSensorModel.h"

//{{HDOSE_CLS_DES(CDragSonarSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CDragSonarSensorModel /*拖曳式声纳传感器模型*/ : public CSonarSensorModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CDragSonarSensorModel();
	virtual ~CDragSonarSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CDragSonarSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CDragSonarSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CDragSonarSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CDragSonarSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
