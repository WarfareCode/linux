//SurfaceESR.h: interface for the CSurfaceESR module.
//!!HDOSE_CLASS(CSurfaceESR,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SurfaceESR_H)
#define AFX_SurfaceESR_H

#include "StateRepository.h"

//{{HDOSE_CLS_DES(CSurfaceESR)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSurfaceESR /*ˮ��ʵ��״̬��*/ : public CStateRepository
{
	DECLARE_CREATE;
public:
	CSurfaceESR();
	virtual ~CSurfaceESR();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	double	GetLength(){return m_Length;}
	double	GetWidth(){return m_Width;}
	double	GetHeight(){return m_Height;}
	double	GetMaxVel(){return m_MaxVel;}
	double	GetCruiseVel(){return m_CruiseVel;}

	//{{HDOSE_MEMBER_FUNCTION(CSurfaceESR)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSurfaceESR)
	double	m_Length/*��ͧ���ȣ�m��*/;
	double	m_Width/*��ͧ��ȣ�m��*/;
	double	m_Height/*��ͧ�߶ȣ�m��*/;
	double	m_MaxVel/*����ٶ�(��)*/;
	double	m_CruiseVel/*Ѳ���ٶ�(��)*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSurfaceESR)
	//}}HDOSE_ATTRIBUTE
};

#endif
