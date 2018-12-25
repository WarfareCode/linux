//ASMSeekerBindingInfo.h: interface for the CASMSeekerBindingInfo module.
//!!HDOSE_CLASS(CASMSeekerBindingInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMSeekerBindingInfo_H)
#define AFX_ASMSeekerBindingInfo_H


//{{HDOSE_CLS_DES(CASMSeekerBindingInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMSeekerBindingInfo /*反舰导弹导引头装订参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CASMSeekerBindingInfo();
	virtual ~CASMSeekerBindingInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetSearchStratege(long val){m_SearchStratege=val;}
	long	GetSearchStratege(){return m_SearchStratege;}
	void	SetRadarSearchChart(double val[14]){
		for(int i=0;i<14;i++)
			m_RadarSearchChart[i]=val[i];
	}
	double*	GetRadarSearchChart(){return m_RadarSearchChart;}

	//{{HDOSE_MEMBER_FUNCTION(CASMSeekerBindingInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMSeekerBindingInfo)
	long	m_TargetNo/*目标编号*/;
	long	m_SearchStratege/*搜捕策略（0，1，2，3，4）*/;
	double	m_RadarSearchChart[14]/*雷达搜索图（包含14个参数的数组，要修改）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
