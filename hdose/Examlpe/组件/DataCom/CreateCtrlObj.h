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

class DATACOM_API CCreateCtrlObj /*�������ƶ���*/ : public CEvt 
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
	char*	m_CtrlObjClassName/*���ƶ�������*/;
	char*	m_strName/*����*/;
	long	m_SimObjId/*����Id*/;
	long	m_LinePointsCount/*���ϵ������*/;
	CLatLonH	m_LinePoints[10]/*���ϸ��㣨10��Ԫ�����飩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
