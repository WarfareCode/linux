//ChaffStateRep.h: interface for the CChaffStateRep module.
//!!HDOSE_CLASS(CChaffStateRep,CMunitionStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChaffStateRep_H)
#define AFX_ChaffStateRep_H

#include "MunitionStateRep.h"

//{{HDOSE_CLS_DES(CChaffStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffStateRep /*箔条弹状态池*/ : public CMunitionStateRep 
{
	DECLARE_CREATE;
public:
	CChaffStateRep();
	virtual ~CChaffStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetChaffRCS(double val){m_ChaffRCS=val;}
	double	GetChaffRCS(){return m_ChaffRCS;}
	void	SetChaffArea(double val){m_ChaffArea=val;}
	double	GetChaffArea(){return m_ChaffArea;}

	//{{HDOSE_MEMBER_FUNCTION(CChaffStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CChaffStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CChaffStateRep)
	double	m_ChaffRCS/*箔条云的RCS值（可变的）*/;
	double	m_ChaffArea/*箔条云的面积*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
