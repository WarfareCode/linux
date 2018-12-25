//RCSDataStruct.h: interface for the CRCSDataStruct module.
//!!HDOSE_CLASS(CRCSDataStruct,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_RCSDataStruct_H)
#define AFX_RCSDataStruct_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CRCSDataStruct)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

#define MAX_RCSVALUE_NUM 512	// һ��RCSData�� �����RCSֵ����

// RCSֵ�Ľṹ�嶨��
struct RCSValue
{
	long	m_PolarizationMatrixType/*������������, 1 ˮƽ-��ֱ����Horizontal_Vertical_OrthogonalPair��2 ����-����Բ����RHC_LHC_OrthogonalPair*/;
	double	m_PolarizationMatrix[4]/*��ͬ������Ϸ�ʽ�¶�Ӧ�ı���ֵ�����磺ˮƽ/��ֱ�������䣬ˮƽ/��ֱ�������յ����,4��ֵ��*/;
	double	m_Rho/*Rhoֵ(��λ��)*/;
	double	m_Theta/*Thetaֵ(��λ��)*/;
	double	m_Value/*RCS��ֵ(��λm^2)*/;
	long	m_extra1/*���Ӳ���1*/;
	long	m_extra2/*���Ӳ���1*/;
	double	m_extra3/*���Ӳ���3,*/;
	double	m_extra4/*���Ӳ���3,*/;
	// Rho��Theta��ʾ�������ĸ��������䵽Ŀ����!

	RCSValue()
	{
		m_PolarizationMatrixType=0;
		for(int i=0;i<4;i++)
			m_PolarizationMatrix[i]=0.0;
		m_Rho=0.0;
		m_Theta=0.0;
		m_Value=0.0;
		m_extra1=0;
		m_extra2=0;
		m_extra3=0.0;
		m_extra4=0.0;
	}

	//����=
	RCSValue operator = (RCSValue val)
	{
		m_PolarizationMatrixType = val.m_PolarizationMatrixType;
		for(int i=0;i<4;i++)
			m_PolarizationMatrix[i] = val.m_PolarizationMatrix[i];
		m_Rho = val.m_Rho;
		m_Theta = val.m_Theta;
		m_Value = val.m_Value;
		m_extra1 = val.m_extra1;
		m_extra2 = val.m_extra2;
		m_extra3 = val.m_extra3;
		m_extra4 = val.m_extra4;

		return *this;
	}
};

//RCS���ݽṹ����
class HYCGF_API CRCSDataStruct /*RCS���ݽṹ*/
{
public:
	CRCSDataStruct();
	~CRCSDataStruct();
public:
	double	m_MinFreq/*��СƵ��(��λGHz)*/;
	double	m_MaxFreq/*���Ƶ��(��λGHz)*/;
	long	m_Mode/*����ģʽ(1����������2һ����ֵ)*/;
	long	m_Swerling/*Swerling����(0��4),-1��ʾ��Ч*/;
	long	m_RhoAxis/*Determines the axis from which  is measured.,(RhoFromZ/RhoFromX), -1��ʾ��Ч,m_ModeΪ2ʱ����Ч*/;
	long	m_interpolationMode/*ǰ�������Ƕ�֮���RCSֵ�Ĳ�ֵģʽ(1����(��1/2����)��2���Ա仯����, -1��ʾ��Ч, m_ModeΪ2ʱ����Ч)*/;
	long	m_RhoNum/*Rho����, m_ModeΪ2ʱ����Ч*/;
	long	m_ThetaNum/*Theta����, m_ModeΪ2ʱ����Ч*/;
	long	m_RCSNum/*RCS����,Ĭ��Ϊ0*/;
	RCSValue m_RCS[MAX_RCSVALUE_NUM]/*RCS����ֵ*/;
	long	m_extra1/*���Ӳ���*/;
	double	m_extra2/*���Ӳ���*/;

	//����=
	CRCSDataStruct operator = (CRCSDataStruct val)
	{
		m_MinFreq = val.m_MinFreq;
		m_MaxFreq = val.m_MaxFreq;
		m_Mode = val.m_Mode;
		m_Swerling = val.m_Swerling;
		m_RhoAxis = val.m_RhoAxis;
		m_interpolationMode = val.m_interpolationMode;
		m_RhoNum = val.m_RhoNum;
		m_ThetaNum = val.m_ThetaNum;
		m_RCSNum = val.m_RCSNum;
		for(int i=0;i<MAX_RCSVALUE_NUM;i++)
			m_RCS[i] = val.m_RCS[i];
		m_extra1 = val.m_extra1;
		m_extra2 = val.m_extra2;

		return *this;
	}
};

// ֻҪ���õ�CRCSDataStructListʱ������֮������ص���ReleaseRCSDataStructList(CRCSDataStructList* list)�����ͷ�����ڴ�
typedef List<DWORD,DWORD> CRCSDataStructList;

// ɾ����������new��RCSDataStruct*�ֻҪ���õ�CRCSDataStructListʱ������֮������ص���ReleaseRCSDataStructList(CRCSDataStructList* list)�����ͷ�����ڴ�
HYCGF_API void ReleaseRCSDataStructList(CRCSDataStructList* list);

// RCSData�������ַ������ת��
//---------------------------------------------------------------------------------------------------------
//����ģʽm_ModeΪ1ʱ���ַ�����ʽΪ��
//"��СƵ��,���Ƶ��,����ģʽ,Swerling����,RCSNum,������������_[0]-[1]-[2]-[3]_RCSֵ,���Ӳ���1,���Ӳ���2;
//��һ������;...;"
//---------------------------------------------------------------------------------------------------------
//����ģʽm_ModeΪ2ʱ���ַ�����ʽΪ��
//"��СƵ��,���Ƶ��,����ģʽ,Swerling����,m_RhoAxis,m_interpolationMode,m_RhoNum,m_ThetaNum,m_RCSNum,
//������������_[0]-[1]-[2]-[3]_m_Rho_m_Theta_RCSֵ/������������_[0]-[1]-[2]-[3]_m_Rho_m_Theta_RCSֵ/��һ��RCS/,���Ӳ���1,���Ӳ���2;
//��һ������;...;"
//---------------------------------------------------------------------------------------------------------
HYCGF_API void RCSDataStr2RCSDataList(CRCSDataStructList& destList,String sourceStr);
HYCGF_API String RCSDataList2RCSDataStr(CRCSDataStructList& sourceList);
// ������ĳ��Ƶ�ʶ�Ӧ��RCSData��
HYCGF_API CRCSDataStruct LookupRCSDataByFreq(String rcsStr,double freq);

//////////////////////////////////////////////////////////////////////////

#endif
