//CornerReflectorStateRep.h: interface for the CCornerReflectorStateRep module.
//!!HDOSE_CLASS(CCornerReflectorStateRep,CSurfaceESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CornerReflectorStateRep_H)
#define AFX_CornerReflectorStateRep_H

//{{HDOSE_CLS_DES(CCornerReflectorStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCornerReflectorStateRep /*角反射体状态池*/ : public CSurfaceESR 
{
	DECLARE_CREATE;
public:
	CCornerReflectorStateRep();
	virtual ~CCornerReflectorStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetReflectorRCS(double val){m_ReflectorRCS=val;}
	double	GetReflectorRCS(){return m_ReflectorRCS;}
	void	SetUnitNumberBelongTo(long val){m_UnitNumberBelongTo=val;}
	long	GetUnitNumberBelongTo(){return m_UnitNumberBelongTo;}

	//{{HDOSE_MEMBER_FUNCTION(CCornerReflectorStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CCornerReflectorStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCornerReflectorStateRep)
	double	m_ReflectorRCS/*回波功率*/;
	long	m_UnitNumberBelongTo/*该角反所依附的舰艇平台编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
