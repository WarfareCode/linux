//LaunchActiveDecoyTask.h: interface for the CLaunchActiveDecoyTask module.
//!!HDOSE_CLASS(CLaunchActiveDecoyTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchActiveDecoyTask_H)
#define AFX_LaunchActiveDecoyTask_H



//{{HDOSE_CLS_DES(CLaunchActiveDecoyTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CLaunchActiveDecoyTask /*布放有源诱饵任务*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CLaunchActiveDecoyTask();
	virtual ~CLaunchActiveDecoyTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
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

	//{{HDOSE_MEMBER_FUNCTION(CLaunchActiveDecoyTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchActiveDecoyTask)
	long	m_FieldNo/*作战单位编号*/;
	GeoPt	m_Position/*布放位置*/;
	double	m_Course/*航向*/;
	double	m_Velocity/*航速*/;
	double	m_AtennaOrientation/*天线指向*/;
	long	m_ActiveDecoyType/*诱饵弹类型（0SSQ95、1）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
