//ExplosionEvent.h: interface for the CExplosionEvent module.
//!!HDOSE_CLASS(CExplosionEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ExplosionEvent_H)
#define AFX_ExplosionEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CExplosionEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CExplosionEvent /*爆炸事件(HYCGF)*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CExplosionEvent();
	virtual ~CExplosionEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLocationType(long val){m_LocationType=val;}
	long	GetLocationType(){return m_LocationType;}
	void	SetRefrenceObjId(long val){m_RefrenceObjId=val;}
	long	GetRefrenceObjId(){return m_RefrenceObjId;}
	void	SetEquivalent(double val){m_Equivalent=val;}
	double	GetEquivalent(){return m_Equivalent;}
	void	SetLocation(GeoPt val){m_Location=val;}
	GeoPt	GetLocation(){return m_Location;}
	void	SetHittedObjId(long val){m_HittedObjId=val;}
	long	GetHittedObjId(){return m_HittedObjId;}
	void	SetLchPltObjId(long val){m_LchPltObjId=val;}
	long	GetLchPltObjId(){return m_LchPltObjId;}
	void	SetRefrenceObjType(DtEntityType val){m_RefrenceObjType=val;}
	DtEntityType	GetRefrenceObjType(){return m_RefrenceObjType;}

	//{{HDOSE_MEMBER_FUNCTION(CExplosionEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CExplosionEvent)
	long	m_LocationType/*位置类型（1-相对位置和2-绝对位置）*/;
	long	m_RefrenceObjId/*参照（爆炸）目标Id*/;
	double	m_Equivalent/*爆炸当量*/;
	GeoPt	m_Location/*爆炸位置*/;
	long m_HittedObjId/*被命中目标Id，需要时填写*/;
	long m_LchPltObjId/*发射平台对象Id，针对武器弹药*/;
	DtEntityType m_RefrenceObjType/*参照（爆炸）目标类型*/;
	//}}HDOSE_ATTRIBUTE
};

// locType - 位置类型
// refId - 参考目标id
// equivalent - 当量
// loc-位置
// refobjtype-参考目标类型
// hittedId - 命中目标id，默认0
// lchPltId - 发射平台对象id, 针对武器弹药
// srcid - 发送事件的对象id，默认0
int HYCGF_API SendExplosionEvt(long locType, long refId, double equivalent, GeoPt loc, DtEntityType refobjtype, long hittedId = 0,  long lchPltId = 0, int srcid = 0);

#endif
