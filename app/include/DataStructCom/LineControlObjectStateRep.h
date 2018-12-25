//LineControlObjectStateRep.h: interface for the CLineControlObjectStateRep module.
//!!HDOSE_CLASS(CLineControlObjectStateRep,CControlObjStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LineControlObjectStateRep_H)
#define AFX_LineControlObjectStateRep_H

#include "ControlObjStateRep.h"


//{{HDOSE_CLS_DES(CLineControlObjectStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CLineControlObjectStateRep /*线控制对象状态池*/ : public CControlObjStateRep 
{
	DECLARE_CREATE;
public:
	CLineControlObjectStateRep();
	virtual ~CLineControlObjectStateRep();
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
	void	SetPoints(GeoPt val[10]){
		for(int i=0;i<10;i++)
			m_Points[i]=val[i];
	}
	GeoPt*	GetPoints(){return m_Points;}
	void	SetPointsCount(long val){m_PointsCount=val;}
	long	GetPointsCount(){return m_PointsCount;}

	//{{HDOSE_MEMBER_FUNCTION(CLineControlObjectStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CLineControlObjectStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CLineControlObjectStateRep)
	float	m_LineWidth/*线宽*/;
	long	m_LineType/*线型*/;
	DWORD	m_Color/*线颜色(RGBA)*/;
	GeoPt	m_Points[10]/*经纬高点数据（10个数据的数组）*/;
	long	m_PointsCount/*点的数量（最多10个）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
