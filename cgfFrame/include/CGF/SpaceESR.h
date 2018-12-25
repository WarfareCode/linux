//SpaceESR.h: interface for the CSpaceESR module.
//!!HDOSE_CLASS(CSpaceESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SpaceESR_H)
#define AFX_SpaceESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CSpaceESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSpaceESR /*Ì«¿ÕÊµÌå×´Ì¬³Ø*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CSpaceESR();
	virtual ~CSpaceESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSpaceESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSpaceESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSpaceESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
