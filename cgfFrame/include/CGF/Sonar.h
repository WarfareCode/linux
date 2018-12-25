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

class CSonar /*����(HYCGF)*/ : public CSensor 
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
	long	m_ActiveDetectDist/*����̽�����*/;
	long	m_PassiveDetectDist/*����̽�����*/;
	long	m_WorkSystem/*�������ƣ���������������ϣ�*/;
	double	m_ActiveWorkFreq/*��������Ƶ��*/;
	CDataRange	m_PassiveWorkFreq/*��������Ƶ��(","�ָ�)*/;
	double	m_ActivePower/*��������*/;
	double	m_DetectPeriod/*̽������*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSonar)
	long	m_WorkingMode/*��ǰ����ģʽ*/;
	CDataRange	m_WorkingFreq/*��ǰ����Ƶ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
