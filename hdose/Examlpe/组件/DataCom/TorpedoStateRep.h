//TorpedoStateRep.h: interface for the CTorpedoStateRep module.
//!!HDOSE_CLASS(CTorpedoStateRep,CNodeStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoStateRep_H)
#define AFX_TorpedoStateRep_H

#include "EntityStateRep.h"

//{{HDOSE_CLS_DES(CTorpedoStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CTorpedoStateRep /*鱼雷状态池*/ : public CNodeStateRep 
{
	DECLARE_CREATE;
public:
	CTorpedoStateRep();
	virtual ~CTorpedoStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetLength(){return m_Length;}
	double	GetMaxRadius(){return m_MaxRadius;}
	double	GetMaxG(){return m_MaxG;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CTorpedoStateRep)
	double	m_Length/*长度*/;
	double	m_MaxRadius/*最大直径*/;
	double	m_MaxG/*最大过载*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTorpedoStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
