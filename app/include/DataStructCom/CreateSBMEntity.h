//CreateSBMEntity.h: interface for the CCreateSBMEntity module.
//!!HDOSE_CLASS(CCreateSBMEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateSBMEntity_H)
#define AFX_CreateSBMEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateSBMEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateSBMEntity /*创建岸导阵地实体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateSBMEntity();
	virtual ~CCreateSBMEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLaunchVehicleCount(long val){m_LaunchVehicleCount=val;}
	long	GetLaunchVehicleCount(){return m_LaunchVehicleCount;}
	void	SetLaunchVehicleInfo(char* val){SetValueString("LaunchVehicleInfo",val);}
	char*	GetLaunchVehicleInfo(){return GetValueString("LaunchVehicleInfo");}

	//{{HDOSE_MEMBER_FUNCTION(CCreateSBMEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateSBMEntity)
	long	m_LaunchVehicleCount/*发射车数量*/;
	char*	m_LaunchVehicleInfo/*发射车信息*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
