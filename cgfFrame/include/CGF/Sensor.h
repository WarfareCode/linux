//Sensor.h: interface for the CSensor module.
//!!HDOSE_CLASS(CSensor,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Sensor_H)
#define AFX_Sensor_H

#include "Model.h"
#include "StateRepository.h"
#include "SensorModelSR.h"

#define MAXLongCount 10	// �����������Ĺ���ģʽ�����Ƶ��ʱ�������������

//{{HDOSE_CLS_DES(CSensor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSensor /*������(HYCGF)*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSensor();
	virtual ~CSensor();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}
	void	SetOwnerEntityID(long val){m_OwnerEntityID=val;}
	long	GetOwnerEntityID(){return m_OwnerEntityID;}
	void	SetDeviceState(long val){m_DeviceState=val;}
	long	GetDeviceState(){return m_DeviceState;}
	void	SetAntennaAz(double val){m_AntennaAz=val;}
	double	GetAntennaAz(){return m_AntennaAz;}
	void	SetAntennaEl(double val){m_AntennaEl=val;}
	double	GetAntennaEl(){return m_AntennaEl;}
	void	SetDetectMode_cur(long val){m_DetectMode_cur=val;}
	long	GetDetectMode_cur(){return m_DetectMode_cur;}
	void	SetWorkMode_cur(long val){m_WorkMode_cur=val;}
	long	GetWorkMode_cur(){return m_WorkMode_cur;}

	DtEntityType	GetSensorEnumType(){return m_SensorEnumType;}
	long	GetSensorType(){return m_SensorType;}
	long	GetSensorCategory(){return m_SensorCategory;}
	//long	GetSensorAbility(){return m_SensorAbility;}
	long	GetSensorAbilityCount(){return m_SensorAbilityCount;}
	char*	GetDeviceName(){return m_DeviceName;}
	Vec3	GetLocalPos(){return m_LocalPos;}
	double	GetMaxDetectDistance(){return m_MaxDetectDistance;}
	double	GetMinDetectDistance(){return m_MinDetectDistance;}
	long	GetFOVType(){return m_FOVType;}
	double	GetConeAngle(){return m_ConeAngle;}
	double	GetMinAz(){return m_MinAz;}
	double	GetMaxAz(){return m_MaxAz;}
	double	GetMinEl(){return m_MinEl;}
	double	GetMaxEl(){return m_MaxEl;}
	double	GetMinHeight(){return m_MinHeight;}
	double	GetMaxHeight(){return m_MaxHeight;}
	bool	GetSimTerrainLOS(){return m_SimTerrainLOS;}

	//{{HDOSE_MEMBER_FUNCTION(CSensor)
	//}}HDOSE_MEMBER_FUNCTION

	///-------------//
	// xks,20161126,��opd������ʼ���õ��������У���Ҫ��tick�е��ò��У��˺���Ϊ�麯��
	// ��Note��Sensor��Tick�в�δ���ô˷�����
	virtual void InitSetEntID()
	{
		if(m_OwnerEntityID>0)		return; // ����Ѿ������˲������򷵻�

		m_OwnerEntityID = GetStateRepository()->GetID();
		CSensorModelSR* pMdSR =(CSensorModelSR*) GetModelSR();
		if(pMdSR)
		{
			pMdSR->SetOwnerEntityID(m_OwnerEntityID);
			pMdSR->SetDeviceName(m_DeviceName);
		}
	}
	//--------------//

	//////////////////////////////////////////////////////////////////////////
	// 20160627,xks
	double base10_to_dB(double x);	// ��ֵת��ΪdB
	double dB_to_base10(double x);	// dBת��Ϊ��ֵ
		/*
	pt // ��ֵ����,KW
	freq // Ƶ��,Hz
	g // ��������,dB
	te // ϵͳ�¶�,K
	b // ����,Hz
	nf//����ϵ��,dB
	loss // �״����,dB

	R // Ŀ�����,m
	sigma // RCS,m^2

	���: Snr -- dB
	*/
	double RadarSNR(double pt, double freq, double g, double te, double b, double nf, double loss, double R, double sigma);	// �״�SNR����
		/*
	D0 -- ��ѧϵͳ����ֱͫ��,m
	Ds -- ̽������̽����,m*sqrt(Hz)/W
	tuo0 -- ����͸����,������
	tuoa -- ��ѧϵͳ͸����,������
	It -- Ŀ�����ǿ��,W/sr
	delta -- �ź�˥������,������
	F -- ��ѧϵͳ��F��,m
	omega -- ����ϵͳ˲ʱ�����ӳ���,rad
	deltaf -- ����ϵͳ������Ч����,Hz
	R -- Ŀ�����,m

	���: Snr -- dB
	*/
	double InfraredSNR(double D0, double Ds, double tuo0, double tuoa, double It, double delta, double F, double omega, double deltaf, double R);	// ����SNR����
	// pfa -- �磺1e-9, snr--dB
	double DetectProb(double pfa, double snr);	// �����龯�ʺ�snr�����������
	double RandomUniform(  double dMinValue,    double dMaxValue);	// ���������
	bool IsDetectObj(double prob); // ���ݼ����ʣ������Ƿ�̽�⵽������̽����ʣ�����ȡ����
