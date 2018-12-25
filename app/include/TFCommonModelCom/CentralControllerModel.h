//CentralControllerModel.h: interface for the CCentralControllerModel module.
//!!HDOSE_CLASS(CCentralControllerModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CentralControllerModel_H)
#define AFX_CentralControllerModel_H



//{{HDOSE_CLS_DES(CCentralControllerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CCentralControllerModel /*×ÛºÏ¿ØÖÆÆ÷*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CCentralControllerModel();
	virtual ~CCentralControllerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CCentralControllerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CCentralControllerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CCentralControllerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCentralControllerModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
