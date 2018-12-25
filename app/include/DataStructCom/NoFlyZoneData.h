//NoFlyZoneData.h: interface for the CNoFlyZoneData module.
//!!HDOSE_CLASS(CNoFlyZoneData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_NoFlyZoneData_H)
#define AFX_NoFlyZoneData_H

//{{HDOSE_CLS_DES(CNoFlyZoneData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CNoFlyZoneData /*禁飞区数据*/
{
public:
	CNoFlyZoneData();
	~CNoFlyZoneData();
public:
	
	//{{HDOSE_ATTRIBUTE(CNoFlyZoneData)
	GeoPt	m_PointSets[10]/*禁飞区点集*/;
	long	m_PointCount/*该禁飞区点的数量*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CNoFlyZoneDataList;
void ReleaseNoFlyZoneDataList(CNoFlyZoneDataList* list);

#endif
