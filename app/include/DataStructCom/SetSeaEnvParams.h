//SetSeaEnvParams.h: interface for the CSetSeaEnvParams module.
//!!HDOSE_CLASS(CSetSeaEnvParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SetSeaEnvParams_H)
#define AFX_SetSeaEnvParams_H


//{{HDOSE_CLS_DES(CSetSeaEnvParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSetSeaEnvParams /*���ú��󻷾�����*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSetSeaEnvParams();
	virtual ~CSetSeaEnvParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetWindVelocity(double val){m_WindVelocity=val;}
	double	GetWindVelocity(){return m_WindVelocity;}
	void	SetWindCourse(double val){m_WindCourse=val;}
	double	GetWindCourse(){return m_WindCourse;}
	void	SetSeaState(long val){m_SeaState=val;}
	long	GetSeaState(){return m_SeaState;}

	//{{HDOSE_MEMBER_FUNCTION(CSetSeaEnvParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSetSeaEnvParams)
	double	m_WindVelocity/*���٣�m/s��*/;
	double	m_WindCourse/*����0-360�ȣ�*/;
	long	m_SeaState/*��������0-8��*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
