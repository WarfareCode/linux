//SimEventScript.h: interface for the CSimEventScript module.
//!!HDOSE_CLASS(CSimEventScript,CLink)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimEventScript_H)
#define AFX_SimEventScript_H


//{{HDOSE_CLS_DES(CSimEventScript)
/*
Author:		
Version:	1.0
Descript:	主要负责从脚本中把事件参数解析出来，并发送相关的事件
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSimEventScript /*仿真事件脚本解析对象*/ : public CLink 
{
	DECLARE_CREATE;
public:
	CSimEventScript();
	virtual ~CSimEventScript();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);

	void	SetEvtClsName(char* val){SetValueString("EvtClsName",val);}
	char*	GetEvtClsName(){return GetValueString("EvtClsName");}
	void	SetEvtParams(char* val){SetValueString("EvtParams",val);}
	char*	GetEvtParams(){return GetValueString("EvtParams");}
	void	SetEvtScope(long val){m_EvtScope=val;}
	long	GetEvtScope(){return m_EvtScope;}
	void	SetEvtDesEntName(char* val){SetValueString("EvtDesEntName",val);}
	char*	GetEvtDesEntName(){return GetValueString("EvtDesEntName");}
	void	SetEvtDesClsName(char* val){SetValueString("EvtDesClsName",val);}
	char*	GetEvtDesClsName(){return GetValueString("EvtDesClsName");}
	void	SetSendTime(long val){m_SendTime=val;}
	long	GetSendTime(){return m_SendTime;}

	//{{HDOSE_MEMBER_FUNCTION(CSimEventScript)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSimEventScript)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSimEventScript)
	char*	m_EvtClsName/*事件类名*/;
	char*	m_EvtParams/*事件参数*/;
	long	m_EvtScope/*事件scope*/;
	char*	m_EvtDesEntName/*事件目的实体名*/;
	char*	m_EvtDesClsName/*事件目的类名*/;
	double	m_SendTime/*参数3*/;
	//}}HDOSE_ATTRIBUTE

	bool isSend;
};

#endif
