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

class HYCGF_API CReturnBase /*���ػ���*/ : public CTask 
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
	long	m_LandingDesLocType/*����Ŀ�ĵ����ͣ�0-Ĭ�ϳ�ʼλ�á�1-ʵ�塢2-����ƶ���3-����㣩*/;
	long	m_CarrierId/*ʵ�壨ĸ����������Id*/;
	long	m_ControlObjId/*����ƶ���Id*/;
	bool m_Landing/*�������Ƿ�ֱ����½��0-��1-�ǣ�Ĭ��Ϊ0*/;
	GeoPt	m_Location/*���������ܵ���ʼ/����λ��*/;
	double m_RunWayHead/*�ܵ���������Ϊ0�ȣ�˳ʱ�룬0-360deg*/;
	long m_LandingRouteType/*������½���߷�ʽ��0-�������룻1���к������룻2���Һ������룻3��ԭ·���أ�*/;
	//}}HDOSE_ATTRIBUTE

};

#endif
