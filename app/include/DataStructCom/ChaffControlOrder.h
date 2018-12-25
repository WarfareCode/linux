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
Descript:	多个箔条弹的控制指令
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffControlOrder /*箔条弹控制指令*/ : public CEvt 
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
	double	m_ChaffLauncherDirection/*箔条发射方向（角度，正北为0，-180～180）*/;
	long	m_ChaffCount/*箔条弹数量（该方向）*/;
	long	m_ChaffJammingType/*箔条弹干扰方式（0质心，1冲弹）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
