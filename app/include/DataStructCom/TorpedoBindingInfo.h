//TorpedoBindingInfo.h: interface for the CTorpedoBindingInfo module.
//!!HDOSE_CLASS(CTorpedoBindingInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TorpedoBindingInfo_H)
#define AFX_TorpedoBindingInfo_H


//{{HDOSE_CLS_DES(CTorpedoBindingInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTorpedoBindingInfo /*鱼雷装订信息*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTorpedoBindingInfo();
	virtual ~CTorpedoBindingInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetCreateTime(double val){m_CreateTime=val;}
	double	GetCreateTime(){return m_CreateTime;}
	void	SetUnitNumber(long val){m_UnitNumber=val;}
	long	GetUnitNumber(){return m_UnitNumber;}

	//{{HDOSE_MEMBER_FUNCTION(CTorpedoBindingInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTorpedoBindingInfo)
	long	m_TargetNo/*目标编号*/;
	double	m_CreateTime/*鱼雷创建时间*/;
	long	m_UnitNumber/*鱼雷单元编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
