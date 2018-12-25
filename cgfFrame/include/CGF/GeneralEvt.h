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
Descript:	具有事件的一般属性，所有的事件都需要从它继承。
*/
//}}HDOSE_CLS_DES

class CGeneralEvt /*通用事件(HYCGF)*/ : public CEvt 
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
	long	m_SenderType/*发送者类型(如0实体、1界面、2脚本、3记录等)*/;
	long	m_SenderForceSide/*发送者实体所属方,阵营（1Red、2Blue、3Other）*/;
	DtEntityType	m_SenderEntityType/*发送者实体类型*/;
	long	m_SenderExPlatFormType/*发送者实体类型,当不使用EntityType时，用户自定义的平台类型*/;
	long	m_SenderEntityID/*发送者实体ID,是由哪个实体内的模型发的,状态池中的唯一的编号*/;
	long	m_SenderModelID/*发送者模型ID,由实体的哪个模型发的*/;
	long	m_ReceiverType/*接收者类型(如0实体、1界面、2记录等)*/;
	bool	m_IsAsgnReceiverEntityType/*接收者实体类型,指定一类实体接收*/;
	DtEntityType	m_ReceiverEntityType/*接收者实体类型,七类码*/;
	long	m_ReceiverExPlatFormType/*接收者实体类型,当不使用EntityType时，用户自定义的平台类型*/;
	bool	m_IsAsgnReceiverEntity/*是否指定了接收实体（0否,1是）*/;
	bool	m_IsAsgnReceiverModel/*是否指定了接收模型（0否,1是）*/;
	long	m_ReceiverEntityID/*接收者实体ID,由哪个实体内的模型接收,状态池中的唯一的编号*/;
	long	m_ReceiverModelID/*接收者模型ID,由实体的哪个模型接收*/;
	double	m_SimuTime/*时戳*/;
	long	m_extra1/*附加参数1*/;
	long	m_extra2/*附加参数2*/;
	double	m_extra3/*附加参数3*/;
	char*	m_extra4/*附加参数4*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
