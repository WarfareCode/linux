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

class DATASTRUCTCOMPONENTDLL_API CTargetData /*目标指示信息*/
{
public:
	CTargetData();
	~CTargetData();
public:
	
	//{{HDOSE_ATTRIBUTE(CTargetData)
	long	m_TargetNo/*目标编号*/;
	char	m_TargetName[32]/*目标名称*/; //新增20151027
	long	m_TargetAttributeType/*属性类型（0舰艇、1防空导弹、2岸导阵地、3飞机、4反舰导弹、5箔条、6指挥所、7卫星、…、11压制干扰）*/;
	DtEntityType m_TargetType; // 目标对象类型，20160627
	double	m_TargetDistance/*目标距离m*/;
	GeoPt	m_TargetPosition/*目标位置*/;
	CAzimuth3D	m_TargetAzimuth/*目标方位（以自身为原点）*/;
	double	m_TargetVelocity/*目标航速m/s*/;
	double	m_TargetCourse/*目标航向*/;
	double m_TargetPitch/*目标航迹倾角*/;
	double	m_TargetRCS/*RCS强度*/;
	double	m_TargetEmittance; //目标辐射强度
	double  m_EchoPower;//回波强度
	double	m_DetectedSeekerPower/*探测到的导引头功率*/;
	double	m_SeekerPW/*导引头脉宽*/;
	double	m_SeekerPRI/*导引头脉冲重复周期*/;
	double	m_SeekerHighFREQ/*导引头信号频率高端*/;
	double	m_SeekerLowFREQ/*导引头信号频率低端*/;
	long	m_SeekerWaveForm/*导引头信号波形（0定频、1捷变频、2脉冲压缩+定频、3脉冲压缩+捷变频）*/;
	
	long	m_TargetExId;// 扩展Id号，20160920
	int m_Side;// 目标敌我属性
	bool m_isAttacked; // 目标是否正在被攻击
	int m_attackingWeaponNum; // 用于攻击该目标的武器数量
	//}}HDOSE_ATTRIBUTE

	CTargetData& operator=(CTargetData val)
	{
		m_TargetNo = val.m_TargetNo/*目标编号*/;
		strcpy(m_TargetName , val.m_TargetName) /*目标名称*/; //新增20151027
		m_TargetAttributeType = val.m_TargetAttributeType/*属性类型（0舰艇、1防空导弹、2岸导阵地、3飞机、4反舰导弹、5箔条、6指挥所、7卫星、…、11压制干扰）*/;
		m_TargetType= val.m_TargetType; // 目标对象类型，20160627
		m_TargetDistance= val.m_TargetDistance/*目标距离km*/;
		m_TargetPosition= val.m_TargetPosition/*目标位置*/;
		m_TargetAzimuth= val.m_TargetAzimuth/*目标方位（以自身为原点）*/;
		m_TargetVelocity= val.m_TargetVelocity/*目标航速m/s*/;
		m_TargetCourse= val.m_TargetCourse/*目标航向*/;
		m_TargetPitch = val.m_TargetPitch;
		m_TargetRCS= val.m_TargetRCS/*RCS强度*/;
		m_TargetEmittance= val.m_TargetEmittance; //目标辐射强度
		m_EchoPower= val.m_EchoPower;//回波强度
		m_DetectedSeekerPower= val.m_DetectedSeekerPower/*探测到的导引头功率*/;
		m_SeekerPW= val.m_SeekerPW/*导引头脉宽*/;
		m_SeekerPRI= val.m_SeekerPRI/*导引头脉冲重复周期*/;
		m_SeekerHighFREQ= val.m_SeekerHighFREQ/*导引头信号频率高端*/;
		m_SeekerLowFREQ= val.m_SeekerLowFREQ/*导引头信号频率低端*/;
		m_SeekerWaveForm= val.m_SeekerWaveForm/*导引头信号波形（0定频、1捷变频、2脉冲压缩+定频、3脉冲压缩+捷变频）*/;
		m_TargetExId = val.m_TargetExId;
		m_Side =  val.m_Side;
		m_isAttacked = val.m_isAttacked; // 目标是否正在被攻击
		m_attackingWeaponNum = val.m_attackingWeaponNum; // 用于攻击该目标的武器数量
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
