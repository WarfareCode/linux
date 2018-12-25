//MissileWayPoints.h: interface for the CMissileWayPoints module.
//!!HDOSE_CLASS(CMissileWayPoints,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MissileWayPoints_H)
#define AFX_MissileWayPoints_H



//{{HDOSE_CLS_DES(CMissileWayPoints)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMissileWayPoints /*������·��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CMissileWayPoints();
	virtual ~CMissileWayPoints();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetWaypointsCount(long val){m_WaypointsCount=val;}
	long	GetWaypointsCount(){return m_WaypointsCount;}
	void	SetWayPoints(DtWayPoint val[]){
		for(int i=0;i<MAX_RP_NUM;i++)
			m_WayPoints[i]=val[i];
	}
	DtWayPoint*	GetWayPoints(){return m_WayPoints;}

	//{{HDOSE_MEMBER_FUNCTION(CMissileWayPoints)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMissileWayPoints)
	long	m_WaypointsCount/*��·����������10����*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*��·��(10��Ԫ�ص����飬Ҫ�޸ģ�*/;

	int		m_ASMTrajType;/*����������������(ָYJ12��YJ91�ȳ����ٵ����ĵ������ͣ�1�͡�2�ߵͻ�ϡ�3��)*/
	//}}HDOSE_ATTRIBUTE
};

#endif
