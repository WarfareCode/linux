//CreateRadarFieldEntity.h: interface for the CCreateRadarFieldEntity module.
//!!HDOSE_CLASS(CCreateRadarFieldEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateRadarFieldEntity_H)
#define AFX_CreateRadarFieldEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateRadarFieldEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateRadarFieldEntity /*雷达阵地实体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateRadarFieldEntity();
	virtual ~CCreateRadarFieldEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CCreateRadarFieldEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateRadarFieldEntity)
	//}}HDOSE_ATTRIBUTE
};

#endif
