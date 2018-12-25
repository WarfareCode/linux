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
Descript:	Ψһ�ĺ�̨��Ա������ǰ̨��Ա�����������������״̬
// 20170926������ǰ�Ľӿ�Э�����������
*/
//}}HDOSE_CLS_DES

class CBackEngineStateEvt /*��̨��������״̬�¼�*/ : public CConsoleEvt 
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
	int	m_ServerID/*��������ʶ*/;
	char	m_ServerName[64]/*����������*/;
	char	m_ServerIP[64]/*������IP*/;
	char	m_ServerFederationName[64]/*��������������*/;
	char	m_ServerFederateName[64]/*�����������Ա����*/;
	int	m_EngineID/*����ID*/;

	int	m_StartFlag/*��̨�����Ƿ����¼����붨(1��,0��)*/;
	int	m_EngineState/*��̨����״̬������μ�Hdose����״̬���壩*/;
	int	m_FastBest/*�Ƿ�����ģʽ(1��,0��)*/;
	double	m_WallClock/*����ʱ�Ӳ���, s*/;
	double	m_LogicClock/*�߼�ʱ�Ӳ���, s*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
