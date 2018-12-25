//DamageAssessControllerModel.h: interface for the CDamageAssessControllerModel module.
//!!HDOSE_CLASS(CDamageAssessControllerModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DamageAssessControllerModel_H)
#define AFX_DamageAssessControllerModel_H


//{{HDOSE_CLS_DES(CDamageAssessControllerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CDamageAssessControllerModel /*»ÙÉËÆÀ¹À¿ØÖÆÆ÷*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CDamageAssessControllerModel();
	virtual ~CDamageAssessControllerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CDamageAssessControllerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CDamageAssessControllerModel)
	virtual void	OnExplosionEvent(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CDamageAssessControllerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CDamageAssessControllerModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
