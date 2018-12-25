//CreateRotaryWingEntity.h: interface for the CCreateRotaryWingEntity module.
//!!HDOSE_CLASS(CCreateRotaryWingEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateRotaryWingEntity_H)
#define AFX_CreateRotaryWingEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateRotaryWingEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateRotaryWingEntity /*旋转翼飞机实体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateRotaryWingEntity();
	virtual ~CCreateRotaryWingEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTorpedoType(long val){m_TorpedoType=val;}
	long	GetTorpedoType(){return m_TorpedoType;}
	void	SetTorpedoCount(long val){m_TorpedoCount=val;}
	long	GetTorpedoCount(){return m_TorpedoCount;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateRotaryWingEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateRotaryWingEntity)
	long	m_TorpedoType/*鱼雷类型*/;
	long	m_TorpedoCount/*鱼雷数量*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
