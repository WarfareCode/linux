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

class DATASTRUCTCOMPONENTDLL_API CAAMMoveOrder /*���յ�������ָ��*/ : public CEvt 
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
	long	m_InstructionType/*ָ�����ͣ�0���䣬1������2ת�䣬3׷�٣�5�Ի٣�*/;
	double	m_TargetDistance/*Ŀ�����*/;
	CAzimuth3D	m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
	double	m_TargetVelocity/*Ŀ�꺽��*/;
	double	m_TargetCourse/*Ŀ�꺽��*/;
	long	m_TargetNo/*Ŀ����*/;
	GeoPt m_TargetPos/*Ŀ��λ��*/;
	GeoPt m_MeetPos/*��ʼ�����λ��*/;

	double	m_InitSegTime/*��ʼ�η���ʱ��(�ӷ���ʱ�̿�ʼ����)*/;
	double	m_InitSegHeight/*��ʼ�ε���ķ��и߶ȣ�m��*/;
	double	m_StartGuideTime/*��ʼ�������Ƶ�ָ���ʱ�䣨�ӷ���ʱ�̿�ʼ����*/;
	bool	m_IsEnterCruiseSeg/*�Ƿ񵽴�Ѳ���߶Ƚ���Ѳ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
