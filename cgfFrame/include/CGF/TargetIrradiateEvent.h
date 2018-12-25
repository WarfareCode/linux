//TargetIrradiateEvent.h: interface for the CTargetIrradiateEvent module.
//!!HDOSE_CLASS(CTargetIrradiateEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetIrradiateEvent_H)
#define AFX_TargetIrradiateEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CTargetIrradiateEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CTargetIrradiateEvent /*目标照射事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTargetIrradiateEvent();
	virtual ~CTargetIrradiateEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetIrradiateState(long val){m_IrradiateState=val;}
	long	GetIrradiateState(){return m_IrradiateState;}
	void	SetSourceID(long val){m_SourceID=val;}
	long	GetSourceID(){return m_SourceID;}
	void	SetEquipmentName(char* val){SetValueString("EquipmentName",val);}
	char*	GetEquipmentName(){return GetValueString("EquipmentName");}
	void	SetTargetID(long val){m_TargetID=val;}
	long	GetTargetID(){return m_TargetID;}
	void	SetSrcEntExId(long val){m_SrcEntExId=val;}
	long	GetSrcEntExId(){return m_SrcEntExId;}
	void	SetDesEntExId(long val){m_DesEntExId=val;}
	long	GetDesEntExId(){return m_DesEntExId;}

	//{{HDOSE_MEMBER_FUNCTION(CTargetIrradiateEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTargetIrradiateEvent)
	long	m_IrradiateState/*照射状态（0-不照射、1-照射）*/;
	long	m_SourceID/*发起者ID*/;
	char*	m_EquipmentName/*发起者的设备名称*/;
	long	m_TargetID/*目标ID*/;
	long	m_SrcEntExId/*发起者扩展Id*/;
	long	m_DesEntExId/*目标扩展Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
