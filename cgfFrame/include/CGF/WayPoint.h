//WayPoint.h: interface for the CWayPoint module.
//!!HDOSE_CLASS(CWayPoint,CControlObject)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_WayPoint_H)
#define AFX_WayPoint_H

#include "ControlObject.h"

//{{HDOSE_CLS_DES(CWayPoint)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWayPoint /*WayPoint*/ : public CControlObject 
{
	DECLARE_CREATE;
public:
	CWayPoint();
	virtual ~CWayPoint();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();

	virtual	void tick(double lasttime);

	void	SetPoint(GeoPt val){m_Point=val;}
	GeoPt	GetPoint(){return m_Point;}

	//{{HDOSE_MEMBER_FUNCTION(CWayPoint)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CWayPoint)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CWayPoint)
	GeoPt	m_Point/*Œª÷√*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
