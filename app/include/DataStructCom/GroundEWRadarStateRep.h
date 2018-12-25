//GroundEWRadarStateRep.h: interface for the CGroundEWRadarStateRep module.
//!!HDOSE_CLASS(CGroundEWRadarStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_GroundEWRadarStateRep_H)
#define AFX_GroundEWRadarStateRep_H

#include "CGF/FacilityESR.h"

//{{HDOSE_CLS_DES(CGroundEWRadarStateRep)
/*
Author:		xks
Version:	1.0
Descript:	特定用处
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CGroundEWRadarStateRep /*地面预警雷达状态池*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CGroundEWRadarStateRep();
	virtual ~CGroundEWRadarStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetType(long val){m_Type=val;}
	long	GetType(){return m_Type;}
	void	SetDetectRadius(double val){m_DetectRadius=val;}
	double	GetDetectRadius(){return m_DetectRadius;}
	void	SetDetectSection(double val){m_DetectSection=val;}
	double	GetDetectSection(){return m_DetectSection;}

	//{{HDOSE_MEMBER_FUNCTION(CGroundEWRadarStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CGroundEWRadarStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CGroundEWRadarStateRep)
	long	m_Type/*类别，1/2/3*/;
	double	m_DetectRadius/*探测半径，m*/;
	double	m_DetectSection/*探测扇区，deg*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
