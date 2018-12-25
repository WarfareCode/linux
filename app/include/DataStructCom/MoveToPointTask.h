//MoveToPointTask.h: interface for the CMoveToPointTask module.
//!!HDOSE_CLASS(CMoveToPointTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveToPointTask_H)
#define AFX_MoveToPointTask_H



//{{HDOSE_CLS_DES(CMoveToPointTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveToPointTask /*运动到指定点任务*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CMoveToPointTask();
	virtual ~CMoveToPointTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetAssignedPoint(GeoPt val){m_AssignedPoint=val;}
	GeoPt	GetAssignedPoint(){return m_AssignedPoint;}
	void	SetAssignedSpeed(double val){m_AssignedSpeed=val;}
	double	GetAssignedSpeed(){return m_AssignedSpeed;}
	void	SetbAssignedControlObj(bool val){m_bAssignedControlObj=val;}
	bool	GetbAssignedControlObj(){return m_bAssignedControlObj;}
	//void	SetAssignedPointObjName(char* val){strcpy(m_AssignedPointObjName,val);}
	//char*	GetAssignedPointObjName(){return m_AssignedPointObjName;}

	void	SetAssignedPointObjName(char* val){SetValueString("AssignedPointObjName",val);}
	char*	GetAssignedPointObjName(){return GetValueString("AssignedPointObjName");}

	//{{HDOSE_MEMBER_FUNCTION(CMoveToPointTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveToPointTask)
	long	m_FieldNo/*阵地编号（岸导阵地、舰艇、飞机等作战单位的编号）*/;
	GeoPt	m_AssignedPoint/*指定位置*/;
	double	m_AssignedSpeed/*速度（m/s)*/;
	bool	m_bAssignedControlObj/*是否指定点控制对象（0否，1是）*/;
	char*	m_AssignedPointObjName/*指定的点控制对象名称*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
