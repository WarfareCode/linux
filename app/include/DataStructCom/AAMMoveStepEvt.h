//AAMMoveStepEvt.h: interface for the CAAMMoveStepEvt module.
//!!HDOSE_CLASS(CAAMMoveStepEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMMoveStepEvt_H)
#define AFX_AAMMoveStepEvt_H


//{{HDOSE_CLS_DES(CAAMMoveStepEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMMoveStepEvt /*防空弹运动阶段事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAAMMoveStepEvt();
	virtual ~CAAMMoveStepEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetMoveStep(int val){m_MoveStep=val;}
	int	GetMoveStep(){return m_MoveStep;}
	void	SetMotherShipNo(int val){m_MotherShipNo=val;}
	int	GetMotherShipNo(){return m_MotherShipNo;}
	void	SetAAMNo(int val){m_AAMNo=val;}
	int	GetAAMNo(){return m_AAMNo;}
	void	SetTargetNo(int val){m_TargetNo=val;}
	int	GetTargetNo(){return m_TargetNo;}

	//{{HDOSE_MEMBER_FUNCTION(CAAMMoveStepEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAAMMoveStepEvt)
	int	m_MoveStep/*运动阶段（0爬升、1平飞可接收中制导指令、2可接收末端照射制导指令、3主动雷达开机不接收照射器指令、4、5错过自毁、6交汇事件）*/;
	int	m_MotherShipNo/*母舰编号（对应的照射器所在的舰艇编号）*/;
	int	m_AAMNo/*防空弹编号*/;
	long	m_TargetNo/*目标编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
