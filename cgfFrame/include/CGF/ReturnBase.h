//ReturnBase.h: interface for the CReturnBase module.
//!!HDOSE_CLASS(CReturnBase,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ReturnBase_H)
#define AFX_ReturnBase_H

#include "Task.h"

//{{HDOSE_CLS_DES(CReturnBase)
/*
Author:		xks
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CReturnBase /*返回基地*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CReturnBase();
	virtual ~CReturnBase();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLandingDesLocType(long val){m_LandingDesLocType=val;}
	long	GetLandingDesLocType(){return m_LandingDesLocType;}
	void	SetCarrierId(long val){m_CarrierId=val;}
	long	GetCarrierId(){return m_CarrierId;}
	void	SetControlObjId(long val){m_ControlObjId=val;}
	long	GetControlObjId(){return m_ControlObjId;}
	void	SetLanding(bool val){m_Landing=val;}
	bool	GetLanding(){return m_Landing;}
	void	SetLocation(GeoPt val){m_Location=val;}
	GeoPt	GetLocation(){return m_Location;}
	void	SetRunWayHead(double val){m_RunWayHead=val;}
	double	GetRunWayHead(){return m_RunWayHead;}
	void	SetLandingRouteType(long val){m_LandingRouteType=val;}
	long	GetLandingRouteType(){return m_LandingRouteType;}
	//{{HDOSE_MEMBER_FUNCTION(CReturnBase)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CReturnBase)
	long	m_LandingDesLocType/*降落目的地类型（0-默认初始位置、1-实体、2-点控制对象、3-任意点）*/;
	long	m_CarrierId/*实体（母舰、机场）Id*/;
	long	m_ControlObjId/*点控制对象Id*/;
	bool m_Landing/*返航后是否直接着陆，0-否、1-是，默认为0*/;
	GeoPt	m_Location/*机场或降落跑道起始/中心位置*/;
	double m_RunWayHead/*跑道航向，正北为0度，顺时针，0-360deg*/;
	long m_LandingRouteType/*进场着陆航线方式，0-左航线切入；1；中航线切入；2：右航线切入；3：原路返回；*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
