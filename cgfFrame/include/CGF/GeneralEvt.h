//GeneralEvt.h: interface for the CGeneralEvt module.
//!!HDOSE_CLASS(CGeneralEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_GeneralEvt_H)
#define AFX_GeneralEvt_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CGeneralEvt)
/*
Author:		
Version:	1.0
Descript:	�����¼���һ�����ԣ����е��¼�����Ҫ�����̳С�
*/
//}}HDOSE_CLS_DES

class CGeneralEvt /*ͨ���¼�(HYCGF)*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CGeneralEvt();
	virtual ~CGeneralEvt();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSenderType(long val){m_SenderType=val;}
	long	GetSenderType(){return m_SenderType;}
	void	SetSenderForceSide(long val){m_SenderForceSide=val;}
	long	GetSenderForceSide(){return m_SenderForceSide;}
	void	SetSenderEntityType(DtEntityType val){m_SenderEntityType=val;}
	DtEntityType	GetSenderEntityType(){return m_SenderEntityType;}
	void	SetSenderExPlatFormType(long val){m_SenderExPlatFormType=val;}
	long	GetSenderExPlatFormType(){return m_SenderExPlatFormType;}
	void	SetSenderEntityID(long val){m_SenderEntityID=val;}
	long	GetSenderEntityID(){return m_SenderEntityID;}
	void	SetSenderModelID(long val){m_SenderModelID=val;}
	long	GetSenderModelID(){return m_SenderModelID;}
	void	SetReceiverType(long val){m_ReceiverType=val;}
	long	GetReceiverType(){return m_ReceiverType;}
	void	SetIsAsgnReceiverEntityType(bool val){m_IsAsgnReceiverEntityType=val;}
	bool	GetIsAsgnReceiverEntityType(){return m_IsAsgnReceiverEntityType;}
	void	SetReceiverEntityType(DtEntityType val){m_ReceiverEntityType=val;}
	DtEntityType	GetReceiverEntityType(){return m_ReceiverEntityType;}
	void	SetReceiverExPlatFormType(long val){m_ReceiverExPlatFormType=val;}
	long	GetReceiverExPlatFormType(){return m_ReceiverExPlatFormType;}
	void	SetIsAsgnReceiverEntity(bool val){m_IsAsgnReceiverEntity=val;}
	bool	GetIsAsgnReceiverEntity(){return m_IsAsgnReceiverEntity;}
	void	SetIsAsgnReceiverModel(bool val){m_IsAsgnReceiverModel=val;}
	bool	GetIsAsgnReceiverModel(){return m_IsAsgnReceiverModel;}
	void	SetReceiverEntityID(long val){m_ReceiverEntityID=val;}
	long	GetReceiverEntityID(){return m_ReceiverEntityID;}
	void	SetReceiverModelID(long val){m_ReceiverModelID=val;}
	long	GetReceiverModelID(){return m_ReceiverModelID;}
	void	SetSimuTime(double val){m_SimuTime=val;}
	double	GetSimuTime(){return m_SimuTime;}
	void	Setextra1(long val){m_extra1=val;}
	long	Getextra1(){return m_extra1;}
	void	Setextra2(long val){m_extra2=val;}
	long	Getextra2(){return m_extra2;}
	void	Setextra3(double val){m_extra3=val;}
	double	Getextra3(){return m_extra3;}
	void	Setextra4(char* val){SetValueString("extra4",val);}
	char*	Getextra4(){return GetValueString("extra4");}

	//{{HDOSE_MEMBER_FUNCTION(CGeneralEvt)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CGeneralEvt)
	long	m_SenderType/*����������(��0ʵ�塢1���桢2�ű���3��¼��)*/;
	long	m_SenderForceSide/*������ʵ��������,��Ӫ��1Red��2Blue��3Other��*/;
	DtEntityType	m_SenderEntityType/*������ʵ������*/;
	long	m_SenderExPlatFormType/*������ʵ������,����ʹ��EntityTypeʱ���û��Զ����ƽ̨����*/;
	long	m_SenderEntityID/*������ʵ��ID,�����ĸ�ʵ���ڵ�ģ�ͷ���,״̬���е�Ψһ�ı��*/;
	long	m_SenderModelID/*������ģ��ID,��ʵ����ĸ�ģ�ͷ���*/;
	long	m_ReceiverType/*����������(��0ʵ�塢1���桢2��¼��)*/;
	bool	m_IsAsgnReceiverEntityType/*������ʵ������,ָ��һ��ʵ�����*/;
	DtEntityType	m_ReceiverEntityType/*������ʵ������,������*/;
	long	m_ReceiverExPlatFormType/*������ʵ������,����ʹ��EntityTypeʱ���û��Զ����ƽ̨����*/;
	bool	m_IsAsgnReceiverEntity/*�Ƿ�ָ���˽���ʵ�壨0��,1�ǣ�*/;
	bool	m_IsAsgnReceiverModel/*�Ƿ�ָ���˽���ģ�ͣ�0��,1�ǣ�*/;
	long	m_ReceiverEntityID/*������ʵ��ID,���ĸ�ʵ���ڵ�ģ�ͽ���,״̬���е�Ψһ�ı��*/;
	long	m_ReceiverModelID/*������ģ��ID,��ʵ����ĸ�ģ�ͽ���*/;
	double	m_SimuTime/*ʱ��*/;
	long	m_extra1/*���Ӳ���1*/;
	long	m_extra2/*���Ӳ���2*/;
	double	m_extra3/*���Ӳ���3*/;
	char*	m_extra4/*���Ӳ���4*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
