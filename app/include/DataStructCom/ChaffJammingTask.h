//ChaffJammingTask.h: interface for the CChaffJammingTask module.
//!!HDOSE_CLASS(CChaffJammingTask,CTask)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ChaffJammingTask_H)
#define AFX_ChaffJammingTask_H


//{{HDOSE_CLS_DES(CChaffJammingTask)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CChaffJammingTask /*箔条干扰任务*/ : public CTask 
{
	DECLARE_CREATE;
public:
	CChaffJammingTask();
	virtual ~CChaffJammingTask();
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
	void	SetForceType(long val){m_ForceType=val;}
	long	GetForceType(){return m_ForceType;}

	//{{HDOSE_MEMBER_FUNCTION(CChaffJammingTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CChaffJammingTask)
	long	m_SurfaceNo/*舰艇编号*/;
	double	m_ChaffLauncherDirection/*箔条发射方向（角度，正北为0，0-360）*/;
	long	m_ChaffCount/*发射数量（该方向）*/;
	long	m_ChaffJammingType/*箔条弹干扰方式（0质心，1冲弹）*/;
	long	m_ForceType/*红蓝方标识（0蓝，1红）*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
