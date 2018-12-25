//ESMDetectReportEvt.h: interface for the CESMDetectReportEvt module.
//!!HDOSE_CLASS(CESMDetectReportEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ESMDetectReportEvt_H)
#define AFX_ESMDetectReportEvt_H

#include "TrackDataStruct.h"

//{{HDOSE_CLS_DES(CESMDetectReportEvt)
/*
Author:		
Version:	1.0
Descript:	用于电子侦察设备的输出
*/
//}}HDOSE_CLS_DES

class HYCGF_API CESMDetectReportEvt /*电子侦察探测报告事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CESMDetectReportEvt();
	virtual ~CESMDetectReportEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSide(long val){m_Side=val;}
	long	GetSide(){return m_Side;}
	void	SetInfoEntId(long val){m_InfoEntId=val;}
	long	GetInfoEntId(){return m_InfoEntId;}
	void	SetInfoSensorName(char* val){SetValueString("InfoSensorName",val);}
	char*	GetInfoSensorName(){return GetValueString("InfoSensorName");}
	void	SetDataCount(long val){m_DataCount=val;}
	long	GetDataCount(){return m_DataCount;}
	void	SetData(DA_CTrackDataStruct val){m_Data=val;}
	DA_CTrackDataStruct	GetData(){return m_Data;}

	//{{HDOSE_MEMBER_FUNCTION(CESMDetectReportEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CESMDetectReportEvt)
	long	m_Side/*所属方*/;
	long	m_InfoEntId/*来源实体Id*/;
	char*	m_InfoSensorName/*来源模型名称*/;
	long	m_DataCount/*数据个数*/;
	DA_CTrackDataStruct	m_Data/*数据*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
