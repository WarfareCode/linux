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

class HYCGF_API CAttitudeCtrlOper /*��̬���Ʋ���*/ : public CTask
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
	bool	m_bAssignKeepCourse/*�Ƿ�ָ�����򱣳�*/;
	bool	m_bKeepCourse/*�Ƿ��򱣳�*/;
	bool	m_bAssignCourse/*�Ƿ��������*/;
	double	m_DesireCourse/*�����ĺ��� (0-360deg)*/;

	bool	m_bAssignKeepBank/*�Ƿ�ָ���¶ȱ���*/;
	bool	m_bKeepBank/*�Ƿ��¶ȱ���*/;
	bool	m_bAssignAPBank/*�Ƿ�����¶�*/;
	double	m_DesireAPBank/*�������¶ȣ�-180 - +180deg����Ϊ����*/;

	bool	m_bAssignAPRollRate/*�Ƿ����ָ���ת������*/;
	double	m_DesireAPRollRate/*������ָ���ת������(-1 - +1 �ٷ������ҹ�Ϊ��)*/;

	bool	m_bAssignKeepPitch/*�Ƿ�ָ����������*/;
	bool	m_bKeepPitch/*�Ƿ�������*/;
	bool	m_bAssignPitch/*�Ƿ���������Ƕ�*/;
	double	m_DesirePitch/*�����ĸ����Ƕ� (-90~90deg,��Ϊ������Ϊ��)*/;

	bool	m_bAssignPitchRatio/*�Ƿ����ָ��������ʣ����������*/;
	double	m_PitchRatio/*���������� (�ٷֱ�-1~1,��Ϊ������Ϊ��)�����������*/;

	// ֱ������������
	bool	m_bAssignYawRatio/*�Ƿ����ƫ��������*/;
	double	m_YawRatio/*ƫ�������� (�ٷֱ�-1~1,��Ϊ������Ϊ��)*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
