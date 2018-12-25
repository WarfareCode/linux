//RotaryWingPlatformModel.h: interface for the CRotaryWingPlatformModel module.
//!!HDOSE_CLASS(CRotaryWingPlatformModel,CPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RotaryWingPlatformModel_H)
#define AFX_RotaryWingPlatformModel_H

#include "PlatformModel.h"

//{{HDOSE_CLS_DES(CRotaryWingPlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CRotaryWingPlatformModel /*ÐýÒí·É»úÆ½Ì¨*/ : public CPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CRotaryWingPlatformModel();
	virtual ~CRotaryWingPlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CRotaryWingPlatformModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CRotaryWingPlatformModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CRotaryWingPlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRotaryWingPlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
