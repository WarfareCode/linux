//Follow.h: interface for the CFollow module.
//!!HDOSE_CLASS(CFollow,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Follow_H)
#define AFX_Follow_H

#include "Task.h"

//{{HDOSE_CLS_DES(CFollow)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CFollow /*����(HYCGF)*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CFollow();
	virtual ~CFollow();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFollowedObjName(char* val){SetValueString("FollowedObjName",val);}
	char*	GetFollowedObjName(){return GetValueString("FollowedObjName");}
	void	SetFollowedObjId(long val){m_FollowedObjId=val;}
	long	GetFollowedObjId(){return m_FollowedObjId;}
	void	SetDistance(double val){m_Distance=val;}
	double	GetDistance(){return m_Distance;}
	void	SetRelativeOrientation(double val){m_RelativeOrientation=val;}
	double	GetRelativeOrientation(){return m_RelativeOrientation;}
	void	SetHighOffset(double val){m_HighOffset=val;}
	double	GetHighOffset(){return m_HighOffset;}

	//{{HDOSE_MEMBER_FUNCTION(CFollow)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CFollow)
	char*	m_FollowedObjName/*�������������*/;
	long	m_FollowedObjId/*���������Id*/;
	double	m_Distance/*ˮƽ����*/;
	double	m_RelativeOrientation/*��ԽǶ�*/;
	double	m_HighOffset/*�߶�ƫ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
