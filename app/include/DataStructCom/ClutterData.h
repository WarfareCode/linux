//ClutterData.h: interface for the CClutterData module.
//!!HDOSE_CLASS(CClutterData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ClutterData_H)
#define AFX_ClutterData_H

#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CClutterData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CClutterData /*杂波干扰数据*/
{
public:
	CClutterData();
	~CClutterData();
public:
	
	//{{HDOSE_ATTRIBUTE(CClutterData)
	CAzimuth3D	m_SuppressingJamingAzimuth/*压制干扰方位*/;
	double	m_Distance/*距离km*/;
	long	m_JammingWaveform/*干扰波形，属性类型为压制干扰时，该项才填写（0压制波形，1杂乱脉冲）*/;
	double	m_JammingPower/*干扰功率，属性类型为压制干扰时，该项才填写*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CClutterDataList;
void ReleaseClutterDataList(CClutterDataList* list);

#endif
