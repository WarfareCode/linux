//Circle.h: interface for the CCircle module.
//!!HDOSE_CLASS(CCircle,CArea)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Circle_H)
#define AFX_Circle_H

#include "Area.h"

//{{HDOSE_CLS_DES(CCircle)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CCircle /*Circle*/ : public CArea 
{
	DECLARE_CREATE;
public:
	CCircle();
	virtual ~CCircle();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();

	virtual	void tick(double lasttime);

	void	SetCenterPos(GeoPt val){m_CenterPos=val;}
	GeoPt	GetCenterPos(){return m_CenterPos;}
	void	SetRadius(double val){m_Radius=val;}
	double	GetRadius(){return m_Radius;}

	//{{HDOSE_MEMBER_FUNCTION(CCircle)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CCircle)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCircle)
	GeoPt	m_CenterPos/*Ô²ÐÄÎ»ÖÃ*/;
	double	m_Radius/*°ë¾¶,m*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
