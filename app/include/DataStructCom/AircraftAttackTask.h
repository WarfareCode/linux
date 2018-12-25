//AircraftAttackTask.h: interface for the CAircraftAttackTask module.
//!!HDOSE_CLASS(CAircraftAttackTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AircraftAttackTask_H)
#define AFX_AircraftAttackTask_H



//{{HDOSE_CLS_DES(CAircraftAttackTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAircraftAttackTask /*飞机攻击任务*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CAircraftAttackTask();
	virtual ~CAircraftAttackTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetAttackPos(GeoPt val){m_AttackPos=val;}
	GeoPt	GetAttackPos(){return m_AttackPos;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetAttackASMCount(long val){m_AttackASMCount=val;}
	long	GetAttackASMCount(){return m_AttackASMCount;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}

	//{{HDOSE_MEMBER_FUNCTION(CAircraftAttackTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAircraftAttackTask)
	long	m_FieldNo/*阵地编号（岸导阵地、舰艇、飞机等作战单位的编号）*/;
	GeoPt	m_AttackPos/*发起攻击点*/;
	long	m_TargetNo/*目标编号*/;
	long	m_AttackASMCount/*攻击导弹数量*/;
	long	m_ForceType/*红蓝方标识（0蓝，1红）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
