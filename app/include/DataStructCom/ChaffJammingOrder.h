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

class DATASTRUCTCOMPONENTDLL_API CChaffJammingOrder /*箔条干扰指令*/ : public CEvt 
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
	long	m_SurfaceNo/*舰艇编号*/;
	double	m_ChaffLauncherDirection/*箔条发射方向（角度，正北为0，0-360）*/;
	long	m_ChaffCount/*发射数量（该方向）*/;
	long	m_ChaffJammingType/*箔条弹干扰方式（0质心，1冲弹）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
