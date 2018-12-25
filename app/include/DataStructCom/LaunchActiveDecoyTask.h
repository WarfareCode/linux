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

class DATASTRUCTCOMPONENTDLL_API CLaunchActiveDecoyTask /*������Դ�ն�����*/ : public CTask 
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
	long	m_FieldNo/*��ս��λ���*/;
	GeoPt	m_Position/*����λ��*/;
	double	m_Course/*����*/;
	double	m_Velocity/*����*/;
	double	m_AtennaOrientation/*����ָ��*/;
	long	m_ActiveDecoyType/*�ն������ͣ�0SSQ95��1��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
