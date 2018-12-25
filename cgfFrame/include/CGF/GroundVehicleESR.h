//GroundVehicleESR.h: interface for the CGroundVehicleESR module.
//!!HDOSE_CLASS(CGroundVehicleESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_GroundVehicleESR_H)
#define AFX_GroundVehicleESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CGroundVehicleESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CGroundVehicleESR /*µØÃæ³µÁ¾×´Ì¬³Ø*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CGroundVehicleESR();
	virtual ~CGroundVehicleESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CGroundVehicleESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CGroundVehicleESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CGroundVehicleESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
