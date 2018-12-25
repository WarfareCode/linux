//Wait.h: interface for the CWait module.
//!!HDOSE_CLASS(CWait,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Wait_H)
#define AFX_Wait_H


//{{HDOSE_CLS_DES(CWait)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CWait /*等待*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CWait();
	virtual ~CWait();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetWaitTime(double val){m_WaitTime=val;}
	double	GetWaitTime(){return m_WaitTime;}

	//{{HDOSE_MEMBER_FUNCTION(CWait)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CWait)
	double	m_WaitTime/*等待时间*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
