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

class DATACOM_API CNodeStateRep /*实体状态池*/ : public CSimObjStateRep 
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
	double	m_InitRCS/*初始RCS*/;
	double	m_InitNoise/*初始噪声值*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CNodeStateRep)
	CLatLonH	m_Pos/*位置*/;
	double	m_Vel/*速度*/;
	double	m_Head/*航向*/;
	double	m_Pitch/*俯仰*/;
	double	m_Roll/*滚转*/;
	short	m_Type/*红蓝方标识*/;
	short	m_Kind/*平台类型*/;
	short	m_Country/*国家*/;
	short	m_Category/*分类*/;
	short	m_SubCategory/*子类*/;
	short	m_Specific/*具体分类*/;
	short	m_extra/*其它*/;
	double	m_RealRCS/*实时RCS*/;
	double	m_RealNoise/*实时噪声值*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
