//CreateObjRequest.h: interface for the CCreateObjRequest module.
//!!HDOSE_CLASS(CCreateObjRequest,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateObjRequest_H)
#define AFX_CreateObjRequest_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CCreateObjRequest)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CCreateObjRequest /*������������*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CCreateObjRequest();
	virtual ~CCreateObjRequest();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetObjType(long val){m_ObjType=val;}
	long	GetObjType(){return m_ObjType;}
	void	SetObjClass(char* val){SetValueString("ObjClass",val);}
	char*	GetObjClass(){return GetValueString("ObjClass");}
	void	SetObjClassId(long val){m_ObjClassId=val;}
	long	GetObjClassId(){return m_ObjClassId;}
	void	SetAttributeValueSet(char* val){SetValueString("AttributeValueSet",val);}
	char*	GetAttributeValueSet(){return GetValueString("AttributeValueSet");}

	//{{HDOSE_MEMBER_FUNCTION(CCreateObjRequest)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateObjRequest)
	long	m_ObjType/*�������ͣ�1ʵ�塢2���ƶ���*/;
	char*	m_ObjClass/*��������(����)*/;
	long	m_ObjClassId/*��������Id*/;
	char*	m_AttributeValueSet/*���Լ�����ʽ��Side;EntityName;OrganizeId;Marking;lat,lon,hei��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
