//CreateFixedWingEntity.h: interface for the CCreateFixedWingEntity module.
//!!HDOSE_CLASS(CCreateFixedWingEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateFixedWingEntity_H)
#define AFX_CreateFixedWingEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateFixedWingEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateFixedWingEntity /*固定翼飞机实体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateFixedWingEntity();
	virtual ~CCreateFixedWingEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetASMCount(long val){m_ASMCount=val;}
	long	GetASMCount(){return m_ASMCount;}
	void	SetAntiShipMissileType(long val){m_AntiShipMissileType=val;}
	long	GetAntiShipMissileType(){return m_AntiShipMissileType;}
	void	SetAirAirMissileCount(long val){m_AirAirMissileCount=val;}
	long	GetAirAirMissileCount(){return m_AirAirMissileCount;}
	void	SetAntiAirMissileType(long val){m_AntiAirMissileType=val;}
	long	GetAntiAirMissileType(){return m_AntiAirMissileType;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateFixedWingEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateFixedWingEntity)
	long	m_ASMCount/*反舰导弹数量*/;
	long	m_AntiShipMissileType/*反舰导弹类型*/;
	long	m_AirAirMissileCount/*空空导弹数量*/;
	long	m_AntiAirMissileType/*空空导弹类型*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
