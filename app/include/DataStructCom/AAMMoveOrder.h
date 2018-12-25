//AAMMoveOrder.h: interface for the CAAMMoveOrder module.
//!!HDOSE_CLASS(CAAMMoveOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMMoveOrder_H)
#define AFX_AAMMoveOrder_H

#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CAAMMoveOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMMoveOrder /*防空导弹机动指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAAMMoveOrder();
	virtual ~CAAMMoveOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetInstructionType(long val){m_InstructionType=val;}
	long	GetInstructionType(){return m_InstructionType;}
	void	SetTargetDistance(double val){m_TargetDistance=val;}
	double	GetTargetDistance(){return m_TargetDistance;}
	void	SetTargetAzimuth(CAzimuth3D val){m_TargetAzimuth=val;}
	CAzimuth3D	GetTargetAzimuth(){return m_TargetAzimuth;}
	void	SetTargetVelocity(double val){m_TargetVelocity=val;}
	double	GetTargetVelocity(){return m_TargetVelocity;}
	void	SetTargetCourse(double val){m_TargetCourse=val;}
	double	GetTargetCourse(){return m_TargetCourse;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetMeetPos(GeoPt val){m_MeetPos=val;}
	GeoPt	GetMeetPos(){return m_MeetPos;}

	void	SetInitSegTime(double val){m_InitSegTime=val;}
	double	GetInitSegTime(){return m_InitSegTime;}
	void	SetInitSegHeight(double val){m_InitSegHeight=val;}
	double	GetInitSegHeight(){return m_InitSegHeight;}
	void	SetStartGuideTime(double val){m_StartGuideTime=val;}
	double	GetStartGuideTime(){return m_StartGuideTime;}
	void	SetIsEnterCruiseSeg(bool val){m_IsEnterCruiseSeg=val;}
	bool	GetIsEnterCruiseSeg(){return m_IsEnterCruiseSeg;}

	//{{HDOSE_MEMBER_FUNCTION(CAAMMoveOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAAMMoveOrder)
	long	m_InstructionType/*指令类型（0弹射，1爬升，2转弯，3追踪，5自毁）*/;
	double	m_TargetDistance/*目标距离*/;
	CAzimuth3D	m_TargetAzimuth/*目标方位（以自身为原点）*/;
	double	m_TargetVelocity/*目标航速*/;
	double	m_TargetCourse/*目标航向*/;
	long	m_TargetNo/*目标编号*/;
	GeoPt m_TargetPos/*目标位置*/;
	GeoPt m_MeetPos/*初始交汇点位置*/;

	double	m_InitSegTime/*初始段飞行时间(从发射时刻开始算起)*/;
	double	m_InitSegHeight/*初始段到达的飞行高度（m）*/;
	double	m_StartGuideTime/*开始接收中制导指令的时间（从发射时刻开始算起）*/;
	bool	m_IsEnterCruiseSeg/*是否到达巡航高度进行巡航*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
