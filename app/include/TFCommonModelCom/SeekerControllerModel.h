//SeekerControllerModel.h: interface for the CSeekerControllerModel module.
//!!HDOSE_CLASS(CSeekerControllerModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SeekerControllerModel_H)
#define AFX_SeekerControllerModel_H



//{{HDOSE_CLS_DES(CSeekerControllerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CSeekerControllerModel /*导引头控制器*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSeekerControllerModel();
	virtual ~CSeekerControllerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSeekerControllerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSeekerControllerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSeekerControllerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSeekerControllerModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
