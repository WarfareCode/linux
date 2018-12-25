//Cruise.h: interface for the CCruise module.
//!!HDOSE_CLASS(CCruise,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Cruise_H)
#define AFX_Cruise_H


//{{HDOSE_CLS_DES(CCruise)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CCruise /*”ŒﬂÆ*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CCruise();
	virtual ~CCruise();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CCruise)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCruise)
	//}}HDOSE_ATTRIBUTE
};

#endif
