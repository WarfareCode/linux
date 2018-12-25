//MoveAlongCircleRouteTask.h: interface for the CMoveAlongCircleRouteTask module.
//!!HDOSE_CLASS(CMoveAlongCircleRouteTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveAlongCircleRouteTask_H)
#define AFX_MoveAlongCircleRouteTask_H



//{{HDOSE_CLS_DES(CMoveAlongCircleRouteTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveAlongCircleRouteTask /*按指定圆形线路运动*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CMoveAlongCircleRouteTask();
	virtual ~CMoveAlongCircleRouteTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetCenterPos(GeoPt val){m_CenterPos=val;}
	GeoPt	GetCenterPos(){return m_CenterPos;}
	void	SetRadius(double val){m_Radius=val;}
	double	GetRadius(){return m_Radius;}
	void	SetAssignedSpeed(double val){m_AssignedSpeed=val;}
	double	GetAssignedSpeed(){return m_AssignedSpeed;}
	void	SetbAssignedControlObj(bool val){m_bAssignedControlObj=val;}
	bool	GetbAssignedControlObj(){return m_bAssignedControlObj;}
	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	//void	SetAssignedCircleObjName(char* val){strcpy(m_AssignedCircleObjName,val);}
	//char*	GetAssignedCircleObjName(){return m_AssignedCircleObjName;}

	void	SetAssignedCircleObjName(char* val){SetValueString("AssignedCircleObjName",val);}
	char*	GetAssignedCircleObjName(){return GetValueString("AssignedCircleObjName");}

	//{{HDOSE_MEMBER_FUNCTION(CMoveAlongCircleRouteTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveAlongCircleRouteTask)
	GeoPt	m_CenterPos/*圆心位置*/;
	double	m_Radius/*半径（m）*/;
	double	m_AssignedSpeed/*速度（m/s）*/;
	bool	m_bAssignedControlObj/*是否指定圆形控制对象（0否，1是）*/;
	char*	m_AssignedCircleObjName/*指定圆形控制对象名称*/;
	long	m_FieldNo/*阵地编号（岸导阵地、舰艇、飞机等作战单位的编号）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
