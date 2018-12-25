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
Descript:	��Ҫ����̽��
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CSensorModel /*������*/ : public CModel 
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
	//{{HDOSE_EVENT_HANDLER(CSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CSensorModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSensorModel)
	bool	m_bPowerOn/*���ػ�״̬��0�ػ���1������*/;
	bool	m_bDetectTarget/*�Ƿ�̽�⵽Ŀ�꣨0��1�ǣ�*/;
	long	m_nState/*״̬������0������1��������2��*/;
	long	m_nOwnerID/*������ʵ��ID*/;
	char*	m_strName/*�豸����*/;
	long	m_nDeviceID/*�豸ID*/;
	CVector	m_vLocalPos/*�ֲ����꣨ǰx-��y-��z����λ���ף�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
