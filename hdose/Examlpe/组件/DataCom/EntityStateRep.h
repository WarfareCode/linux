//EntityStateRep.h: interface for the CNodeStateRep module.
//!!HDOSE_CLASS(CNodeStateRep,CSimObjStateRep)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_EntityStateRep_H)
#define AFX_EntityStateRep_H

#include "SimObjStateRep.h"
#include "LatLonH.h"

//{{HDOSE_CLS_DES(CNodeStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CNodeStateRep /*ʵ��״̬��*/ : public CSimObjStateRep 
{
	DECLARE_CREATE;
public:
	CNodeStateRep();
	virtual ~CNodeStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetPos(CLatLonH val){m_Pos=val;}
	CLatLonH	GetPos(){return m_Pos;}
	void	SetVel(double val){m_Vel=val;}
	double	GetVel(){return m_Vel;}
	void	SetHead(double val){m_Head=val;}
	double	GetHead(){return m_Head;}
	void	SetPitch(double val){m_Pitch=val;}
	double	GetPitch(){return m_Pitch;}
	void	SetRoll(double val){m_Roll=val;}
	double	GetRoll(){return m_Roll;}
	void	SetType(short val){m_Type=val;}
	short	GetType(){return m_Type;}
	void	SetKind(short val){m_Kind=val;}
	short	GetKind(){return m_Kind;}
	void	SetCountry(short val){m_Country=val;}
	short	GetCountry(){return m_Country;}
	void	SetCategory(short val){m_Category=val;}
	short	GetCategory(){return m_Category;}
	void	SetSubCategory(short val){m_SubCategory=val;}
	short	GetSubCategory(){return m_SubCategory;}
	void	SetSpecific(short val){m_Specific=val;}
	short	GetSpecific(){return m_Specific;}
	void	Setextra(short val){m_extra=val;}
	short	Getextra(){return m_extra;}
	void	SetRealRCS(double val){m_RealRCS=val;}
	double	GetRealRCS(){return m_RealRCS;}
	void	SetRealNoise(double val){m_RealNoise=val;}
	double	GetRealNoise(){return m_RealNoise;}
	double	GetInitRCS(){return m_InitRCS;}
	double	GetInitNoise(){return m_InitNoise;}

	//{{HDOSE_MEMBER_FUNCTION(CNodeStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CNodeStateRep)
	double	m_InitRCS/*��ʼRCS*/;
	double	m_InitNoise/*��ʼ����ֵ*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CNodeStateRep)
	CLatLonH	m_Pos/*λ��*/;
	double	m_Vel/*�ٶ�*/;
	double	m_Head/*����*/;
	double	m_Pitch/*����*/;
	double	m_Roll/*��ת*/;
	short	m_Type/*��������ʶ*/;
	short	m_Kind/*ƽ̨����*/;
	short	m_Country/*����*/;
	short	m_Category/*����*/;
	short	m_SubCategory/*����*/;
	short	m_Specific/*�������*/;
	short	m_extra/*����*/;
	double	m_RealRCS/*ʵʱRCS*/;
	double	m_RealNoise/*ʵʱ����ֵ*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
