//TargetInfoStateRep.h: interface for the CTargetInfoStateRep module.
//!!HDOSE_CLASS(CTargetInfoStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetInfoStateRep_H)
#define AFX_TargetInfoStateRep_H


//{{HDOSE_CLS_DES(CTargetInfoStateRep)
/*
Author:		
Version:	1.0
Descript:	维护融合后的目标信息
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTargetInfoStateRep /*目标信息状态池*/ : public CStateRepository 
{
	DECLARE_CREATE;
public:
	CTargetInfoStateRep();
	virtual ~CTargetInfoStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CTargetInfoStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CTargetInfoStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CTargetInfoStateRep)
	//}}HDOSE_ATTRIBUTE
};

#endif
