//Route.h: interface for the CRoute module.
//!!HDOSE_CLASS(CRoute,CControlObject)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_Route_H)
#define AFX_Route_H

#include "ControlObject.h"

//{{HDOSE_CLS_DES(CRoute)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CRoute /*Route*/ : public CControlObject 
{
	DECLARE_CREATE;
public:
	CRoute();
	virtual ~CRoute();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();

	virtual	void tick(double lasttime);

	void	SetPointCount(long val){m_PointCount=val;}
	long	GetPointCount(){return m_PointCount;}
	void	SetPointsArray(char* ptStr)
	{
		this->SetValueString("PointsArray",ptStr);
	}
	void	SetPointsArray(GeoPtList& ptList)
	{
		String ptStr = GeoPtList2GeoPtStr(ptList);
		this->SetValueString("PointsArray",ptStr.GetBuffer(ptStr.GetLength()));
	}
	void	GetPointsArray(GeoPtList& ptList)
	{
		GeoPtStr2GeoPtList(ptList, m_PointsArray);
	}
	char* GetPointsArray(){return GetValueString("PointsArray");}

	//{{HDOSE_MEMBER_FUNCTION(CRoute)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CRoute)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CRoute)
	long	m_PointCount/*点数量,最大64个*/;
	char*	m_PointsArray/*点列位置数组*/;
	//}}HDOSE_ATTRIBUTE

	String tempPoint;	// 临时记录点
};

#endif
