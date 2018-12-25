//AAMUnitFireAssignmentData.h: interface for the CAAMUnitFireAssignmentData module.
//!!HDOSE_CLASS(CAAMUnitFireAssignmentData,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_AAMUnitFireAssignmentData_H)
#define AFX_AAMUnitFireAssignmentData_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CAAMUnitFireAssignmentData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CAAMUnitFireAssignmentData /*防空导弹单元火力分配数据*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CAAMUnitFireAssignmentData();
	virtual ~CAAMUnitFireAssignmentData();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetbLaunch(bool val){m_bLaunch=val;}
	bool	GetbLaunch(){return m_bLaunch;}
	void	SetGroupOrSelf(long val){m_GroupOrSelf=val;}
	long	GetGroupOrSelf(){return m_GroupOrSelf;}
	void	SetAAMLauncherNo(long val){m_AAMLauncherNo=val;}
	long	GetAAMLauncherNo(){return m_AAMLauncherNo;}
	void	SetAAMDataNo(long val){m_AAMDataNo=val;}
	long	GetAAMDataNo(){return m_AAMDataNo;}
	void	SetInitTargetInfo(CTargetData val){m_InitTargetInfo=val;}
	CTargetData	GetInitTargetInfo(){return m_InitTargetInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CAAMUnitFireAssignmentData)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CAAMUnitFireAssignmentData)
	long	m_TargetNo/*目标编号*/;
	bool	m_bLaunch/*是否发射（0不发射、1发射）*/;
	// 20160305
	long	m_GroupOrSelf/*指令来源（1本舰或2编队）*/;
	long	m_AAMLauncherNo/*防空导弹发射架编号，默认-1*/;
	long	m_AAMDataNo/*发射架上的防空导弹数据编号（可能有多种类型的舰空弹），默认-1*/;
	// 20160308
	CTargetData	m_InitTargetInfo/*初始目指信息*/;
	// 20160920
	long	m_targetExId;/*扩展Id号*/
	//}}HDOSE_ATTRIBUTE
};

#endif
