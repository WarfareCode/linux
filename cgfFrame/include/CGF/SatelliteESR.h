//SatelliteESR.h: interface for the CSatelliteESR module.
//!!HDOSE_CLASS(CSatelliteESR,CSpaceESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SatelliteESR_H)
#define AFX_SatelliteESR_H

#include "OrbitData.h"
#include "SpaceESR.h"

//{{HDOSE_CLS_DES(CSatelliteESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSatelliteESR /*卫星实体状态池*/ : public CSpaceESR 
{
	DECLARE_CREATE;
public:
	CSatelliteESR();
	virtual ~CSatelliteESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetOrbitInfo(COrbitData val){m_OrbitInfo=val;}
	COrbitData	GetOrbitInfo(){return m_OrbitInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CSatelliteESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSatelliteESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSatelliteESR)
	COrbitData	m_OrbitInfo/*轨道参数*/;
		//可通过脚本写入六个参数，用','分隔，内容如下：	
		//				m_a/*半长轴(Km)*/,
		//				m_e/*偏心率(0圆,0-1椭圆,>1双曲线)*/,
		//				m_Incl/*轨道倾角,弹道平面与赤道面的夹角(度)*/,
		//				m_RA/*升交点赤经(度)*/,
		//				m_w/*近地点中心角(Argument of perigee)(度)*/,
		//				m_TA/*真近点角(True Anomaly)(度)*/）

	//}}HDOSE_ATTRIBUTE
};

#endif
