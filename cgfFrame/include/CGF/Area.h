//Area.h: interface for the CArea module.
//!!HDOSE_CLASS(CArea,CControlObject)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Area_H)
#define AFX_Area_H

#include "ControlObject.h"

//{{HDOSE_CLS_DES(CArea)
/*
Author:		
Version:	1.0
Descript:	��Ҫ���������ڵĻ�������
*/
//}}HDOSE_CLS_DES

class HYCGF_API CArea /*Area*/ : public CControlObject 
{
	DECLARE_CREATE;
public:
	CArea();
	virtual ~CArea();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();

	virtual	void tick(double lasttime);

	void	SetNormal(double val){m_Normal=val;}
	double	GetNormal(){return m_Normal;}
	void	SetHeading(double val){m_Heading=val;}
	double	GetHeading(){return m_Heading;}

	//{{HDOSE_MEMBER_FUNCTION(CArea)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CArea)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CArea)
	double	m_Normal/*����Ĭ������洹ֱ,90�ȣ�*/;
	double	m_Heading/*����(��)*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
