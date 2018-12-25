//AAMBindingInfo.h: interface for the CAAMBindingInfo module.
//!!HDOSE_CLASS(CAAMBindingInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMBindingInfo_H)
#define AFX_AAMBindingInfo_H

#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CAAMBindingInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMBindingInfo /*���յ���װ����Ϣ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAAMBindingInfo();
	virtual ~CAAMBindingInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetTargetPos(GeoPt val){m_TargetPos=val;}
	GeoPt	GetTargetPos(){return m_TargetPos;}
	void	SetMeetPos(GeoPt val){m_MeetPos=val;}
	GeoPt	GetMeetPos(){return m_MeetPos;}
	void	SetTargetVel(double val){m_TargetVel=val;}
	double	GetTargetVel(){return m_TargetVel;}
	void	SetTargetCou(double val){m_TargetCou=val;}
	double	GetTargetCou(){return m_TargetCou;}
	void	SetMissileCreateTime(double val){m_MissileCreateTime=val;}
	double	GetMissileCreateTime(){return m_MissileCreateTime;}
	void	SetTargetAzimuth(CAzimuth3D val){m_TargetAzimuth=val;}
	CAzimuth3D	GetTargetAzimuth(){return m_TargetAzimuth;}
	void	SetUnitNumber(long val){m_UnitNumber=val;}
	long	GetUnitNumber(){return m_UnitNumber;}

	void	SetInitSegTime(double val){m_InitSegTime=val;}
	double	GetInitSegTime(){return m_InitSegTime;}
	void	SetInitSegHeight(double val){m_InitSegHeight=val;}
	double	GetInitSegHeight(){return m_InitSegHeight;}
	void	SetStartGuideTime(double val){m_StartGuideTime=val;}
	double	GetStartGuideTime(){return m_StartGuideTime;}
	void	SetIsEnterCruiseSeg(bool val){m_IsEnterCruiseSeg=val;}
	bool	GetIsEnterCruiseSeg(){return m_IsEnterCruiseSeg;}

	//{{HDOSE_MEMBER_FUNCTION(CAAMBindingInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAAMBindingInfo)
	long	m_TargetNo/*Ŀ����*/;
	GeoPt	m_TargetPos/*Ŀ��λ��*/;
	GeoPt	m_MeetPos/*�����λ��*/;
	double	m_TargetVel/*Ŀ�꺽��*/;
	double	m_TargetCou/*Ŀ�꺽��*/;
	double	m_MissileCreateTime/*���յ�������ʱ�䣨����ʱ�䣩*/;
	CAzimuth3D	m_TargetAzimuth/*Ŀ�귽λ*/;
	long	m_UnitNumber/*���յ�����Ԫ���*/;

	double	m_InitSegTime/*��ʼ�η���ʱ��(�ӷ���ʱ�̿�ʼ����)*/;
	double	m_InitSegHeight/*��ʼ�ε���ķ��и߶ȣ�m��*/;
	double	m_StartGuideTime/*��ʼ�������Ƶ�ָ���ʱ�䣨�ӷ���ʱ�̿�ʼ����*/;
	bool	m_IsEnterCruiseSeg/*�Ƿ񵽴�Ѳ���߶Ƚ���Ѳ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
