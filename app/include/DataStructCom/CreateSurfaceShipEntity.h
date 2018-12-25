//CreateSurfaceShipEntity.h: interface for the CCreateSurfaceShipEntity module.
//!!HDOSE_CLASS(CCreateSurfaceShipEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateSurfaceShipEntity_H)
#define AFX_CreateSurfaceShipEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateSurfaceShipEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateSurfaceShipEntity /*������ͧʵ��*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateSurfaceShipEntity();
	virtual ~CCreateSurfaceShipEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLauncherCount(long val){m_LauncherCount=val;}
	long	GetLauncherCount(){return m_LauncherCount;}
	void	SetLauncherInfo(char* val){SetValueString("LauncherInfo",val);}
	char*	GetLauncherInfo(){return GetValueString("LauncherInfo");}
	void	SetJammerChannelCount(long val){m_JammerChannelCount=val;}
	long	GetJammerChannelCount(){return m_JammerChannelCount;}
	void	SetIrradiatorCount(long val){m_IrradiatorCount=val;}
	long	GetIrradiatorCount(){return m_IrradiatorCount;}
	void	SetChaffCount(long val){m_ChaffCount=val;}
	long	GetChaffCount(){return m_ChaffCount;}
	void	SetTorpedoType(long val){m_TorpedoType=val;}
	long	GetTorpedoType(){return m_TorpedoType;}
	void	SetTorpedoCount(long val){m_TorpedoCount=val;}
	long	GetTorpedoCount(){return m_TorpedoCount;}
	void	SetAAMLauncherCount(long val){m_AAMLauncherCount=val;}
	long	GetAAMLauncherCount(){return m_AAMLauncherCount;}
	void	SetAAMLauncherInfo(char* val){SetValueString("AAMLauncherInfo",val);}
	char*	GetAAMLauncherInfo(){return GetValueString("AAMLauncherInfo");}
	void	SetActiveDecoyCount(long val){m_ActiveDecoyCount=val;}
	long	GetActiveDecoyCount(){return m_ActiveDecoyCount;}
	void	SetActiveDecoyType(long val){m_ActiveDecoyType=val;}
	long	GetActiveDecoyType(){return m_ActiveDecoyType;}
	void	SetChaffType(long val){m_ChaffType=val;}
	long	GetChaffType(){return m_ChaffType;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateSurfaceShipEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateSurfaceShipEntity)
	long	m_LauncherCount/*�����������������*/;
	char*	m_LauncherInfo/*���������������Ϣ*/;
	long	m_JammerChannelCount/*����ͨ������*/;
	long	m_IrradiatorCount/*����ͨ������*/;
	long	m_ChaffCount/*����������*/;
	long	m_TorpedoType/*��������*/;
	long	m_TorpedoCount/*��������*/;
	long	m_AAMLauncherCount/*���յ������������*/;
	char*	m_AAMLauncherInfo/*���յ����������Ϣ*/;
	long	m_ActiveDecoyCount/*��Դ�ն�������*/;
	long	m_ActiveDecoyType/*��Դ�ն�������*/;
	long	m_ChaffType/*����������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
