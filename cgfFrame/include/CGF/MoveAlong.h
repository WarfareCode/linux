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

class HYCGF_API CMoveAlong /*��ָ��·���˶�(HYCGF)*/ : public CTask 
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
	long	m_AssignCtrlObjName_Id/*ָ�����ƶ���ķ�ʽ,���ƻ�Id(1���ơ�2Id��3·��)*/;
	char*	m_ControlObjName/*���ƶ�������*/;
	long	m_ControlObjId/*���ƶ���Id*/;
	char*	m_Route;/*·�ߣ���ʽ��lat,lon,hei;...;lat,lon,hei;*/
	bool	m_OverContorlPoint/*�Ƿ��������*/;
	double	m_MoveTime/*ָ�����˶�ʱ��*/;
	double	m_MoveVel/*ָ�����˶��ٶ�(���˶�ʱ���ѡһ)*/;
	long	m_LimitConditionType/*������������(1���ٶȡ�2��ʱ��)*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
