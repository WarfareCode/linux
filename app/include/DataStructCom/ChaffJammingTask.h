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

class DATASTRUCTCOMPONENTDLL_API CChaffJammingTask /*������������*/ : public CTask 
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
	long	m_SurfaceNo/*��ͧ���*/;
	double	m_ChaffLauncherDirection/*�������䷽�򣨽Ƕȣ�����Ϊ0��0-360��*/;
	long	m_ChaffCount/*�����������÷���*/;
	long	m_ChaffJammingType/*���������ŷ�ʽ��0���ģ�1�嵯��*/;
	long	m_ForceType/*��������ʶ��0����1�죩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
