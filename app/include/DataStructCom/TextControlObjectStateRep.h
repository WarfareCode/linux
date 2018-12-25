//TextControlObjectStateRep.h: interface for the CTextControlObjectStateRep module.
//!!HDOSE_CLASS(CTextControlObjectStateRep,CControlObjStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TextControlObjectStateRep_H)
#define AFX_TextControlObjectStateRep_H

#include "ControlObjStateRep.h"

//{{HDOSE_CLS_DES(CTextControlObjectStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTextControlObjectStateRep /*�ı�״̬��*/ : public CControlObjStateRep 
{
	DECLARE_CREATE;
public:
	CTextControlObjectStateRep();
	virtual ~CTextControlObjectStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	//void	SetstrText(char* val){strcpy(m_strText,val);}
	//char*	GetstrText(){return m_strText;}

	void	SetstrText(char* val){SetValueString("strText",val);}
	char*	GetstrText(){return GetValueString("strText");}
	void	SetHoriAlign(long val){m_HoriAlign=val;}
	long	GetHoriAlign(){return m_HoriAlign;}
	void	SetVertAlign(long val){m_VertAlign=val;}
	long	GetVertAlign(){return m_VertAlign;}
	void	SetRotate(float val){m_Rotate=val;}
	float	GetRotate(){return m_Rotate;}

	//{{HDOSE_MEMBER_FUNCTION(CTextControlObjectStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CTextControlObjectStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTextControlObjectStateRep)
	char*	m_strText/*�ı�*/;
	long	m_HoriAlign/*ˮƽ���뷽ʽ*/;
	long	m_VertAlign/*��ֱ���뷽ʽ*/;
	float	m_Rotate/*��ת�Ƕ�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
