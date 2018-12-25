//ASMBindingInfo.h: interface for the CASMBindingInfo module.
//!!HDOSE_CLASS(CASMBindingInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMBindingInfo_H)
#define AFX_ASMBindingInfo_H



//{{HDOSE_CLS_DES(CASMBindingInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMBindingInfo /*反舰导弹装订信息*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CASMBindingInfo();
	virtual ~CASMBindingInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}
	void	SetSearchStratege(long val){m_SearchStratege=val;}
	long	GetSearchStratege(){return m_SearchStratege;}
	void	SetWayPoints(DtWayPoint val[]){
		for(int i=0;i<MAX_RP_NUM;i++)
			m_WayPoints[i]=val[i];
	}
	DtWayPoint*	GetWayPoints(){return m_WayPoints;}
	void	SetWayPointsCount(long val){m_WayPointsCount=val;}
	long	GetWayPointsCount(){return m_WayPointsCount;}
	void	SetRadarSearchChart(double val[14]){
		for(int i=0;i<14;i++)
			m_RadarSearchChart[i]=val[i];
	}
	double*	GetRadarSearchChart(){return m_RadarSearchChart;}
	void	SetASMCreateTime(double val){m_ASMCreateTime=val;}
	double	GetASMCreateTime(){return m_ASMCreateTime;}
	void	SetUnitNumber(long val){m_UnitNumber=val;}
	long	GetUnitNumber(){return m_UnitNumber;}
	void	SetDesEntName(char* val){strcpy(m_DesEntName,val);}
	char*	GetDestEntName(){return m_DesEntName;}
	//{{HDOSE_MEMBER_FUNCTION(CASMBindingInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMBindingInfo)
	long	m_TargetNo/*目标编号*/;
	long	m_SearchStratege/*搜捕策略（0，1，2）*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*航路点（10个元素的数组，要修改）*/;
	long	m_WayPointsCount/*航路点个数（最多10个）*/;
	double	m_RadarSearchChart[14]/*雷达搜索图（包含14个参数的数组，要修改）*/;
	double	m_ASMCreateTime/*反舰导弹创建时间*/;
	long	m_UnitNumber/*反舰导弹单元编号*/;
	char		m_DesEntName[MAX_CHARLEN]/*反舰导弹的名称*/; // 20160926

	// 20160222新增
	double m_totalDist;		// 航路总长度km
	double m_totalFlyTime;		// 总飞行时间
	int m_ASMType;	// 发射的反舰导弹类型
	int m_ASMTrajType;	// 反舰导弹弹道类型（指YJ12的弹道，1-低、2-高低、3-高）
	//}}HDOSE_ATTRIBUTE
};

#endif
