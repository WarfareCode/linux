//Recall.h: interface for the CRecall module.
//!!HDOSE_CLASS(CRecall,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Recall_H)
#define AFX_Recall_H


//{{HDOSE_CLS_DES(CRecall)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CRecall /*回收兵力*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CRecall();
	virtual ~CRecall();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetObjId(long val){m_ObjId=val;}
	long	GetObjId(){return m_ObjId;}
	void	SetHostId(long val){m_HostId=val;}
	long	GetHostId(){return m_HostId;}

	//{{HDOSE_MEMBER_FUNCTION(CRecall)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRecall)
	long	m_ObjId/*回收兵力Id*/;
	long	m_HostId/*目的地Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
