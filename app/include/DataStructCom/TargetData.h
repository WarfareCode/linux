//TargetData.h: interface for the CTargetData module.
//!!HDOSE_CLASS(CTargetData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetData_H)
#define AFX_TargetData_H


#include "Azimuth3D.h"

//{{HDOSE_CLS_DES(CTargetData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTargetData /*Ŀ��ָʾ��Ϣ*/
{
public:
	CTargetData();
	~CTargetData();
public:
	
	//{{HDOSE_ATTRIBUTE(CTargetData)
	long	m_TargetNo/*Ŀ����*/;
	char	m_TargetName[32]/*Ŀ������*/; //����20151027
	long	m_TargetAttributeType/*�������ͣ�0��ͧ��1���յ�����2������ء�3�ɻ���4����������5������6ָ������7���ǡ�����11ѹ�Ƹ��ţ�*/;
	DtEntityType m_TargetType; // Ŀ��������ͣ�20160627
	double	m_TargetDistance/*Ŀ�����m*/;
	GeoPt	m_TargetPosition/*Ŀ��λ��*/;
	CAzimuth3D	m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
	double	m_TargetVelocity/*Ŀ�꺽��m/s*/;
	double	m_TargetCourse/*Ŀ�꺽��*/;
	double m_TargetPitch/*Ŀ�꺽�����*/;
	double	m_TargetRCS/*RCSǿ��*/;
	double	m_TargetEmittance; //Ŀ�����ǿ��
	double  m_EchoPower;//�ز�ǿ��
	double	m_DetectedSeekerPower/*̽�⵽�ĵ���ͷ����*/;
	double	m_SeekerPW/*����ͷ����*/;
	double	m_SeekerPRI/*����ͷ�����ظ�����*/;
	double	m_SeekerHighFREQ/*����ͷ�ź�Ƶ�ʸ߶�*/;
	double	m_SeekerLowFREQ/*����ͷ�ź�Ƶ�ʵͶ�*/;
	long	m_SeekerWaveForm/*����ͷ�źŲ��Σ�0��Ƶ��1�ݱ�Ƶ��2����ѹ��+��Ƶ��3����ѹ��+�ݱ�Ƶ��*/;
	
	long	m_TargetExId;// ��չId�ţ�20160920
	int m_Side;// Ŀ���������
	bool m_isAttacked; // Ŀ���Ƿ����ڱ�����
	int m_attackingWeaponNum; // ���ڹ�����Ŀ�����������
	//}}HDOSE_ATTRIBUTE

	CTargetData& operator=(CTargetData val)
	{
		m_TargetNo = val.m_TargetNo/*Ŀ����*/;
		strcpy(m_TargetName , val.m_TargetName) /*Ŀ������*/; //����20151027
		m_TargetAttributeType = val.m_TargetAttributeType/*�������ͣ�0��ͧ��1���յ�����2������ء�3�ɻ���4����������5������6ָ������7���ǡ�����11ѹ�Ƹ��ţ�*/;
		m_TargetType= val.m_TargetType; // Ŀ��������ͣ�20160627
		m_TargetDistance= val.m_TargetDistance/*Ŀ�����km*/;
		m_TargetPosition= val.m_TargetPosition/*Ŀ��λ��*/;
		m_TargetAzimuth= val.m_TargetAzimuth/*Ŀ�귽λ��������Ϊԭ�㣩*/;
		m_TargetVelocity= val.m_TargetVelocity/*Ŀ�꺽��m/s*/;
		m_TargetCourse= val.m_TargetCourse/*Ŀ�꺽��*/;
		m_TargetPitch = val.m_TargetPitch;
		m_TargetRCS= val.m_TargetRCS/*RCSǿ��*/;
		m_TargetEmittance= val.m_TargetEmittance; //Ŀ�����ǿ��
		m_EchoPower= val.m_EchoPower;//�ز�ǿ��
		m_DetectedSeekerPower= val.m_DetectedSeekerPower/*̽�⵽�ĵ���ͷ����*/;
		m_SeekerPW= val.m_SeekerPW/*����ͷ����*/;
		m_SeekerPRI= val.m_SeekerPRI/*����ͷ�����ظ�����*/;
		m_SeekerHighFREQ= val.m_SeekerHighFREQ/*����ͷ�ź�Ƶ�ʸ߶�*/;
		m_SeekerLowFREQ= val.m_SeekerLowFREQ/*����ͷ�ź�Ƶ�ʵͶ�*/;
		m_SeekerWaveForm= val.m_SeekerWaveForm/*����ͷ�źŲ��Σ�0��Ƶ��1�ݱ�Ƶ��2����ѹ��+��Ƶ��3����ѹ��+�ݱ�Ƶ��*/;
		m_TargetExId = val.m_TargetExId;
		m_Side =  val.m_Side;
		m_isAttacked = val.m_isAttacked; // Ŀ���Ƿ����ڱ�����
		m_attackingWeaponNum = val.m_attackingWeaponNum; // ���ڹ�����Ŀ�����������
		return *this;
	}

	void clear()
	{
		CTargetData nullEle;
		(*this) = nullEle;
	}
};
typedef List<DWORD,DWORD> CTargetDataList;
void ReleaseTargetDataList(CTargetDataList* list);

#endif
