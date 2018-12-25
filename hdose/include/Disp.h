#pragma once
#include "Node.h"

class HDOSE_API CDisp :
	public CNode
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CDisp(void);
	virtual ~CDisp(void);
	virtual void OnSetParameter(char *name,char *value);
	CClasInfoList  m_TruthModels;
	CClasInfoList  m_SensorModels;
	CClasInfoList  m_BehaveModels;
	CClasInfoList  m_SimulationModels;
	CClasInfoList  m_OutputModels;
	CClasInfoList  m_UpdateModels;

	CScnMgr *m_pScnMgr;
protected:
	DWORD m_counter;//计数器
	DWORD m_autUpdate;//自动更新，如果为零，由模型显示调用Update更新；如果不为零，模型调用失效，由引擎自动按设定的采样率更新

	void ParseModels(CClasInfoList *pClsList,char *value);
	void tick_exe(CClasInfoList *pClsList,double lasttime);

public:
	virtual void Output();
	virtual void Simulation(double time);
	virtual void tick(double lasttime=0);
	virtual void UpdateObjs(double lasttime);
};
