//WeaponLaunchEvent.h: interface for the CWeaponLaunchEvent module.
//!!HDOSE_CLASS(CWeaponLaunchEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_WeaponLaunchEvent_H)
#define AFX_WeaponLaunchEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CWeaponLaunchEvent)
/*
Author:		
Version:	1.0
Descript:	当实体发射武器时，发送该事件，表明实体当前正在发射武器，其它的实体或台位可接收该事件，作相应的处理或显示。
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponLaunchEvent /*武器发射事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CWeaponLaunchEvent();
	virtual ~CWeaponLaunchEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSrcEntID(long val){m_SrcEntID=val;}
	long	GetSrcEntID(){return m_SrcEntID;}
	void	SetSrcEntExId(long val){m_SrcEntExId=val;}
	long	GetSrcEntExId(){return m_SrcEntExId;}
	void	SetSrcMountType(long val){m_SrcMountType=val;}
	long	GetSrcMountType(){return m_SrcMountType;}
	void	SetSrcMountName(char* val){SetValueString("SrcMountName",val);}
	char*	GetSrcMountName(){return GetValueString("SrcMountName");}
	void	SetSrcMountId(long val){m_SrcMountId=val;}
	long	GetSrcMountId(){return m_SrcMountId;}
	void	SetSrcWeaponName(char* val){SetValueString("SrcWeaponName",val);}
	char*	GetSrcWeaponName(){return GetValueString("SrcWeaponName");}
	void	SetSrcWeaponId(long val){m_SrcWeaponId=val;}
	long	GetSrcWeaponId(){return m_SrcWeaponId;}

	//{{HDOSE_MEMBER_FUNCTION(CWeaponLaunchEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CWeaponLaunchEvent)
	long	m_SrcEntID/*实体ID*/;
	long	m_SrcEntExId/*实体扩展Id*/;
	long	m_SrcMountType/*发射系统类别*/;
	char*	m_SrcMountName/*发射系统名称*/;
	long	m_SrcMountId/*发射系统Id*/;
	char*	m_SrcWeaponName/*武器类型名称*/;
	long	m_SrcWeaponId/*武器Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
