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

class HYCGF_API CScnCtrl /*想定管理*/ : public CConsoleEvt 
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
	int	m_ScnCtrlType/*想定管理类型(1新建、2加载、3卸载、4保存、5另存为)*/;
	int	m_ScnSourceType/*想定来源，0:本地文件，1:数据库，2:表示前端给定想定内容*/;
	char	m_FileName[512]/*想定文件名称或数据库键名;如果加载的想定在数据库里，则该字符串表示想定的键名;如果想定文件在本地，则表示前台给定的想定文件名称；当给定想定内容时，也需要给定文件名称；约定想定文件名称需要加上后缀名.scn*/;
	char*	m_FileContent/*想定文件内容*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
