//SimResume.h: interface for the CSimResume module.
//!!HDOSE_CLASS(CSimResume,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimResume_H)
#define AFX_SimResume_H


//{{HDOSE_CLS_DES(CSimResume)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSimResume /*·ÂÕæ¼ÌÐø*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSimResume();
	virtual ~CSimResume();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CSimResume)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimResume)
	//}}HDOSE_ATTRIBUTE
};

#endif
