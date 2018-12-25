//SatelliteESR.h: interface for the CSatelliteESR module.
//!!HDOSE_CLASS(CSatelliteESR,CSpaceESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SatelliteESR_H)
#define AFX_SatelliteESR_H

#include "OrbitData.h"
#include "SpaceESR.h"

//{{HDOSE_CLS_DES(CSatelliteESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSatelliteESR /*����ʵ��״̬��*/ : public CSpaceESR 
{
	DECLARE_CREATE;
public:
	CSatelliteESR();
	virtual ~CSatelliteESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetOrbitInfo(COrbitData val){m_OrbitInfo=val;}
	COrbitData	GetOrbitInfo(){return m_OrbitInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CSatelliteESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSatelliteESR)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSatelliteESR)
	COrbitData	m_OrbitInfo/*�������*/;
		//��ͨ���ű�д��������������','�ָ����������£�	
		//				m_a/*�볤��(Km)*/,
		//				m_e/*ƫ����(0Բ,0-1��Բ,>1˫����)*/,
		//				m_Incl/*������,����ƽ��������ļн�(��)*/,
		//				m_RA/*������ྭ(��)*/,
		//				m_w/*���ص����Ľ�(Argument of perigee)(��)*/,
		//				m_TA/*������(True Anomaly)(��)*/��

	//}}HDOSE_ATTRIBUTE
};

#endif
