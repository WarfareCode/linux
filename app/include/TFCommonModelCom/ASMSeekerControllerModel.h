//ASMSeekerControllerModel.h: interface for the CASMSeekerControllerModel module.
//!!HDOSE_CLASS(CASMSeekerControllerModel,CSeekerControllerModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMSeekerControllerModel_H)
#define AFX_ASMSeekerControllerModel_H

#include "SeekerControllerModel.h"

//{{HDOSE_CLS_DES(CASMSeekerControllerModel)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class TFCOMMONMODELCOM_API CASMSeekerControllerModel /*反舰导弹导引头控制器*/ : public CSeekerControllerModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CASMSeekerControllerModel();
	virtual ~CASMSeekerControllerModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetSeekerDistSearchNear(double val){m_SeekerDistSearchNear=val;}
	double	GetSeekerDistSearchNear(){return m_SeekerDistSearchNear;}
	void	SetSeekerDistSearchFar(double val){m_SeekerDistSearchFar=val;}
	double	GetSeekerDistSearchFar(){return m_SeekerDistSearchFar;}
	void	SetSeekerAngleSearchLeft(double val){m_SeekerAngleSearchLeft=val;}
	double	GetSeekerAngleSearchLeft(){return m_SeekerAngleSearchLeft;}
	void	SetSeekerAngleSearchRight(double val){m_SeekerAngleSearchRight=val;}
	double	GetSeekerAngleSearchRight(){return m_SeekerAngleSearchRight;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}

	//{{HDOSE_MEMBER_FUNCTION(CASMSeekerControllerModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CASMSeekerControllerModel)
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CASMSeekerControllerModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CASMSeekerControllerModel)
	double	m_SeekerDistSearchNear/*导引头距离搜索近端*/;
	double	m_SeekerDistSearchFar/*导引头距离搜索远端*/;
	double	m_SeekerAngleSearchLeft/*导引头角度搜索左极限*/;
	double	m_SeekerAngleSearchRight/*导引头角度搜索右极限*/;
	long	m_TargetNo/*目标编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
