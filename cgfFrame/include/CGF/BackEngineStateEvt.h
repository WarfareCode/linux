//BackEngineStateEvt.h: interface for the CBackEngineStateEvt module.
//!!HDOSE_CLASS(CBackEngineStateEvt,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_BackEngineStateEvt_H)
#define AFX_BackEngineStateEvt_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CBackEngineStateEvt)
/*
Author:		
Version:	1.0
Descript:	唯一的后台成员向其它前台成员报告自身引擎的运行状态
// 20170926根据先前的接口协议进行了完善
*/
//}}HDOSE_CLS_DES

class CBackEngineStateEvt /*后台引擎运行状态事件*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CBackEngineStateEvt();
	virtual ~CBackEngineStateEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetServerID(int val){m_ServerID=val;}
	int	GetServerID(){return m_ServerID;}
	void	SetServerName(char* val){strcpy( m_ServerName,val );}
	char*	GetServerName(){return m_ServerName;}
	void	SetServerIP(char* val){strcpy( m_ServerIP,val);}
	char*	GetServerIP(){return m_ServerIP;}
	void	SetServerFederationName(char* val){strcpy( m_ServerFederationName,val);}
	char*	GetServerFederationName(){return m_ServerFederationName;}
	void	SetServerFederateName(char* val){strcpy( m_ServerFederateName,val);}
	char*	GetServerFederateName(){return m_ServerFederateName;}
	void SetEngineID(int val){m_EngineID = val;}
	int GetEngineID(){return m_EngineID;}

	void	SetStartFlag(int val){m_StartFlag=val;}
	int	GetStartFlag(){return m_StartFlag;}
	void	SetEngineState(int val){m_EngineState=val;}
	int	GetEngineState(){return m_EngineState;}
	void	SetFastBest(int val){m_FastBest=val;}
	int	GetFastBest(){return m_FastBest;}
	void	SetWallClock(double val){m_WallClock=val;}
	double	GetWallClock(){return m_WallClock;}
	void	SetLogicClock(double val){m_LogicClock=val;}
	double	GetLogicClock(){return m_LogicClock;}

	//{{HDOSE_MEMBER_FUNCTION(CBackEngineStateEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CBackEngineStateEvt)
	int	m_ServerID/*服务器标识*/;
	char	m_ServerName[64]/*服务器名称*/;
	char	m_ServerIP[64]/*服务器IP*/;
	char	m_ServerFederationName[64]/*服务器联邦名称*/;
	char	m_ServerFederateName[64]/*服务器联邦成员名称*/;
	int	m_EngineID/*引擎ID*/;

	int	m_StartFlag/*后台引擎是否重新加载想定(1是,0否)*/;
	int	m_EngineState/*后台引擎状态（定义参见Hdose引擎状态定义）*/;
	int	m_FastBest/*是否尽量快模式(1是,0否)*/;
	double	m_WallClock/*物理时钟步长, s*/;
	double	m_LogicClock/*逻辑时钟步长, s*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
