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

class DATASTRUCTCOMPONENTDLL_API CAAMBindingInfo /*防空导弹装订信息*/ : public CEvt 
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
	long	m_TargetNo/*目标编号*/;
	GeoPt	m_TargetPos/*目标位置*/;
	GeoPt	m_MeetPos/*交汇点位置*/;
	double	m_TargetVel/*目标航速*/;
	double	m_TargetCou/*目标航向*/;
	double	m_MissileCreateTime/*防空导弹创建时间（仿真时间）*/;
	CAzimuth3D	m_TargetAzimuth/*目标方位*/;
	long	m_UnitNumber/*防空导弹单元编号*/;

	double	m_InitSegTime/*初始段飞行时间(从发射时刻开始算起)*/;
	double	m_InitSegHeight/*初始段到达的飞行高度（m）*/;
	double	m_StartGuideTime/*开始接收中制导指令的时间（从发射时刻开始算起）*/;
	bool	m_IsEnterCruiseSeg/*是否到达巡航高度进行巡航*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
