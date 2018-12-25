//RemoveObjRequest.h: interface for the CRemoveObjRequest module.
//!!HDOSE_CLASS(CRemoveObjRequest,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RemoveObjRequest_H)
#define AFX_RemoveObjRequest_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CRemoveObjRequest)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CRemoveObjRequest /*ɾ����������*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CRemoveObjRequest();
	virtual ~CRemoveObjRequest();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetObjType(long val){m_ObjType=val;}
	long	GetObjType(){return m_ObjType;}
	void	SetObjId(long val){m_ObjId=val;}
	long	GetObjId(){return m_ObjId;}

	//{{HDOSE_MEMBER_FUNCTION(CRemoveObjRequest)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRemoveObjRequest)
	long	m_ObjType/*ɾ���������ͣ�1ʵ�塢2���ƶ���*/;
	long	m_ObjId/*����Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
