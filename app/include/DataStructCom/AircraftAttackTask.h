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

class DATASTRUCTCOMPONENTDLL_API CAircraftAttackTask /*�ɻ���������*/ : public CTask 
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
	long	m_FieldNo/*��ر�ţ�������ء���ͧ���ɻ�����ս��λ�ı�ţ�*/;
	GeoPt	m_AttackPos/*���𹥻���*/;
	long	m_TargetNo/*Ŀ����*/;
	long	m_AttackASMCount/*������������*/;
	long	m_ForceType/*��������ʶ��0����1�죩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
