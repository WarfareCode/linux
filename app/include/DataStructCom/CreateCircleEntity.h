//CreateCircleEntity.h: interface for the CCreateCircleEntity module.
//!!HDOSE_CLASS(CCreateCircleEntity,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateCircleEntity_H)
#define AFX_CreateCircleEntity_H



//{{HDOSE_CLS_DES(CCreateCircleEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateCircleEntity /*创建圆形控制对象实体*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCreateCircleEntity();
	virtual ~CCreateCircleEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}
	//void	SetEntityClassName(char* val){strcpy(m_EntityClassName,val);}
	//char*	GetEntityClassName(){return m_EntityClassName;}

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetEntityClassName(char* val){SetValueString("EntityClassName",val);}
	char*	GetEntityClassName(){return GetValueString("EntityClassName");}
	void	SetCentrePos(GeoPt val){m_CentrePos=val;}
	GeoPt	GetCentrePos(){return m_CentrePos;}
	void	SetRadius(double val){m_Radius=val;}
	double	GetRadius(){return m_Radius;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateCircleEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateCircleEntity)
	char*	m_EntityName/*圆形对象名称*/;
	char*	m_EntityClassName/*圆形实体对象属性类名称（CCircleControlObject）*/;
	GeoPt	m_CentrePos/*圆心位置*/;
	double	m_Radius/*半径*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
