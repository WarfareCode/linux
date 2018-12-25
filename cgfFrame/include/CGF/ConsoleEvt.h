//ConsoleEvt.h: interface for the CConsoleEvt module.
//!!HDOSE_CLASS(CConsoleEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ConsoleEvt_H)
#define AFX_ConsoleEvt_H


//{{HDOSE_CLS_DES(CConsoleEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

#include "CGFDS.h"

class HYCGF_API CConsoleEvt /*控制台事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CConsoleEvt();
	virtual ~CConsoleEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CConsoleEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CConsoleEvt)
	//}}HDOSE_ATTRIBUTE
};

#endif
