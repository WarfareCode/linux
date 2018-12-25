//MoveToPointEvt.h: interface for the CMoveToPointEvt module.
//!!HDOSE_CLASS(CMoveToPointEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveToPointEvt_H)
#define AFX_MoveToPointEvt_H



//{{HDOSE_CLS_DES(CMoveToPointEvt)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveToPointEvt /*�˶���ָ�����¼�*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CMoveToPointEvt();
	virtual ~CMoveToPointEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetAssignedPoint(GeoPt val){m_AssignedPoint=val;}
	GeoPt	GetAssignedPoint(){return m_AssignedPoint;}
	void	SetAssignedSpeed(double val){m_AssignedSpeed=val;}
	double	GetAssignedSpeed(){return m_AssignedSpeed;}

	//{{HDOSE_MEMBER_FUNCTION(CMoveToPointEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveToPointEvt)
	GeoPt	m_AssignedPoint/*ָ��λ�õľ�γ��*/;
	double	m_AssignedSpeed/*�ٶȣ�m/s)*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
