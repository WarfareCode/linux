//MoveAlongRouteTask.h: interface for the CMoveAlongRouteTask module.
//!!HDOSE_CLASS(CMoveAlongRouteTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveAlongRouteTask_H)
#define AFX_MoveAlongRouteTask_H



//{{HDOSE_CLS_DES(CMoveAlongRouteTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveAlongRouteTask /*按路线运动任务*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CMoveAlongRouteTask();
	virtual ~CMoveAlongRouteTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetAssigendRoute(GeoPt val[10]){
		for(int i=0;i<10;i++)
			m_AssigendRoute[i]=val[i];
	}
	GeoPt*	GetAssigendRoute(){return m_AssigendRoute;}
	void	SetRoutePointCount(long val){m_RoutePointCount=val;}
	long	GetRoutePointCount(){return m_RoutePointCount;}
	void	SetAssignedSpeed(double val){m_AssignedSpeed=val;}
	double	GetAssignedSpeed(){return m_AssignedSpeed;}
	void	SetbPatrolOnRoute(bool val){m_bPatrolOnRoute=val;}
	bool	GetbPatrolOnRoute(){return m_bPatrolOnRoute;}
	void	SetbAssignedControlObj(bool val){m_bAssignedControlObj=val;}
	bool	GetbAssignedControlObj(){return m_bAssignedControlObj;}
	//void	SetAssignedRouteObjName(char* val){strcpy(m_AssignedRouteObjName,val);}
	//char*	GetAssignedRouteObjName(){return m_AssignedRouteObjName;}

	void	SetAssignedRouteObjName(char* val){SetValueString("AssignedRouteObjName",val);}
	char*	GetAssignedRouteObjName(){return GetValueString("AssignedRouteObjName");}

	//{{HDOSE_MEMBER_FUNCTION(CMoveAlongRouteTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveAlongRouteTask)
	long	m_FieldNo/*阵地编号（岸导阵地、舰艇、飞机等作战单位的编号）*/;
	GeoPt	m_AssigendRoute[10]/*10个位置点数据成员的数组， 要修改*/;
	long	m_RoutePointCount/*路线点的个数（最多10个）*/;
	double	m_AssignedSpeed/*速度*/;
	bool	m_bPatrolOnRoute/*是否在路线上巡逻（0否，1是）*/;
	bool	m_bAssignedControlObj/*是否指定线控制对象（0否，1是）*/;
	char*	m_AssignedRouteObjName/*指定路线控制对象名称*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
