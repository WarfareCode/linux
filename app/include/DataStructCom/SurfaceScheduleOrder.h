//SurfaceScheduleOrder.h: interface for the CSurfaceScheduleOrder module.
//!!HDOSE_CLASS(CSurfaceScheduleOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SurfaceScheduleOrder_H)
#define AFX_SurfaceScheduleOrder_H



//{{HDOSE_CLS_DES(CSurfaceScheduleOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSurfaceScheduleOrder /*��ͧ����ָ��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSurfaceScheduleOrder();
	virtual ~CSurfaceScheduleOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSurfaceNo(long val){m_SurfaceNo=val;}
	long	GetSurfaceNo(){return m_SurfaceNo;}
	void	SetSpeed(double val){m_Speed=val;}
	double	GetSpeed(){return m_Speed;}
	void	SetCourse(double val){m_Course=val;}
	double	GetCourse(){return m_Course;}
	void	SetAssignedPoint(GeoPt val){m_AssignedPoint=val;}
	GeoPt	GetAssignedPoint(){return m_AssignedPoint;}
	void	SetDelayTime(long val){m_DelayTime=val;}
	long	GetDelayTime(){return m_DelayTime;}
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

	//{{HDOSE_MEMBER_FUNCTION(CSurfaceScheduleOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSurfaceScheduleOrder)
	long	m_SurfaceNo/*��ͧ���*/;
	double	m_Speed/*����*/;
	double	m_Course/*����*/;
	GeoPt	m_AssignedPoint/*ָ����*/;
	long	m_DelayTime/*�ӳ�ʱ��*/;
	GeoPt	m_AssigendRoute[10]/*ָ��·�ߣ�10��Ԫ�ص����飬�޸ģ�*/;
	long	m_RoutePointCount/*·�ߵ�ĸ��������10���㣩*/;
	bool	m_bAssignedSpeed/*�Ƿ�ָ������*/;
	bool	m_bAssignedCourse/*�Ƿ�ָ������*/;
	bool	m_bAssignedPoint/*�Ƿ�ָ����*/;
	bool	m_bAssignedRoute/*�Ƿ�ָ��·��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
