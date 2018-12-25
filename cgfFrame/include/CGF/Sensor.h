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

#define MAXLongCount 10	// 描述传感器的工作模式或各种频段时，数组的最大个数

//{{HDOSE_CLS_DES(CSensor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSensor /*传感器(HYCGF)*/ : public CModel 
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
	// xks,20161126,将opd参数初始设置到参数集中，需要在tick中调用才行，此函数为虚函数
	// ！Note：Sensor的Tick中并未调用此方法！
	virtual void InitSetEntID()
	{
		if(m_OwnerEntityID>0)		return; // 如果已经设置了参数，则返回

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
	double base10_to_dB(double x);	// 数值转换为dB
	double dB_to_base10(double x);	// dB转换为数值
		/*
	pt // 峰值功率,KW
	freq // 频率,Hz
	g // 天线增益,dB
	te // 系统温度,K
	b // 带宽,Hz
	nf//噪声系数,dB
	loss // 雷达损耗,dB

	R // 目标距离,m
	sigma // RCS,m^2

	输出: Snr -- dB
	*/
	double RadarSNR(double pt, double freq, double g, double te, double b, double nf, double loss, double R, double sigma);	// 雷达SNR计算
		/*
	D0 -- 光学系统的入瞳直径,m
	Ds -- 探测器的探测率,m*sqrt(Hz)/W
	tuo0 -- 大气透过率,无量纲
	tuoa -- 光学系统透过率,无量纲
	It -- 目标辐射强度,W/sr
	delta -- 信号衰减因子,无量纲
	F -- 光学系统的F数,m
	omega -- 红外系统瞬时立体视场角,rad
	deltaf -- 红外系统噪声等效带宽,Hz
	R -- 目标距离,m

	输出: Snr -- dB
	*/
	double InfraredSNR(double D0, double Ds, double tuo0, double tuoa, double It, double delta, double F, double omega, double deltaf, double R);	// 红外SNR计算
	// pfa -- 如：1e-9, snr--dB
	double DetectProb(double pfa, double snr);	// 根据虚警率和snr，计算检测概率
	double RandomUniform(  double dMinValue,    double dMaxValue);	// 产生随机数
	bool IsDetectObj(double prob); // 根据检测概率，计算是否探测到（根据探测概率，进行取样）
//////////////////////////////////////////////////////////////////////////

protected:
	//{{HDOSE_EVENT_HANDLER(CSensor)
	virtual void	OnSensorOper(CEvt *pevent);		// 此处改为虚函数，子类可可重写此函数，重写后，该事件将自动在子类中响应, xks
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSensor)
	DtEntityType	m_SensorEnumType/*雷达7位码的编码规则（'.'，可选择使用）*/;
	long	m_SensorType/*传感器类型(1雷达、2红外、3声学、4 IFF)*/;
	long	m_SensorCategory/*传感器类别（每一种类型中有不同的类别）*/;
	long	m_SensorAbility[MAXLongCount]/*传感器能力分类（数组，可能有多个，','）*/;
	long	m_SensorAbilityCount/*传感器能力分类的数量*/;
	char	m_DeviceName[MAX_CHARLEN]/*设备名称*/;
	Vec3	m_LocalPos/*安装位置，局部坐标（x,y,z）*/;
	double	m_MinDetectDistance/*最小探测距离(km)*/;
	double	m_MaxDetectDistance/*最大探测距离(km)*/;
	long	m_FOVType/*视场类型（1简单锥形、2复杂锥形）*/;
	double	m_ConeAngle/*简单锥形半角（deg）*/;
	double	m_MinAz/*探测方位角小值（以载体中心轴为基准，0-360或者-180～180可以为负值，表示从负到正的范围，中心指向向左为负、向右为正）*/;
	double	m_MaxAz/*探测方位角大值（以载体中心轴为基准，0-360）*/;
	double	m_MinEl/*探测高低角小值（-90～+90）*/;
	double	m_MaxEl/*探测高低角大值（-90～+90）*/;
	double	m_MinHeight/*最小探测高度(m)*/;
	double	m_MaxHeight/*最大探测高度(m)*/;
	bool m_SimTerrainLOS/*是否考虑地形对传感器-目标通视性的影响，默认为0*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSensor)
	bool	m_bPowerOn/*是否开机*/;
	long	m_OwnerEntityID/*所有者实体ID*/;
	long	m_DeviceState/*设备状态（良好0，故障1，降功能2）*/;
	double	m_AntennaAz/*当前天线方位角*/;
	double	m_AntennaEl/*当前天线高低角*/;
	long	m_DetectMode_cur/*当前探测模式*/;
	long	m_WorkMode_cur/*当前工作模式*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
