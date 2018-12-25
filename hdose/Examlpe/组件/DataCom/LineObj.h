//LineObj.h: interface for the CLineObj module.
//!!HDOSE_CLASS(CLineObj,CControlObj)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LineObj_H)
#define AFX_LineObj_H

#include "ControlObj.h"
#include "LatLonH.h"

//{{HDOSE_CLS_DES(CLineObj)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CLineObj /*线控制对象*/ : public CControlObj 
{
	DECLARE_CREATE;
public:
	CLineObj();
	virtual ~CLineObj();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetPointsCount(int val){m_PointsCount=val;}
	int	GetPointsCount(){return m_PointsCount;}
	void	SetPoints(CLatLonH val[])
	{
		for(int i=0;i<10;i++)
		m_Points[i]=val[i];
	}
	CLatLonH*	GetPoints(){return m_Points;}

	//{{HDOSE_MEMBER_FUNCTION(CLineObj)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CLineObj)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CLineObj)
	int	m_PointsCount/*点数量*/;
	CLatLonH	m_Points[10]/*点数组（最多10个点）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
