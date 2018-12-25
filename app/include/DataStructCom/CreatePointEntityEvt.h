//CreatePointEntityEvt.h: interface for the CCreatePointEntityEvt module.
//!!HDOSE_CLASS(CCreatePointEntityEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreatePointEntityEvt_H)
#define AFX_CreatePointEntityEvt_H



//{{HDOSE_CLS_DES(CCreatePointEntityEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreatePointEntityEvt /*创建点控制对象实体*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCreatePointEntityEvt();
	virtual ~CCreatePointEntityEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	/*void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	char*	GetEntityName(){return m_EntityName;}
	void	SetEntityClassName(char* val){strcpy(m_EntityClassName,val);}
	char*	GetEntityClassName(){return m_EntityClassName;}*/

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetEntityClassName(char* val){SetValueString("EntityClassName",val);}
	char*	GetEntityClassName(){return GetValueString("EntityClassName");}
	void	SetPointPos(GeoPt val){m_PointPos=val;}
	GeoPt	GetPointPos(){return m_PointPos;}

	//{{HDOSE_MEMBER_FUNCTION(CCreatePointEntityEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreatePointEntityEvt)
	char*	m_EntityName/*点对象名称*/;
	char*	m_EntityClassName/*点对象属性类名称（CPointControlObject）*/;
	GeoPt	m_PointPos/*点的位置*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
