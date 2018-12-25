//TorpedoAttackTask.h: interface for the CTorpedoAttackTask module.
//!!HDOSE_CLASS(CTorpedoAttackTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoAttackTask_H)
#define AFX_TorpedoAttackTask_H


//{{HDOSE_CLS_DES(CTorpedoAttackTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoAttackTask /*���׹�������*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CTorpedoAttackTask();
	virtual ~CTorpedoAttackTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoAttackTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoAttackTask)
	long	m_FieldNo/*��ر�ţ�������ء���ͧ���ɻ�����ս��λ�ı�ţ�*/;
	long	m_TargetNo/*Ŀ����*/;
	long	m_ForceType/*��������ʶ��0����1�죩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