//////////////////////////////////////////////////////////////////////////

protected:
	//{{HDOSE_EVENT_HANDLER(CSensor)
	virtual void	OnSensorOper(CEvt *pevent);		// �˴���Ϊ�麯��������ɿ���д�˺�������д�󣬸��¼����Զ�����������Ӧ, xks
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSensor)
	DtEntityType	m_SensorEnumType/*�״�7λ��ı������'.'����ѡ��ʹ�ã�*/;
	long	m_SensorType/*����������(1�״2���⡢3��ѧ��4 IFF)*/;
	long	m_SensorCategory/*���������ÿһ���������в�ͬ�����*/;
	long	m_SensorAbility[MAXLongCount]/*�������������ࣨ���飬�����ж����','��*/;
	long	m_SensorAbilityCount/*�������������������*/;
	char	m_DeviceName[MAX_CHARLEN]/*�豸����*/;
	Vec3	m_LocalPos/*��װλ�ã��ֲ����꣨x,y,z��*/;
	double	m_MinDetectDistance/*��С̽�����(km)*/;
	double	m_MaxDetectDistance/*���̽�����(km)*/;
	long	m_FOVType/*�ӳ����ͣ�1��׶�Ρ�2����׶�Σ�*/;
	double	m_ConeAngle/*��׶�ΰ�ǣ�deg��*/;
	double	m_MinAz/*̽�ⷽλ��Сֵ��������������Ϊ��׼��0-360����-180��180����Ϊ��ֵ����ʾ�Ӹ������ķ�Χ������ָ������Ϊ��������Ϊ����*/;
	double	m_MaxAz/*̽�ⷽλ�Ǵ�ֵ��������������Ϊ��׼��0-360��*/;
	double	m_MinEl/*̽��ߵͽ�Сֵ��-90��+90��*/;
	double	m_MaxEl/*̽��ߵͽǴ�ֵ��-90��+90��*/;
	double	m_MinHeight/*��С̽��߶�(m)*/;
	double	m_MaxHeight/*���̽��߶�(m)*/;
	bool m_SimTerrainLOS/*�Ƿ��ǵ��ζԴ�����-Ŀ��ͨ���Ե�Ӱ�죬Ĭ��Ϊ0*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSensor)
	bool	m_bPowerOn/*�Ƿ񿪻�*/;
	long	m_OwnerEntityID/*������ʵ��ID*/;
	long	m_DeviceState/*�豸״̬������0������1��������2��*/;
	double	m_AntennaAz/*��ǰ���߷�λ��*/;
	double	m_AntennaEl/*��ǰ���߸ߵͽ�*/;
	long	m_DetectMode_cur/*��ǰ̽��ģʽ*/;
	long	m_WorkMode_cur/*��ǰ����ģʽ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
