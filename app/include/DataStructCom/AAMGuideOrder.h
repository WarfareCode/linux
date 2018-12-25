//AAMGuideOrder.h: interface for the CAAMGuideOrder module.
//!!HDOSE_CLASS(CAAMGuideOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMGuideOrder_H)
#define AFX_AAMGuideOrder_H


#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CAAMGuideOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMGuideOrder /*防空导弹制导指令*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAAMGuideOrder();
	virtual ~CAAMGuideOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetUnitNumber(int val){m_UnitNumber=val;}
	int	GetUnitNumber(){return m_UnitNumber;}
	void	SetGuideMethod(long val){m_GuideMethod=val;}
	long	GetGuideMethod(){return m_GuideMethod;}
	void	SetTargetPos(GeoPt val){m_TargetPos=val;}
	GeoPt	GetTargetPos(){return m_TargetPos;}
	void	SetTargetAzimuth(CAzimuth3D val){m_TargetAzimuth=val;}
	CAzimuth3D	GetTargetAzimuth(){return m_TargetAzimuth;}
	void	SetTargetDist(double val){m_TargetDist=val;}
	double	GetTargetDist(){return m_TargetDist;}

	//{{HDOSE_MEMBER_FUNCTION(CAAMGuideOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAAMGuideOrder)
	int	m_UnitNumber/*防空导弹单元编号*/;
	long	m_GuideMethod/*制导方式（0、1、2）*/;
	GeoPt	m_TargetPos/*目标位置（告诉防空弹目标的位置）*/;
	CAzimuth3D	m_TargetAzimuth/*目标方位（告诉防空弹目标相对于防空弹的方位）*/;
	double	m_TargetDist/*目标与防空导弹的距离距离*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
