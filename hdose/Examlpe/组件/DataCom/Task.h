// Task.h: interface for the CTask class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASK_H__4CEFB7C2_AB18_4894_9FD5_92F10D1A5C85__INCLUDED_)
#define AFX_TASK_H__4CEFB7C2_AB18_4894_9FD5_92F10D1A5C85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PlanStr	String

class DATACOM_API CTask : public CEvt  
{
	DECLARE_CREATE
public:
	enum Cmd_Role{
		Role_UnKnown=-1,
		CONSOLE=0,			//控制台，GUI
		PLAN,				//计划
		SUPERIOR,			//上级
	};
	CTask();
	virtual ~CTask();

	static void ClassInit(ClassInfo *clsinfo);

	virtual	void	OnSetParameter(int idx,char *value){}
	virtual	PlanStr	FormatParaStr(){return _T("");}

	virtual	BOOL	GetNeedHalt(){return 1;}
	Cmd_Role	GetCmdRole(){return (Cmd_Role)m_cmdRole;}
	void		SetCmdRole(Cmd_Role role){m_cmdRole=role;}
	long		GetTaskId(){return m_taskId;}
	long		GetRecver(){return m_recver;}
	void		SetRecver(long recver){m_recver=recver;}
	BOOL		MatchRecver(long ref);

protected:
	short	m_cmdRole;
	long	m_recver;
private:
	long	m_taskId;
};

class DATACOM_API CSetDataRequest : public CTask
{
	DECLARE_CREATE
public:
	CSetDataRequest();
	virtual ~CSetDataRequest(){}

	static void ClassInit(ClassInfo *clsinfo);

	virtual	void	OnSetParameter(int idx,char *value);
	virtual	PlanStr	FormatParaStr();
	virtual	BOOL	GetNeedHalt(){return 0;}

	char	m_fieldName[32];
	char	m_value[32];
};

#endif // !defined(AFX_TASK_H__4CEFB7C2_AB18_4894_9FD5_92F10D1A5C85__INCLUDED_)
