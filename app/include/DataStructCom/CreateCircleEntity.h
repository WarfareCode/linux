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

class DATASTRUCTCOMPONENTDLL_API CCreateCircleEntity /*����Բ�ο��ƶ���ʵ��*/ : public CEvt 
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
	char*	m_EntityName/*Բ�ζ�������*/;
	char*	m_EntityClassName/*Բ��ʵ��������������ƣ�CCircleControlObject��*/;
	GeoPt	m_CentrePos/*Բ��λ��*/;
	double	m_Radius/*�뾶*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
