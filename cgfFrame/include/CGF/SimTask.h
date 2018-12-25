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
Descript:	主要功能：从想定脚本中读取任务数据，并根据任务的类型和执行时间，将相关任务发送给相关的执行者。
*/
//}}HDOSE_CLS_DES

class HYCGF_API CSimTask /*仿真实体任务信息*/ : public CLink 
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
	char*	m_Executant/*执行者,实体名称*/;
	char*	m_TaskName/*任务名称*/;
	char*	m_TaskType/*任务类型(MoveToPoint, MoveAlongRoute, PatrolAlongRoute, PatrolInZone,LaunchMissile)*/;
	long	m_StartTime/*任务开始时间*/;

	char*	m_CtrlObjName/*控制对象名称*/;

	long	m_TargetAssignType/*目标给定方式: 1名称、2位置*/;
	char*	m_TargetObjectName/*发射攻击目标任务时所特有的参数,目标实体名称*/;
	GeoPt	m_TargetPosition/*发射攻击固定点任务时所特有的参数,与攻击目标名称二选一,目标的位置*/;

	char* m_DeviceName;// 模型设备名称
	long	m_SensorOperType;// 传感器操作类型
	long	m_PowerOn; // 开关机（0关机、1开机）	

	//////////////////////////////
	// 返回基地参数
	struct DtReturnBase
	{
		long	m_LandingDesLocType/*降落目的地类型（0-默认初始位置、1-实体、2-点控制对象、3-任意点）*/;
		long	m_CarrierId/*实体（母舰、机场）Id*/;
		long	m_ControlObjId/*点控制对象Id*/;
		bool m_Landing/*返航后是否直接着陆，0-否、1-是，默认为0*/;
		GeoPt	m_Location/*机场或降落跑道起始/中心位置*/;
		double m_RunWayHead/*跑道航向，正北为0度，顺时针，0-360deg*/;
		long m_LandingRouteType/*进场着陆航线方式，0-左航线切入；1；中航线切入；2：右航线切入；3：原路返回；*/;
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
	DtReturnBase RetBasePrams; // 返回基地参数
	//////////////////////////////

	//}}HDOSE_ATTRIBUTE
};

#endif
