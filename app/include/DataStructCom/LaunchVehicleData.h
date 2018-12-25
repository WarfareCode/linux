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

class DATASTRUCTCOMPONENTDLL_API CLaunchVehicleData /*���䳵����*/
{
public:
	CLaunchVehicleData();
	~CLaunchVehicleData();
public:
	
	//{{HDOSE_ATTRIBUTE(CLaunchVehicleData)
	long	m_LaunchVehicleNo/*���䳵���*/;
	long	m_LaunchVehicleState/*���䳵״̬��0���á�1δ׼���á�2���ϣ�*/;
	long	m_MissileCount/*��������*/;
	long	m_AntiShipMissileType/*��������*/;
	double	m_TimeInterval/*����ʱ����*/;
	double	m_MinRange/*��С���*/;
	double	m_MaxRange/*������*/;
	double	m_KillProb/*����ɱ�˸���*/;
	long	m_Type1/*����1��Զ�н���(1-����2-�С�3-Զ)*/;
	long	m_Type2/*����2���߿յͿ�(1-�͡�2-�С�3-��)*/;
	double	m_MinAltitude/*��С�߶�,m*/;
	double	m_MaxAltitude/*���߶�,m*/;
	double	m_KillRadius/*ɱ�˰뾶,m*/;
	long	m_WarheadType/*��ͷ����,1-���桢2-��*/;
	//}}HDOSE_ATTRIBUTE

	CLaunchVehicleData& operator=(CLaunchVehicleData val)
	{
		m_LaunchVehicleNo = val.m_LaunchVehicleNo	/*���䳵���ܣ����*/;
		m_LaunchVehicleState = val.m_LaunchVehicleState	/*���䳵���ܣ�״̬��0���á�1δ׼���á�2���ϣ�*/;
		m_MissileCount = val.m_MissileCount	/*������������*/;
		m_AntiShipMissileType = val.m_AntiShipMissileType	/*������������*/;
		m_TimeInterval = val.m_TimeInterval	/*����ʱ����*/;
		m_MinRange = val.m_MinRange	/*��С���,m*/;
		m_MaxRange = val.m_MaxRange	/*������,m*/;
		m_KillProb = val.m_KillProb	/*��ɱ�˸���*/;
		m_Type1 = val.m_Type1	/*����1��Զ�н���*/;
		m_Type2 = val.m_Type2	/*����2���߿յͿ�*/;
		m_MinAltitude = val.m_MinAltitude	/*��С�߶�,m*/;
		m_MaxAltitude = val.m_MaxAltitude	/*���߶�,m*/;
		m_KillRadius = val.m_KillRadius	/*ɱ�˰뾶,m*/;
		m_WarheadType = val.m_WarheadType	/*��ͷ����,����/��*/;

		return *this;
	}
};
typedef List<DWORD,DWORD> CLaunchVehicleDataList;
void ReleaseLaunchVehicleDataList(CLaunchVehicleDataList* list);

#endif
