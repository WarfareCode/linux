//OrbitData.h: interface for the COrbitData module.
//!!HDOSE_CLASS(COrbitData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_OrbitData_H)
#define AFX_OrbitData_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(COrbitData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API COrbitData /*轨道参数*/
{
public:
	COrbitData();
	~COrbitData();
public:
	
	//{{HDOSE_ATTRIBUTE(COrbitData)
	double	m_h/*角动量AngularMomentum(Km^2/s)*/;
	double	m_a/*半长轴(Km)*/;
	double	m_e/*偏心率(0圆,0-1椭圆,>1双曲线)*/;
	double	m_Incl/*轨道倾角,弹道平面与赤道面的夹角(度)*/;
	double	m_RA/*升交点赤经(度)*/;
	double	m_w/*近地点中心角(Argument of perigee)(度)*/;
	double	m_TA/*真近点角(True Anomaly)(度)*/;
	double	m_EA/*偏近点角,Eccentric Anomaly(度)*/;
	double	m_Tp/*过近地点的时刻*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> COrbitDataList;
void ReleaseOrbitDataList(COrbitDataList* list);

#endif
