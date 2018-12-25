//SimCtrl.h: interface for the CSimCtrl module.
//!!HDOSE_CLASS(CSimCtrl,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimCtrl_H)
#define AFX_SimCtrl_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CSimCtrl)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSimCtrl /*仿真控制*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CSimCtrl();
	virtual ~CSimCtrl();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSimCtrlType(int val){m_SimCtrlType=val;}
	int	GetSimCtrlType(){return m_SimCtrlType;}
	void	SetClockChange(int val){m_ClockChange=val;}
	int	GetClockChange(){return m_ClockChange;}
	void	SetWallClock(double val){m_WallClock=val;}
	double	GetWallClock(){return m_WallClock;}
	void	SetLogicClock(double val){m_LogicClock=val;}
	double	GetLogicClock(){return m_LogicClock;}
	void	SetSpeedUpRate(double val){m_SpeedUpRate=val;}
	double	GetSpeedUpRate(){return m_SpeedUpRate;}
	void	SetRealWorldTime(double val){m_RealWorldTime=val;}
	double	GetRealWorldTime(){return m_RealWorldTime;}

	//{{HDOSE_MEMBER_FUNCTION(CSimCtrl)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimCtrl)
	int	m_SimCtrlType/*仿真控制类型（1-开始、2-暂停、3-重置、4-尽量快、5-时间比例）*/;
	int	m_ClockChange/*是否设置时钟步长(0-不设置、1-同时设置物理时钟步长和逻辑时钟步长、2-只设置物理时钟步长、3-只设置逻辑时钟步长、4-设置加速比率、5-设置真实时间)*/;
	double	m_WallClock/*物理时钟步长,s*/;
	double	m_LogicClock/*逻辑时钟步长,s*/;
	double	m_SpeedUpRate/*加速比率（加速倍率，比如0.1、0.5、1、2、5、10）*/;
	double	m_RealWorldTime/*真实时间,s*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
