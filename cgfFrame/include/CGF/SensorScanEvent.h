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

class HYCGF_API CSensorScanEvent /*������ɨ���¼�*/ : public CEvt 
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
	long	m_DataUpdate/*ɨ�����ݸ��£�0�����¡�1���£�*/;
	bool	m_PowerOn/*ɨ��״̬��false�رա�true������*/;
	long	m_EntityID/*����ʵ��ID*/;
	long	m_SensorID/*����������ID*/;
	Vec3	m_RelativePos/*���λ�ã������ʵ������λ�õ�ƫ�ƣ�*/;
	long	m_ScanGraphType/*ɨ����״��1׶�塢2Բ����3����...��*/;
	double	m_Angle/*Բ׶�嶥���н�(��)*/;
	double	m_Heading/*ˮƽָ�򣨶ȣ�����Ϊ0����˳ʱ�뷽��Ϊ����0-360�ȣ�*/;
	double	m_Pitch/*��ֱָ�򣨶ȣ��뵱��ˮƽ��ƽ��Ϊ0�ȣ�����Ϊ��������Ϊ����*/;
	double	m_EffectiveDist/*��Ч���þ���(m)*/;
	long	m_SrcEntExId/*����ʵ����չId*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
