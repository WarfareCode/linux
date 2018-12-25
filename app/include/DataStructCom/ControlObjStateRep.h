//ControlObjStateRep.h: interface for the CControlObjStateRep module.
//!!HDOSE_CLASS(CControlObjStateRep,CControlObject)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ControlObjStateRep_H)
#define AFX_ControlObjStateRep_H

//{{HDOSE_CLS_DES(CControlObjStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CControlObjStateRep /*控制对象状态池*/ : public CControlObject 
{
	DECLARE_CREATE;
public:
	CControlObjStateRep();
	virtual ~CControlObjStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	/*void	SetstrAttachObject(char* val){strcpy(m_strAttachObject,val);}
	char*	GetstrAttachObject(){return m_strAttachObject;}*/

	void	SetstrAttachObject(char* val){SetValueString("strAttachObject",val);}
	char*	GetstrAttachObject(){return GetValueString("strAttachObject");}

	//{{HDOSE_MEMBER_FUNCTION(CControlObjStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CControlObjStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CControlObjStateRep)
	char*	m_strAttachObject/*依附对象（会随该对象移动）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
