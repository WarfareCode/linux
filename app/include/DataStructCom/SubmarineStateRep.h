//SubmarineStateRep.h: interface for the CSubmarineStateRep module.
//!!HDOSE_CLASS(CSubmarineStateRep,CStateRepository)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SubmarineStateRep_H)
#define AFX_SubmarineStateRep_H

#include "LaunchVehicleData.h"

//{{HDOSE_CLS_DES(CSubmarineStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class CSubmarineStateRep /*Ǳͧ״̬��*/ : public CSubSurfaceESR 
{
	DECLARE_CREATE;
public:
	CSubmarineStateRep();
	virtual ~CSubmarineStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetASMCount(long val){m_ASMCount=val;}
	long	GetASMCount(){return m_ASMCount;}
	void	SetTorpedoCount(long val){m_TorpedoCount=val;}
	long	GetTorpedoCount(){return m_TorpedoCount;}
	void	SetLauncherInfo(CLaunchVehicleData val[]){
		for(int i=0;i<4;i++)
			m_LauncherInfo[i]=val[i];
	}
	CLaunchVehicleData*	GetLauncherInfo(){return m_LauncherInfo;}
	void	SetLauncherCount(long val){m_LauncherCount=val;}
	long	GetLauncherCount(){return m_LauncherCount;}
	void	SetTorpedoType(long val){m_TorpedoType=val;}
	long	GetTorpedoType(){return m_TorpedoType;}

	double	GetLength(){return m_Length;}
	double	GetWidth(){return m_Width;}
	double	GetHeight(){return m_Height;}
	double	GetDraft(){return m_Draft;}
	double	GetlfCruiseVel(){return m_lfCruiseVel;}
	float	GetlfMaxAcc(){return m_lfMaxAcc;}
	float	GetlfMaxDecelAcc(){return m_lfMaxDecelAcc;}
	float	GetlfMaxHeight(){return m_lfMaxHeight;}
	float	GetlfMinHeight(){return m_lfMinHeight;}
	float	GetlfCruiseHeight(){return m_lfCruiseHeight;}
	float	GetlfMaxTurnRate(){return m_lfMaxTurnRate;}
	float	GetlfMaxG(){return m_lfMaxG;}

	//{{HDOSE_MEMBER_FUNCTION(CSubmarineStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CSubmarineStateRep)
	double	m_Length/*��*/;
	double	m_Width/*��*/;
	double	m_Height/*��*/;
	double	m_Draft/*��ˮ��*/;
	double	m_lfCruiseVel/*Ѳ���ٶ�*/;
	float	m_lfMaxAcc/*�����ٶ�*/;
	float	m_lfMaxDecelAcc/*��С���ٶ�*/;
	float	m_lfMaxHeight/*���߶ȣ�ǱͧΪ0����ͧΪ0*/;
	float	m_lfMinHeight/*��С�߶ȣ�ǱͧΪ������ͧΪ0*/;
	float	m_lfCruiseHeight/*Ѳ���߶ȣ�ǱͧΪ����0����ͧΪ0*/;
	float	m_lfMaxTurnRate/*���ת������*/;
	float	m_lfMaxG/*����*/;
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CSubmarineStateRep)
	long	m_ASMCount/*������������*/;
	long	m_TorpedoCount/*��������*/;
	CLaunchVehicleData	m_LauncherInfo[4]/*����Ͳ��Ϣ*/;
	long	m_LauncherCount/*����Ͳ����*/;
	long	m_TorpedoType/*��������*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
