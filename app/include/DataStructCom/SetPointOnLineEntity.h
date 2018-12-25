//SetPointOnLineEntity.h: interface for the CSetPointOnLineEntity module.
//!!HDOSE_CLASS(CSetPointOnLineEntity,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SetPointOnLineEntity_H)
#define AFX_SetPointOnLineEntity_H



//{{HDOSE_CLS_DES(CSetPointOnLineEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSetPointOnLineEntity /*�����߿��ƶ����ϵ��λ��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSetPointOnLineEntity();
	virtual ~CSetPointOnLineEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetCurrentPos(GeoPt val){m_CurrentPos=val;}
	GeoPt	GetCurrentPos(){return m_CurrentPos;}
	void	SetNewPos(GeoPt val){m_NewPos=val;}
	GeoPt	GetNewPos(){return m_NewPos;}

	//{{HDOSE_MEMBER_FUNCTION(CSetPointOnLineEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSetPointOnLineEntity)
	char*	m_EntityName/*�߿��ƶ���ʵ������*/;
	GeoPt	m_CurrentPos/*��Ҫ������ĵ�ǰλ��*/;
	GeoPt	m_NewPos/*��Ҫ���������λ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
