//SubmarineStateRep.h: interface for the CSubmarineStateRep module.
//!!HDOSE_CLASS(CSubmarineStateRep,CNodeStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubmarineStateRep_H)
#define AFX_SubmarineStateRep_H

#include "EntityStateRep.h"

//{{HDOSE_CLS_DES(CSubmarineStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CSubmarineStateRep /*潜艇状态池*/ : public CNodeStateRep 
{
	DECLARE_CREATE;
public:
	CSubmarineStateRep();
	virtual ~CSubmarineStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetLength(){return m_Length;}
	double	GetMaxRadius(){return m_MaxRadius;}
	double	GetMaxVel(){return m_MaxVel;}

	//{{HDOSE_MEMBER_FUNCTION(CSubmarineStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSubmarineStateRep)
	double	m_Length/*长度*/;
	double	m_MaxRadius/*最大直径*/;
	double	m_MaxVel/*最大速度*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubmarineStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
