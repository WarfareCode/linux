//Phaseline.h: interface for the CPhaseline module.
//!!HDOSE_CLASS(CPhaseline,CControlObject)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Phaseline_H)
#define AFX_Phaseline_H

#include "ControlObject.h"

//{{HDOSE_CLS_DES(CPhaseline)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CPhaseline /*Phaseline*/ : public CControlObject 
{
	DECLARE_CREATE;
public:
	CPhaseline();
	virtual ~CPhaseline();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();

	virtual	void tick(double lasttime);

	void	SetStartPoint(GeoPt val){m_StartPoint=val;}
	GeoPt	GetStartPoint(){return m_StartPoint;}
	void	SetEndPoint(GeoPt val){m_EndPoint=val;}
	GeoPt	GetEndPoint(){return m_EndPoint;}

	//{{HDOSE_MEMBER_FUNCTION(CPhaseline)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CPhaseline)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CPhaseline)
	GeoPt	m_StartPoint/*Æðµã*/;
	GeoPt	m_EndPoint/*ÖÕµã*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
