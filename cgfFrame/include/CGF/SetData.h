//SetData.h: interface for the CSetData module.
//!!HDOSE_CLASS(CSetData,CConsoleEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SetData_H)
#define AFX_SetData_H

#include "ConsoleEvt.h"

//{{HDOSE_CLS_DES(CSetData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSetData /*设置数据*/ : public CConsoleEvt 
{
	DECLARE_CREATE;
public:
	CSetData();
	virtual ~CSetData();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetRequestId(long val){m_RequestId=val;}
	long	GetRequestId(){return m_RequestId;}
	void	SetObjId(long val){m_ObjId=val;}
	long	GetObjId(){return m_ObjId;}
	void	SetDataName(char* val){SetValueString("DataName",val);}
	char*	GetDataName(){return GetValueString("DataName");}
	void	SetDataValue(char* val){SetValueString("DataValue",val);}
	char*	GetDataValue(){return GetValueString("DataValue");}

	//{{HDOSE_MEMBER_FUNCTION(CSetData)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSetData)
	long	m_RequestId/*参数1*/;
	long	m_ObjId/*被设置对象的Id*/;
	char*	m_DataName/*数据名称*/;
	char*	m_DataValue/*数据值*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
