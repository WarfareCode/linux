//AircrftScheduleOrder.h: interface for the CAircrftScheduleOrder module.
//!!HDOSE_CLASS(CAircrftScheduleOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AircrftScheduleOrder_H)
#define AFX_AircrftScheduleOrder_H



//{{HDOSE_CLS_DES(CAircrftScheduleOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAircrftScheduleOrder /*飞机调度指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAircrftScheduleOrder();
	virtual ~CAircrftScheduleOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
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
	void	SetRoutePointCount(int val){m_RoutePointCount=val;}
	int	GetRoutePointCount(){return m_RoutePointCount;}
	void	SetbAssignedSpeed(bool val){m_bAssignedSpeed=val;}
	bool	GetbAssignedSpeed(){return m_bAssignedSpeed;}
	void	SetbAssignedCourse(bool val){m_bAssignedCourse=val;}
	bool	GetbAssignedCourse(){return m_bAssignedCourse;}
	void	SetbAssignedPoint(bool val){m_bAssignedPoint=val;}
	bool	GetbAssignedPoint(){return m_bAssignedPoint;}
	void	SetbAssignedRoute(bool val){m_bAssignedRoute=val;}
	bool	GetbAssignedRoute(){return m_bAssignedRoute;}

	//{{HDOSE_MEMBER_FUNCTION(CAircrftScheduleOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAircrftScheduleOrder)
	long	m_FieldNo/*阵地编号*/;
	double	m_Speed/*航速*/;
	double	m_Course/*航向*/;
	GeoPt	m_AssignedPoint/*指定点*/;
	double	m_DelayTime/*延迟时间*/;
	GeoPt	m_AssigendRoute[10]/*指定路线（10个元素的数组数组，修改）*/;
	int	m_RoutePointCount/*路线点的个数（最多10个）*/;
	bool	m_bAssignedSpeed/*是否指定航速*/;
	bool	m_bAssignedCourse/*是否指定航向*/;
	bool	m_bAssignedPoint/*是否指定点*/;
	bool	m_bAssignedRoute/*是否指定路线*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
