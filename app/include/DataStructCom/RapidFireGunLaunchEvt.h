//RapidFireGunLaunchEvt.h: interface for the CRapidFireGunLaunchEvt module.
//!!HDOSE_CLASS(CRapidFireGunLaunchEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RapidFireGunLaunchEvt_H)
#define AFX_RapidFireGunLaunchEvt_H


//{{HDOSE_CLS_DES(CRapidFireGunLaunchEvt)
/*
Author:		xks
Version:	1.0
Descript:	����ģ�����佢�ڷ���Ľ��������ڲ�����ȫģ�����������ڵ����˶��켣��
���ͨ�����ֽ�����ʽ��֪������Ŀ�꣬����֪����ص�����������
������Ŀ��ͨ��ģ��һ��������ķ�ʽ�����л����жϡ�

*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CRapidFireGunLaunchEvt /*���佢�ڷ����¼�*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CRapidFireGunLaunchEvt();
	virtual ~CRapidFireGunLaunchEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetId(long val){m_TargetId=val;}
	long	GetTargetId(){return m_TargetId;}
	void	SetTargetDis(double val){m_TargetDis=val;}
	double	GetTargetDis(){return m_TargetDis;}
	void	SetDurationTime(double val){m_DurationTime=val;}
	double	GetDurationTime(){return m_DurationTime;}
	void	SetROF(double val){m_ROF=val;}
	double	GetROF(){return m_ROF;}
	void	SetCannonVelInit(double val){m_CannonVelInit=val;}
	double	GetCannonVelInit(){return m_CannonVelInit;}
	void	SetBestKillDist(double val){m_BestKillDist=val;}
	double	GetBestKillDist(){return m_BestKillDist;}

	//{{HDOSE_MEMBER_FUNCTION(CRapidFireGunLaunchEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CRapidFireGunLaunchEvt)
	long	m_TargetId/*���Ŀ����*/;
	double	m_TargetDis/*����ʱ��Ŀ��ľ���,m*/;
	double	m_DurationTime/*�������ʱ��,s*/;
	double	m_ROF/*�ڵ���������,��/min*/;
	double	m_CannonVelInit/*�ڵ���ʼ�ٶ�,m/s*/;
	double	m_BestKillDist/*�ڵ���������,m*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
