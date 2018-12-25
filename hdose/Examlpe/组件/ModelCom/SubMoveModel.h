//SubMoveModel.h: interface for the CSubMoveModel module.
//!!HDOSE_CLASS(CSubMoveModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubMoveModel_H)
#define AFX_SubMoveModel_H

#include "Model.h"

//{{HDOSE_CLS_DES(CSubMoveModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class MODELCOM_API CSubMoveModel /*潜艇运动模型*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSubMoveModel();
	virtual ~CSubMoveModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CSubMoveModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CSubMoveModel)
	void	OnEntityMoveOrderEvt(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSubMoveModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubMoveModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
