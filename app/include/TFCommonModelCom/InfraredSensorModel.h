//InfraredSensorModel.h: interface for the CInfraredSensorModel module.
//!!HDOSE_CLASS(CInfraredSensorModel,CSensor)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_InfraredSensorModel_H)
#define AFX_InfraredSensorModel_H

//#include "SensorModel.h"

//{{HDOSE_CLS_DES(CInfraredSensorModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CInfraredSensorModel /*���⴫����*/ : public CSensor 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CInfraredSensorModel();
	virtual ~CInfraredSensorModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetLocatedH(){return m_LocatedH;}
	double	GetMaxDetectDistance(){return m_MaxDetectDistance;}
	double	GetMinAz(){return m_MinAz;}
	double	GetMaxAz(){return m_MaxAz;}
	double	GetMinEl(){return m_MinEl;}
	double	GetMaxEl(){return m_MaxEl;}
	long	Getf(){return m_f;}
	double	GetD0(){return m_D0;}
	double	GetDs(){return m_Ds;}
	double	Gettuoa(){return m_tuoa;}
	double	GetF(){return m_F;}
	double	Getomega(){return m_omega;}
	double	Getdeltaf(){return m_deltaf;}
	double	Getpfa(){return m_pfa;}
	double	GetdataRate(){return m_dataRate;}
	long	GetmaxDealTargets(){return m_maxDealTargets;}
	long	GetfirstBatchNo(){return m_firstBatchNo;}

	//{{HDOSE_MEMBER_FUNCTION(CInfraredSensorModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CInfraredSensorModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CInfraredSensorModel)
	double	m_LocatedH/*��װ�߶ȣ�m��������������ģ�*/;
	double	m_MaxDetectDistance/*���̽����루���*/;
	double	m_MinAz/*̽�ⷽλ��Сֵ��������������Ϊ��׼��0-360����-180��180����Ϊ��ֵ�����Ϊ��ֵ�����ʾ�Ӹ������ķ�Χ������ָ������Ϊ��������Ϊ����*/;
	double	m_MaxAz/*̽�ⷽλ�Ǵ�ֵ��������������Ϊ��׼��0-360������Ϊ����*/;
	double	m_MinEl/*̽��ߵͽ�Сֵ��-90��+90��*/;
	double	m_MaxEl/*̽��ߵͽǴ�ֵ��-90��+90��*/;
	long	m_f/*����ϵͳ����m*/;
	double	m_D0/*����ϵͳ��ֱͫ��m*/;
	double	m_Ds/*̽������̽����,m*sqrt(Hz)/W*/;
	double	m_tuoa/*����ϵͳ͸����*/;
	double	m_F/*����ϵͳ��F��*/;
	double	m_omega/*����ϵͳ˲ʱ�����ӳ���*/;
	double	m_deltaf/*����ϵͳ������Ч����*/;
	double	m_pfa/*�龯��*/;
	double	m_dataRate/*������s*/;
	long	m_maxDealTargets/*�����Ŀ����*/;
	long	m_firstBatchNo/*��ʼ����*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CInfraredSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
