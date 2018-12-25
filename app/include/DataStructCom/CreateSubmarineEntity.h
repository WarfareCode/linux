//CreateSubmarineEntity.h: interface for the CCreateSubmarineEntity module.
//!!HDOSE_CLASS(CCreateSubmarineEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateSubmarineEntity_H)
#define AFX_CreateSubmarineEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateSubmarineEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateSubmarineEntity /*创建潜艇实体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateSubmarineEntity();
	virtual ~CCreateSubmarineEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLauncherCount(long val){m_LauncherCount=val;}
	long	GetLauncherCount(){return m_LauncherCount;}
	void	SetLauncherInfo(char* val){SetValueString("LauncherInfo",val);}
	char*	GetLauncherInfo(){return GetValueString("LauncherInfo");}
	void	SetTorpedoType(long val){m_TorpedoType=val;}
	long	GetTorpedoType(){return m_TorpedoType;}
	void	SetTorpedoCount(long val){m_TorpedoCount=val;}
	long	GetTorpedoCount(){return m_TorpedoCount;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateSubmarineEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateSubmarineEntity)
	long	m_LauncherCount/*导弹发射筒数量*/;
	char*	m_LauncherInfo/*导弹发射筒信息*/;
	long	m_TorpedoType/*鱼雷类型*/;
	long	m_TorpedoCount/*鱼雷数量*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
