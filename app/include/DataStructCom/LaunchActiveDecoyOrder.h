//LaunchActiveDecoyOrder.h: interface for the CLaunchActiveDecoyOrder module.
//!!HDOSE_CLASS(CLaunchActiveDecoyOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchActiveDecoyOrder_H)
#define AFX_LaunchActiveDecoyOrder_H



//{{HDOSE_CLS_DES(CLaunchActiveDecoyOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CLaunchActiveDecoyOrder /*布放有源诱饵弹指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CLaunchActiveDecoyOrder();
	virtual ~CLaunchActiveDecoyOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}
	void	SetCourse(double val){m_Course=val;}
	double	GetCourse(){return m_Course;}
	void	SetVelocity(double val){m_Velocity=val;}
	double	GetVelocity(){return m_Velocity;}
	void	SetAtennaOrientation(double val){m_AtennaOrientation=val;}
	double	GetAtennaOrientation(){return m_AtennaOrientation;}
	void	SetActiveDecoyType(long val){m_ActiveDecoyType=val;}
	long	GetActiveDecoyType(){return m_ActiveDecoyType;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchActiveDecoyOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchActiveDecoyOrder)
	GeoPt	m_Position/*布放位置*/;
	double	m_LaunchAz/*发射方位 0-360deg*/;
	double	m_LaunchDist/*发射距离 m (水平面距离)*/;
	double	m_Course/*航向*/;
	double	m_Velocity/*航速*/;
	double	m_AtennaOrientation/*天线指向*/;
	long	m_ActiveDecoyType/*诱饵弹类型（1-SSQ95、2-Nulka）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
