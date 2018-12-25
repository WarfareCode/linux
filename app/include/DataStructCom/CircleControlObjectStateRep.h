//CircleControlObjectStateRep.h: interface for the CCircleControlObjectStateRep module.
//!!HDOSE_CLASS(CCircleControlObjectStateRep,CControlObjStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CircleControlObjectStateRep_H)
#define AFX_CircleControlObjectStateRep_H

#include "ControlObjStateRep.h"


//{{HDOSE_CLS_DES(CCircleControlObjectStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCircleControlObjectStateRep /*圆形控制对象状态池*/ : public CControlObjStateRep 
{
	DECLARE_CREATE;
public:
	CCircleControlObjectStateRep();
	virtual ~CCircleControlObjectStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetLineWidth(float val){m_LineWidth=val;}
	float	GetLineWidth(){return m_LineWidth;}
	void	SetLineType(long val){m_LineType=val;}
	long	GetLineType(){return m_LineType;}
	void	SetdColor(DWORD val){m_dColor=val;}
	DWORD	GetdColor(){return m_dColor;}
	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}
	void	SetRadius(double val){m_Radius=val;}
	double	GetRadius(){return m_Radius;}
	void	SetbFill(bool val){m_bFill=val;}
	bool	GetbFill(){return m_bFill;}
	void	SetbSolidFill(bool val){m_bSolidFill=val;}
	bool	GetbSolidFill(){return m_bSolidFill;}
	void	SetFillColor(DWORD val){m_FillColor=val;}
	DWORD	GetFillColor(){return m_FillColor;}
	void	SetBackColor(DWORD val){m_BackColor=val;}
	DWORD	GetBackColor(){return m_BackColor;}
	void	SetFillStyle(long val){m_FillStyle=val;}
	long	GetFillStyle(){return m_FillStyle;}

	//{{HDOSE_MEMBER_FUNCTION(CCircleControlObjectStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CCircleControlObjectStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCircleControlObjectStateRep)
	float	m_LineWidth/*线宽*/;
	long	m_LineType/*线型*/;
	DWORD	m_dColor/*线颜色(RGBA)*/;
	GeoPt	m_Position/*圆心位置*/;
	double	m_Radius/*半径（m）*/;
	bool	m_bFill/*是否填充*/;
	bool	m_bSolidFill/*是否单色填充*/;
	DWORD	m_FillColor/*填充颜色*/;
	DWORD	m_BackColor/*背景颜色*/;
	long	m_FillStyle/*填充样式*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
