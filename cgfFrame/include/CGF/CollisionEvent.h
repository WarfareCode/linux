//CollisionEvent.h: interface for the CCollisionEvent module.
//!!HDOSE_CLASS(CCollisionEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CollisionEvent_H)
#define AFX_CollisionEvent_H

//{{HDOSE_CLS_DES(CCollisionEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

#include "CGFDS.h"

class HYCGF_API CCollisionEvent /*碰撞事件(HYCGF)*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCollisionEvent();
	virtual ~CCollisionEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetCollidingObjectId(long val){m_CollidingObjectId=val;}
	long	GetCollidingObjectId(){return m_CollidingObjectId;}
	void	SetIssuingObjMass(double val){m_IssuingObjMass=val;}
	double	GetIssuingObjMass(){return m_IssuingObjMass;}
	void	SetIssuingObjVelocityVector(Vec3 val){m_IssuingObjVelocityVector=val;}
	Vec3	GetIssuingObjVelocityVector(){return m_IssuingObjVelocityVector;}
	void	SetCollisionLocation(GeoPt val){m_CollisionLocation=val;}
	GeoPt	GetCollisionLocation(){return m_CollisionLocation;}
	void	SetCollisionType(long val){m_CollisionType=val;}
	long	GetCollisionType(){return m_CollisionType;}
	void	SetIssuingObjId(long val){m_IssuingObjId=val;}
	long	GetIssuingObjId(){return m_IssuingObjId;}
	void	SetCollidingObjectExId(long val){m_CollidingObjectExId=val;}
	long	GetCollidingObjectExId(){return m_CollidingObjectExId;}
	void	SetIssuingObjExId(long val){m_IssuingObjExId=val;}
	long	GetIssuingObjExId(){return m_IssuingObjExId;}

	//{{HDOSE_MEMBER_FUNCTION(CCollisionEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCollisionEvent)
	long	m_CollidingObjectId/*被碰撞对象Id*/;
	double	m_IssuingObjMass/*发起碰撞对象质量*/;
	Vec3	m_IssuingObjVelocityVector/*发起碰撞对象的速度*/;
	GeoPt	m_CollisionLocation/*碰撞位置*/;
	long	m_CollisionType/*碰撞类型*/;
	long	m_IssuingObjId/*发起碰撞对象Id*/;
	long	m_CollidingObjectExId/*被碰撞对象扩展Id*/;
	long	m_IssuingObjExId/*发起碰撞对象扩展Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
