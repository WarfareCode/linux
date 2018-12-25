//PolygonControlObjectStateRep.h: interface for the CPolygonControlObjectStateRep module.
//!!HDOSE_CLASS(CPolygonControlObjectStateRep,CControlObjStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_PolygonControlObjectStateRep_H)
#define AFX_PolygonControlObjectStateRep_H

#include "ControlObjStateRep.h"

//{{HDOSE_CLS_DES(CPolygonControlObjectStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CPolygonControlObjectStateRep /*����ο��ƶ���״̬��*/ : public CControlObjStateRep 
{
	DECLARE_CREATE;
public:
	CPolygonControlObjectStateRep();
	virtual ~CPolygonControlObjectStateRep();
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
	void	SetColor(DWORD val){m_Color=val;}
	DWORD	GetColor(){return m_Color;}
	//void	SetPoint(char* val){strcpy(m_Point,val);}
	//char*	GetPoint(){return m_Point;}

	void	SetPoint(char* val){SetValueString("Point",val);}
	char*	GetPoint(){return GetValueString("Point");}
	void	SetPointNum(long val){m_PointNum=val;}
	long	GetPointNum(){return m_PointNum;}
	void	SetFill(bool val){m_Fill=val;}
	bool	GetFill(){return m_Fill;}
	void	SetSolidFill(bool val){m_SolidFill=val;}
	bool	GetSolidFill(){return m_SolidFill;}
	void	SetFillColor(DWORD val){m_FillColor=val;}
	DWORD	GetFillColor(){return m_FillColor;}
	void	SetBackColor(DWORD val){m_BackColor=val;}
	DWORD	GetBackColor(){return m_BackColor;}
	void	SetFillStyle(int val){m_FillStyle=val;}
	int	GetFillStyle(){return m_FillStyle;}

	//{{HDOSE_MEMBER_FUNCTION(CPolygonControlObjectStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CPolygonControlObjectStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CPolygonControlObjectStateRep)
	float	m_LineWidth/*�߿�*/;
	long	m_LineType/*����*/;
	DWORD	m_Color/*����ɫ(RGBA)*/;
	char*	m_Point/*��γ�ߵ�����*/;
	long	m_PointNum/*������*/;
	bool	m_Fill/*�Ƿ����*/;
	bool	m_SolidFill/*�Ƿ�ɫ���*/;
	DWORD	m_FillColor/*�����ɫ*/;
	DWORD	m_BackColor/*������ɫ*/;
	int	m_FillStyle/*�����ʽ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
