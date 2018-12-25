//CreateSatOrbitEvent.h: interface for the CCreateSatOrbitEvent module.
//!!HDOSE_CLASS(CCreateSatOrbitEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateSatOrbitEvent_H)
#define AFX_CreateSatOrbitEvent_H

#include "OrbitData.h"

//{{HDOSE_CLS_DES(CCreateSatOrbitEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CCreateSatOrbitEvent /*创建卫星轨道事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCreateSatOrbitEvent();
	virtual ~CCreateSatOrbitEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	Setyear(int val){m_year=val;}
	int	Getyear(){return m_year;}
	void	Setmon(int val){m_mon=val;}
	int	Getmon(){return m_mon;}
	void	Setday(int val){m_day=val;}
	int	Getday(){return m_day;}
	void	SetUT(double val){m_UT=val;}
	double	GetUT(){return m_UT;}
	void	SetUM(double val){m_UM=val;}
	double	GetUM(){return m_UM;}
	void	SetUS(double val){m_US=val;}
	double	GetUS(){return m_US;}
	void	SetEntityID(long val){m_EntityID=val;}
	long	GetEntityID(){return m_EntityID;}
	void	SetOrbitCoe(COrbitData val){m_OrbitCoe=val;}
	COrbitData	GetOrbitCoe(){return m_OrbitCoe;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateSatOrbitEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateSatOrbitEvent)
	int	m_year/*年*/;
	int	m_mon/*月*/;
	int	m_day/*日*/;
	double	m_UT/*时*/;
	double	m_UM/*分*/;
	double	m_US/*秒*/;
	long	m_EntityID/*实体ID*/;
	COrbitData	m_OrbitCoe/*轨道参数*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
