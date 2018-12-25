//MoveControllerModel.h: interface for the CMoveControllerModel module.
//!!HDOSE_CLASS(CMoveControllerModel,CController)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveControllerModel_H)
#define AFX_MoveControllerModel_H



//{{HDOSE_CLS_DES(CMoveControllerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CMoveControllerModel /*ÔË¶¯¿ØÖÆÆ÷*/ : public CController 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CMoveControllerModel();
	virtual ~CMoveControllerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CMoveControllerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CMoveControllerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CMoveControllerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMoveControllerModel)
	//}}HDOSE_ATTRIBUTE

	void CalcNextPos(GeoPt& newPos);
};

#endif
