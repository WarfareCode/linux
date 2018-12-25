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

class DATASTRUCTCOMPONENTDLL_API CAAMGuideOrder /*���յ����Ƶ�ָ��*/ : public CEvt 
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
	int	m_UnitNumber/*���յ�����Ԫ���*/;
	long	m_GuideMethod/*�Ƶ���ʽ��0��1��2��*/;
	GeoPt	m_TargetPos/*Ŀ��λ�ã����߷��յ�Ŀ���λ�ã�*/;
	CAzimuth3D	m_TargetAzimuth/*Ŀ�귽λ�����߷��յ�Ŀ������ڷ��յ��ķ�λ��*/;
	double	m_TargetDist/*Ŀ������յ����ľ������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
