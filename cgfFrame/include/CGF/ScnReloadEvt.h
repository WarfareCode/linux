//ScnReloadEvt.h: interface for the CScnReloadEvt module.
//!!HDOSE_CLASS(CScnReloadEvt,CEvt)
//////////////////////////////////////////////////////////////////////

/* Note:
	1. ���¼��������붨���غ�������ģ�ͻ��Ա�������ص���ʾ���������κβ�����
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
Descript:	����֪ͨ���ݼ�¼ȫ�ֶ����붨�Ѿ����¿�ʼ�����֮ǰ�����ݡ�
*/
//}}HDOSE_CLS_DES

class HYCGF_API CScnReloadEvt /*�붨�����¼�*/ : public CEvt 
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
