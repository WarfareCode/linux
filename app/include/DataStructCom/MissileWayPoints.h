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

class DATASTRUCTCOMPONENTDLL_API CMissileWayPoints /*导弹航路点*/ : public CEvt 
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
	long	m_WaypointsCount/*航路点个数（最多10个）*/;
	DtWayPoint	m_WayPoints[MAX_RP_NUM]/*航路点(10个元素的数组，要修改）*/;

	int		m_ASMTrajType;/*反舰导弹弹道类型(指YJ12、YJ91等超音速导弹的弹道类型：1低、2高低混合、3高)*/
	//}}HDOSE_ATTRIBUTE
};

#endif
