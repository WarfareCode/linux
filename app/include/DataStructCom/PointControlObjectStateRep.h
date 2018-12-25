//PointControlObjectStateRep.h: interface for the CPointControlObjectStateRep module.
//!!HDOSE_CLASS(CPointControlObjectStateRep,CControlObjStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_PointControlObjectStateRep_H)
#define AFX_PointControlObjectStateRep_H

#include "ControlObjStateRep.h"


//{{HDOSE_CLS_DES(CPointControlObjectStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CPointControlObjectStateRep /*点控制对象状态池*/ : public CControlObjStateRep 
{
	DECLARE_CREATE;
public:
	CPointControlObjectStateRep();
	virtual ~CPointControlObjectStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}

	//{{HDOSE_MEMBER_FUNCTION(CPointControlObjectStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CPointControlObjectStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CPointControlObjectStateRep)
	GeoPt	m_Position/*位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
