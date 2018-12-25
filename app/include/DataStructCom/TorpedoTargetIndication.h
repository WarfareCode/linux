//TorpedoTargetIndication.h: interface for the CTorpedoTargetIndication module.
//!!HDOSE_CLASS(CTorpedoTargetIndication,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoTargetIndication_H)
#define AFX_TorpedoTargetIndication_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CTorpedoTargetIndication)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoTargetIndication /*鱼雷目标指示*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoTargetIndication();
	virtual ~CTorpedoTargetIndication();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetInfo(CTargetData val){m_TargetInfo=val;}
	CTargetData	GetTargetInfo(){return m_TargetInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoTargetIndication)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoTargetIndication)
	CTargetData	m_TargetInfo/*目标信息*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
