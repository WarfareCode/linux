//LaunchFakeTarget.h: interface for the CLaunchFakeTarget module.
//!!HDOSE_CLASS(CLaunchFakeTarget,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchFakeTarget_H)
#define AFX_LaunchFakeTarget_H


//{{HDOSE_CLS_DES(CLaunchFakeTarget)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CLaunchFakeTarget /*�����Ŀ��*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CLaunchFakeTarget();
	virtual ~CLaunchFakeTarget();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFakeTargetType(long val){m_FakeTargetType=val;}
	long	GetFakeTargetType(){return m_FakeTargetType;}
	void	SetOrientation(double val){m_Orientation=val;}
	double	GetOrientation(){return m_Orientation;}

	//{{HDOSE_MEMBER_FUNCTION(CLaunchFakeTarget)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchFakeTarget)
	long	m_FakeTargetType/*��Ŀ�����ͣ��Ƿ����塢�����ն���������Դ�ն������ն���*/;
	double	m_Orientation/*��λ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
