//GroundFCRadarStateRep.h: interface for the CGroundFCRadarStateRep module.
//!!HDOSE_CLASS(CGroundFCRadarStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_GroundFCRadarStateRep_H)
#define AFX_GroundFCRadarStateRep_H

#include "CGF/FacilityESR.h"

//{{HDOSE_CLS_DES(CGroundFCRadarStateRep)
/*
Author:		xks
Version:	1.0
Descript:	�����ô�
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CGroundFCRadarStateRep /*�������״�״̬��*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CGroundFCRadarStateRep();
	virtual ~CGroundFCRadarStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetType(long val){m_Type=val;}
	long	GetType(){return m_Type;}
	void	SetDetectRadius(double val){m_DetectRadius=val;}
	double	GetDetectRadius(){return m_DetectRadius;}
	void	SetDetectSection(double val){m_DetectSection=val;}
	double	GetDetectSection(){return m_DetectSection;}
	void	SetMaxTrackTargetCount(long val){m_MaxTrackTargetCount=val;}
	long	GetMaxTrackTargetCount(){return m_MaxTrackTargetCount;}
	void	SetMaxFireChannelCount(long val){m_MaxFireChannelCount=val;}
	long	GetMaxFireChannelCount(){return m_MaxFireChannelCount;}
	void	SetRelateAAMVehicleID(long val){m_RelateAAMVehicleID=val;}
	long	GetRelateAAMVehicleID(){return m_RelateAAMVehicleID;}

	//{{HDOSE_MEMBER_FUNCTION(CGroundFCRadarStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CGroundFCRadarStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CGroundFCRadarStateRep)
	long	m_Type/*���1/2/3*/;
	double	m_DetectRadius/*̽��뾶��m*/;
	double	m_DetectSection/*̽��������deg*/;
	long	m_MaxTrackTargetCount/*������Ŀ����*/;
	long	m_MaxFireChannelCount/*������ͨ����*/;
	long	m_RelateAAMVehicleID/*��ָ�ӵ������䳵���*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
