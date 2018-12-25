//ChaffLaunchParams.h: interface for the CChaffLaunchParams module.
//!!HDOSE_CLASS(CChaffLaunchParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChaffLaunchParams_H)
#define AFX_ChaffLaunchParams_H


//{{HDOSE_CLS_DES(CChaffLaunchParams)
/*
Author:		
Version:	1.0
Descript:	一个箔条弹的初始参数
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffLaunchParams /*箔条弹发射参数*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CChaffLaunchParams();
	virtual ~CChaffLaunchParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetChaffLauncherDirection(double val){m_ChaffLauncherDirection=val;}
	double	GetChaffLauncherDirection(){return m_ChaffLauncherDirection;}
	void	SetChaffJammingType(long val){m_ChaffJammingType=val;}
	long	GetChaffJammingType(){return m_ChaffJammingType;}
	void	SetUnitNumber(long val){m_UnitNumber=val;}
	long	GetUnitNumber(){return m_UnitNumber;}
	//{{HDOSE_MEMBER_FUNCTION(CChaffLaunchParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CChaffLaunchParams)
	double	m_ChaffLauncherDirection/*箔条发射方向（角度，正北为0，-180～180）*/;
	long	m_ChaffJammingType/*箔条弹干扰方式（0质心，1冲弹）*/;
	long	m_UnitNumber/*箔条弹单元编号*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
