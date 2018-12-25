//MunitionESR.h: interface for the CMunitionESR module.
//!!HDOSE_CLASS(CMunitionESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MunitionESR_H)
#define AFX_MunitionESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CMunitionESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CMunitionESR /*µ¯Ò©×´Ì¬³Ø*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CMunitionESR();
	virtual ~CMunitionESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CMunitionESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CMunitionESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CMunitionESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
