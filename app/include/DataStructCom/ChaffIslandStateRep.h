//ChaffIslandStateRep.h: interface for the CChaffIslandStateRep module.
//!!HDOSE_CLASS(CChaffIslandStateRep,CSurfaceESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChaffIslandStateRep_H)
#define AFX_ChaffIslandStateRep_H



//{{HDOSE_CLS_DES(CChaffIslandStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffIslandStateRep /*岛岸状态池*/ : public CSurfaceESR 
{
	DECLARE_CREATE;
public:
	CChaffIslandStateRep();
	virtual ~CChaffIslandStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetPointsArray(GeoPt val[10]){
		for(int i=0;i<10;i++)
			m_PointsArray[i]=val[i];
	}
	GeoPt*	GetPointsArray(){return m_PointsArray;}
	void	SetPointsCount(long val){m_PointsCount=val;}
	long	GetPointsCount(){return m_PointsCount;}
	void	SetArea(double val){m_Area=val;}
	double	GetArea(){return m_Area;}
	void	SetChaffIslandRCS(double val){m_ChaffIslandRCS=val;}
	double	GetChaffIslandRCS(){return m_ChaffIslandRCS;}

	//{{HDOSE_MEMBER_FUNCTION(CChaffIslandStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CChaffIslandStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CChaffIslandStateRep)
	GeoPt	m_PointsArray[10]/*组成该岛岸形状的点集（数组）*/;
	long	m_PointsCount/*点的个数*/;
	double	m_Area/*岛岸面积*/;
	double	m_ChaffIslandRCS/*岛岸RCS*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
