//TorpedoBindingParams.h: interface for the CTorpedoBindingParams module.
//!!HDOSE_CLASS(CTorpedoBindingParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoBindingParams_H)
#define AFX_TorpedoBindingParams_H

#include "LatLonH.h"

//{{HDOSE_CLS_DES(CTorpedoBindingParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CTorpedoBindingParams /*����װ������*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoBindingParams();
	virtual ~CTorpedoBindingParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetRcverId(long val){m_RcverId=val;}
	long	GetRcverId(){return m_RcverId;}
	void	SetTargetId(long val){m_TargetId=val;}
	long	GetTargetId(){return m_TargetId;}
	void	SetTargetPos(CLatLonH val){m_TargetPos=val;}
	CLatLonH	GetTargetPos(){return m_TargetPos;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoBindingParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoBindingParams)
	long	m_RcverId/*������Id*/;
	long	m_TargetId/*Ŀ��Id*/;
	CLatLonH	m_TargetPos/*Ŀ��λ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
