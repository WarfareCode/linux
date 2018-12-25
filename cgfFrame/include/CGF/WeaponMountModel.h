//WeaponMountModel.h: interface for the CWeaponMountModel module.
//!!HDOSE_CLASS(CWeaponMountModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_WeaponMountModel_H)
#define AFX_WeaponMountModel_H

#include "Model.h"
#include "WeaponRecDataStr.h"
#include "WeaponSysModelSR.h"

//{{HDOSE_CLS_DES(CWeaponMountModel)
/*
Author:		xks
Version:	1.0
Descript:	武器发射系统，代表平台上的一个独立武器发射装置，可配置本身的发射约束参数、状态、装弹参数等。
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponMountModel /*武器发射系统模型*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CWeaponMountModel();
	virtual ~CWeaponMountModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	///-------------//
	// xks,20161208,将opd参数初始设置到参数集中，需要在tick中调用才行,
	// 此函数为虚函数，自己在派生类中重写并调用
	virtual void InitSetEntID()	
	{
		m_OwnerEntityID = GetStateRepository()->GetID();
		CWeaponSysModelSR* pMdSR =(CWeaponSysModelSR*) GetModelSR();
		if(pMdSR)
		{
			pMdSR->SetOwnerEntityID(m_OwnerEntityID);
			pMdSR->SetDeviceName(m_DeviceName);

			pMdSR->SetWeaponCount(m_WeaponCountNormal);
			pMdSR->SetWeaponRecCount(m_WeaponRecCount);

			for(int i = 0; i<m_WeaponRecCount; i++)
			{
				pMdSR->m_WeaponRecData[i].m_WeaponRecID = m_WeaponRecData[i].m_WeaponRecID;
				strcpy(pMdSR->m_WeaponRecData[i].m_Name, m_WeaponRecData[i].m_Name);
				pMdSR->m_WeaponRecData[i].m_Count = m_WeaponRecData[i].m_Count;
				pMdSR->m_WeaponRecData[i].m_Available =m_WeaponRecData[i].m_Available;
				pMdSR->m_WeaponRecData[i].m_TimeToFire =m_WeaponRecData[i].m_TimeToFire;
			}
			pMdSR->m_WeaponRecData.m_len = m_WeaponRecCount;
		}
	}
	//--------------//

	//////////////////////////////////////////////////////////////////////////
	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}
	void	SetOwnerEntityID(long val){m_OwnerEntityID=val;}
	long	GetOwnerEntityID(){return m_OwnerEntityID;}
	void	SetDeviceState(long val){m_DeviceState=val;}
	long	GetDeviceState(){return m_DeviceState;}
	void	SetWorkMode_cur(long val){m_WorkMode_cur=val;}
	long	GetWorkMode_cur(){return m_WorkMode_cur;}

	long	GetType(){return m_Type;}
	long	GetCategroy(){return m_Category;}
	char*	GetMountName(){return m_MountName;}
	char*	GetDeviceName(){return m_DeviceName;}
	Vec3	GetLocalPos(){return m_LocalPos;}
	double	GetMinAz(){return m_MinAz;}
	double	GetMaxAz(){return m_MaxAz;}
	double	GetMinEl(){return m_MinEl;}
	double	GetMaxEl(){return m_MaxEl;}
	double	GetSysPrepTime(){return m_SysPrepTime;}
	double	GetSysRespTime(){return m_SysRespTime;}
	double	GetFireIntervalTime(){return m_FireIntervalTime;}
	double	GetRoF(){return m_RoF;}
	double	GetAzTurnRate(){return m_AzTurnRate;}
	double	GetElTurnRate(){return m_ElTurnRate;}
	double	GetLoadTime(){return m_LoadTime;}
	double	GetRouteShortMax(){return m_RouteShortMax;}
	long	GetWeaponCountMax(){return m_WeaponCountMax;}
	long	GetWeaponCountNormal(){return m_WeaponCountNormal;}
	long	GetSalvoCount(){return m_SalvoCount;}
	long	GetWeaponRecCount(){return m_WeaponRecCount;}
	//CWeaponRecDataStr	GetWeaponRecData(){return m_WeaponRecData;}

	//{{HDOSE_MEMBER_FUNCTION(CWeaponMountModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CWeaponMountModel)
	virtual void	OnDeviceOper(CEvt *pevent);		// 此处改为虚函数，子类可可重写此函数，重写后，该事件将自动在子类中响应, xks
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CWeaponMountModel)
	long	m_Type/*发射装置类型*/;
	long	m_Category/*发射装置类别（每一种类型中有不同的类别）*/;
	char	m_MountName[MAX_CHARLEN]/*发射装置型号名称*/;
	char	m_DeviceName[MAX_CHARLEN]/*设备名称*/;
	Vec3	m_LocalPos/*安装位置，局部坐标（x,y,x）*/;
	double	m_MinAz/*发射方位角小值（以载体中心轴为基准，0-360或者-180～180可以为负值，表示从负到正的范围，中心指向向左为负、向右为正）*/;
	double	m_MaxAz/*发射方位角大值（以载体中心轴为基准，0-360）*/;
	double	m_MinEl/*发射高低角小值（-90～+90）*/;
	double	m_MaxEl/*发射高低角大值（-90～+90）*/;
	double	m_SysPrepTime/*系统准备时间(s)*/;
	double	m_SysRespTime/*系统反应时间(s)*/;
	double	m_FireIntervalTime/*最小发射间隔(s)*/;
	double	m_RoF/*发射速率(发/min)*/;
	double	m_AzTurnRate/*方位转动速率(deg/s)*/;
	double	m_ElTurnRate/*俯仰转动速率(deg/s)*/;
	double	m_LoadTime/*再装填时间(s)*/;
	double	m_RouteShortMax/*最大航路捷径(Km)*/;
	long	m_WeaponCountMax/*最大储弹量*/;
	long	m_WeaponCountNormal/*当前储弹量*/;
	long	m_SalvoCount/*齐射数量*/;
	long	m_WeaponRecCount/*装弹种类数量*/;
	DA_CWeaponRecDataStr	m_WeaponRecData/*装弹参数*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CWeaponMountModel)
	bool	m_bPowerOn/*是否开机*/;
	long	m_OwnerEntityID/*所有者实体ID*/;
	long	m_DeviceState/*设备状态（良好0，故障1，降功能2）*/;
	long	m_WorkMode_cur/*当前工作模式*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
