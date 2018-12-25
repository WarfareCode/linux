//FuzzySituationInfo.h: interface for the CFuzzySituationInfo module.
//!!HDOSE_CLASS(CFuzzySituationInfo,CLink)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FuzzySituationInfo_H)
#define AFX_FuzzySituationInfo_H

#include "SensorData.h"

#define FUZZYDATA_NUM_MAX 100

//{{HDOSE_CLS_DES(CFuzzySituationInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CFuzzySituationInfo /*综合态势信息*/ : public CLink 
{
	DECLARE_CREATE;
public:
	CFuzzySituationInfo();
	virtual ~CFuzzySituationInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetFuzzyInfo(CSensorData val[]){
		for(int i=0;i<FUZZYDATA_NUM_MAX;i++)
			m_FuzzyInfo[i]=val[i];
	}
	CSensorData*	GetFuzzyInfo(){return m_FuzzyInfo;}
	void	SetFuzzyInfoCount(long val){m_FuzzyInfoCount=val;}
	long	GetFuzzyInfoCount(){return m_FuzzyInfoCount;}
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}
	//{{HDOSE_MEMBER_FUNCTION(CFuzzySituationInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CFuzzySituationInfo)
	CSensorData	m_FuzzyInfo[FUZZYDATA_NUM_MAX]/*融合数据信息（100元素的数组）*/;
	long	m_FuzzyInfoCount/*数据个数（最多100个）*/;
	long	m_ForceType/*红蓝方标识（0蓝，1红）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
