//SimEnd.h: interface for the CSimEnd module.
//!!HDOSE_CLASS(CSimEnd,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimEnd_H)
#define AFX_SimEnd_H


//{{HDOSE_CLS_DES(CSimEnd)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSimEnd /*·ÂÕæ½áÊø*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSimEnd();
	virtual ~CSimEnd();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CSimEnd)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimEnd)
	//}}HDOSE_ATTRIBUTE
};

#endif
