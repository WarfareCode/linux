//MunitionPlatformModel.h: interface for the CMunitionPlatformModel module.
//!!HDOSE_CLASS(CMunitionPlatformModel,CPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MunitionPlatformModel_H)
#define AFX_MunitionPlatformModel_H

#include "PlatformModel.h"

//{{HDOSE_CLS_DES(CMunitionPlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CMunitionPlatformModel /*µ¯Ò©Æ½Ì¨*/ : public CPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CMunitionPlatformModel();
	virtual ~CMunitionPlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CMunitionPlatformModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CMunitionPlatformModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CMunitionPlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMunitionPlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
