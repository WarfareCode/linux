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

class DATASTRUCTCOMPONENTDLL_API CCircleControlObjectStateRep /*Բ�ο��ƶ���״̬��*/ : public CControlObjStateRep 
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
	float	m_LineWidth/*�߿�*/;
	long	m_LineType/*����*/;
	DWORD	m_dColor/*����ɫ(RGBA)*/;
	GeoPt	m_Position/*Բ��λ��*/;
	double	m_Radius/*�뾶��m��*/;
	bool	m_bFill/*�Ƿ����*/;
	bool	m_bSolidFill/*�Ƿ�ɫ���*/;
	DWORD	m_FillColor/*�����ɫ*/;
	DWORD	m_BackColor/*������ɫ*/;
	long	m_FillStyle/*�����ʽ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
