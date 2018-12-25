//ScnReloadEvt.h: interface for the CScnReloadEvt module.
//!!HDOSE_CLASS(CScnReloadEvt,CEvt)
//////////////////////////////////////////////////////////////////////

/* Note:
	1. 此事件用于在想定重载后，向其它模型或成员发送重载的提示，本身无任何参数。
*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ScnReloadEvt_H)
#define AFX_ScnReloadEvt_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CScnReloadEvt)
/*
Author:		xks
Version:	1.0
Descript:	用于通知数据记录全局对象，想定已经重新开始，清空之前的数据。
*/
//}}HDOSE_CLS_DES

class HYCGF_API CScnReloadEvt /*想定重载事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CScnReloadEvt();
	virtual ~CScnReloadEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CScnReloadEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CScnReloadEvt)
	//}}HDOSE_ATTRIBUTE

};

#endif
