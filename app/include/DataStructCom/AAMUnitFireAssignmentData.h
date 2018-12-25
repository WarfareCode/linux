//AAMUnitFireAssignmentData.h: interface for the CAAMUnitFireAssignmentData module.
//!!HDOSE_CLASS(CAAMUnitFireAssignmentData,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMUnitFireAssignmentData_H)
#define AFX_AAMUnitFireAssignmentData_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CAAMUnitFireAssignmentData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMUnitFireAssignmentData /*���յ�����Ԫ������������*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAAMUnitFireAssignmentData();
	virtual ~CAAMUnitFireAssignmentData();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetbLaunch(bool val){m_bLaunch=val;}
	bool	GetbLaunch(){return m_bLaunch;}
	void	SetGroupOrSelf(long val){m_GroupOrSelf=val;}
	long	GetGroupOrSelf(){return m_GroupOrSelf;}
	void	SetAAMLauncherNo(long val){m_AAMLauncherNo=val;}
	long	GetAAMLauncherNo(){return m_AAMLauncherNo;}
	void	SetAAMDataNo(long val){m_AAMDataNo=val;}
	long	GetAAMDataNo(){return m_AAMDataNo;}
	void	SetInitTargetInfo(CTargetData val){m_InitTargetInfo=val;}
	CTargetData	GetInitTargetInfo(){return m_InitTargetInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CAAMUnitFireAssignmentData)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAAMUnitFireAssignmentData)
	long	m_TargetNo/*Ŀ����*/;
	bool	m_bLaunch/*�Ƿ��䣨0�����䡢1���䣩*/;
	// 20160305
	long	m_GroupOrSelf/*ָ����Դ��1������2��ӣ�*/;
	long	m_AAMLauncherNo/*���յ�������ܱ�ţ�Ĭ��-1*/;
	long	m_AAMDataNo/*������ϵķ��յ������ݱ�ţ������ж������͵Ľ��յ�����Ĭ��-1*/;
	// 20160308
	CTargetData	m_InitTargetInfo/*��ʼĿָ��Ϣ*/;
	// 20160920
	long	m_targetExId;/*��չId��*/
	//}}HDOSE_ATTRIBUTE
};

#endif
