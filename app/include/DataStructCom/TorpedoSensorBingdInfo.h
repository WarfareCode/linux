//TorpedoSensorBingdInfo.h: interface for the CTorpedoSensorBingdInfo module.
//!!HDOSE_CLASS(CTorpedoSensorBingdInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoSensorBingdInfo_H)
#define AFX_TorpedoSensorBingdInfo_H


//{{HDOSE_CLS_DES(CTorpedoSensorBingdInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoSensorBingdInfo /*鱼雷探测器装订信息*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoSensorBingdInfo();
	virtual ~CTorpedoSensorBingdInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetPowerOnTime(double val){m_PowerOnTime=val;}
	double	GetPowerOnTime(){return m_PowerOnTime;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoSensorBingdInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoSensorBingdInfo)
	long	m_TargetNo/*目标编号*/;
	double	m_PowerOnTime/*开机时间*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
