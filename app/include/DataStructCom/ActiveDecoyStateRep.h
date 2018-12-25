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

class DATASTRUCTCOMPONENTDLL_API CActiveDecoyStateRep /*��Դ�ն���״̬��*/ : public CMunitionStateRep 
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
	double	m_MaxPower/*����书��(W)*/;
	double	m_UpWorkFrequency/*����Ƶ������*/;
	double	m_LowWorkFrequency/*����Ƶ������*/;
	double	m_BeamWidth/*�������(��)*/;
	double	m_DetectThreshold/*�������(W)*/;
	double	m_DynamicRange/*��̬��Χ(dB)*/;
	double	m_WorkTime/*����ʱ��(s)*/;
	double	m_AtennaHight/*���߸߶�(m)*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CActiveDecoyStateRep)
	long	m_JammingWaveForm/*0��Ŀ�꣬1�ڸǣ�2����*/;
	CFakeTargetData	m_FakeTargetInfo[50]/*��Ŀ����Ϣ�����飩*/;
	long	m_FakeTargetInfoCount/*��Ŀ�����*/;
	CCoveringJammingData	m_CoveringJammingInfo[50]/*�ڸǸ�����Ϣ���ݣ����飩*/;
	long	m_CoveringJammingInfoCount/*�ڸǸ�����Ϣ����*/;
	double	m_AtennaOrientation/*����ָ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
