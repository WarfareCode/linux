//JammerModel.h: interface for the CJammerModel module.
//!!HDOSE_CLASS(CJammerModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_JammerModel_H)
#define AFX_JammerModel_H


//{{HDOSE_CLS_DES(CJammerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CJammerModel /*¸ÉÈÅÆ÷*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CJammerModel();
	virtual ~CJammerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CJammerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CJammerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CJammerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CJammerModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
