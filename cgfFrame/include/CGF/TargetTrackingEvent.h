//TargetTrackingEvent.h: interface for the CTargetTrackingEvent module.
//!!HDOSE_CLASS(CTargetTrackingEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetTrackingEvent_H)
#define AFX_TargetTrackingEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CTargetTrackingEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CTargetTrackingEvent /*目标跟踪事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTargetTrackingEvent();
	virtual ~CTargetTrackingEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTrackState(long val){m_TrackState=val;}
	long	GetTrackState(){return m_TrackState;}
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

	//{{HDOSE_MEMBER_FUNCTION(CTargetTrackingEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTargetTrackingEvent)
	long	m_TrackState/*跟踪状态（0-不跟踪、1-跟踪）*/;
	long	m_SourceID/*发起跟踪者ID*/;
	char*	m_EquipmentName/*发起跟踪的设备名称*/;
	long	m_TargetID/*目标ID*/;
	long	m_SrcEntExId/*发起跟踪者扩展Id*/;
	long	m_DesEntExId/*目标扩展Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
