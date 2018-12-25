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

class DATASTRUCTCOMPONENTDLL_API CSetCircleRadius /*����Բ�ο��ƶ���Ĵ�С*/ : public CEvt 
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
	char*	m_EntityName/*Բ�ο��ƶ���ʵ������*/;
	double	m_Radius/*�µİ뾶*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
