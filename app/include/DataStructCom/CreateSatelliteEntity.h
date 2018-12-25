//CreateSatelliteEntity.h: interface for the CCreateSatelliteEntity module.
//!!HDOSE_CLASS(CCreateSatelliteEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateSatelliteEntity_H)
#define AFX_CreateSatelliteEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateSatelliteEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateSatelliteEntity /*创建卫星实体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateSatelliteEntity();
	virtual ~CCreateSatelliteEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();


	//{{HDOSE_MEMBER_FUNCTION(CCreateSatelliteEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateSatelliteEntity)
	//}}HDOSE_ATTRIBUTE
};

#endif
