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

class DATASTRUCTCOMPONENTDLL_API CChaffIslandStateRep /*����״̬��*/ : public CSurfaceESR 
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
	GeoPt	m_PointsArray[10]/*��ɸõ�����״�ĵ㼯�����飩*/;
	long	m_PointsCount/*��ĸ���*/;
	double	m_Area/*�������*/;
	double	m_ChaffIslandRCS/*����RCS*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
