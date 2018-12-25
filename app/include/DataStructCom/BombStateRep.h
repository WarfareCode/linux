//BombStateRep.h: interface for the CBombStateRep module.
//!!HDOSE_CLASS(CBombStateRep,CMunitionStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_BombStateRep_H)
#define AFX_BombStateRep_H

#include "MunitionStateRep.h"

//{{HDOSE_CLS_DES(CBombStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CBombStateRep /*º½¿ÕÕ¨µ¯×´Ì¬³Ø*/ : public CMunitionStateRep 
{
	DECLARE_CREATE;
public:
	CBombStateRep();
	virtual ~CBombStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CBombStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CBombStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CBombStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
