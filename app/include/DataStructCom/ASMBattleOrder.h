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

class DATASTRUCTCOMPONENTDLL_API CASMBattleOrder /*反舰导弹战斗指令*/ : public CEvt 
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
	long	m_MissileBattleInstruction/*导弹战斗指令（0-航战开、1航战关、2高战、3俯冲）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
