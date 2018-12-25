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

class DATASTRUCTCOMPONENTDLL_API CASMPlaningInfo /*���������滯��Ϣ*/ : public CLink 
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
	bool	m_bValid/*�Ƿ����(0���У�1���У�*/;
	GeoPt	m_Route[256]/*��·��256��������飩*/;
	double	m_TotalFlyTime/*�ܷ���ʱ��*/;
	double	m_RadarSearchChart[14]/*�״�����ͼ��14�����������飩*/;
	long	m_FieldNo/*��ر��*/;
	long	m_LaunchVehicleNo/*���䳵���*/;
	long	m_RoutePointCount/*��·�����*/;

	// 20160219����
	double	m_totalDist;/*�ܺ���*/
	int		m_ASMType;/*������������*/
	int		m_ASMTrajType;/*����������������(ָYJ12��YJ91�ȳ����ٵ����ĵ������ͣ�1�͡�2�ߵͻ�ϡ�3��)*/
	char m_uuid[MAX_CHARLEN];// ����Ψһ��ʶ

	// 20160923
	bool	m_update;// �÷��䵥Ԫ�������ŵĺ�·�Ƿ������¼�����һ��
	//}}HDOSE_ATTRIBUTE
};

#endif
