//CommanderESR.h: interface for the CCommanderESR module.
//!!HDOSE_CLASS(CCommanderESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CommanderESR_H)
#define AFX_CommanderESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CCommanderESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CCommanderESR /*指挥所状态池*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CCommanderESR();
	virtual ~CCommanderESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetHostObjectName(char* val){SetValueString("HostObjectName",val);}
	char*	GetHostObjectName(){return GetValueString("HostObjectName");}

	//{{HDOSE_MEMBER_FUNCTION(CCommanderESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CCommanderESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CCommanderESR)
	char*	m_HostObjectName/*指挥所依附的实体名称(移动指挥所)*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
