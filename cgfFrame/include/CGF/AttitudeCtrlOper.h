//AttitudeCtrlOper.h: interface for the CAttitudeCtrlOper module.
//!!HDOSE_CLASS(CAttitudeCtrlOper,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AttitudeCtrlOper_H)
#define AFX_AttitudeCtrlOper_H

#include "Task.h"

//{{HDOSE_CLS_DES(CAttitudeCtrlOper)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CAttitudeCtrlOper /*姿态控制操作*/ : public CTask
{
	DECLARE_CREATE;
public:
	CAttitudeCtrlOper();
	virtual ~CAttitudeCtrlOper();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetbAssignCourse(bool val){m_bAssignCourse=val;}
	bool	GetbAssignCourse(){return m_bAssignCourse;}
	void	SetDesireCourse(double val){m_DesireCourse=val;}
	double	GetDesireCourse(){return m_DesireCourse;}
	void	SetbAssignAPBank(bool val){m_bAssignAPBank=val;}
	bool	GetbAssignAPBank(){return m_bAssignAPBank;}
	void	SetDesireAPBank(double val){m_DesireAPBank=val;}
	double	GetDesireAPBank(){return m_DesireAPBank;}
	void	SetbAssignAPRollRate(bool val){m_bAssignAPRollRate=val;}
	bool	GetbAssignAPRollRate(){return m_bAssignAPRollRate;}
	void	SetDesireAPRollRate(double val){m_DesireAPRollRate=val;}
	double	GetDesireAPRollRate(){return m_DesireAPRollRate;}
	void	SetbAssignKeepCourse(bool val){m_bAssignKeepCourse=val;}
	bool	GetbAssignKeepCourse(){return m_bAssignKeepCourse;}
	void	SetbKeepCourse(bool val){m_bKeepCourse=val;}
	bool	GetbKeepCourse(){return m_bKeepCourse;}
	void	SetbAssignKeepBank(bool val){m_bAssignKeepBank=val;}
	bool	GetbAssignKeepBank(){return m_bAssignKeepBank;}
	void	SetbKeepBank(bool val){m_bKeepBank=val;}
	bool	GetbKeepBank(){return m_bKeepBank;}
	void	SetbAssignYawRatio(bool val){m_bAssignYawRatio=val;}
	bool	GetbAssignYawRatio(){return m_bAssignYawRatio;}
	void	SetYawRatio(double val){m_YawRatio=val;}
	double	GetYawRatio(){return m_YawRatio;}
	void	SetbAssignPitch(bool val){m_bAssignPitch=val;}
	bool	GetbAssignPitch(){return m_bAssignPitch;}
	void	SetDesirePitch(double val){m_DesirePitch=val;}
	double	GetDesirePitch(){return m_DesirePitch;}
	void	SetbAssignKeepPitch(bool val){m_bAssignKeepPitch=val;}
	bool	GetbAssignKeepPitch(){return m_bAssignKeepPitch;}
	void	SetbKeepPitch(bool val){m_bKeepPitch=val;}
	bool	GetbKeepPitch(){return m_bKeepPitch;}
	void	SetbAssignPitchRatio(bool val){m_bAssignPitchRatio=val;}
	bool	GetbAssignPitchRatio(){return m_bAssignPitchRatio;}
	void	SetPitchRatio(double val){m_PitchRatio=val;}
	double	GetPitchRatio(){return m_PitchRatio;}

	//{{HDOSE_MEMBER_FUNCTION(CAttitudeCtrlOper)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAttitudeCtrlOper)
	bool	m_bAssignKeepCourse/*是否指定航向保持*/;
	bool	m_bKeepCourse/*是否航向保持*/;
	bool	m_bAssignCourse/*是否给定航向*/;
	double	m_DesireCourse/*期望的航向 (0-360deg)*/;

	bool	m_bAssignKeepBank/*是否指定坡度保持*/;
	bool	m_bKeepBank/*是否坡度保持*/;
	bool	m_bAssignAPBank/*是否给定坡度*/;
	double	m_DesireAPBank/*期望的坡度（-180 - +180deg，右为正）*/;

	bool	m_bAssignAPRollRate/*是否给定指令滚转角速率*/;
	double	m_DesireAPRollRate/*期望的指令滚转角速率(-1 - +1 百分数，右滚为正)*/;

	bool	m_bAssignKeepPitch/*是否指定俯仰保持*/;
	bool	m_bKeepPitch/*是否俯仰保持*/;
	bool	m_bAssignPitch/*是否给定俯仰角度*/;
	double	m_DesirePitch/*期望的俯仰角度 (-90~90deg,上为正，下为负)*/;

	bool	m_bAssignPitchRatio/*是否给定指令俯仰角速率，即法向过载*/;
	double	m_PitchRatio/*俯仰速率量 (百分比-1~1,上为正，下为负)，即法向过载*/;

	// 直升机、舰船等
	bool	m_bAssignYawRatio/*是否给定偏航速率量*/;
	double	m_YawRatio/*偏航速率量 (百分比-1~1,左为正，右为负)*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
