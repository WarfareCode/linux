//Ellipse.h: interface for the CEllipse module.
//!!HDOSE_CLASS(CEllipse,CArea)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Ellipse_H)
#define AFX_Ellipse_H

#include "Area.h"

//{{HDOSE_CLS_DES(CEllipse)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CEllipse /*Ellipse*/ : public CArea 
{
	DECLARE_CREATE;
public:
	CEllipse();
	virtual ~CEllipse();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();

	virtual	void tick(double lasttime);

	void	SetCenterPos(GeoPt val){m_CenterPos=val;}
	GeoPt	GetCenterPos(){return m_CenterPos;}
	void	SetMajorSemiAxis(double val){m_MajorSemiAxis=val;}
	double	GetMajorSemiAxis(){return m_MajorSemiAxis;}
	void	SetMinorSemiAxis(double val){m_MinorSemiAxis=val;}
	double	GetMinorSemiAxis(){return m_MinorSemiAxis;}

	//{{HDOSE_MEMBER_FUNCTION(CEllipse)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CEllipse)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CEllipse)
	GeoPt	m_CenterPos/*‘≤–ƒ*/;
	double	m_MajorSemiAxis/*≥§∞Î÷·,m*/;
	double	m_MinorSemiAxis/*∂Ã∞Î÷·,m*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
