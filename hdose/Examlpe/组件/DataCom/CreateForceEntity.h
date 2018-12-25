//CreateForceEntity.h: interface for the CCreateForceEntity module.
//!!HDOSE_CLASS(CCreateForceEntity,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateForceEntity_H)
#define AFX_CreateForceEntity_H

#include "LatLonH.h"

//{{HDOSE_CLS_DES(CCreateForceEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CCreateForceEntity /*创建兵力实体*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCreateForceEntity();
	virtual ~CCreateForceEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetEntityClassName(char* val){SetValueString("EntityClassName",val);}
	char*	GetEntityClassName(){return GetValueString("EntityClassName");}
	void	SetstrName(char* val){SetValueString("strName",val);}
	char*	GetstrName(){return GetValueString("strName");}
	void	SetSimObjId(long val){m_SimObjId=val;}
	long	GetSimObjId(){return m_SimObjId;}
	void	SetPos(CLatLonH val){m_Pos=val;}
	CLatLonH	GetPos(){return m_Pos;}
	void	SetType(short val){m_Type=val;}
	short	GetType(){return m_Type;}
	void	SetKind(short val){m_Kind=val;}
	short	GetKind(){return m_Kind;}
	void	SetCountry(short val){m_Country=val;}
	short	GetCountry(){return m_Country;}
	void	SetCategory(short val){m_Category=val;}
	short	GetCategory(){return m_Category;}
	void	SetSubCategory(short val){m_SubCategory=val;}
	short	GetSubCategory(){return m_SubCategory;}
	void	SetSpecific(short val){m_Specific=val;}
	short	GetSpecific(){return m_Specific;}
	void	Setextra(short val){m_extra=val;}
	short	Getextra(){return m_extra;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateForceEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateForceEntity)
	char*	m_EntityClassName/*实体类名*/;
	char*	m_strName/*名称*/;
	long	m_SimObjId/*实体对象Id*/;
	CLatLonH	m_Pos/*位置*/;
	short	m_Type/*红蓝方标识*/;
	short	m_Kind/*平台类型*/;
	short	m_Country/*国家*/;
	short	m_Category/*分类*/;
	short	m_SubCategory/*子类*/;
	short	m_Specific/*具体分类*/;
	short	m_extra/*其它*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
