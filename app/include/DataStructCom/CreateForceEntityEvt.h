//CreateForceEntityEvt.h: interface for the CCreateForceEntityEvt module.
//!!HDOSE_CLASS(CCreateForceEntityEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_CreateForceEntityEvt_H)
#define AFX_CreateForceEntityEvt_H



//{{HDOSE_CLS_DES(CCreateForceEntityEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CCreateForceEntityEvt /*创建兵力实体*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CCreateForceEntityEvt();
	virtual ~CCreateForceEntityEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	//void	SetEntityName(char* val){strcpy(m_EntityName,val);}
	//char*	GetEntityName(){return m_EntityName;}
	//void	SetEntityClassName(char* val){strcpy(m_EntityClassName,val);}
	//char*	GetEntityClassName(){return m_EntityClassName;}

	void	SetEntityName(char* val){SetValueString("EntityName",val);}
	char*	GetEntityName(){return GetValueString("EntityName");}
	void	SetEntityClassName(char* val){SetValueString("EntityClassName",val);}
	char*	GetEntityClassName(){return GetValueString("EntityClassName");}
	void	SetUnitNumber(long val){m_UnitNumber=val;}
	long	GetUnitNumber(){return m_UnitNumber;}
	void	SetPosition(GeoPt val){m_Position=val;}
	GeoPt	GetPosition(){return m_Position;}
	void	SetType(long val){m_Type=val;}
	long	GetType(){return m_Type;}
	void	SetCountry(long val){m_Country=val;}
	long	GetCountry(){return m_Country;}
	void	SetKind(long val){m_Kind=val;}
	long	GetKind(){return m_Kind;}
	void	SetSideNo(long val){m_SideNo=val;}
	long	GetSideNo(){return m_SideNo;}
	void	SetState(long val){m_State=val;}
	long	GetState(){return m_State;}
	void	SetPlatformCategory(long val){m_PlatformCategory=val;}
	long	GetPlatformCategory(){return m_PlatformCategory;}
	void	SetCourse(double val){m_Course=val;}
	double	GetCourse(){return m_Course;}
	void	SetVelocity(double val){m_Velocity=val;}
	double	GetVelocity(){return m_Velocity;}
	void	SetPitch(double val){m_Pitch=val;}
	double	GetPitch(){return m_Pitch;}
	//{{HDOSE_MEMBER_FUNCTION(CCreateForceEntityEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CCreateForceEntityEvt)
	char*	m_EntityName/*实体名称*/;
	char*	m_EntityClassName/*实体所属类名称（）*/;
	long	m_UnitNumber/*单位编号*/;
	GeoPt	m_Position/*实体位置*/;
	long	m_Type/*类别（0敌、1我、2中立、3不明）*/;
	long	m_Country/*国家/地区(0中、日1、台2)*/;
	long	m_Kind/*目标属性（0舰船、1导弹、2岸导阵地、3飞机）*/;
	long	m_SideNo/*机/舷号（0、1、2...）*/;
	long	m_State/*完好状态*/;
	long	m_PlatformCategory/*平台性质（0空中、1水面、2水下、3岸基）*/;
	double	m_Course/*航向*/;
	double	m_Velocity/*速度*/;
	double	m_Pitch/*俯仰角*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
