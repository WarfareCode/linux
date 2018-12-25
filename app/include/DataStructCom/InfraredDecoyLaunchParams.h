//InfraredDecoyLaunchParams.h: interface for the CInfraredDecoyLaunchParams module.
//!!HDOSE_CLASS(CInfraredDecoyLaunchParams,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_InfraredDecoyLaunchParams_H)
#define AFX_InfraredDecoyLaunchParams_H


//{{HDOSE_CLS_DES(CInfraredDecoyLaunchParams)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CInfraredDecoyLaunchParams /*�����ն��������*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CInfraredDecoyLaunchParams();
	virtual ~CInfraredDecoyLaunchParams();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetLaunchAz(double val){m_LaunchAz=val;}
	double	GetLaunchAz(){return m_LaunchAz;}
	void	SetLaunchEl(double val){m_LaunchEl=val;}
	double	GetLaunchEl(){return m_LaunchEl;}
	void	SetLaunchPltType(long val){m_LaunchPltType=val;}
	long	GetLaunchPltType(){return m_LaunchPltType;}
	void	SetUnitNumber(long val){m_UnitNumber=val;}
	long	GetUnitNumber(){return m_UnitNumber;}
	void	SetExpanTime(double val){m_ExpanTime=val;}
	double	GetExpanTime(){return m_ExpanTime;}
	void	SetLaunchVel(double val){m_LaunchVel=val;}
	double	GetLaunchVel(){return m_LaunchVel;}

	//{{HDOSE_MEMBER_FUNCTION(CInfraredDecoyLaunchParams)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CInfraredDecoyLaunchParams)
	double	m_LaunchAz/*���䷽λ��*/;
	double	m_LaunchEl/*����ߵͽ�*/;
	long	m_LaunchPltType/*����ƽ̨����*/;
	long	m_UnitNumber/*���ⵯ��Ԫ���*/;
	double	m_ExpanTime/*չ��ʱ��*/;
	double	m_LaunchVel/*������ٶ�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
