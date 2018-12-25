//ControlObj.h: interface for the CControlObj module.
//!!HDOSE_CLASS(CControlObj,CSimObjStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ControlObj_H)
#define AFX_ControlObj_H

#include "SimObjStateRep.h"

//{{HDOSE_CLS_DES(CControlObj)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CControlObj /*øÿ÷∆∂‘œÛ*/ : public CSimObjStateRep 
{
	DECLARE_CREATE;
public:
	CControlObj();
	virtual ~CControlObj();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CControlObj)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CControlObj)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CControlObj)
	//}}HDOSE_ATTRIBUTE
};

#endif
