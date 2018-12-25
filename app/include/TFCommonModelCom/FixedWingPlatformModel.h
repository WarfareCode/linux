//FixedWingPlatformModel.h: interface for the CFixedWingPlatformModel module.
//!!HDOSE_CLASS(CFixedWingPlatformModel,CPlatformModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FixedWingPlatformModel_H)
#define AFX_FixedWingPlatformModel_H

#include "PlatformModel.h"

//{{HDOSE_CLS_DES(CFixedWingPlatformModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CFixedWingPlatformModel /*固定翼飞机平台*/ : public CPlatformModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CFixedWingPlatformModel();
	virtual ~CFixedWingPlatformModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CFixedWingPlatformModel)
	//}}HDOSE_MEMBER_FUNCTION
//	CStdioFile file;

protected:
	//{{HDOSE_EVENT_HANDLER(CFixedWingPlatformModel)
	void	OnAircraftMoveCtrlParams(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CFixedWingPlatformModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CFixedWingPlatformModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
