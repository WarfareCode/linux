//CreateChaffIslandEntity.h: interface for the CCreateChaffIslandEntity module.
//!!HDOSE_CLASS(CCreateChaffIslandEntity,CCreateForceEntityEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateChaffIslandEntity_H)
#define AFX_CreateChaffIslandEntity_H

#include "CreateForceEntityEvt.h"

//{{HDOSE_CLS_DES(CCreateChaffIslandEntity)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateChaffIslandEntity /*��������ʵ��*/ : public CCreateForceEntityEvt 
{
	DECLARE_CREATE;
public:
	CCreateChaffIslandEntity();
	virtual ~CCreateChaffIslandEntity();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetPointsCount(long val){m_PointsCount=val;}
	long	GetPointsCount(){return m_PointsCount;}
	void	SetPointsArray(char* val){SetValueString("PointsArray",val);}
	char*	GetPointsArray(){return GetValueString("PointsArray");}
	void	SetArea(double val){m_Area=val;}
	double	GetArea(){return m_Area;}
	void	SetChaffIslandRCS(double val){m_ChaffIslandRCS=val;}
	double	GetChaffIslandRCS(){return m_ChaffIslandRCS;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateChaffIslandEntity)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateChaffIslandEntity)
	long	m_PointsCount/*����������Ϊ�̶���ɢ���ʱ�����*/;
	char*	m_PointsArray/*�����λ�ã�ÿ�����ɡ�γ�ȣ����ȣ��߶ȡ���ɣ�����÷ֺŸ������ԷֺŽ���*/;
	double	m_Area/*���������*/;
	double	m_ChaffIslandRCS/*������RCS��С����Ϊ�̶�ɢ���ʱ�����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
