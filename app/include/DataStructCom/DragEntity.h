//DragEntity.h: interface for the CDragEntity module.
//!!HDOSE_CLASS(CDragEntity,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DragEntity_H)
#define AFX_DragEntity_H



//{{HDOSE_CLS_DES(CDragEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CDragEntity /*移动实体*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CDragEntity();
	virtual ~CDragEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetNewPos(GeoPt val){m_NewPos=val;}
	GeoPt	GetNewPos(){return m_NewPos;}

	//{{HDOSE_MEMBER_FUNCTION(CDragEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CDragEntity)
	char*	m_EntityName/*要移动的实体名称*/;
	GeoPt	m_NewPos/*新的位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
