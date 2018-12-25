//ForceScheduleTask.h: interface for the CForceScheduleTask module.
//!!HDOSE_CLASS(CForceScheduleTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ForceScheduleTask_H)
#define AFX_ForceScheduleTask_H



//{{HDOSE_CLS_DES(CForceScheduleTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CForceScheduleTask /*������������*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CForceScheduleTask();
	virtual ~CForceScheduleTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFeildNo(long val){m_FeildNo=val;}
	long	GetFeildNo(){return m_FeildNo;}
	void	SetSpeed(double val){m_Speed=val;}
	double	GetSpeed(){return m_Speed;}
	void	SetCourse(double val){m_Course=val;}
	double	GetCourse(){return m_Course;}
	void	SetAssignedPoint(GeoPt val){m_AssignedPoint=val;}
	GeoPt	GetAssignedPoint(){return m_AssignedPoint;}
	void	SetDelayTime(double val){m_DelayTime=val;}
	double	GetDelayTime(){return m_DelayTime;}
	void	SetAssigendRoute(GeoPt val[10]){
		for(int i=0;i<10;i++)
			m_AssigendRoute[i]=val[i];
	}
	GeoPt*	GetAssigendRoute(){return m_AssigendRoute;}
	void	SetRoutePointCount(long val){m_RoutePointCount=val;}
	long	GetRoutePointCount(){return m_RoutePointCount;}
	void	SetbAssignedSpeed(bool val){m_bAssignedSpeed=val;}
	bool	GetbAssignedSpeed(){return m_bAssignedSpeed;}
	void	SetbAssignedCourse(bool val){m_bAssignedCourse=val;}
	bool	GetbAssignedCourse(){return m_bAssignedCourse;}
	void	SetbAssignedPoint(bool val){m_bAssignedPoint=val;}
	bool	GetbAssignedPoint(){return m_bAssignedPoint;}
	void	SetbAssignedRoute(bool val){m_bAssignedRoute=val;}
	bool	GetbAssignedRoute(){return m_bAssignedRoute;}
	void	SetbPatrolOnRoute(bool val){m_bPatrolOnRoute=val;}
	bool	GetbPatrolOnRoute(){return m_bPatrolOnRoute;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}

	//{{HDOSE_MEMBER_FUNCTION(CForceScheduleTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CForceScheduleTask)
	long	m_FeildNo/*��ر�ţ�������ء���ͧ���ɻ�����ս��λ�ı�ţ�*/;
	double	m_Speed/*����*/;
	double	m_Course/*����*/;
	GeoPt	m_AssignedPoint/*ָ����*/;
	double	m_DelayTime/*�ӳ�ʱ��*/;
	GeoPt	m_AssigendRoute[10]/*ָ��·�ߣ�10��Ԫ�ص����飬�޸ģ�*/;
	long	m_RoutePointCount/*·�ߵ�ĸ��������10����*/;
	bool	m_bAssignedSpeed/*�Ƿ�ָ�����٣�0��1�ǣ�*/;
	bool	m_bAssignedCourse/*�Ƿ�ָ������0��1�ǣ�*/;
	bool	m_bAssignedPoint/*�Ƿ�ָ���㣨0��1�ǣ�*/;
	bool	m_bAssignedRoute/*�Ƿ�ָ��·�ߣ�0��1�ǣ�*/;
	bool	m_bPatrolOnRoute/*�Ƿ���·����Ѳ�ߣ�0��1�ǣ�*/;
	long	m_ForceType/*��������ʶ��0����1�죩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
