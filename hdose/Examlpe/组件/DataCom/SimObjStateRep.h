//SimObjStateRep.h: interface for the CSimObjStateRep module.
//!!HDOSE_CLASS(CSimObjStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimObjStateRep_H)
#define AFX_SimObjStateRep_H

#include "StateRepository.h"
//{{HDOSE_CLS_DES(CSimObjStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CSimObjStateRep /*仿真对象状态池*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CSimObjStateRep();
	virtual ~CSimObjStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetstrName(char* val){SetValueString("strName",val);}
	char*	GetstrName(){return GetValueString("strName");}
	void	SetSimObjId(long val){m_SimObjId=val;}
	long	GetSimObjId(){return m_SimObjId;}

	//{{HDOSE_MEMBER_FUNCTION(CSimObjStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSimObjStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSimObjStateRep)
	char*	m_strName/*名称*/;
	long	m_SimObjId/*仿真对象标识(唯一,自定义)*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
