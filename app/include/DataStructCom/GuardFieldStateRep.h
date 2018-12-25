//GuardFieldStateRep.h: interface for the CGuardFieldStateRep module.
//!!HDOSE_CLASS(CGuardFieldStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_GuardFieldStateRep_H)
#define AFX_GuardFieldStateRep_H

#include "CGF/FacilityESR.h"

//{{HDOSE_CLS_DES(CGuardFieldStateRep)
/*
Author:		xks
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CGuardFieldStateRep /*±£ÎÀÒªµØ×´Ì¬³Ø*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CGuardFieldStateRep();
	virtual ~CGuardFieldStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetGuardRadius(double val){m_GuardRadius=val;}
	double	GetGuardRadius(){return m_GuardRadius;}

	//{{HDOSE_MEMBER_FUNCTION(CGuardFieldStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CGuardFieldStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CGuardFieldStateRep)
	double	m_GuardRadius/*±£ÎÀ°ë¾¶,m*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
