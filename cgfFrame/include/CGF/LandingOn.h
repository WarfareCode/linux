//LandingOn.h: interface for the CLandingOn module.
//!!HDOSE_CLASS(CLandingOn,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LandingOn_H)
#define AFX_LandingOn_H


//{{HDOSE_CLS_DES(CLandingOn)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CLandingOn /*½µÂä*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CLandingOn();
	virtual ~CLandingOn();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//{{HDOSE_MEMBER_FUNCTION(CLandingOn)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLandingOn)
	bool m_Landing/*ÊÇ·ñ×ÅÂ½£¬0-·ñ¡¢1-ÊÇ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
