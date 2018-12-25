//ShipStateRep.h: interface for the CShipStateRep module.
//!!HDOSE_CLASS(CShipStateRep,CNodeStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ShipStateRep_H)
#define AFX_ShipStateRep_H

#include "EntityStateRep.h"

//{{HDOSE_CLS_DES(CShipStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CShipStateRep /*½¢Í§×´Ì¬³Ø*/ : public CNodeStateRep 
{
	DECLARE_CREATE;
public:
	CShipStateRep();
	virtual ~CShipStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetLength(){return m_Length;}
	double	GetWidth(){return m_Width;}

	//{{HDOSE_MEMBER_FUNCTION(CShipStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CShipStateRep)
	double	m_Length/*³¤¶È*/;
	double	m_Width/*¿í¶È*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CShipStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
