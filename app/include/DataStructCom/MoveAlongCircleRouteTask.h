//MoveAlongCircleRouteTask.h: interface for the CMoveAlongCircleRouteTask module.
//!!HDOSE_CLASS(CMoveAlongCircleRouteTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveAlongCircleRouteTask_H)
#define AFX_MoveAlongCircleRouteTask_H



//{{HDOSE_CLS_DES(CMoveAlongCircleRouteTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveAlongCircleRouteTask /*��ָ��Բ����·�˶�*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CMoveAlongCircleRouteTask();
	virtual ~CMoveAlongCircleRouteTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetCenterPos(GeoPt val){m_CenterPos=val;}
	GeoPt	GetCenterPos(){return m_CenterPos;}
	void	SetRadius(double val){m_Radius=val;}
	double	GetRadius(){return m_Radius;}
	void	SetAssignedSpeed(double val){m_AssignedSpeed=val;}
	double	GetAssignedSpeed(){return m_AssignedSpeed;}
	void	SetbAssignedControlObj(bool val){m_bAssignedControlObj=val;}
	bool	GetbAssignedControlObj(){return m_bAssignedControlObj;}
	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	//void	SetAssignedCircleObjName(char* val){strcpy(m_AssignedCircleObjName,val);}
	//char*	GetAssignedCircleObjName(){return m_AssignedCircleObjName;}

	void	SetAssignedCircleObjName(char* val){SetValueString("AssignedCircleObjName",val);}
	char*	GetAssignedCircleObjName(){return GetValueString("AssignedCircleObjName");}

	//{{HDOSE_MEMBER_FUNCTION(CMoveAlongCircleRouteTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveAlongCircleRouteTask)
	GeoPt	m_CenterPos/*Բ��λ��*/;
	double	m_Radius/*�뾶��m��*/;
	double	m_AssignedSpeed/*�ٶȣ�m/s��*/;
	bool	m_bAssignedControlObj/*�Ƿ�ָ��Բ�ο��ƶ���0��1�ǣ�*/;
	char*	m_AssignedCircleObjName/*ָ��Բ�ο��ƶ�������*/;
	long	m_FieldNo/*��ر�ţ�������ء���ͧ���ɻ�����ս��λ�ı�ţ�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
