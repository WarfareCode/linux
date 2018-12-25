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
Descript:	��Ҫ����ӽű��а��¼�����������������������ص��¼�
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSimEventScript /*�����¼��ű���������*/ : public CLink 
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
	char*	m_EvtClsName/*�¼�����*/;
	char*	m_EvtParams/*�¼�����*/;
	long	m_EvtScope/*�¼�scope*/;
	char*	m_EvtDesEntName/*�¼�Ŀ��ʵ����*/;
	char*	m_EvtDesClsName/*�¼�Ŀ������*/;
	double	m_SendTime/*����3*/;
	//}}HDOSE_ATTRIBUTE

	bool isSend;
};

#endif
