//SensorData.h: interface for the CSensorData module.
//!!HDOSE_CLASS(CSensorData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SensorData_H)
#define AFX_SensorData_H


#include "WXCTime.h"
#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CSensorData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSensorData /*̽����Ϣ���ݽṹ*/
{
public:
	CSensorData();
	~CSensorData();
public:
	
	//{{HDOSE_ATTRIBUTE(CSensorData)
	long	m_TargetNo/*Ŀ����*/;
	long	m_Type/*��𣨵�0����1������2������3��*/;
	long	m_Country/*���ҵ�����0�С���1��̨2��*/;
	long	m_PlatformCategory/*ƽ̨���ʣ�0���С�1ˮ�桢2ˮ�¡�3������*/;
	long	m_Kind/*Ŀ�����ԣ�0���𽢡�1���յ�����2������أ���������3Ԥ������4����������5������6ָ������7���ǡ�8Ǳͧ��ˮ�£���9���ף�ˮ�£���10�߻�����11�߻���ը����12��ը����13��Ǳֱ������14�״���ء�15����ͧ��16��������17��Դ�ն�����ˮ�棩��18���˻���19������20���Ӹ��Ż�����.��29���ƶ���30���󻷾�ʵ��)*/;
	long	m_SideNo/*��/�Ϻţ�0��1��2...��*/;
	GeoPt	m_TargetPosition/*Ŀ��λ��*/;
	double	m_TargetVelocity/*Ŀ�꺽��*/;
	double	m_TargetCourse/*Ŀ�꺽��*/;
	double m_TargetPitch/*Ŀ�꺽�����*/;
	double	m_SpeedPrecision/*���پ���*/;
	double	m_CoursePrecision/*���򾫶�*/;
	double	m_DataCredibility/*���ݿ��Ŷ�*/;
	CWXCTime	m_UpdateTime/*����ʱ��*/;
	long	m_InfoSource/*��Դ��Ԥ����0������1������2��*/;
	char	m_TargetName[128]/*Ŀ������*/;
	
	//20161109��չ
	long	m_TargetAttributeType/*�������ͣ�0��ͧ��1���յ�����2������ء�3�ɻ���4����������5������6ָ������7���ǡ�����11ѹ�Ƹ��ţ�*/;
	DtEntityType m_TargetType; // Ŀ��������ͣ�20160627
	double	m_TargetDistance/*Ŀ�����m*/;
	CAzimuth3D	m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
	long	m_TargetExId;// ��չId��
	int	m_Side; // Ŀ���������


	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CSensorDataList;
void ReleaseSensorDataList(CSensorDataList* list);

#endif
