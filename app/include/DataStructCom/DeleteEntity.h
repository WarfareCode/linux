//DeleteEntity.h: interface for the CDeleteEntity module.
//!!HDOSE_CLASS(CDeleteEntity,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DeleteEntity_H)
#define AFX_DeleteEntity_H


//{{HDOSE_CLS_DES(CDeleteEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CDeleteEntity /*删除实体*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CDeleteEntity();
	virtual ~CDeleteEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}

	//{{HDOSE_MEMBER_FUNCTION(CDeleteEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CDeleteEntity)
	char*	m_EntityName/*实体名称*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
