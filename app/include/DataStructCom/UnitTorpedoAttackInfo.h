//UnitTorpedoAttackInfo.h: interface for the CUnitTorpedoAttackInfo module.
//!!HDOSE_CLASS(CUnitTorpedoAttackInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_UnitTorpedoAttackInfo_H)
#define AFX_UnitTorpedoAttackInfo_H


//{{HDOSE_CLS_DES(CUnitTorpedoAttackInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CUnitTorpedoAttackInfo /*��ս��Ԫ���׹�����Ϣ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CUnitTorpedoAttackInfo();
	virtual ~CUnitTorpedoAttackInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}

	//{{HDOSE_MEMBER_FUNCTION(CUnitTorpedoAttackInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CUnitTorpedoAttackInfo)
	long	m_FieldNo/*��ر�ţ�������ء���ͧ���ɻ�����ս��λ�ı�ţ�*/;
	long	m_TargetNo/*Ŀ����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
