//SimStart.h: interface for the CSimStart module.
//!!HDOSE_CLASS(CSimStart,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimStart_H)
#define AFX_SimStart_H


//{{HDOSE_CLS_DES(CSimStart)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSimStart /*·ÂÕæ¿ªÊ¼*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSimStart();
	virtual ~CSimStart();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CSimStart)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimStart)
	//}}HDOSE_ATTRIBUTE
};

#endif
