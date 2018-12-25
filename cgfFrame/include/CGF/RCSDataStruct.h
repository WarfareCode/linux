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

#define MAX_RCSVALUE_NUM 512	// 一项RCSData中 的最大RCS值数量

// RCS值的结构体定义
struct RCSValue
{
	long	m_PolarizationMatrixType/*极化矩阵类型, 1 水平-垂直极化Horizontal_Vertical_OrthogonalPair、2 右旋-左旋圆极化RHC_LHC_OrthogonalPair*/;
	double	m_PolarizationMatrix[4]/*不同极化组合方式下对应的倍率值（比如：水平/垂直极化发射，水平/垂直极化接收的组合,4个值）*/;
	double	m_Rho/*Rho值(单位度)*/;
	double	m_Theta/*Theta值(单位度)*/;
	double	m_Value/*RCS数值(单位m^2)*/;
	long	m_extra1/*附加参数1*/;
	long	m_extra2/*附加参数1*/;
	double	m_extra3/*附加参数3,*/;
	double	m_extra4/*附加参数3,*/;
	// Rho和Theta表示波束从哪个方向照射到目标上!

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

	//重载=
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

//RCS数据结构定义
class HYCGF_API CRCSDataStruct /*RCS数据结构*/
{
public:
	CRCSDataStruct();
	~CRCSDataStruct();
public:
	double	m_MinFreq/*最小频率(单位GHz)*/;
	double	m_MaxFreq/*最大频率(单位GHz)*/;
	long	m_Mode/*数据模式(1单个常量、2一组数值)*/;
	long	m_Swerling/*Swerling类型(0～4),-1表示无效*/;
	long	m_RhoAxis/*Determines the axis from which  is measured.,(RhoFromZ/RhoFromX), -1表示无效,m_Mode为2时才有效*/;
	long	m_interpolationMode/*前后两个角度之间的RCS值的插值模式(1常数(各1/2划分)、2线性变化、…, -1表示无效, m_Mode为2时才有效)*/;
	long	m_RhoNum/*Rho个数, m_Mode为2时才有效*/;
	long	m_ThetaNum/*Theta个数, m_Mode为2时才有效*/;
	long	m_RCSNum/*RCS个数,默认为0*/;
	RCSValue m_RCS[MAX_RCSVALUE_NUM]/*RCS的数值*/;
	long	m_extra1/*附加参数*/;
	double	m_extra2/*附加参数*/;

	//重载=
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

// 只要是用到CRCSDataStructList时，用完之后请务必调用ReleaseRCSDataStructList(CRCSDataStructList* list)函数释放相关内存
typedef List<DWORD,DWORD> CRCSDataStructList;

// 删除链表中所new的RCSDataStruct*项，只要是用到CRCSDataStructList时，用完之后请务必调用ReleaseRCSDataStructList(CRCSDataStructList* list)函数释放相关内存
HYCGF_API void ReleaseRCSDataStructList(CRCSDataStructList* list);

// RCSData链表与字符串间的转换
//---------------------------------------------------------------------------------------------------------
//数据模式m_Mode为1时的字符串格式为：
//"最小频率,最大频率,数据模式,Swerling类型,RCSNum,极化矩阵类型_[0]-[1]-[2]-[3]_RCS值,附加参数1,附加参数2;
//下一组数据;...;"
//---------------------------------------------------------------------------------------------------------
//数据模式m_Mode为2时的字符串格式为：
//"最小频率,最大频率,数据模式,Swerling类型,m_RhoAxis,m_interpolationMode,m_RhoNum,m_ThetaNum,m_RCSNum,
//极化矩阵类型_[0]-[1]-[2]-[3]_m_Rho_m_Theta_RCS值/极化矩阵类型_[0]-[1]-[2]-[3]_m_Rho_m_Theta_RCS值/另一组RCS/,附加参数1,附加参数2;
//下一组数据;...;"
//---------------------------------------------------------------------------------------------------------
HYCGF_API void RCSDataStr2RCSDataList(CRCSDataStructList& destList,String sourceStr);
HYCGF_API String RCSDataList2RCSDataStr(CRCSDataStructList& sourceList);
// 查找与某个频率对应的RCSData项
HYCGF_API CRCSDataStruct LookupRCSDataByFreq(String rcsStr,double freq);

//////////////////////////////////////////////////////////////////////////

#endif
