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

class DATASTRUCTCOMPONENTDLL_API CCreateSurfaceShipEntity /*创建舰艇实体*/ : public CCreateForceEntityEvt 
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
	long	m_LauncherCount/*反舰导弹发射架数量*/;
	char*	m_LauncherInfo/*反舰导弹发射架信息*/;
	long	m_JammerChannelCount/*干扰通道数量*/;
	long	m_IrradiatorCount/*火力通道数量*/;
	long	m_ChaffCount/*箔条弹数量*/;
	long	m_TorpedoType/*鱼雷类型*/;
	long	m_TorpedoCount/*鱼雷数量*/;
	long	m_AAMLauncherCount/*防空导弹发射架数量*/;
	char*	m_AAMLauncherInfo/*防空导弹发射架信息*/;
	long	m_ActiveDecoyCount/*有源诱饵弹数量*/;
	long	m_ActiveDecoyType/*有源诱饵弹类型*/;
	long	m_ChaffType/*箔条弹类型*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
