//TakeOff.h: interface for the CTakeOff module.
//!!HDOSE_CLASS(CTakeOff,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TakeOff_H)
#define AFX_TakeOff_H


//{{HDOSE_CLS_DES(CTakeOff)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CTakeOff /*���*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CTakeOff();
	virtual ~CTakeOff();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CTakeOff)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTakeOff)
	bool m_Takeoff; // �Ƿ���ɣ�0-��1-��
	//}}HDOSE_ATTRIBUTE
};

#endif
