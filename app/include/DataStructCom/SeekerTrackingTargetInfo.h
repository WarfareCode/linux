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
Descript:	�����Ѳ����ԣ�ѡ����Ŀ��ľ���ͷ�λ
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSeekerTrackingTargetInfo /*����ͷ����Ŀ������*/ : public CEvt 
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
	double	m_SelectedTargetDist/*ѡ��Ŀ��ľ���*/;
	CAzimuth3D	m_SelectedTargetAzimuth/*ѡ��Ŀ��ķ�λ*/;
	long	m_TargetNo/*Ŀ����*/;
	double	m_RCS/*Ŀ��RCS*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
