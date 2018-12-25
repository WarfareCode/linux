//TargetLossEvent.h: interface for the CTargetLossEvent module.
//!!HDOSE_CLASS(CTargetLossEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetLossEvent_H)
#define AFX_TargetLossEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CTargetLossEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CTargetLossEvent /*目标消失事件(HYCGF)*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTargetLossEvent();
	virtual ~CTargetLossEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetInfoSourceObjId(long val){m_InfoSourceObjId=val;}
	long	GetInfoSourceObjId(){return m_InfoSourceObjId;}
	void	SetBatchNo(long val){m_BatchNo=val;}
	long	GetBatchNo(){return m_BatchNo;}

	//{{HDOSE_MEMBER_FUNCTION(CTargetLossEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTargetLossEvent)
	long	m_InfoSourceObjId/*信息来源对象Id*/;
	long	m_BatchNo/*目标批号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
