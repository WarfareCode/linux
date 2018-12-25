//Sonar.h: interface for the CSonar module.
//!!HDOSE_CLASS(CSonar,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Sonar_H)
#define AFX_Sonar_H

#include "Sensor.h"
#include "DataRange.h"

//{{HDOSE_CLS_DES(CSonar)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class CSonar /*声纳(HYCGF)*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSonar();
	virtual ~CSonar();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetWorkingMode(long val){m_WorkingMode=val;}
	long	GetWorkingMode(){return m_WorkingMode;}
	void	SetWorkingFreq(CDataRange val){m_WorkingFreq=val;}
	CDataRange	GetWorkingFreq(){return m_WorkingFreq;}
	long	GetActiveDetectDist(){return m_ActiveDetectDist;}
	long	GetPassiveDetectDist(){return m_PassiveDetectDist;}
	long	GetWorkSystem(){return m_WorkSystem;}
	double	GetActiveWorkFreq(){return m_ActiveWorkFreq;}
	CDataRange	GetPassiveWorkFreq(){return m_PassiveWorkFreq;}
	double	GetActivePower(){return m_ActivePower;}
	double	GetDetectPeriod(){return m_DetectPeriod;}

	//{{HDOSE_MEMBER_FUNCTION(CSonar)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSonar)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSonar)
	long	m_ActiveDetectDist/*主动探测距离*/;
	long	m_PassiveDetectDist/*被动探测距离*/;
	long	m_WorkSystem/*工作体制（主动、被动、组合）*/;
	double	m_ActiveWorkFreq/*主动工作频点*/;
	CDataRange	m_PassiveWorkFreq/*被动工作频段(","分隔)*/;
	double	m_ActivePower/*主动功率*/;
	double	m_DetectPeriod/*探测周期*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSonar)
	long	m_WorkingMode/*当前工作模式*/;
	CDataRange	m_WorkingFreq/*当前工作频段*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
