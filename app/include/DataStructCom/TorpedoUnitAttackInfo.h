//TorpedoUnitAttackInfo.h: interface for the CTorpedoUnitAttackInfo module.
//!!HDOSE_CLASS(CTorpedoUnitAttackInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoUnitAttackInfo_H)
#define AFX_TorpedoUnitAttackInfo_H


//{{HDOSE_CLS_DES(CTorpedoUnitAttackInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoUnitAttackInfo /*���׵�Ԫ������Ϣ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoUnitAttackInfo();
	virtual ~CTorpedoUnitAttackInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoUnitAttackInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoUnitAttackInfo)
	long	m_FieldNo/*��ر�ţ�������ء���ͧ���ɻ�����ս��λ�ı�ţ�*/;
	long	m_TargetNo/*Ŀ����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
