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
Descript:	��������ϵͳ������ƽ̨�ϵ�һ��������������װ�ã������ñ���ķ���Լ��������״̬��װ�������ȡ�
*/
//}}HDOSE_CLS_DES

class HYCGF_API CWeaponMountModel /*��������ϵͳģ��*/ : public CModel 
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
	// xks,20161208,��opd������ʼ���õ��������У���Ҫ��tick�е��ò���,
	// �˺���Ϊ�麯�����Լ�������������д������
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
	virtual void	OnDeviceOper(CEvt *pevent);		// �˴���Ϊ�麯��������ɿ���д�˺�������д�󣬸��¼����Զ�����������Ӧ, xks
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CWeaponMountModel)
	long	m_Type/*����װ������*/;
	long	m_Category/*����װ�����ÿһ���������в�ͬ�����*/;
	char	m_MountName[MAX_CHARLEN]/*����װ���ͺ�����*/;
	char	m_DeviceName[MAX_CHARLEN]/*�豸����*/;
	Vec3	m_LocalPos/*��װλ�ã��ֲ����꣨x,y,x��*/;
	double	m_MinAz/*���䷽λ��Сֵ��������������Ϊ��׼��0-360����-180��180����Ϊ��ֵ����ʾ�Ӹ������ķ�Χ������ָ������Ϊ��������Ϊ����*/;
	double	m_MaxAz/*���䷽λ�Ǵ�ֵ��������������Ϊ��׼��0-360��*/;
	double	m_MinEl/*����ߵͽ�Сֵ��-90��+90��*/;
	double	m_MaxEl/*����ߵͽǴ�ֵ��-90��+90��*/;
	double	m_SysPrepTime/*ϵͳ׼��ʱ��(s)*/;
	double	m_SysRespTime/*ϵͳ��Ӧʱ��(s)*/;
	double	m_FireIntervalTime/*��С������(s)*/;
	double	m_RoF/*��������(��/min)*/;
	double	m_AzTurnRate/*��λת������(deg/s)*/;
	double	m_ElTurnRate/*����ת������(deg/s)*/;
	double	m_LoadTime/*��װ��ʱ��(s)*/;
	double	m_RouteShortMax/*���·�ݾ�(Km)*/;
	long	m_WeaponCountMax/*��󴢵���*/;
	long	m_WeaponCountNormal/*��ǰ������*/;
	long	m_SalvoCount/*��������*/;
	long	m_WeaponRecCount/*װ����������*/;
	DA_CWeaponRecDataStr	m_WeaponRecData/*װ������*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CWeaponMountModel)
	bool	m_bPowerOn/*�Ƿ񿪻�*/;
	long	m_OwnerEntityID/*������ʵ��ID*/;
	long	m_DeviceState/*�豸״̬������0������1��������2��*/;
	long	m_WorkMode_cur/*��ǰ����ģʽ*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
