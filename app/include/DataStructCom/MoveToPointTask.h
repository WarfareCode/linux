//MoveToPointTask.h: interface for the CMoveToPointTask module.
//!!HDOSE_CLASS(CMoveToPointTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MoveToPointTask_H)
#define AFX_MoveToPointTask_H



//{{HDOSE_CLS_DES(CMoveToPointTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMoveToPointTask /*�˶���ָ��������*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CMoveToPointTask();
	virtual ~CMoveToPointTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetFieldNo(long val){m_FieldNo=val;}
	long	GetFieldNo(){return m_FieldNo;}
	void	SetAssignedPoint(GeoPt val){m_AssignedPoint=val;}
	GeoPt	GetAssignedPoint(){return m_AssignedPoint;}
	void	SetAssignedSpeed(double val){m_AssignedSpeed=val;}
	double	GetAssignedSpeed(){return m_AssignedSpeed;}
	void	SetbAssignedControlObj(bool val){m_bAssignedControlObj=val;}
	bool	GetbAssignedControlObj(){return m_bAssignedControlObj;}
	//void	SetAssignedPointObjName(char* val){strcpy(m_AssignedPointObjName,val);}
	//char*	GetAssignedPointObjName(){return m_AssignedPointObjName;}

	void	SetAssignedPointObjName(char* val){SetValueString("AssignedPointObjName",val);}
	char*	GetAssignedPointObjName(){return GetValueString("AssignedPointObjName");}

	//{{HDOSE_MEMBER_FUNCTION(CMoveToPointTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CMoveToPointTask)
	long	m_FieldNo/*��ر�ţ�������ء���ͧ���ɻ�����ս��λ�ı�ţ�*/;
	GeoPt	m_AssignedPoint/*ָ��λ��*/;
	double	m_AssignedSpeed/*�ٶȣ�m/s)*/;
	bool	m_bAssignedControlObj/*�Ƿ�ָ������ƶ���0��1�ǣ�*/;
	char*	m_AssignedPointObjName/*ָ���ĵ���ƶ�������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
