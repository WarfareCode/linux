//LaunchVehicleData.h: interface for the CLaunchVehicleData module.
//!!HDOSE_CLASS(CLaunchVehicleData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_LaunchVehicleData_H)
#define AFX_LaunchVehicleData_H


//{{HDOSE_CLS_DES(CLaunchVehicleData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CLaunchVehicleData /*发射车参数*/
{
public:
	CLaunchVehicleData();
	~CLaunchVehicleData();
public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchVehicleData)
	long	m_LaunchVehicleNo/*发射车编号*/;
	long	m_LaunchVehicleState/*发射车状态（0可用、1未准备好、2故障）*/;
	long	m_MissileCount/*导弹数量*/;
	long	m_AntiShipMissileType/*导弹类型*/;
	double	m_TimeInterval/*发射时间间隔*/;
	double	m_MinRange/*最小射程*/;
	double	m_MaxRange/*最大射程*/;
	double	m_KillProb/*单发杀伤概率*/;
	long	m_Type1/*类型1，远中近程(1-近、2-中、3-远)*/;
	long	m_Type2/*类型2，高空低空(1-低、2-中、3-高)*/;
	double	m_MinAltitude/*最小高度,m*/;
	double	m_MaxAltitude/*最大高度,m*/;
	double	m_KillRadius/*杀伤半径,m*/;
	long	m_WarheadType/*弹头类型,1-常规、2-核*/;
	//}}HDOSE_ATTRIBUTE

	CLaunchVehicleData& operator=(CLaunchVehicleData val)
	{
		m_LaunchVehicleNo = val.m_LaunchVehicleNo	/*发射车（架）编号*/;
		m_LaunchVehicleState = val.m_LaunchVehicleState	/*发射车（架）状态（0可用、1未准备好、2故障）*/;
		m_MissileCount = val.m_MissileCount	/*反舰导弹数量*/;
		m_AntiShipMissileType = val.m_AntiShipMissileType	/*反舰导弹类型*/;
		m_TimeInterval = val.m_TimeInterval	/*发射时间间隔*/;
		m_MinRange = val.m_MinRange	/*最小射程,m*/;
		m_MaxRange = val.m_MaxRange	/*最大射程,m*/;
		m_KillProb = val.m_KillProb	/*发杀伤概率*/;
		m_Type1 = val.m_Type1	/*类型1，远中近程*/;
		m_Type2 = val.m_Type2	/*类型2，高空低空*/;
		m_MinAltitude = val.m_MinAltitude	/*最小高度,m*/;
		m_MaxAltitude = val.m_MaxAltitude	/*最大高度,m*/;
		m_KillRadius = val.m_KillRadius	/*杀伤半径,m*/;
		m_WarheadType = val.m_WarheadType	/*弹头类型,常规/核*/;

		return *this;
	}
};
typedef List<DWORD,DWORD> CLaunchVehicleDataList;
void ReleaseLaunchVehicleDataList(CLaunchVehicleDataList* list);

#endif
