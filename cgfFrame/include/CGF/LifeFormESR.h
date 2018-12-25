//LifeFormESR.h: interface for the CLifeFormESR module.
//!!HDOSE_CLASS(CLifeFormESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LifeFormESR_H)
#define AFX_LifeFormESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CLifeFormESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CLifeFormESR /*ÉúÃüÌå×´Ì¬³Ø*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CLifeFormESR();
	virtual ~CLifeFormESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CLifeFormESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CLifeFormESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CLifeFormESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
