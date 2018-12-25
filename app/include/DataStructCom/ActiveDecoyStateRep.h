//ActiveDecoyStateRep.h: interface for the CActiveDecoyStateRep module.
//!!HDOSE_CLASS(CActiveDecoyStateRep,CMunitionStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ActiveDecoyStateRep_H)
#define AFX_ActiveDecoyStateRep_H

#include "MunitionStateRep.h"
#include "FakeTargetData.h"
#include "CoveringJammingData.h"

//{{HDOSE_CLS_DES(CActiveDecoyStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CActiveDecoyStateRep /*有源诱饵弹状态池*/ : public CMunitionStateRep 
{
	DECLARE_CREATE;
public:
	CActiveDecoyStateRep();
	virtual ~CActiveDecoyStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetJammingWaveForm(long val){m_JammingWaveForm=val;}
	long	GetJammingWaveForm(){return m_JammingWaveForm;}
	void	SetFakeTargetInfo(CFakeTargetData val[50]){
		for(int i=0;i<50;i++)
			m_FakeTargetInfo[i]=val[i];
	}
	CFakeTargetData*	GetFakeTargetInfo(){return m_FakeTargetInfo;}
	void	SetFakeTargetInfoCount(long val){m_FakeTargetInfoCount=val;}
	long	GetFakeTargetInfoCount(){return m_FakeTargetInfoCount;}
	void	SetCoveringJammingInfo(CCoveringJammingData val[50]){
		for(int i=0;i<50;i++)
			m_CoveringJammingInfo[i]=val[i];
	}
	CCoveringJammingData*	GetCoveringJammingInfo(){return m_CoveringJammingInfo;}
	void	SetCoveringJammingInfoCount(long val){m_CoveringJammingInfoCount=val;}
	long	GetCoveringJammingInfoCount(){return m_CoveringJammingInfoCount;}
	void	SetAtennaOrientation(double val){m_AtennaOrientation=val;}
	double	GetAtennaOrientation(){return m_AtennaOrientation;}
	double	GetMaxPower(){return m_MaxPower;}
	double	GetUpWorkFrequency(){return m_UpWorkFrequency;}
	double	GetLowWorkFrequency(){return m_LowWorkFrequency;}
	double	GetBeamWidth(){return m_BeamWidth;}
	double	GetDetectThreshold(){return m_DetectThreshold;}
	double	GetDynamicRange(){return m_DynamicRange;}
	double	GetWorkTime(){return m_WorkTime;}
	double	GetAtennaHight(){return m_AtennaHight;}

	//{{HDOSE_MEMBER_FUNCTION(CActiveDecoyStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CActiveDecoyStateRep)
	double	m_MaxPower/*最大发射功率(W)*/;
	double	m_UpWorkFrequency/*工作频率上限*/;
	double	m_LowWorkFrequency/*工作频率下限*/;
	double	m_BeamWidth/*波束宽度(度)*/;
	double	m_DetectThreshold/*检测门限(W)*/;
	double	m_DynamicRange/*动态范围(dB)*/;
	double	m_WorkTime/*续航时间(s)*/;
	double	m_AtennaHight/*天线高度(m)*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CActiveDecoyStateRep)
	long	m_JammingWaveForm/*0假目标，1遮盖，2其它*/;
	CFakeTargetData	m_FakeTargetInfo[50]/*假目标信息（数组）*/;
	long	m_FakeTargetInfoCount/*假目标个数*/;
	CCoveringJammingData	m_CoveringJammingInfo[50]/*遮盖干扰信息数据（数组）*/;
	long	m_CoveringJammingInfoCount/*遮盖干扰信息个数*/;
	double	m_AtennaOrientation/*天线指向*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
