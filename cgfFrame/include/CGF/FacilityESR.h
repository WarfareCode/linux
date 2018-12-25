//FacilityESR.h: interface for the CFacilityESR module.
//!!HDOSE_CLASS(CFacilityESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FacilityESR_H)
#define AFX_FacilityESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CFacilityESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CFacilityESR /*设施状态池*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CFacilityESR();
	virtual ~CFacilityESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetFieldType(short val){m_FieldType=val;}
	short	GetFieldType(){return m_FieldType;}

	//{{HDOSE_MEMBER_FUNCTION(CFacilityESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CFacilityESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CFacilityESR)
	short	m_FieldType/*阵地类型*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
