//ASMBattleOrder.h: interface for the CASMBattleOrder module.
//!!HDOSE_CLASS(CASMBattleOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMBattleOrder_H)
#define AFX_ASMBattleOrder_H


//{{HDOSE_CLS_DES(CASMBattleOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMBattleOrder /*��������ս��ָ��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CASMBattleOrder();
	virtual ~CASMBattleOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetMissileBattleInstruction(long val){m_MissileBattleInstruction=val;}
	long	GetMissileBattleInstruction(){return m_MissileBattleInstruction;}

	//{{HDOSE_MEMBER_FUNCTION(CASMBattleOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMBattleOrder)
	long	m_MissileBattleInstruction/*����ս��ָ�0-��ս����1��ս�ء�2��ս��3���壩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
