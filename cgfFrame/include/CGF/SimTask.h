//SimTask.h: interface for the CSimTask module.
//!!HDOSE_CLASS(CSimTask,CLink)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SimTask_H)
#define AFX_SimTask_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CSimTask)
/*
Author:		
Version:	1.0
Descript:	��Ҫ���ܣ����붨�ű��ж�ȡ�������ݣ���������������ͺ�ִ��ʱ�䣬����������͸���ص�ִ���ߡ�
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSimTask /*����ʵ��������Ϣ*/ : public CLink 
{
	DECLARE_CREATE;
public:
	CSimTask();
	virtual ~CSimTask();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual void OnSetParameter(char *name,char *value);
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	void	SetExecutant(char* val){SetValueString("Executant",val);}
	char*	GetExecutant(){return GetValueString("Executant");}
	void	SetTaskName(char* val){SetValueString("TaskName",val);}
	char*	GetTaskName(){return GetValueString("TaskName");}
	void	SetTaskType(char* val){SetValueString("TaskType",val);}
	char*	GetTaskType(){return GetValueString("TaskType");}
	void	SetStartTime(long val){m_StartTime=val;}
	long	GetStartTime(){return m_StartTime;}
	void	SetCtrlObjName(char* val){SetValueString("CtrlObjName",val);}
	char*	GetCtrlObjName(){return GetValueString("CtrlObjName");}
	void	SetTargetAssignType(long val){m_TargetAssignType=val;}
	long	GetTargetAssignType(){return m_TargetAssignType;}
	void	SetTargetObjectName(char* val){SetValueString("TargetObjectNamee",val);}
	char*	GetTargetObjectName(){return GetValueString("TargetObjectName");}
	void	SetTargetPosition(GeoPt val){m_TargetPosition=val;}
	GeoPt	GetTargetPosition(){return m_TargetPosition;}

	void	SetDeviceName(char* val){SetValueString("DeviceName",val);}
	char*	GetDeviceName(){return GetValueString("DeviceName");}

	void SetSensorOperType(long val){m_SensorOperType = val;}
	long	GetSensorOperType(){return m_SensorOperType;}
	void SetPowerOn(long val){m_PowerOn = val;}
	long	GetPowerOn(){return m_PowerOn;}
	//{{HDOSE_MEMBER_FUNCTION(CSimTask)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSimTask)
	char*	m_Executant/*ִ����,ʵ������*/;
	char*	m_TaskName/*��������*/;
	char*	m_TaskType/*��������(MoveToPoint, MoveAlongRoute, PatrolAlongRoute, PatrolInZone,LaunchMissile)*/;
	long	m_StartTime/*����ʼʱ��*/;

	char*	m_CtrlObjName/*���ƶ�������*/;

	long	m_TargetAssignType/*Ŀ�������ʽ: 1���ơ�2λ��*/;
	char*	m_TargetObjectName/*���乥��Ŀ������ʱ�����еĲ���,Ŀ��ʵ������*/;
	GeoPt	m_TargetPosition/*���乥���̶�������ʱ�����еĲ���,�빥��Ŀ�����ƶ�ѡһ,Ŀ���λ��*/;

	char* m_DeviceName;// ģ���豸����
	long	m_SensorOperType;// ��������������
	long	m_PowerOn; // ���ػ���0�ػ���1������	

	//////////////////////////////
	// ���ػ��ز���
	struct DtReturnBase
	{
		long	m_LandingDesLocType/*����Ŀ�ĵ����ͣ�0-Ĭ�ϳ�ʼλ�á�1-ʵ�塢2-����ƶ���3-����㣩*/;
		long	m_CarrierId/*ʵ�壨ĸ����������Id*/;
		long	m_ControlObjId/*����ƶ���Id*/;
		bool m_Landing/*�������Ƿ�ֱ����½��0-��1-�ǣ�Ĭ��Ϊ0*/;
		GeoPt	m_Location/*���������ܵ���ʼ/����λ��*/;
		double m_RunWayHead/*�ܵ���������Ϊ0�ȣ�˳ʱ�룬0-360deg*/;
		long m_LandingRouteType/*������½���߷�ʽ��0-�������룻1���к������룻2���Һ������룻3��ԭ·���أ�*/;
		DtReturnBase()
		{
			m_LandingDesLocType=0;
			m_CarrierId=0;
			m_ControlObjId=0;
			m_Landing = 0;
			m_RunWayHead=0;
			m_LandingRouteType = 0;
		}
	};
	DtReturnBase RetBasePrams; // ���ػ��ز���
	//////////////////////////////

	//}}HDOSE_ATTRIBUTE
};

#endif
