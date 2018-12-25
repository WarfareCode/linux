//CreateCmdFieldEntity.h: interface for the CCreateCmdFieldEntity module.
//!!HDOSE_CLASS(CCreateCmdFieldEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateCmdFieldEntity_H)
#define AFX_CreateCmdFieldEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateCmdFieldEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateCmdFieldEntity /*创建指挥所实体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateCmdFieldEntity();
	virtual ~CCreateCmdFieldEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CCreateCmdFieldEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateCmdFieldEntity)
	//}}HDOSE_ATTRIBUTE
};

#endif
