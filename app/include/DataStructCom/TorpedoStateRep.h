//TorpedoStateRep.h: interface for the CTorpedoStateRep module.
//!!HDOSE_CLASS(CTorpedoStateRep,CMunitionStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoStateRep_H)
#define AFX_TorpedoStateRep_H

#include "MunitionStateRep.h"

//{{HDOSE_CLS_DES(CTorpedoStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoStateRep /*ÓãÀ××´Ì¬³Ø*/ : public CMunitionStateRep 
{
	DECLARE_CREATE;
public:
	CTorpedoStateRep();
	virtual ~CTorpedoStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CTorpedoStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CTorpedoStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTorpedoStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
