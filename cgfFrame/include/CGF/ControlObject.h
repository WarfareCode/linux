//ControlObject.h: interface for the CControlObject module.
//!!HDOSE_CLASS(CControlObject,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ControlObject_H)
#define AFX_ControlObject_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CControlObject)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CControlObject /*ControlObject*/ : public CNode 
{
	DECLARE_CREATE;
public:
	CControlObject();
	virtual ~CControlObject();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();

	virtual	void	tick(double lasttime/* =0 */);

	void	SetSide(long val){m_Side=val;}
	long	GetSide(){return m_Side;}
	void	SetCtrlObjName(char* val){SetValueString("CtrlObjName",val);}
	char*	GetCtrlObjName(){return GetValueString("CtrlObjName");}
	void	SetShapeType(ShapeType val){m_CtrlObjShapeType=val;}
	ShapeType	GetShapeType(){return m_CtrlObjShapeType;}
	void	SetChanged(bool val){m_Changed=val;}
	bool	GetChanged(){return m_Changed;}

	//{{HDOSE_MEMBER_FUNCTION(CControlObject)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CControlObject)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CControlObject)
	long	m_Side/*红蓝方中立属性*/;
	char*	m_CtrlObjName/*控制对象名称*/;
	ShapeType	m_CtrlObjShapeType/*控制对象类型*/;
	bool	m_Changed/*属性是否改变,true 改变*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
