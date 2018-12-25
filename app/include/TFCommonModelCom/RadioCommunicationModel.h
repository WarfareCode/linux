//RadioCommunicationModel.h: interface for the CRadioCommunicationModel module.
//!!HDOSE_CLASS(CRadioCommunicationModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RadioCommunicationModel_H)
#define AFX_RadioCommunicationModel_H


//{{HDOSE_CLS_DES(CRadioCommunicationModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CRadioCommunicationModel /*通信模型*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CRadioCommunicationModel();
	virtual ~CRadioCommunicationModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CRadioCommunicationModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CRadioCommunicationModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CRadioCommunicationModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRadioCommunicationModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
