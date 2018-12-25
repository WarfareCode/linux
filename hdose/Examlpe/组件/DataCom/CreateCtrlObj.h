//CreateCtrlObj.h: interface for the CCreateCtrlObj module.
//!!HDOSE_CLASS(CCreateCtrlObj,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateCtrlObj_H)
#define AFX_CreateCtrlObj_H

#include "LatLonH.h"

//{{HDOSE_CLS_DES(CCreateCtrlObj)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CCreateCtrlObj /*创建控制对象*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCreateCtrlObj();
	virtual ~CCreateCtrlObj();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetCtrlObjClassName(char* val){SetValueString("CtrlObjClassName",val);}
	char*	GetCtrlObjClassName(){return GetValueString("CtrlObjClassName");}
	void	SetstrName(char* val){SetValueString("strName",val);}
	char*	GetstrName(){return GetValueString("strName");}
	void	SetSimObjId(long val){m_SimObjId=val;}
	long	GetSimObjId(){return m_SimObjId;}
	void	SetLinePointsCount(long val){m_LinePointsCount=val;}
	long	GetLinePointsCount(){return m_LinePointsCount;}
	void	SetLinePoints(CLatLonH val[])
	{
		for(int i=0;i<10;i++)
		m_LinePoints[i]=val[i];
	}
	CLatLonH*	GetLinePoints(){return m_LinePoints;}

	//{{HDOSE_MEMBER_FUNCTION(CCreateCtrlObj)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateCtrlObj)
	char*	m_CtrlObjClassName/*控制对象类名*/;
	char*	m_strName/*名称*/;
	long	m_SimObjId/*对象Id*/;
	long	m_LinePointsCount/*线上点的数量*/;
	CLatLonH	m_LinePoints[10]/*线上各点（10个元素数组）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
