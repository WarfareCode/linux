//MoveAlong.h: interface for the CMoveAlong module.
//!!HDOSE_CLASS(CMoveAlong,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveAlong_H)
#define AFX_MoveAlong_H

#include "Task.h"

//{{HDOSE_CLS_DES(CMoveAlong)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CMoveAlong /*沿指定路线运动(HYCGF)*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CMoveAlong();
	virtual ~CMoveAlong();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetAssignCtrlObjName_Id(long val){m_AssignCtrlObjName_Id=val;}
	long	GetAssignCtrlObjName_Id(){return m_AssignCtrlObjName_Id;}
	void	SetControlObjName(char* val){SetValueString("ControlObjName",val);}
	char*	GetControlObjName(){return GetValueString("ControlObjName");}
	void	SetControlObjId(long val){m_ControlObjId=val;}
	long	GetControlObjId(){return m_ControlObjId;}
	void	SetRoute(char* val){SetValueString("Route",val);}
	char*	GetRoute(){return GetValueString("Route");}
	void	SetOverContorlPoint(bool val){m_OverContorlPoint=val;}
	bool	GetOverContorlPoint(){return m_OverContorlPoint;}
	void	SetMoveTime(double val){m_MoveTime=val;}
	double	GetMoveTime(){return m_MoveTime;}
	void	SetMoveVel(double val){m_MoveVel=val;}
	double	GetMoveVel(){return m_MoveVel;}
	void	SetLimitConditionType(long val){m_LimitConditionType=val;}
	long	GetLimitConditionType(){return m_LimitConditionType;}

	//{{HDOSE_MEMBER_FUNCTION(CMoveAlong)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveAlong)
	long	m_AssignCtrlObjName_Id/*指定控制对象的方式,名称或Id(1名称、2Id、3路线)*/;
	char*	m_ControlObjName/*控制对象名称*/;
	long	m_ControlObjId/*控制对象Id*/;
	char*	m_Route;/*路线，格式：lat,lon,hei;...;lat,lon,hei;*/
	bool	m_OverContorlPoint/*是否过顶飞行*/;
	double	m_MoveTime/*指定的运动时间*/;
	double	m_MoveVel/*指定的运动速度(与运动时间二选一)*/;
	long	m_LimitConditionType/*限制条件类型(1给速度、2给时间)*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
