//ScoutInfo.h: interface for the CScoutInfo module.
//!!HDOSE_CLASS(CScoutInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ScoutInfo_H)
#define AFX_ScoutInfo_H

#include "SensorData.h"

//{{HDOSE_CLS_DES(CScoutInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CScoutInfo /*侦察信息*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CScoutInfo();
	virtual ~CScoutInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetData(CSensorData val[100]){
		for(int i=0;i<100;i++)
			m_TargetData[i]=val[i];
	}
	CSensorData*	GetTargetData(){return m_TargetData;}
	void	SetTargetDataCount(long val){m_TargetDataCount=val;}
	long	GetTargetDataCount(){return m_TargetDataCount;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}

	//{{HDOSE_MEMBER_FUNCTION(CScoutInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CScoutInfo)
	CSensorData	m_TargetData[100]/*目标数据(100个元素的数组，要修改）*/;
	long	m_TargetDataCount/*目标数据个数（最多100个）*/;
	long	m_ForceType/*红蓝方标识（0蓝，1红）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
