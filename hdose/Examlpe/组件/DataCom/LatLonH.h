//LatLonH.h: interface for the CLatLonH module.
//!!HDOSE_CLASS(CLatLonH,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LatLonH_H)
#define AFX_LatLonH_H


//{{HDOSE_CLS_DES(CLatLonH)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CLatLonH /*��γ������*/
{
public:
	CLatLonH();
	~CLatLonH();
public:
	
	//{{HDOSE_ATTRIBUTE(CLatLonH)
	double	m_latitude/*����1*/;
	double	m_longitude/*����2*/;
	double	m_height/*����3*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CLatLonHList;
void ReleaseLatLonHList(CLatLonHList* list);

#endif
