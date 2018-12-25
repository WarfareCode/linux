//AntiAirOrder.h: interface for the CAntiAirOrder module.
//!!HDOSE_CLASS(CAntiAirOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AntiAirOrder_H)
#define AFX_AntiAirOrder_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CAntiAirOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAntiAirOrder /*���շ���ָ��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAntiAirOrder();
	virtual ~CAntiAirOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSurfaceNo(long val){m_SurfaceNo=val;}
	long	GetSurfaceNo(){return m_SurfaceNo;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetbLaunch(bool val){m_bLaunch=val;}
	bool	GetbLaunch(){return m_bLaunch;}
	void	SetSelfInterceptStratege(long val){m_SelfInterceptStratege=val;}
	long	GetSelfInterceptStratege(){return m_SelfInterceptStratege;}
	void	SetIsJoinedGroup(long val){m_IsJoinedGroup=val;}
	long	GetIsJoinedGroup(){return m_IsJoinedGroup;}
	void	SetSelfAutoAntiAir(long val){m_SelfAutoAntiAir=val;}
	long	GetSelfAutoAntiAir(){return m_SelfAutoAntiAir;}
	void	SetSelfAutoECM(long val){m_SelfAutoECM=val;}
	long	GetSelfAutoECM(){return m_SelfAutoECM;}
	void	SetGroupOrSelf(long val){m_GroupOrSelf=val;}
	long	GetGroupOrSelf(){return m_GroupOrSelf;}
	void	SetAAMLauncherNo(long val){m_AAMLauncherNo=val;}
	long	GetAAMLauncherNo(){return m_AAMLauncherNo;}
	void	SetAAMDataNo(long val){m_AAMDataNo=val;}
	long	GetAAMDataNo(){return m_AAMDataNo;}
	void	SetInitTargetInfo(CTargetData val){m_InitTargetInfo=val;}
	CTargetData	GetInitTargetInfo(){return m_InitTargetInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CAntiAirOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAntiAirOrder)
	long	m_SurfaceNo/*��ͧ���*/;
	long	m_TargetNo/*Ŀ����*/;
	bool	m_bLaunch/*�Ƿ��䣨0�����䡢1���䣩*/;
	long	m_SelfInterceptStratege/*�������յ����ز���*/;
	long	m_IsJoinedGroup/*�Ƿ������*/;
	long m_SelfAutoAntiAir/*�����Զ����գ�0��1�ǣ���Ĭ��-1*/;
	long m_SelfAutoECM/*�����Զ�����ս��0��1�ǣ���Ĭ��-1*/;
	// 20160305
	long	m_GroupOrSelf/*ָ����Դ��1������2��ӣ�*/;
	long	m_AAMLauncherNo/*���յ�������ܱ��*/;
	long	m_AAMDataNo/*������ϵķ��յ������ݱ�ţ������ж������͵Ľ��յ���*/;
	// 20160308
	CTargetData	m_InitTargetInfo/*��ʼĿָ��Ϣ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
