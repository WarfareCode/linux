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

class DATASTRUCTCOMPONENTDLL_API CSurfaceShipStateRep /*ˮ�潢ͧ״̬��*/ : public CSurfaceESR 
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
	long	m_JammerChannelCount/*������ͨ�����������10����*/;
	CJammerChannelData	m_JammerChannelInfo[10]/*������ͨ����Ϣ��10��Ԫ�ص����飩*/;
	long	m_AAMCount/*���÷��յ������������100����*/;
	long	m_ChaffCount/*���ò��������������100����*/;

	long	m_IrradiatorCount/*����ͨ�����������100����*/;
	CIrradiatorData	 m_IrradiatorInfo[100]/*����ͨ����Ϣ��100��Ԫ�ص����飩*/;

	double	m_SurfaceEWDistance/*��ͧԤ���״�̽�����km�����״ﾲ̬�����л�ȡ��*/;
	double	m_AAMInterceptDistance/*���յ������ؾ���km������״���룩*/;
//	CTargetData	m_ElectricScoutInfo[100]/*�������澯ָʾ��Ϣ��100��Ԫ�ص����飬Ҫ�޸ģ�*/;
//	long	m_ElectricScoutInfoCount/*�������澯ָʾ��Ϣ���������100����*/;
	CLaunchVehicleData	m_LauncherInfo[4]/*���������������Ϣ�����飩*/;

	long	m_LauncherCount/*�����������������*/;
	long	m_TorpedoCount/*��������*/;
	long	m_TorpedoType/*��������*/;
	long	m_selfAutoAntiAir/*�Ƿ��Զ�����,0��,1��*/;	// 20160629
	long	m_SelfInterceptStratege/*�������յ����ز���*/;
	long	m_IsJoinedGroup/*�Ƿ���뵽���ر��(-1��Ч��0δ����-Ĭ�ϣ�1����)*/;
	long	m_AAMLauncherCount/*���յ�����������������5����*/;
	CAAMLauncherData	m_AAMLauncherInfo[5]/*���յ����������Ϣ�����5����*/;
	long	m_ActiveDecoyCount/*��Դ�ն�������*/;
	long	m_ActiveDecoyType/*��Դ�ն�������*/;
	long	m_ChaffType/*����������*/;

	// 20151004����
	long	m_ChaffLauncherCount;		// �������������
	long	m_ShipECM;	// �Ƿ�ʵʩ��������ս��0��1��
	int	m_ShipGunAntiAir; // �Ƿ�ʹ�ý��ڷ���,0��1��
	// 20171030
	int	m_ShipAAMLaunchMode; // �������յ�������ģʽ��Ĭ��0-�������䡢1-��������ģʽ��2-����-�۲�-����ģʽ

	CRadiationData	m_SurfRadiationInfo/*��ͧ����Դ��Ϣ*/;

	//}}HDOSE_ATTRIBUTE

	//{{HDOSE_PARAMETER(CSurfaceShipStateRep)
	double	m_Length/*��ͧ���ȣ�m��*/;
	double	m_Width/*��ͧ��ȣ�m��*/;
	double	m_Height/*��ͧ�߶ȣ�m��*/;
	double	m_Draft/*��ˮ��ȣ�m��*/;
	double	m_DeckH/*�ɻ�ͣ�żװ�߶ȣ���*/;
	double	m_MaxVelocity/*����ٶȣ��ڣ�*/;
	double	m_MaxAcc/*�����ٶȣ�m/s^2��*/;
	double	m_MaxDec/*�����ٶȣ�m/s^2��*/;
	//}}HDOSE_PARAMETER

};

#endif
