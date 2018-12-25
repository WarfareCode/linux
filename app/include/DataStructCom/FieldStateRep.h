//FieldStateRep.h: interface for the CFieldStateRep module.
//!!HDOSE_CLASS(CFieldStateRep,CFacilityESR)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FieldStateRep_H)
#define AFX_FieldStateRep_H

#include "LaunchVehicleData.h"

//{{HDOSE_CLS_DES(CFieldStateRep)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CFieldStateRep /*�������״̬��*/ : public CFacilityESR 
{
	DECLARE_CREATE;
public:
	CFieldStateRep();
	virtual ~CFieldStateRep();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetLaunchVehicleCount(long val){m_LaunchVehicleCount=val;}
	long	GetLaunchVehicleCount(){return m_LaunchVehicleCount;}
	void	SetLaunchVehicleInfo(CLaunchVehicleData val[10]){
		for(int i=0;i<10;i++)
			m_LaunchVehicleInfo[i]=val[i];
	}
	CLaunchVehicleData*	GetLaunchVehicleInfo(){return m_LaunchVehicleInfo;}

	//{{HDOSE_MEMBER_FUNCTION(CFieldStateRep)
	//}}HDOSE_MEMBER_FUNCTION

public:
		
	//{{HDOSE_PARAMETER(CFieldStateRep)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CFieldStateRep)
	long	m_LaunchVehicleCount/*���䳵���������10����*/;
	CLaunchVehicleData	m_LaunchVehicleInfo[10]/*���䳵��Ϣ��10��Ԫ�ص����飩*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
