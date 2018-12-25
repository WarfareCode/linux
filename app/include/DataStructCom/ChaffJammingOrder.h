//ChaffJammingOrder.h: interface for the CChaffJammingOrder module.
//!!HDOSE_CLASS(CChaffJammingOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChaffJammingOrder_H)
#define AFX_ChaffJammingOrder_H


//{{HDOSE_CLS_DES(CChaffJammingOrder)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffJammingOrder /*��������ָ��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CChaffJammingOrder();
	virtual ~CChaffJammingOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetSurfaceNo(long val){m_SurfaceNo=val;}
	long	GetSurfaceNo(){return m_SurfaceNo;}
	void	SetChaffLauncherDirection(double val){m_ChaffLauncherDirection=val;}
	double	GetChaffLauncherDirection(){return m_ChaffLauncherDirection;}
	void	SetChaffCount(long val){m_ChaffCount=val;}
	long	GetChaffCount(){return m_ChaffCount;}
	void	SetChaffJammingType(long val){m_ChaffJammingType=val;}
	long	GetChaffJammingType(){return m_ChaffJammingType;}

	//{{HDOSE_MEMBER_FUNCTION(CChaffJammingOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CChaffJammingOrder)
	long	m_SurfaceNo/*��ͧ���*/;
	double	m_ChaffLauncherDirection/*�������䷽�򣨽Ƕȣ�����Ϊ0��0-360��*/;
	long	m_ChaffCount/*�����������÷���*/;
	long	m_ChaffJammingType/*���������ŷ�ʽ��0���ģ�1�嵯��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
