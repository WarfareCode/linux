// Scheduler.h: interface for the CScnMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCHEDULER_H__8EDADC72_20C2_4E9A_85B8_1754994D99CA__INCLUDED_)
#define AFX_SCHEDULER_H__8EDADC72_20C2_4E9A_85B8_1754994D99CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Node.h"
#include "Markup.h"
#include "Evt.h"


class HDOSE_API ScnEvt:public CEvt
{
	DECLARE_CREATE;
	ScnEvt(){};
	virtual ~ScnEvt(){};

public:
	///double m_time;基类CEvt已定义
	WORD cmd;
	String subjectName;//类名//场景名
	int id;//objid//事件ID，如果是带模板事件，该值无意义，否则用以标识事件类型
	String p1;//ObjName//m_scope事件调度时的传播范围，0表示实体内，1表示成员内，2表示联邦内，默认为1
	String p2;//RecFile//attname//paraname//m_sourceid事件发送ID
	String p3;//opd//attntype//paravalue//m_desobjid;//事件目的地ID
	String p4;//ParentName//attvalue//m_desclsname;//事件目的类名
	String p5;//data;//m_buffer事件参数缓冲区，如果是模板事件，该值无意义
};


class CDisp;
class HDOSE_API CScnMgr : public CNode  
{
	friend class CEngineImp;
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
	CScnMgr();
	virtual ~CScnMgr();
	static void ClassInit(ClassInfo *clsinfo);
	virtual void OnSetParameter(char *name,char *value);

protected:
	virtual void OnInit(){};
	virtual void OnClose(){};
	virtual void OnCreate(char *Para=0);
	void OnObjQuit(CEvt *pEvt);
	void CreateAttribParaXml(String& strOut,CMarkup &inputXml);

public:
	virtual void LoadScenario(char* ScnName,char* Var=0,char *SSNFile=0);
	virtual void UnLoadScenario();

	virtual void AddAggregateObj(CObj *pObj);
	virtual void RemoveAggregateObj(CObj *pObj);

	virtual void Output();
	virtual void Simulation(double time);
	virtual void tick(double lasttime=0);
	virtual void TimeAdvanceStep();
	virtual void Fire();

	virtual void Close();
	void SetDisp(CObj *Dispatch);
public:
//////////////////////////
	virtual void StartRecord();
	virtual void PauseRecord();
	virtual void ResumeRecord();
	virtual void StopRecord();
	virtual void PlayToRun();//回放态切换到运行态
	virtual void PlayCtl(double startTime=0,DWORD rate=1);//可实现快进或快倒
	virtual void SkipTo(char* PlyFileName,double time);

public:

	DWORD m_SimNumTimes;//总仿真次数
	DWORD m_iSim;//当前仿真次

	//记录回放状态与参数
	//DWORD m_RecPlayMode;//记录回放状态，基类已定义
	DWORD m_RemoteObjRec;//远程对象是否记录
	DWORD m_RecPause;
	CMarkup m_RecSimXml;

	String m_RecDir;
	double m_Play_StartTime;
	int m_Play_Rate;

	CHMutex m_hmutex_xml;
	double m_preRecTime;
	CDisp *m_pDispatch;//

protected:
	CHEvent m_timeAdv;

public:
	int	m_initScnEvtPos;

	double m_startTime;///场景加载时HLA已推进到的时间
	double m_ScnStartTime;//场景开始计算的时间，有可能不为0，取决于场景文件的第一个时间点

	double m_ScnTime;//场景当前的逻辑时间，也是驱动模型的时间
	double m_FedTime;//联邦时间
	double m_ScnGxTime;//本场景本成员推进的贡献时间
	/////m_startTime+m_ScnGxTime=m_FedTime
	/////m_ScnStartTime+m_ScnGxTime=m_ScnTime

	double m_NextScnTime;//下一次计划场景事件被执行时间
	double m_preTime;//本次场景开始后的上一步时间

protected:
	Array<char*,char*> m_InitScnEvts;
	ScnEvt* CreateScnEvt(double time,WORD cmd);
	double ParseScnXml( char *xmlFile,double startTime=0,char* Var=0);
	void ParseScnXmlObj( CMarkup *xml,char* ParName=0,double time=0);

	void ProcessMdbInputEvt();
	void PlanScnAdvanceTo(double time);

	void OnObjJoinScn(CLink *pItem);

//////////////////////////
	String m_script;
};

#endif // !defined(AFX_SCHEDULER_H__8EDADC72_20C2_4E9A_85B8_1754994D99CA__INCLUDED_)
