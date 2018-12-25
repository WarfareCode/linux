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

class DATASTRUCTCOMPONENTDLL_API CAntiAirOrder /*防空反导指令*/ : public CEvt 
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
	long	m_SurfaceNo/*舰艇编号*/;
	long	m_TargetNo/*目标编号*/;
	bool	m_bLaunch/*是否发射（0不发射、1发射）*/;
	long	m_SelfInterceptStratege/*本舰防空弹拦截策略*/;
	long	m_IsJoinedGroup/*是否加入编队*/;
	long m_SelfAutoAntiAir/*本舰自动防空（0否、1是），默认-1*/;
	long m_SelfAutoECM/*本舰自动电子战（0否、1是），默认-1*/;
	// 20160305
	long	m_GroupOrSelf/*指令来源（1本舰或2编队）*/;
	long	m_AAMLauncherNo/*防空导弹发射架编号*/;
	long	m_AAMDataNo/*发射架上的防空导弹数据编号（可能有多种类型的舰空弹）*/;
	// 20160308
	CTargetData	m_InitTargetInfo/*初始目指信息*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
