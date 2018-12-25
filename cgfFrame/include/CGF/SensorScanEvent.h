//SensorScanEvent.h: interface for the CSensorScanEvent module.
//!!HDOSE_CLASS(CSensorScanEvent,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SensorScanEvent_H)
#define AFX_SensorScanEvent_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CSensorScanEvent)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSensorScanEvent /*传感器扫描事件*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSensorScanEvent();
	virtual ~CSensorScanEvent();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetDataUpdate(long val){m_DataUpdate=val;}
	long	GetDataUpdate(){return m_DataUpdate;}
	void	SetPowerOn(bool val){m_PowerOn=val;}
	bool	GetPowerOn(){return m_PowerOn;}
	void	SetEntityID(long val){m_EntityID=val;}
	long	GetEntityID(){return m_EntityID;}
	void	SetSensorID(long val){m_SensorID=val;}
	long	GetSensorID(){return m_SensorID;}
	void	SetRelativePos(Vec3 val){m_RelativePos=val;}
	Vec3	GetRelativePos(){return m_RelativePos;}
	void	SetScanGraphType(long val){m_ScanGraphType=val;}
	long	GetScanGraphType(){return m_ScanGraphType;}
	void	SetAngle(double val){m_Angle=val;}
	double	GetAngle(){return m_Angle;}
	void	SetHeading(double val){m_Heading=val;}
	double	GetHeading(){return m_Heading;}
	void	SetPitch(double val){m_Pitch=val;}
	double	GetPitch(){return m_Pitch;}
	void	SetEffectiveDist(double val){m_EffectiveDist=val;}
	double	GetEffectiveDist(){return m_EffectiveDist;}
	void	SetSrcEntExId(long val){m_SrcEntExId=val;}
	long	GetSrcEntExId(){return m_SrcEntExId;}

	//{{HDOSE_MEMBER_FUNCTION(CSensorScanEvent)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSensorScanEvent)
	long	m_DataUpdate/*扫描数据更新（0不更新、1更新）*/;
	bool	m_PowerOn/*扫描状态（false关闭、true开启）*/;
	long	m_EntityID/*所属实体ID*/;
	long	m_SensorID/*传感器自身ID*/;
	Vec3	m_RelativePos/*相对位置（相对于实体所在位置的偏移）*/;
	long	m_ScanGraphType/*扫描形状（1锥体、2圆柱、3球体...）*/;
	double	m_Angle/*圆锥体顶部夹角(度)*/;
	double	m_Heading/*水平指向（度，正北为0，沿顺时针方向为正，0-360度）*/;
	double	m_Pitch/*垂直指向（度，与当地水平面平行为0度，向下为负，向上为正）*/;
	double	m_EffectiveDist/*有效作用距离(m)*/;
	long	m_SrcEntExId/*所属实体扩展Id*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
