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

class HYCGF_API CPatrol /*Ѳ��(HYCGF)*/ : public CTask 
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
	long	m_PatrolType/*Ѳ�߷�ʽ(1�����Ѳ�ߡ�2��·��Ѳ�ߡ�3�����������Ѳ�ߡ�4Բ������Ѳ�ߡ�5��Բ������Ѳ�ߡ�6 8��������Ѳ�ߡ�7����)*/;
	long	m_AssignCtrlObjName_Id/*ָ�����ƶ���ķ�ʽ,���ƻ�Id(1-���ơ�2-Id��3-ֱ�Ӹ�������λ����������)*/;
	char*	m_Point1_Name/*���Ƶ�1����*/;
	char*	m_Point2_Name/*���Ƶ�2����*/;
	long	m_Point1_Id/*���Ƶ�1Id*/;
	long	m_Point2_Id/*���Ƶ�2Id*/;
	long	m_ControlObjId/*·�߻�������ƶ���Id*/;
	char*	m_ControlObjName/*·�߻�������ƶ�������*/;
	double	m_PatrolTime/*Ѳ��ʱ��*/;

	// ----20171227����---------
	/* *m_AreaPara��ʽ�涨���£�
	* ����Ѳ�ߵ㣺lat, lon, alt(m) ; lat, lon, alt(m)  ; 
	* Ѳ��·��: lat, lon, alt(m)  ; lat, lon, alt(m)  ; ... ;
	* ��������� ��˳ʱ�뷽�����ʱ�뷽�����ν���д�룺lat, lon, alt(m)  ; lat, lon, alt(m)  ; ... ;
	* Բ������lat, lon, alt(m)  ; Radius(km) ;
	* ��Բ����lat, lon, alt(m)  ; RadiusMajorSemi_km(km) ; RadiusMinorSemi_km ;  HeadingMajorAxis_deg ;
	* 8��������lat, lon, alt(m)  ; RadiusMajorSemi_km(km) ; RadiusMinorSemi_km ;  HeadingMajorAxis_deg ;
	*/
	char* m_AreaPara/*Ѳ�ߵ㣬Ѳ��·�ߣ�Ѳ�������ֱ����������*/;
	// -------------------------------

	//}}HDOSE_ATTRIBUTE
};

#endif
