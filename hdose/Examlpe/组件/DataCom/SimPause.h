//SimPause.h: interface for the CSimPause module.
//!!HDOSE_CLASS(CSimPause,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimPause_H)
#define AFX_SimPause_H


//{{HDOSE_CLS_DES(CSimPause)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CSimPause /*·ÂÕæÔÝÍ£*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSimPause();
	virtual ~CSimPause();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CSimPause)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimPause)
	//}}HDOSE_ATTRIBUTE
};

#endif
