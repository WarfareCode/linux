//Disembark.h: interface for the CDisembark module.
//!!HDOSE_CLASS(CDisembark,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Disembark_H)
#define AFX_Disembark_H


//{{HDOSE_CLS_DES(CDisembark)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CDisembark /*派出兵力*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CDisembark();
	virtual ~CDisembark();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetCount(long val){m_Count=val;}
	long	GetCount(){return m_Count;}
	void	SetTaskDescription(char* val){SetValueString("TaskDescription",val);}
	char*	GetTaskDescription(){return GetValueString("TaskDescription");}
	void	SetMountingId(long val){m_MountingId=val;}
	long	GetMountingId(){return m_MountingId;}

	//{{HDOSE_MEMBER_FUNCTION(CDisembark)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CDisembark)
	long	m_Count/*数量*/;
	char*	m_TaskDescription/*任务描述*/;
	long	m_MountingId/*挂载方案Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
