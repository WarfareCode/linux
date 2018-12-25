//HarborDockEntityStateRep.h: interface for the CHarborDockEntityStateRep module.
//!!HDOSE_CLASS(CHarborDockEntityStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_HarborDockEntityStateRep_H)
#define AFX_HarborDockEntityStateRep_H

//{{HDOSE_CLS_DES(CHarborDockEntityStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CHarborDockEntityStateRep /*港口码头实体状态池*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CHarborDockEntityStateRep();
	virtual ~CHarborDockEntityStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CHarborDockEntityStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CHarborDockEntityStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CHarborDockEntityStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
