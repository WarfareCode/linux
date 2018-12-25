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

class HYCGF_API CSimCtrl /*�������*/ : public CConsoleEvt 
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
	int	m_SimCtrlType/*����������ͣ�1-��ʼ��2-��ͣ��3-���á�4-�����졢5-ʱ�������*/;
	int	m_ClockChange/*�Ƿ�����ʱ�Ӳ���(0-�����á�1-ͬʱ��������ʱ�Ӳ������߼�ʱ�Ӳ�����2-ֻ��������ʱ�Ӳ�����3-ֻ�����߼�ʱ�Ӳ�����4-���ü��ٱ��ʡ�5-������ʵʱ��)*/;
	double	m_WallClock/*����ʱ�Ӳ���,s*/;
	double	m_LogicClock/*�߼�ʱ�Ӳ���,s*/;
	double	m_SpeedUpRate/*���ٱ��ʣ����ٱ��ʣ�����0.1��0.5��1��2��5��10��*/;
	double	m_RealWorldTime/*��ʵʱ��,s*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
