//AAMSeekerBindingInfo.h: interface for the CAAMSeekerBindingInfo module.
//!!HDOSE_CLASS(CAAMSeekerBindingInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMSeekerBindingInfo_H)
#define AFX_AAMSeekerBindingInfo_H

#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CAAMSeekerBindingInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMSeekerBindingInfo /*���յ�������ͷװ������*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAAMSeekerBindingInfo();
	virtual ~CAAMSeekerBindingInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetSeekerOnDist(double val){m_SeekerOnDist=val;}
	double	GetSeekerOnDist(){return m_SeekerOnDist;}
	void	SetMissileCreateTime(double val){m_MissileCreateTime=val;}
	double	GetMissileCreateTime(){return m_MissileCreateTime;}
	void	SetTargetAzimuth(CAzimuth3D val){m_TargetAzimuth=val;}
	CAzimuth3D	GetTargetAzimuth(){return m_TargetAzimuth;}

	//{{HDOSE_MEMBER_FUNCTION(CAAMSeekerBindingInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAAMSeekerBindingInfo)
	long	m_TargetNo/*Ŀ����*/;
	double	m_SeekerOnDist/*����ͷ�������루�������ӳ�ʱ�䣩*/;
	double	m_MissileCreateTime/*���յ�������ʱ�䣨����ʱ�䣩*/;
	CAzimuth3D	m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
