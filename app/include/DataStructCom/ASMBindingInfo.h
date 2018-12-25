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

class DATASTRUCTCOMPONENTDLL_API CASMBindingInfo /*��������װ����Ϣ*/ : public CEvt 
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
	long	m_TargetNo/*Ŀ����*/;
	long	m_SearchStratege/*�Ѳ����ԣ�0��1��2��*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*��·�㣨10��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_WayPointsCount/*��·����������10����*/;
	double	m_RadarSearchChart[14]/*�״�����ͼ������14�����������飬Ҫ�޸ģ�*/;
	double	m_ASMCreateTime/*������������ʱ��*/;
	long	m_UnitNumber/*����������Ԫ���*/;
	char		m_DesEntName[MAX_CHARLEN]/*��������������*/; // 20160926

	// 20160222����
	double m_totalDist;		// ��·�ܳ���km
	double m_totalFlyTime;		// �ܷ���ʱ��
	int m_ASMType;	// ����ķ�����������
	int m_ASMTrajType;	// ���������������ͣ�ָYJ12�ĵ�����1-�͡�2-�ߵ͡�3-�ߣ�
	//}}HDOSE_ATTRIBUTE
};

#endif
