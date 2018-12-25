//RadarFieldStateRep.h: interface for the CRadarFieldStateRep module.
//!!HDOSE_CLASS(CRadarFieldStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RadarFieldStateRep_H)
#define AFX_RadarFieldStateRep_H

//{{HDOSE_CLS_DES(CRadarFieldStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CRadarFieldStateRep /*À×´ïÕóµØ×´Ì¬³Ø*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CRadarFieldStateRep();
	virtual ~CRadarFieldStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CRadarFieldStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CRadarFieldStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRadarFieldStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
