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

class HYCGF_API COrbitData /*�������*/
{
public:
	COrbitData();
	~COrbitData();
public:
	
	//{{HDOSE_ATTRIBUTE(COrbitData)
	double	m_h/*�Ƕ���AngularMomentum(Km^2/s)*/;
	double	m_a/*�볤��(Km)*/;
	double	m_e/*ƫ����(0Բ,0-1��Բ,>1˫����)*/;
	double	m_Incl/*������,����ƽ��������ļн�(��)*/;
	double	m_RA/*������ྭ(��)*/;
	double	m_w/*���ص����Ľ�(Argument of perigee)(��)*/;
	double	m_TA/*������(True Anomaly)(��)*/;
	double	m_EA/*ƫ�����,Eccentric Anomaly(��)*/;
	double	m_Tp/*�����ص��ʱ��*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> COrbitDataList;
void ReleaseOrbitDataList(COrbitDataList* list);

#endif
