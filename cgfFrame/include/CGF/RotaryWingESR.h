//RotaryWingESR.h: interface for the CRotaryWingESR module.
//!!HDOSE_CLASS(CRotaryWingESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RotaryWingESR_H)
#define AFX_RotaryWingESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CRotaryWingESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CRotaryWingESR /*旋转翼飞机实体状态池*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CRotaryWingESR();
	virtual ~CRotaryWingESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CRotaryWingESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CRotaryWingESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRotaryWingESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
