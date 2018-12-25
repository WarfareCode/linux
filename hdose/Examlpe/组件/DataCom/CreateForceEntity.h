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

class DATACOM_API CCreateForceEntity /*��������ʵ��*/ : public CEvt 
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
	char*	m_EntityClassName/*ʵ������*/;
	char*	m_strName/*����*/;
	long	m_SimObjId/*ʵ�����Id*/;
	CLatLonH	m_Pos/*λ��*/;
	short	m_Type/*��������ʶ*/;
	short	m_Kind/*ƽ̨����*/;
	short	m_Country/*����*/;
	short	m_Category/*����*/;
	short	m_SubCategory/*����*/;
	short	m_Specific/*�������*/;
	short	m_extra/*����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
