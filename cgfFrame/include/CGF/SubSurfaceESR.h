//SubSurfaceESR.h: interface for the CSubSurfaceESR module.
//!!HDOSE_CLASS(CSubSurfaceESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubSurfaceESR_H)
#define AFX_SubSurfaceESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CSubSurfaceESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSubSurfaceESR /*水下实体状态池*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CSubSurfaceESR();
	virtual ~CSubSurfaceESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSubSurfaceESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSubSurfaceESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubSurfaceESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
