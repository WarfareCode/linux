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

class DATASTRUCTCOMPONENTDLL_API CCreateForceEntityEvt /*��������ʵ��*/ : public CEvt 
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
	char*	m_EntityName/*ʵ������*/;
	char*	m_EntityClassName/*ʵ�����������ƣ���*/;
	long	m_UnitNumber/*��λ���*/;
	GeoPt	m_Position/*ʵ��λ��*/;
	long	m_Type/*���0�С�1�ҡ�2������3������*/;
	long	m_Country/*����/����(0�С���1��̨2)*/;
	long	m_Kind/*Ŀ�����ԣ�0������1������2������ء�3�ɻ���*/;
	long	m_SideNo/*��/�Ϻţ�0��1��2...��*/;
	long	m_State/*���״̬*/;
	long	m_PlatformCategory/*ƽ̨���ʣ�0���С�1ˮ�桢2ˮ�¡�3������*/;
	double	m_Course/*����*/;
	double	m_Velocity/*�ٶ�*/;
	double	m_Pitch/*������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
