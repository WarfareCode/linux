//AAMSeekerControllerModel.h: interface for the CAAMSeekerControllerModel module.
//!!HDOSE_CLASS(CAAMSeekerControllerModel,CSeekerControllerModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMSeekerControllerModel_H)
#define AFX_AAMSeekerControllerModel_H

#include "SeekerControllerModel.h"

//{{HDOSE_CLS_DES(CAAMSeekerControllerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CAAMSeekerControllerModel /*防空导弹导引头控制器*/ : public CSeekerControllerModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CAAMSeekerControllerModel();
	virtual ~CAAMSeekerControllerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CAAMSeekerControllerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CAAMSeekerControllerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CAAMSeekerControllerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CAAMSeekerControllerModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
