//RadarFieldDetectInfo.h: interface for the CRadarFieldDetectInfo module.
//!!HDOSE_CLASS(CRadarFieldDetectInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RadarFieldDetectInfo_H)
#define AFX_RadarFieldDetectInfo_H

#include "SensorData.h"

//{{HDOSE_CLS_DES(CRadarFieldDetectInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class CRadarFieldDetectInfo /*�״����̽����Ϣ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CRadarFieldDetectInfo();
	virtual ~CRadarFieldDetectInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetData(CSensorData *val){
		for(int i=0;i<100;i++)
		m_TargetData[i]=val[i];}
	CSensorData*	GetTargetData(){return m_TargetData;}
	void	SetTargetDataCount(long val){m_TargetDataCount=val;}
	long	GetTargetDataCount(){return m_TargetDataCount;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}

	//{{HDOSE_MEMBER_FUNCTION(CRadarFieldDetectInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRadarFieldDetectInfo)
	CSensorData	m_TargetData[100]/*Ŀ������(100��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_TargetDataCount/*Ŀ�����ݸ��������100����*/;
	long	m_ForceType/*��������ʶ��0����1�죩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
