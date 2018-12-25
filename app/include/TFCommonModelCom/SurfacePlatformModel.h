//SurfacePlatformModel.h: interface for the CSurfacePlatformModel module.
//!!HDOSE_CLASS(CSurfacePlatformModel,CPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SurfacePlatformModel_H)
#define AFX_SurfacePlatformModel_H

#include "PlatformModel.h"

//{{HDOSE_CLS_DES(CSurfacePlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CSurfacePlatformModel /*水面平台*/ : public CPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSurfacePlatformModel();
	virtual ~CSurfacePlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSurfacePlatformModel)
	//}}HDOSE_MEMBER_FUNCTION
//	CStdioFile file;

protected:
	//{{HDOSE_EVENT_HANDLER(CSurfacePlatformModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSurfacePlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSurfacePlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
