//InfraredDecoyLaunchParams.h: interface for the CInfraredDecoyLaunchParams module.
//!!HDOSE_CLASS(CInfraredDecoyLaunchParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_InfraredDecoyLaunchParams_H)
#define AFX_InfraredDecoyLaunchParams_H


//{{HDOSE_CLS_DES(CInfraredDecoyLaunchParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CInfraredDecoyLaunchParams /*红外诱饵发射参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CInfraredDecoyLaunchParams();
	virtual ~CInfraredDecoyLaunchParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLaunchAz(double val){m_LaunchAz=val;}
	double	GetLaunchAz(){return m_LaunchAz;}
	void	SetLaunchEl(double val){m_LaunchEl=val;}
	double	GetLaunchEl(){return m_LaunchEl;}
	void	SetLaunchPltType(long val){m_LaunchPltType=val;}
	long	GetLaunchPltType(){return m_LaunchPltType;}
	void	SetUnitNumber(long val){m_UnitNumber=val;}
	long	GetUnitNumber(){return m_UnitNumber;}
	void	SetExpanTime(double val){m_ExpanTime=val;}
	double	GetExpanTime(){return m_ExpanTime;}
	void	SetLaunchVel(double val){m_LaunchVel=val;}
	double	GetLaunchVel(){return m_LaunchVel;}

	//{{HDOSE_MEMBER_FUNCTION(CInfraredDecoyLaunchParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CInfraredDecoyLaunchParams)
	double	m_LaunchAz/*发射方位角*/;
	double	m_LaunchEl/*发射高低角*/;
	long	m_LaunchPltType/*发射平台类型*/;
	long	m_UnitNumber/*红外弹单元编号*/;
	double	m_ExpanTime/*展开时间*/;
	double	m_LaunchVel/*发射初速度*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
