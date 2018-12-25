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

class HYCGF_API CThrottleCtrlOper /*档位控制操作*/ : public CTask 
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
	bool	m_bAssignVel/*是否给定速度*/;
	double	m_DesireVel/*期望的速度值 m/s*/;
	bool	m_bAssignKeepVel/*是否指定速度保持*/;
	bool	m_bKeepVel/*是否速度保持*/;
	bool	m_bAssignThrottlePreset/*是否给定油门档位*/;
	long	m_ThrottlePreset/*油门档位*/;
	bool	m_bAssignThrottleRatio/*是否给定油门量*/;
	double	m_ThrottleRatio/*油门量（百分比-1~+1,加速为正，减速为负）*/;
	bool	m_bAssignHeight/*是否给定高度*/;
	double	m_DesireHeight/*期望的高度 m*/;
	bool	m_bAssignKeepHeight/*是否指定高度保持*/;
	bool	m_bKeepHeight/*是否高度保持*/;
	bool	m_bAssignHeightPreset/*是否给定高度档位*/;
	long	m_HeightPreset/*高度档位*/;
	bool	m_bAssignUpDownRatio/*是否给定升降速率量*/;
	double	m_UpDownRatio/*升降速率量（百分比-1~+1,上为正，下为负）*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
