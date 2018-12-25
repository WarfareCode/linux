//RequestBackEngineStateEvt.h: interface for the CRequestBackEngineStateEvt module.
//!!HDOSE_CLASS(CRequestBackEngineStateEvt,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RequestBackEngineStateEvt_H)
#define AFX_RequestBackEngineStateEvt_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CRequestBackEngineStateEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CRequestBackEngineStateEvt /*请求后台引擎报告状态事件*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CRequestBackEngineStateEvt();
	virtual ~CRequestBackEngineStateEvt();
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
	void	SetLocalID(int val){m_LocalID=val;}
	int	GetLocalID(){return m_LocalID;}
	void	SetLocalName(char* val){strcpy( m_LocalName,val);}
	char*	GetLocalName(){return m_LocalName;}
	void	SetLocalIP(char* val){strcpy( m_LocalIP,val);}
	char*	GetLocalIP(){return m_LocalIP;}
	void	SetLocalFederationName(char* val){strcpy( m_LocalFederationName,val);}
	char*	GetLocalFederationName(){return m_LocalFederationName;}
	void	SetLocalFederateName(char* val){strcpy( m_LocalFederateName,val);}
	char*	GetLocalFederateName(){return m_LocalFederateName;}

	//{{HDOSE_MEMBER_FUNCTION(CRequestBackEngineStateEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRequestBackEngineStateEvt)
	int	m_ServerID/*服务器标识*/;
	char	m_ServerName[64]/*服务器名称*/;
	char	m_ServerIP[64]/*服务器IP*/;
	char	m_ServerFederationName[64]/*服务器联邦名称*/;
	char	m_ServerFederateName[64]/*服务器联邦成员名称*/;
	int	m_LocalID/*本机标识*/;
	char	m_LocalName[64]/*本机名称*/;
	char	m_LocalIP[64]/*本机IP*/;
	char	m_LocalFederationName[64]/*本机联邦名称*/;
	char	m_LocalFederateName[64]/*本机联邦成员名称*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
