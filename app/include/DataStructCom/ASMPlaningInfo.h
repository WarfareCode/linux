//ASMPlaningInfo.h: interface for the CASMPlaningInfo module.
//!!HDOSE_CLASS(CASMPlaningInfo,CLink)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ASMPlaningInfo_H)
#define AFX_ASMPlaningInfo_H



//{{HDOSE_CLS_DES(CASMPlaningInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CASMPlaningInfo /*反舰导弹规化信息*/ : public CLink 
{
	DECLARE_CREATE;
public:
	CASMPlaningInfo();
	virtual ~CASMPlaningInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetbValid(bool val){m_bValid=val;}
	bool	GetbValid(){return m_bValid;}
	void	SetRoute(GeoPt val[256]){
		for(int i=0;i<256;i++)
			m_Route[i]=val[i];
	}
	GeoPt*	GetRoute(){return m_Route;}
	void	SetRadarSearchChart(double val[14]){
		for(int i=0;i<14;i++)
			m_RadarSearchChart[i]=val[i];
	}
	double*	GetRadarSearchChart(){return m_RadarSearchChart;}
	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetLaunchVehicleNo(long val){m_LaunchVehicleNo=val;}
	long	GetLaunchVehicleNo(){return m_LaunchVehicleNo;}
	void	SetRoutePointCount(long val){m_RoutePointCount=val;}
	long	GetRoutePointCount(){return m_RoutePointCount;}
	void	SetTotalFlyTime(double val){m_TotalFlyTime=val;}
	double	GetTotalFlyTime(){return m_TotalFlyTime;}

	void	SettotalDist(long val){m_totalDist=val;}
	long	GettotalDist(){return m_totalDist;}
	void	SetASMType(long val){m_ASMType=val;}
	long	GetASMType(){return m_ASMType;}
	void	SetASMTrajType(long val){m_ASMTrajType=val;}
	long	GetASMTrajType(){return m_ASMTrajType;}

	//{{HDOSE_MEMBER_FUNCTION(CASMPlaningInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CASMPlaningInfo)
	bool	m_bValid/*是否可行(0不行，1可行）*/;
	GeoPt	m_Route[256]/*航路（256个点的数组）*/;
	double	m_TotalFlyTime/*总飞行时间*/;
	double	m_RadarSearchChart[14]/*雷达搜索图（14个参数，数组）*/;
	long	m_FieldNo/*阵地编号*/;
	long	m_LaunchVehicleNo/*发射车编号*/;
	long	m_RoutePointCount/*航路点个数*/;

	// 20160219新增
	double	m_totalDist;/*总航程*/
	int		m_ASMType;/*反舰导弹类型*/
	int		m_ASMTrajType;/*反舰导弹弹道类型(指YJ12、YJ91等超音速导弹的弹道类型：1低、2高低混合、3高)*/
	char m_uuid[MAX_CHARLEN];// 导弹唯一标识

	// 20160923
	bool	m_update;// 该发射单元、发射编号的航路是否又重新计算了一次
	//}}HDOSE_ATTRIBUTE
};

#endif
