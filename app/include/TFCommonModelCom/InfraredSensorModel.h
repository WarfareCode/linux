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

class TFCOMMONMODELCOM_API CInfraredSensorModel /*红外传感器*/ : public CSensor 
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
	double	m_LocatedH/*安装高度（m，相对于载体中心）*/;
	double	m_MaxDetectDistance/*最大探测距离（公里）*/;
	double	m_MinAz/*探测方位角小值（以载体中心轴为基准，0-360或者-180～180可以为负值，如果为负值，则表示从负到正的范围，中心指向向左为负、向右为正）*/;
	double	m_MaxAz/*探测方位角大值（以载体中心轴为基准，0-360，不能为负）*/;
	double	m_MinEl/*探测高低角小值（-90～+90）*/;
	double	m_MaxEl/*探测高低角大值（-90～+90）*/;
	long	m_f/*红外系统焦距m*/;
	double	m_D0/*红外系统入瞳直径m*/;
	double	m_Ds/*探测器的探测率,m*sqrt(Hz)/W*/;
	double	m_tuoa/*红外系统透过率*/;
	double	m_F/*红外系统的F数*/;
	double	m_omega/*红外系统瞬时立体视场角*/;
	double	m_deltaf/*红外系统噪声等效带宽*/;
	double	m_pfa/*虚警率*/;
	double	m_dataRate/*数据率s*/;
	long	m_maxDealTargets/*最大处理目标数*/;
	long	m_firstBatchNo/*起始批号*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CInfraredSensorModel)
	//}}HDOSE_ATTRIBUTE
};

#endif
