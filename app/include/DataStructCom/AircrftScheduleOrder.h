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

class DATASTRUCTCOMPONENTDLL_API CAircrftScheduleOrder /*�ɻ�����ָ��*/ : public CEvt 
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
	long	m_FieldNo/*��ر��*/;
	double	m_Speed/*����*/;
	double	m_Course/*����*/;
	GeoPt	m_AssignedPoint/*ָ����*/;
	double	m_DelayTime/*�ӳ�ʱ��*/;
	GeoPt	m_AssigendRoute[10]/*ָ��·�ߣ�10��Ԫ�ص��������飬�޸ģ�*/;
	int	m_RoutePointCount/*·�ߵ�ĸ��������10����*/;
	bool	m_bAssignedSpeed/*�Ƿ�ָ������*/;
	bool	m_bAssignedCourse/*�Ƿ�ָ������*/;
	bool	m_bAssignedPoint/*�Ƿ�ָ����*/;
	bool	m_bAssignedRoute/*�Ƿ�ָ��·��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
