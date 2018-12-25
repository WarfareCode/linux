//SubSurfacePlatformModel.h: interface for the CSubSurfacePlatformModel module.
//!!HDOSE_CLASS(CSubSurfacePlatformModel,CPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubSurfacePlatformModel_H)
#define AFX_SubSurfacePlatformModel_H

#include "PlatformModel.h"

//{{HDOSE_CLS_DES(CSubSurfacePlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CSubSurfacePlatformModel /*水下平台*/ : public CPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSubSurfacePlatformModel();
	virtual ~CSubSurfacePlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSubSurfacePlatformModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSubSurfacePlatformModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSubSurfacePlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubSurfacePlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
