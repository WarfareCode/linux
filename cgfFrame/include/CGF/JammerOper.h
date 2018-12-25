//JammerOper.h: interface for the CJammerOper module.
//!!HDOSE_CLASS(CJammerOper,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_JammerOper_H)
#define AFX_JammerOper_H


//{{HDOSE_CLS_DES(CJammerOper)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CJammerOper /*干扰机操作*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CJammerOper();
	virtual ~CJammerOper();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetJamMode(long val){m_JamMode=val;}
	long	GetJamMode(){return m_JamMode;}
	void	SetFrequency(double val){m_Frequency=val;}
	double	GetFrequency(){return m_Frequency;}
	void	SetPower(double val){m_Power=val;}
	double	GetPower(){return m_Power;}
	void	SetOrientation(double val){m_Orientation=val;}
	double	GetOrientation(){return m_Orientation;}
	void	SetPowerOn(bool val){m_PowerOn=val;}
	bool	GetPowerOn(){return m_PowerOn;}

	//{{HDOSE_MEMBER_FUNCTION(CJammerOper)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CJammerOper)
	long	m_JamMode/*干扰模式*/;
	double	m_Frequency/*频率*/;
	double	m_Power/*功率*/;
	double	m_Orientation/*方位*/;
	bool	m_PowerOn/*开关机*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
