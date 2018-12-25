//LayoutMine.h: interface for the CLayoutMine module.
//!!HDOSE_CLASS(CLayoutMine,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LayoutMine_H)
#define AFX_LayoutMine_H


//{{HDOSE_CLS_DES(CLayoutMine)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES
#include "Task.h"

class HYCGF_API CLayoutMine /*����ˮ��*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CLayoutMine();
	virtual ~CLayoutMine();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetControlObjId(long val){m_ControlObjId=val;}
	long	GetControlObjId(){return m_ControlObjId;}
	void	SetLayMode(long val){m_LayMode=val;}
	long	GetLayMode(){return m_LayMode;}
	void	SetCount(double val){m_Count=val;}
	double	GetCount(){return m_Count;}
	void	SetInterval(double val){m_Interval=val;}
	double	GetInterval(){return m_Interval;}
	void	SetDepth(double val){m_Depth=val;}
	double	GetDepth(){return m_Depth;}
	void	SetValidTime(double val){m_ValidTime=val;}
	double	GetValidTime(){return m_ValidTime;}

	//{{HDOSE_MEMBER_FUNCTION(CLayoutMine)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CLayoutMine)
	long	m_ControlObjId/*���ƶ���Id*/;
	long	m_LayMode/*����ˮ��*/;
	double	m_Count/*����*/;
	double	m_Interval/*�����m��*/;
	double	m_Depth/*���*/;
	double	m_ValidTime/*��Чʱ��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
