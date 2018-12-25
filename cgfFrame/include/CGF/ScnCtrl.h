//ScnCtrl.h: interface for the CScnCtrl module.
//!!HDOSE_CLASS(CScnCtrl,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ScnCtrl_H)
#define AFX_ScnCtrl_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CScnCtrl)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CScnCtrl /*�붨����*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CScnCtrl();
	virtual ~CScnCtrl();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetScnCtrlType(int val){m_ScnCtrlType=val;}
	int	GetScnCtrlType(){return m_ScnCtrlType;}
	void	SetScnSourceType(int val){m_ScnSourceType=val;}
	int	GetScnSourceType(){return m_ScnSourceType;}
	void	SetFileName(char* val){strcpy(m_FileName, val);}
	char*	GetFileName(){return m_FileName;}
	void	SetFileContent(char* val){SetValueString("FileContent",val);}
	char*	GetFileContent(){return GetValueString("FileContent");}

	//{{HDOSE_MEMBER_FUNCTION(CScnCtrl)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CScnCtrl)
	int	m_ScnCtrlType/*�붨��������(1�½���2���ء�3ж�ء�4���桢5���Ϊ)*/;
	int	m_ScnSourceType/*�붨��Դ��0:�����ļ���1:���ݿ⣬2:��ʾǰ�˸����붨����*/;
	char	m_FileName[512]/*�붨�ļ����ƻ����ݿ����;������ص��붨�����ݿ������ַ�����ʾ�붨�ļ���;����붨�ļ��ڱ��أ����ʾǰ̨�������붨�ļ����ƣ��������붨����ʱ��Ҳ��Ҫ�����ļ����ƣ�Լ���붨�ļ�������Ҫ���Ϻ�׺��.scn*/;
	char*	m_FileContent/*�붨�ļ�����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
