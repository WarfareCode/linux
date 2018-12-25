//RegulateMoveState.h: interface for the CRegulateMoveState module.
//!!HDOSE_CLASS(CRegulateMoveState,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RegulateMoveState_H)
#define AFX_RegulateMoveState_H


//{{HDOSE_CLS_DES(CRegulateMoveState)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CRegulateMoveState /*�����˶�����*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CRegulateMoveState();
	virtual ~CRegulateMoveState();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetParaId(long val){m_ParaId=val;}
	long	GetParaId(){return m_ParaId;}
	void	SetParaValue(double val){m_ParaValue=val;}
	double	GetParaValue(){return m_ParaValue;}

	//{{HDOSE_MEMBER_FUNCTION(CRegulateMoveState)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRegulateMoveState)
	long	m_ParaId/*����Id���߶ȡ��ٶȡ�����*/;
	double	m_ParaValue/*����ֵ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
