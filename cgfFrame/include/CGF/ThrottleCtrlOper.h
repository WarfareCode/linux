//ThrottleCtrlOper.h: interface for the CThrottleCtrlOper module.
//!!HDOSE_CLASS(CThrottleCtrlOper,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ThrottleCtrlOper_H)
#define AFX_ThrottleCtrlOper_H

#include "Task.h"

//{{HDOSE_CLS_DES(CThrottleCtrlOper)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CThrottleCtrlOper /*��λ���Ʋ���*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CThrottleCtrlOper();
	virtual ~CThrottleCtrlOper();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetbAssignVel(bool val){m_bAssignVel=val;}
	bool	GetbAssignVel(){return m_bAssignVel;}
	void	SetDesireVel(double val){m_DesireVel=val;}
	double	GetDesireVel(){return m_DesireVel;}
	void	SetbAssignKeepVel(bool val){m_bAssignKeepVel=val;}
	bool	GetbAssignKeepVel(){return m_bAssignKeepVel;}
	void	SetbKeepVel(bool val){m_bKeepVel=val;}
	bool	GetbKeepVel(){return m_bKeepVel;}
	void	SetbAssignThrottlePreset(bool val){m_bAssignThrottlePreset=val;}
	bool	GetbAssignThrottlePreset(){return m_bAssignThrottlePreset;}
	void	SetThrottlePreset(long val){m_ThrottlePreset=val;}
	long	GetThrottlePreset(){return m_ThrottlePreset;}
	void	SetbAssignThrottleRatio(bool val){m_bAssignThrottleRatio=val;}
	bool	GetbAssignThrottleRatio(){return m_bAssignThrottleRatio;}
	void	SetThrottleRatio(double val){m_ThrottleRatio=val;}
	double	GetThrottleRatio(){return m_ThrottleRatio;}
	void	SetbAssignHeight(bool val){m_bAssignHeight=val;}
	bool	GetbAssignHeight(){return m_bAssignHeight;}
	void	SetDesireHeight(double val){m_DesireHeight=val;}
	double	GetDesireHeight(){return m_DesireHeight;}
	void	SetbAssignKeepHeight(bool val){m_bAssignKeepHeight=val;}
	bool	GetbAssignKeepHeight(){return m_bAssignKeepHeight;}
	void	SetbKeepHeight(bool val){m_bKeepHeight=val;}
	bool	GetbKeepHeight(){return m_bKeepHeight;}
	void	SetbAssignHeightPreset(bool val){m_bAssignHeightPreset=val;}
	bool	GetbAssignHeightPreset(){return m_bAssignHeightPreset;}
	void	SetHeightPreset(long val){m_HeightPreset=val;}
	long	GetHeightPreset(){return m_HeightPreset;}
	void	SetbAssignUpDownRatio(bool val){m_bAssignUpDownRatio=val;}
	bool	GetbAssignUpDownRatio(){return m_bAssignUpDownRatio;}
	void	SetUpDownRatio(double val){m_UpDownRatio=val;}
	double	GetUpDownRatio(){return m_UpDownRatio;}

	//{{HDOSE_MEMBER_FUNCTION(CThrottleCtrlOper)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CThrottleCtrlOper)
	bool	m_bAssignVel/*�Ƿ�����ٶ�*/;
	double	m_DesireVel/*�������ٶ�ֵ m/s*/;
	bool	m_bAssignKeepVel/*�Ƿ�ָ���ٶȱ���*/;
	bool	m_bKeepVel/*�Ƿ��ٶȱ���*/;
	bool	m_bAssignThrottlePreset/*�Ƿ�������ŵ�λ*/;
	long	m_ThrottlePreset/*���ŵ�λ*/;
	bool	m_bAssignThrottleRatio/*�Ƿ����������*/;
	double	m_ThrottleRatio/*���������ٷֱ�-1~+1,����Ϊ��������Ϊ����*/;
	bool	m_bAssignHeight/*�Ƿ�����߶�*/;
	double	m_DesireHeight/*�����ĸ߶� m*/;
	bool	m_bAssignKeepHeight/*�Ƿ�ָ���߶ȱ���*/;
	bool	m_bKeepHeight/*�Ƿ�߶ȱ���*/;
	bool	m_bAssignHeightPreset/*�Ƿ�����߶ȵ�λ*/;
	long	m_HeightPreset/*�߶ȵ�λ*/;
	bool	m_bAssignUpDownRatio/*�Ƿ��������������*/;
	double	m_UpDownRatio/*�������������ٷֱ�-1~+1,��Ϊ������Ϊ����*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
