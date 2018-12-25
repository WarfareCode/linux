//RectangleControlObjectStateRep.h: interface for the CRectangleControlObjectStateRep module.
//!!HDOSE_CLASS(CRectangleControlObjectStateRep,CPolygonControlObjectStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RectangleControlObjectStateRep_H)
#define AFX_RectangleControlObjectStateRep_H

#include "PolygonControlObjectStateRep.h"

//{{HDOSE_CLS_DES(CRectangleControlObjectStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CRectangleControlObjectStateRep /*¾ØÐÎ¶ÔÏó×´Ì¬³Ø*/ : public CPolygonControlObjectStateRep 
{
	DECLARE_CREATE;
public:
	CRectangleControlObjectStateRep();
	virtual ~CRectangleControlObjectStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CRectangleControlObjectStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CRectangleControlObjectStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRectangleControlObjectStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
