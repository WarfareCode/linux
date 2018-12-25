//AAMSeekerModel.h: interface for the CAAMSeekerModel module.
//!!HDOSE_CLASS(CAAMSeekerModel,CRadarSensorModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMSeekerModel_H)
#define AFX_AAMSeekerModel_H

#include "RadarSensorModel.h"

//{{HDOSE_CLS_DES(CAAMSeekerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CAAMSeekerModel /*防空导弹导引头*/ : public CRadarSensorModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CAAMSeekerModel();
	virtual ~CAAMSeekerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CAAMSeekerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CAAMSeekerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CAAMSeekerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CAAMSeekerModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
