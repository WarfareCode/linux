//ChaffControlOrder.h: interface for the CChaffControlOrder module.
//!!HDOSE_CLASS(CChaffControlOrder,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChaffControlOrder_H)
#define AFX_ChaffControlOrder_H


//{{HDOSE_CLS_DES(CChaffControlOrder)
/*
Author:		
Version:	1.0
Descript:	����������Ŀ���ָ��
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffControlOrder /*����������ָ��*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CChaffControlOrder();
	virtual ~CChaffControlOrder();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetChaffLauncherDirection(double val){m_ChaffLauncherDirection=val;}
	double	GetChaffLauncherDirection(){return m_ChaffLauncherDirection;}
	void	SetChaffCount(long val){m_ChaffCount=val;}
	long	GetChaffCount(){return m_ChaffCount;}
	void	SetChaffJammingType(long val){m_ChaffJammingType=val;}
	long	GetChaffJammingType(){return m_ChaffJammingType;}

	//{{HDOSE_MEMBER_FUNCTION(CChaffControlOrder)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CChaffControlOrder)
	double	m_ChaffLauncherDirection/*�������䷽�򣨽Ƕȣ�����Ϊ0��-180��180��*/;
	long	m_ChaffCount/*�������������÷���*/;
	long	m_ChaffJammingType/*���������ŷ�ʽ��0���ģ�1�嵯��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
