//TargetIrradiateEvt.h: interface for the CTargetIrradiateEvt module.
//!!HDOSE_CLASS(CTargetIrradiateEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetIrradiateEvt_H)
#define AFX_TargetIrradiateEvt_H


//{{HDOSE_CLS_DES(CTargetIrradiateEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTargetIrradiateEvt /*Ŀ�������¼�*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTargetIrradiateEvt();
	virtual ~CTargetIrradiateEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetIrradiatorNo(int val){m_IrradiatorNo=val;}
	int	GetIrradiatorNo(){return m_IrradiatorNo;}
	void	SetAAMNo(int val){m_AAMNo=val;}
	int	GetAAMNo(){return m_AAMNo;}
	void	SetAAMType(int val){m_AAMType=val;}
	int	GetAAMType(){return m_AAMType;}
	void	SetTarNo(int val){m_TarNo=val;}
	int	GetTarNo(){return m_TarNo;}

	//{{HDOSE_MEMBER_FUNCTION(CTargetIrradiateEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTargetIrradiateEvt)
	int	m_IrradiatorNo/*����ͨ�����*/;
	int	m_AAMNo/*����Ӧ�ķ��յ����*/;
	int	m_AAMType/*���յ����ͣ������ж�����������������*/;
	int	m_TarNo/*Ŀ����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
