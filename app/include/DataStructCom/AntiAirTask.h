//AntiAirTask.h: interface for the CAntiAirTask module.
//!!HDOSE_CLASS(CAntiAirTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AntiAirTask_H)
#define AFX_AntiAirTask_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CAntiAirTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAntiAirTask /*���շ�������*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CAntiAirTask();
	virtual ~CAntiAirTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSurfaceNo(long val){m_SurfaceNo=val;}
	long	GetSurfaceNo(){return m_SurfaceNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetbLaunch(bool val){m_bLaunch=val;}
	bool	GetbLaunch(){return m_bLaunch;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}
	void	SetGroupAutoAntiAir(long val){m_GroupAutoAntiAir=val;}
	long	GetGroupAutoAntiAir(){return m_GroupAutoAntiAir;}
	void	SetSelfAutoAntiAir(long val){m_SelfAutoAntiAir=val;}
	long	GetSelfAutoAntiAir(){return m_SelfAutoAntiAir;}
	void	SetSelfAutoECM(long val){m_SelfAutoECM=val;}
	long	GetSelfAutoECM(){return m_SelfAutoECM;}
	void	SetGroupInterceptStratege(long val){m_GroupInterceptStratege=val;}
	long	GetGroupInterceptStratege(){return m_GroupInterceptStratege;}
	void	SetSelfInterceptStratege(long val){m_SelfInterceptStratege=val;}
	long	GetSelfInterceptStratege(){return m_SelfInterceptStratege;}
	void	SetIsJoinedGroup(long val){m_IsJoinedGroup=val;}
	long	GetIsJoinedGroup(){return m_IsJoinedGroup;}
	void	SetGroupOrSelf(long val){m_GroupOrSelf=val;}
	long	GetGroupOrSelf(){return m_GroupOrSelf;}
	void	SetAAMLauncherNo(long val){m_AAMLauncherNo=val;}
	long	GetAAMLauncherNo(){return m_AAMLauncherNo;}
	void	SetAAMDataNo(long val){m_AAMDataNo=val;}
	long	GetAAMDataNo(){return m_AAMDataNo;}
	void	SetInitTargetInfo(CTargetData val){m_InitTargetInfo=val;}
	CTargetData	GetInitTargetInfo(){return m_InitTargetInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CAntiAirTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAntiAirTask)
	long	m_SurfaceNo/*��ͧ��ţ�Ĭ��Ϊ-1��*/;
	long	m_TargetNo/*Ŀ���ţ�Ĭ��Ϊ-1��*/;
	bool	m_bLaunch/*�Ƿ��䣨0�����䡢1���䣩��Ĭ��Ϊ0��*/;
	long	m_ForceType/*��������ʶ��1�졢2������Ĭ��Ϊ-1��*/;
	long m_GroupAutoAntiAir/*����Զ����գ�0��1�ǣ���Ĭ��-1*/;
	long m_SelfAutoAntiAir/*�����Զ����գ�0��1�ǣ���Ĭ��-1*/;
	long m_SelfAutoECM/*�����Զ�����ս��0��1�ǣ���Ĭ��-1*/;
	long	m_GroupInterceptStratege/*��ӷ��յ����ز��ԣ�Ĭ��Ϊ-1��*/;
	long	m_SelfInterceptStratege/*�������յ����ز��ԣ�Ĭ��Ϊ-1��*/;
	long	m_IsJoinedGroup/*�Ƿ������(-1��Ч-Ĭ�ϣ�0�����룬1����)*/;
	// 20160305
	long	m_GroupOrSelf/*ָ����Դ��1������2��ӣ�*/;
	long	m_AAMLauncherNo/*���յ�������ܱ��*/;
	long	m_AAMDataNo/*������ϵķ��յ������ݱ�ţ������ж������͵Ľ��յ���*/;
	// 20160308
	CTargetData	m_InitTargetInfo/*��ʼĿָ��Ϣ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
