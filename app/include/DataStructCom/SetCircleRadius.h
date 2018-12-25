//SetCircleRadius.h: interface for the CSetCircleRadius module.
//!!HDOSE_CLASS(CSetCircleRadius,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SetCircleRadius_H)
#define AFX_SetCircleRadius_H


//{{HDOSE_CLS_DES(CSetCircleRadius)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSetCircleRadius /*调整圆形控制对象的大小*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSetCircleRadius();
	virtual ~CSetCircleRadius();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetRadius(double val){m_Radius=val;}
	double	GetRadius(){return m_Radius;}

	//{{HDOSE_MEMBER_FUNCTION(CSetCircleRadius)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSetCircleRadius)
	char*	m_EntityName/*圆形控制对象实体名称*/;
	double	m_Radius/*新的半径*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
