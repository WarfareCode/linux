//SimRefresh.h: interface for the CSimRefresh module.
//!!HDOSE_CLASS(CSimRefresh,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimRefresh_H)
#define AFX_SimRefresh_H


//{{HDOSE_CLS_DES(CSimRefresh)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSimRefresh /*ЗТецжибн*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSimRefresh();
	virtual ~CSimRefresh();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CSimRefresh)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimRefresh)
	//}}HDOSE_ATTRIBUTE
};

#endif
