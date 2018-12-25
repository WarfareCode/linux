//CruiseMissileESR.h: interface for the CCruiseMissileESR module.
//!!HDOSE_CLASS(CCruiseMissileESR,CMissileESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CruiseMissileESR_H)
#define AFX_CruiseMissileESR_H

#include "MissileESR.h"

//{{HDOSE_CLS_DES(CCruiseMissileESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CCruiseMissileESR /*Ñ²º½µ¼µ¯×´Ì¬³Ø*/ : public CMissileESR 
{
	DECLARE_CREATE;
public:
	CCruiseMissileESR();
	virtual ~CCruiseMissileESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CCruiseMissileESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CCruiseMissileESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCruiseMissileESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
