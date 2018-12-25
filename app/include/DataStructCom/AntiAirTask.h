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

class DATASTRUCTCOMPONENTDLL_API CAntiAirTask /*防空反导任务*/ : public CTask 
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
	long	m_SurfaceNo/*舰艇编号（默认为-1）*/;
	long	m_TargetNo/*目标编号（默认为-1）*/;
	bool	m_bLaunch/*是否发射（0不发射、1发射）（默认为0）*/;
	long	m_ForceType/*红蓝方标识（1红、2蓝）（默认为-1）*/;
	long m_GroupAutoAntiAir/*编队自动防空（0否、1是），默认-1*/;
	long m_SelfAutoAntiAir/*本舰自动防空（0否、1是），默认-1*/;
	long m_SelfAutoECM/*本舰自动电子战（0否、1是），默认-1*/;
	long	m_GroupInterceptStratege/*编队防空弹拦截策略（默认为-1）*/;
	long	m_SelfInterceptStratege/*本舰防空弹拦截策略（默认为-1）*/;
	long	m_IsJoinedGroup/*是否加入编队(-1无效-默认，0不加入，1加入)*/;
	// 20160305
	long	m_GroupOrSelf/*指令来源（1本舰或2编队）*/;
	long	m_AAMLauncherNo/*防空导弹发射架编号*/;
	long	m_AAMDataNo/*发射架上的防空导弹数据编号（可能有多种类型的舰空弹）*/;
	// 20160308
	CTargetData	m_InitTargetInfo/*初始目指信息*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
