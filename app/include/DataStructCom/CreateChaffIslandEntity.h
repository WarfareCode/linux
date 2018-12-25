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

class DATASTRUCTCOMPONENTDLL_API CCreateChaffIslandEntity /*创建岛岸实体*/ : public CCreateForceEntityEvt 
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
	long	m_PointsCount/*点数量（作为固定点散射点时，不填）*/;
	char*	m_PointsArray/*各点的位置，每个点由“纬度，经度，高度“组成，点间用分号隔开，以分号结束*/;
	double	m_Area/*岛岸的面积*/;
	double	m_ChaffIslandRCS/*岛岸的RCS大小（作为固定散射点时，必填）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
