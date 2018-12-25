//SurfaceShipStateRep.h: interface for the CSurfaceShipStateRep module.
//!!HDOSE_CLASS(CSurfaceShipStateRep,CSurfaceESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SurfaceShipStateRep_H)
#define AFX_SurfaceShipStateRep_H

#include "JammerChannelData.h"
#include "IrradiatorData.h"
#include "TargetData.h"
#include "LaunchVehicleData.h"
#include "AAMLauncherData.h"
#include "RadiationData.h"

//{{HDOSE_CLS_DES(CSurfaceShipStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSurfaceShipStateRep /*水面舰艇状态池*/ : public CSurfaceESR 
{
	DECLARE_CREATE;
public:
	CSurfaceShipStateRep();
	virtual ~CSurfaceShipStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetJammerChannelCount(long val){m_JammerChannelCount=val;}
	long	GetJammerChannelCount(){return m_JammerChannelCount;}
	void	SetJammerChannelInfo(CJammerChannelData val[10]){
		for(int i=0;i<10;i++)
			m_JammerChannelInfo[i]=val[i];
	}
	CJammerChannelData*	GetJammerChannelInfo(){return m_JammerChannelInfo;}
	void	SetAAMCount(long val){m_AAMCount=val;}
	long	GetAAMCount(){return m_AAMCount;}
	void	SetChaffCount(long val){m_ChaffCount=val;}
	long	GetChaffCount(){return m_ChaffCount;}
	void	SetIrradiatorCount(long val){m_IrradiatorCount=val;}
	long	GetIrradiatorCount(){return m_IrradiatorCount;}
	void	SetIrradiatorInfo(CIrradiatorData val[]){
		for(int i=0;i<100;i++)
			m_IrradiatorInfo[i]=val[i];
	}
	CIrradiatorData*	GetIrradiatorInfo(){return m_IrradiatorInfo;}
	void	SetSurfaceEWDistance(double val){m_SurfaceEWDistance=val;}
	double	GetSurfaceEWDistance(){return m_SurfaceEWDistance;}
	void	SetAAMInterceptDistance(double val){m_AAMInterceptDistance=val;}
	double	GetAAMInterceptDistance(){return m_AAMInterceptDistance;}
/*	void	SetElectricScoutInfo(CTargetData val[100]){
		for(int i=0;i<100;i++)
			m_ElectricScoutInfo[i]=val[i];}
	CTargetData*	GetElectricScoutInfo(){return m_ElectricScoutInfo;}
	void	SetElectricScoutInfoCount(long val){m_ElectricScoutInfoCount=val;}
	long	GetElectricScoutInfoCount(){return m_ElectricScoutInfoCount;}*/
	void	SetLauncherInfo(CLaunchVehicleData val[]){
		for(int i=0;i<4;i++)
		m_LauncherInfo[i]=val[i];
	}
	CLaunchVehicleData*	GetLauncherInfo(){return m_LauncherInfo;}
	void	SetLauncherCount(long val){m_LauncherCount=val;}
	long	GetLauncherCount(){return m_LauncherCount;}
	void	SetTorpedoCount(long val){m_TorpedoCount=val;}
	long	GetTorpedoCount(){return m_TorpedoCount;}
	void	SetTorpedoType(long val){m_TorpedoType=val;}
	long	GetTorpedoType(){return m_TorpedoType;}
	void	SetSelfInterceptStratege(long val){m_SelfInterceptStratege=val;}
	long	GetSelfInterceptStratege(){return m_SelfInterceptStratege;}
	void	SetIsJoinedGroup(long val){m_IsJoinedGroup=val;}
	long	GetIsJoinedGroup(){return m_IsJoinedGroup;}
	void	SetAAMLauncherCount(long val){m_AAMLauncherCount=val;}
	long	GetAAMLauncherCount(){return m_AAMLauncherCount;}
	void	SetAAMLauncherInfo(CAAMLauncherData val[]){
		for(int i=0;i<5;i++)
			m_AAMLauncherInfo[i]=val[i];
	}
	CAAMLauncherData*	GetAAMLauncherInfo(){return m_AAMLauncherInfo;}
	void	SetActiveDecoyCount(long val){m_ActiveDecoyCount=val;}
	long	GetActiveDecoyCount(){return m_ActiveDecoyCount;}
	void	SetActiveDecoyType(long val){m_ActiveDecoyType=val;}
	long	GetActiveDecoyType(){return m_ActiveDecoyType;}
	void	SetChaffType(long val){m_ChaffType=val;}
	long	GetChaffType(){return m_ChaffType;}
	void	SetSurfRadiationInfo(CRadiationData val){m_SurfRadiationInfo=val;}
	CRadiationData	GetSurfRadiationInfo(){return m_SurfRadiationInfo;}

	double	GetLength(){return m_Length;}
	double	GetWidth(){return m_Width;}
	double	GetHeight(){return m_Height;}
	double	GetDraft(){return m_Draft;}
	double	GetDeckH(){return m_DeckH;}
	double	GetMaxVelocity(){return m_MaxVelocity;}
	double	GetMaxAcc(){return m_MaxAcc;}
	double	GetMaxDec(){return m_MaxDec;}

	//{{HDOSE_MEMBER_FUNCTION(CSurfaceShipStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:

	//{{HDOSE_ATTRIBUTE(CSurfaceShipStateRep)
	long	m_JammerChannelCount/*干扰器通道数量（最多10个）*/;
	CJammerChannelData	m_JammerChannelInfo[10]/*干扰器通道信息（10个元素的数组）*/;
	long	m_AAMCount/*可用防空导弹数量（最多100个）*/;
	long	m_ChaffCount/*可用箔条弹数量（最多100个）*/;

	long	m_IrradiatorCount/*火力通道数量（最多100个）*/;
	CIrradiatorData	 m_IrradiatorInfo[100]/*火力通道信息（100个元素的数组）*/;

	double	m_SurfaceEWDistance/*舰艇预警雷达探测距离km（从雷达静态参数中获取）*/;
	double	m_AAMInterceptDistance/*防空导弹拦截距离km（火控雷达距离）*/;
//	CTargetData	m_ElectricScoutInfo[100]/*电子侦察告警指示信息（100个元素的数组，要修改）*/;
//	long	m_ElectricScoutInfoCount/*电子侦察告警指示信息个数（最多100个）*/;
	CLaunchVehicleData	m_LauncherInfo[4]/*反舰导弹发射架信息（数组）*/;

	long	m_LauncherCount/*反舰导弹发射架数量*/;
	long	m_TorpedoCount/*鱼雷数量*/;
	long	m_TorpedoType/*鱼雷类型*/;
	long	m_selfAutoAntiAir/*是否自动防空,0否,1是*/;	// 20160629
	long	m_SelfInterceptStratege/*本舰防空弹拦截策略*/;
	long	m_IsJoinedGroup/*是否加入到拦截编队(-1无效，0未加入-默认，1加入)*/;
	long	m_AAMLauncherCount/*防空导弹发射架数量（最多5个）*/;
	CAAMLauncherData	m_AAMLauncherInfo[5]/*防空导弹发射架信息（最多5个）*/;
	long	m_ActiveDecoyCount/*有源诱饵弹数量*/;
	long	m_ActiveDecoyType/*有源诱饵弹类型*/;
	long	m_ChaffType/*箔条弹类型*/;

	// 20151004新增
	long	m_ChaffLauncherCount;		// 箔条发射架数量
	long	m_ShipECM;	// 是否实施单舰电子战，0否，1是
	int	m_ShipGunAntiAir; // 是否使用舰炮防空,0否，1是
	// 20171030
	int	m_ShipAAMLaunchMode; // 本舰防空导弹发射模式，默认0-连续发射、1-连续发射模式、2-发射-观察-发射模式

	CRadiationData	m_SurfRadiationInfo/*舰艇辐射源信息*/;

	//}}HDOSE_ATTRIBUTE

	//{{HDOSE_PARAMETER(CSurfaceShipStateRep)
	double	m_Length/*舰艇长度（m）*/;
	double	m_Width/*舰艇宽度（m）*/;
	double	m_Height/*舰艇高度（m）*/;
	double	m_Draft/*吃水深度（m）*/;
	double	m_DeckH/*飞机停放甲板高度，米*/;
	double	m_MaxVelocity/*最大速度（节）*/;
	double	m_MaxAcc/*最大加速度（m/s^2）*/;
	double	m_MaxDec/*最大减速度（m/s^2）*/;
	//}}HDOSE_PARAMETER

};

#endif
