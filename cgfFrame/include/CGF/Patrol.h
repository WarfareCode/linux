//Patrol.h: interface for the CPatrol module.
//!!HDOSE_CLASS(CPatrol,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Patrol_H)
#define AFX_Patrol_H

#include "Task.h"

//{{HDOSE_CLS_DES(CPatrol)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CPatrol /*巡逻(HYCGF)*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CPatrol();
	virtual ~CPatrol();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPatrolType(long val){m_PatrolType=val;}
	long	GetPatrolType(){return m_PatrolType;}
	void	SetAssignCtrlObjName_Id(long val){m_AssignCtrlObjName_Id=val;}
	long	GetAssignCtrlObjName_Id(){return m_AssignCtrlObjName_Id;}
	void	SetPoint1_Name(char* val){SetValueString("Point1_Name",val);}
	char*	GetPoint1_Name(){return GetValueString("Point1_Name");}
	void	SetPoint2_Name(char* val){SetValueString("Point2_Name",val);}
	char*	GetPoint2_Name(){return GetValueString("Point2_Name");}
	void	SetPoint1_Id(long val){m_Point1_Id=val;}
	long	GetPoint1_Id(){return m_Point1_Id;}
	void	SetPoint2_Id(long val){m_Point2_Id=val;}
	long	GetPoint2_Id(){return m_Point2_Id;}
	void	SetControlObjId(long val){m_ControlObjId=val;}
	long	GetControlObjId(){return m_ControlObjId;}
	void	SetControlObjName(char* val){SetValueString("ControlObjName",val);}
	char*	GetControlObjName(){return GetValueString("ControlObjName");}
	void	SetPatrolTime(double val){m_PatrolTime=val;}
	double	GetPatrolTime(){return m_PatrolTime;}
	void SetAreaPara(char* val){SetValueString("AreaPara",val);}
	char* GetAreaPara(){return GetValueString("AreaPara");}

	//{{HDOSE_MEMBER_FUNCTION(CPatrol)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CPatrol)
	long	m_PatrolType/*巡逻方式(1两点间巡逻、2按路线巡逻、3按多边形区域巡逻、4圆形区域巡逻、5椭圆形区域巡逻、6 8字形区域巡逻、7备用)*/;
	long	m_AssignCtrlObjName_Id/*指定控制对象的方式,名称或Id(1-名称、2-Id、3-直接给定区域位置描述数据)*/;
	char*	m_Point1_Name/*控制点1名称*/;
	char*	m_Point2_Name/*控制点2名称*/;
	long	m_Point1_Id/*控制点1Id*/;
	long	m_Point2_Id/*控制点2Id*/;
	long	m_ControlObjId/*路线或区域控制对象Id*/;
	char*	m_ControlObjName/*路线或区域控制对象名称*/;
	double	m_PatrolTime/*巡逻时间*/;

	// ----20171227新增---------
	/* *m_AreaPara格式规定如下：
	* 两个巡逻点：lat, lon, alt(m) ; lat, lon, alt(m)  ; 
	* 巡逻路线: lat, lon, alt(m)  ; lat, lon, alt(m)  ; ... ;
	* 多边形区域： 按顺时针方向或逆时针方向依次将点写入：lat, lon, alt(m)  ; lat, lon, alt(m)  ; ... ;
	* 圆形区域：lat, lon, alt(m)  ; Radius(km) ;
	* 椭圆区域：lat, lon, alt(m)  ; RadiusMajorSemi_km(km) ; RadiusMinorSemi_km ;  HeadingMajorAxis_deg ;
	* 8字形区域：lat, lon, alt(m)  ; RadiusMajorSemi_km(km) ; RadiusMinorSemi_km ;  HeadingMajorAxis_deg ;
	*/
	char* m_AreaPara/*巡逻点，巡逻路线，巡逻区域的直接描述数据*/;
	// -------------------------------

	//}}HDOSE_ATTRIBUTE
};

#endif
