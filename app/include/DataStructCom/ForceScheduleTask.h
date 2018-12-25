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

class DATASTRUCTCOMPONENTDLL_API CForceScheduleTask /*兵力调度任务*/ : public CTask 
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
	long	m_FeildNo/*阵地编号（岸导阵地、舰艇、飞机等作战单位的编号）*/;
	double	m_Speed/*航速*/;
	double	m_Course/*航向*/;
	GeoPt	m_AssignedPoint/*指定点*/;
	double	m_DelayTime/*延迟时间*/;
	GeoPt	m_AssigendRoute[10]/*指定路线（10个元素的数组，修改）*/;
	long	m_RoutePointCount/*路线点的个数（最多10个）*/;
	bool	m_bAssignedSpeed/*是否指定航速（0否，1是）*/;
	bool	m_bAssignedCourse/*是否指定航向（0否，1是）*/;
	bool	m_bAssignedPoint/*是否指定点（0否，1是）*/;
	bool	m_bAssignedRoute/*是否指定路线（0否，1是）*/;
	bool	m_bPatrolOnRoute/*是否在路线上巡逻（0否，1是）*/;
	long	m_ForceType/*红蓝方标识（0蓝，1红）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
