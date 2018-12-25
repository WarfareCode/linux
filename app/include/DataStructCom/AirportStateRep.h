//AirportStateRep.h: interface for the CAirportStateRep module.
//!!HDOSE_CLASS(CAirportStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AirportStateRep_H)
#define AFX_AirportStateRep_H

//{{HDOSE_CLS_DES(CAirportStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAirportStateRep /*机场实体状态池*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CAirportStateRep();
	virtual ~CAirportStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CAirportStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CAirportStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CAirportStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
