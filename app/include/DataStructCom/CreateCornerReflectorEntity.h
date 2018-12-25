//CreateCornerReflectorEntity.h: interface for the CCreateCornerReflectorEntity module.
//!!HDOSE_CLASS(CCreateCornerReflectorEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateCornerReflectorEntity_H)
#define AFX_CreateCornerReflectorEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateCornerReflectorEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateCornerReflectorEntity /*创建角反射体*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateCornerReflectorEntity();
	virtual ~CCreateCornerReflectorEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetReflectorRCS(double val){m_ReflectorRCS=val;}
	double	GetReflectorRCS(){return m_ReflectorRCS;}
	void	SetUnitNumberBelongTo(long val){m_UnitNumberBelongTo=val;}
	long	GetUnitNumberBelongTo(){return m_UnitNumberBelongTo;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateCornerReflectorEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateCornerReflectorEntity)
	double	m_ReflectorRCS/*回波功率*/;
	long	m_UnitNumberBelongTo/*该角反所依附的舰艇平台编号(施放角反的舰艇编号)*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
