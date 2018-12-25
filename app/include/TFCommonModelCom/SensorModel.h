//SensorModel.h: interface for the CSensorModel module.
//!!HDOSE_CLASS(CSensorModel,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SensorModel_H)
#define AFX_SensorModel_H

#include "Vector.h"

//{{HDOSE_CLS_DES(CSensorModel)
/*
Author:		
Version:	1.0
Descript:	主要负责探测
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CSensorModel /*传感器*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CSensorModel();
	virtual ~CSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetbPowerOn(bool val){m_bPowerOn=val;}
	bool	GetbPowerOn(){return m_bPowerOn;}
	void	SetbDetectTarget(bool val){m_bDetectTarget=val;}
	bool	GetbDetectTarget(){return m_bDetectTarget;}
	void	SetnState(long val){m_nState=val;}
	long	GetnState(){return m_nState;}
	void	SetnOwnerID(long val){m_nOwnerID=val;}
	long	GetnOwnerID(){return m_nOwnerID;}
	//void	SetstrName(char* val){strcpy(m_strName,val);}
	//char*	GetstrName(){return m_strName;}
	void	SetstrName(char* val){SetValueString("strName",val);}
	char*	GetstrName(){return GetValueString("strName");}
	void	SetnDeviceID(long val){m_nDeviceID=val;}
	long	GetnDeviceID(){return m_nDeviceID;}
	void	SetvLocalPos(CVector val){m_vLocalPos=val;}
	CVector	GetvLocalPos(){return m_vLocalPos;}

	//{{HDOSE_MEMBER_FUNCTION(CSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

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
	//{{HDOSE_EVENT_HANDLER(CSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSensorModel)
	bool	m_bPowerOn/*开关机状态（0关机、1开机）*/;
	bool	m_bDetectTarget/*是否探测到目标（0否，1是）*/;
	long	m_nState/*状态（良好0，故障1，降功能2）*/;
	long	m_nOwnerID/*所有者实体ID*/;
	char*	m_strName/*设备名称*/;
	long	m_nDeviceID/*设备ID*/;
	CVector	m_vLocalPos/*局部坐标（前x-右y-上z，单位：米）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
