//TargetParaEvent.h: interface for the CTargetParaEvent module.
//!!HDOSE_CLASS(CTargetParaEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetParaEvent_H)
#define AFX_TargetParaEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CTargetParaEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CTargetParaEvent /*Ŀ������¼�(HYCGF)*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTargetParaEvent();
	virtual ~CTargetParaEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetInfoSourceObjId(long val){m_InfoSourceObjId=val;}
	long	GetInfoSourceObjId(){return m_InfoSourceObjId;}
	void	SetBatchNo(long val){m_BatchNo=val;}
	long	GetBatchNo(){return m_BatchNo;}
	void	SetSide(long val){m_Side=val;}
	long	GetSide(){return m_Side;}
	void	SetEntityType(DtEntityType val){m_EntityType=val;}
	DtEntityType	GetEntityType(){return m_EntityType;}
	void	SetThreatLevel(long val){m_ThreatLevel=val;}
	long	GetThreatLevel(){return m_ThreatLevel;}
	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}
	void	SetVelocity(Vec3 val){m_Velocity=val;}
	Vec3	GetVelocity(){return m_Velocity;}

	//{{HDOSE_MEMBER_FUNCTION(CTargetParaEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTargetParaEvent)
	long	m_InfoSourceObjId/*��Ϣ��Դ����Id*/;
	long	m_BatchNo/*����*/;
	long	m_Side/*��������*/;
	DtEntityType	m_EntityType/*Ŀ������*/;
	long	m_ThreatLevel/*��в�ȼ�*/;
	GeoPt	m_Position/*λ��*/;
	Vec3	m_Velocity/*�ٶ�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
