//SeekerTrackingTargetInfo.h: interface for the CSeekerTrackingTargetInfo module.
//!!HDOSE_CLASS(CSeekerTrackingTargetInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SeekerTrackingTargetInfo_H)
#define AFX_SeekerTrackingTargetInfo_H

#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CSeekerTrackingTargetInfo)
/*
Author:		
Version:	1.0
Descript:	根据搜捕策略，选定的目标的距离和方位
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerTrackingTargetInfo /*导引头跟踪目标数据*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSeekerTrackingTargetInfo();
	virtual ~CSeekerTrackingTargetInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSelectedTargetDist(double val){m_SelectedTargetDist=val;}
	double	GetSelectedTargetDist(){return m_SelectedTargetDist;}
	void	SetSelectedTargetAzimuth(CAzimuth3D val){m_SelectedTargetAzimuth=val;}
	CAzimuth3D	GetSelectedTargetAzimuth(){return m_SelectedTargetAzimuth;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetRCS(double val){m_RCS=val;}
	double	GetRCS(){return m_RCS;}

	//{{HDOSE_MEMBER_FUNCTION(CSeekerTrackingTargetInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSeekerTrackingTargetInfo)
	double	m_SelectedTargetDist/*选定目标的距离*/;
	CAzimuth3D	m_SelectedTargetAzimuth/*选定目标的方位*/;
	long	m_TargetNo/*目标编号*/;
	double	m_RCS/*目标RCS*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
