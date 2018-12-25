//TiltRotorAircratfPlatformModel.h: interface for the CTiltRotorAircratfPlatformModel module.
//!!HDOSE_CLASS(CTiltRotorAircratfPlatformModel,CRotaryWingPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TiltRotorAircratfPlatformModel_H)
#define AFX_TiltRotorAircratfPlatformModel_H

#include "RotaryWingPlatformModel.h"

//{{HDOSE_CLS_DES(CTiltRotorAircratfPlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CTiltRotorAircratfPlatformModel /*ÇãÐýÒí·É»úÆ½Ì¨*/ : public CRotaryWingPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CTiltRotorAircratfPlatformModel();
	virtual ~CTiltRotorAircratfPlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CTiltRotorAircratfPlatformModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CTiltRotorAircratfPlatformModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CTiltRotorAircratfPlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTiltRotorAircratfPlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
