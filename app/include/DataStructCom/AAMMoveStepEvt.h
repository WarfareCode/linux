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

class DATASTRUCTCOMPONENTDLL_API CAAMMoveStepEvt /*���յ��˶��׶��¼�*/ : public CEvt 
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
	int	m_MoveStep/*�˶��׶Σ�0������1ƽ�ɿɽ������Ƶ�ָ�2�ɽ���ĩ�������Ƶ�ָ�3�����״￪��������������ָ�4��5����Ի١�6�����¼���*/;
	int	m_MotherShipNo/*ĸ����ţ���Ӧ�����������ڵĽ�ͧ��ţ�*/;
	int	m_AAMNo/*���յ����*/;
	long	m_TargetNo/*Ŀ����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
