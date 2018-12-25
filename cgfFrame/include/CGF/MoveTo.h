//MoveTo.h: interface for the CMoveTo module.
//!!HDOSE_CLASS(CMoveTo,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveTo_H)
#define AFX_MoveTo_H

#include "Task.h"

//{{HDOSE_CLS_DES(CMoveTo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CMoveTo /*�˶���ָ����(HYCGF)*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CMoveTo();
	virtual ~CMoveTo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetAssignCtrlObjName_Id(long val){m_AssignCtrlObjName_Id=val;}
	long	GetAssignCtrlObjName_Id(){return m_AssignCtrlObjName_Id;}
	void	SetControlObjName(char* val){SetValueString("ControlObjName",val);}
	char*	GetControlObjName(){return GetValueString("ControlObjName");}
	void	SetControlObjId(long val){m_ControlObjId=val;}
	long	GetControlObjId(){return m_ControlObjId;}
	void	SetLimitConditionType(long val){m_LimitConditionType=val;}
	long	GetLimitConditionType(){return m_LimitConditionType;}
	void	SetMoveVel(double val){m_MoveVel=val;}
	double	GetMoveVel(){return m_MoveVel;}
	void	SetMoveTime(double val){m_MoveTime=val;}
	double	GetMoveTime(){return m_MoveTime;}
	void	SetDesPoint(GeoPt val){m_DesPoint=val;}
	GeoPt	GetDesPoint(){return m_DesPoint;}

	//{{HDOSE_MEMBER_FUNCTION(CMoveTo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveTo)
	long	m_AssignCtrlObjName_Id/*ָ�����ƶ���ķ�ʽ,���ƻ�Id(1���ơ�2Id��3λ�õ�)*/;
	char*	m_ControlObjName/*���ƶ�������*/;
	long	m_ControlObjId/*���ƶ���Id*/;
	long	m_LimitConditionType/*������������(1���ٶȡ�2��ʱ��)*/;
	double	m_MoveVel/*ָ�����˶��ٶ�(���˶�ʱ���ѡһ)*/;
	double	m_MoveTime/*ָ�����˶�ʱ��*/;
	GeoPt	m_DesPoint/*Ŀ�ĵ�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
