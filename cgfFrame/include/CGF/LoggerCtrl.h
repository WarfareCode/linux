//LoggerCtrl.h: interface for the CLoggerCtrl module.
//!!HDOSE_CLASS(CLoggerCtrl,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LoggerCtrl_H)
#define AFX_LoggerCtrl_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CLoggerCtrl)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CLoggerCtrl /*��¼����*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CLoggerCtrl();
	virtual ~CLoggerCtrl();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLoggerCtrlType(long val){m_LoggerCtrlType=val;}
	long	GetLoggerCtrlType(){return m_LoggerCtrlType;}
	void	SetFileName(char* val){SetValueString("FileName",val);}
	char*	GetFileName(){return GetValueString("FileName");}

	//{{HDOSE_MEMBER_FUNCTION(CLoggerCtrl)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLoggerCtrl)
	long	m_LoggerCtrlType/*��¼����*/;
	char*	m_FileName/*�ļ�����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
