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
Descript:	��ʵ�巢������ʱ�����͸��¼�������ʵ�嵱ǰ���ڷ���������������ʵ���̨λ�ɽ��ո��¼�������Ӧ�Ĵ������ʾ��
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponLaunchEvent /*���������¼�*/ : public CEvt 
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
	long	m_SrcEntID/*ʵ��ID*/;
	long	m_SrcEntExId/*ʵ����չId*/;
	long	m_SrcMountType/*����ϵͳ���*/;
	char*	m_SrcMountName/*����ϵͳ����*/;
	long	m_SrcMountId/*����ϵͳId*/;
	char*	m_SrcWeaponName/*������������*/;
	long	m_SrcWeaponId/*����Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
