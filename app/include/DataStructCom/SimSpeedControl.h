//SimSpeedControl.h: interface for the CSimSpeedControl module.
//!!HDOSE_CLASS(CSimSpeedControl,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimSpeedControl_H)
#define AFX_SimSpeedControl_H


//{{HDOSE_CLS_DES(CSimSpeedControl)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSimSpeedControl /*仿真速度控制*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSimSpeedControl();
	virtual ~CSimSpeedControl();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSpeedTimes(long val){m_SpeedTimes=val;}
	long	GetSpeedTimes(){return m_SpeedTimes;}

	//{{HDOSE_MEMBER_FUNCTION(CSimSpeedControl)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimSpeedControl)
	long	m_SpeedTimes/*速度倍数（0、1、--10）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
