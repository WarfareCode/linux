//MoveAlongRouteEvt.h: interface for the CMoveAlongRouteEvt module.
//!!HDOSE_CLASS(CMoveAlongRouteEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveAlongRouteEvt_H)
#define AFX_MoveAlongRouteEvt_H



//{{HDOSE_CLS_DES(CMoveAlongRouteEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveAlongRouteEvt /*按指定路线运动事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CMoveAlongRouteEvt();
	virtual ~CMoveAlongRouteEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetAssigendRoute(GeoPt val[10]){
		for(int i=0;i<10;i++)
			m_AssigendRoute[i]=val[i];
	}
	GeoPt*	GetAssigendRoute(){return m_AssigendRoute;}
	void	SetRoutePointCount(long val){m_RoutePointCount=val;}
	long	GetRoutePointCount(){return m_RoutePointCount;}
	void	SetAssignedSpeed(double val){m_AssignedSpeed=val;}
	double	GetAssignedSpeed(){return m_AssignedSpeed;}

	//{{HDOSE_MEMBER_FUNCTION(CMoveAlongRouteEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveAlongRouteEvt)
	GeoPt	m_AssigendRoute[10]/*10个位置点数据成员的数组， 要修改*/;
	long	m_RoutePointCount/*路线点的个数(最多10个）*/;
	double	m_AssignedSpeed/*速度*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
