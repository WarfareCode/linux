//TargetIndicatingEvt.h: interface for the CTargetIndicatingEvt module.
//!!HDOSE_CLASS(CTargetIndicatingEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetIndicatingEvt_H)
#define AFX_TargetIndicatingEvt_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CTargetIndicatingEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CTargetIndicatingEvt /*目标指示信息*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTargetIndicatingEvt();
	virtual ~CTargetIndicatingEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetCount(long val){m_TargetCount=val;}
	long	GetTargetCount(){return m_TargetCount;}
	void	SetTargetInfo(CTargetData val[])
	{
		for(int i=0;i<10;i++)
		m_TargetInfo[i]=val[i];
	}
	CTargetData*	GetTargetInfo(){return m_TargetInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CTargetIndicatingEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTargetIndicatingEvt)
	long	m_TargetCount/*目标个数*/;
	CTargetData	m_TargetInfo[10]/*目标信息（数组）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
