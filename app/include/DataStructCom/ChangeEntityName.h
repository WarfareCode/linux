//ChangeEntityName.h: interface for the CChangeEntityName module.
//!!HDOSE_CLASS(CChangeEntityName,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChangeEntityName_H)
#define AFX_ChangeEntityName_H


//{{HDOSE_CLS_DES(CChangeEntityName)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChangeEntityName /*改变实体名称*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CChangeEntityName();
	virtual ~CChangeEntityName();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}
	//void	SetNewName(char* val){strcpy(m_NewName,val);}
	//char*	GetNewName(){return m_NewName;}

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetNewName(char* val){SetValueString("NewName",val);}
	char*	GetNewName(){return GetValueString("NewName");}

	//{{HDOSE_MEMBER_FUNCTION(CChangeEntityName)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CChangeEntityName)
	char*	m_EntityName/*需要更名的实体名称*/;
	char*	m_NewName/*新的实体名称*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
