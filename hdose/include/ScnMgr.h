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
	///double m_time;����CEvt�Ѷ���
	WORD cmd;
	String subjectName;//����//������
	int id;//objid//�¼�ID������Ǵ�ģ���¼�����ֵ�����壬�������Ա�ʶ�¼�����
	String p1;//ObjName//m_scope�¼�����ʱ�Ĵ�����Χ��0��ʾʵ���ڣ�1��ʾ��Ա�ڣ�2��ʾ�����ڣ�Ĭ��Ϊ1
	String p2;//RecFile//attname//paraname//m_sourceid�¼�����ID
	String p3;//opd//attntype//paravalue//m_desobjid;//�¼�Ŀ�ĵ�ID
	String p4;//ParentName//attvalue//m_desclsname;//�¼�Ŀ������
	String p5;//data;//m_buffer�¼������������������ģ���¼�����ֵ������
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
	virtual void PlayToRun();//�ط�̬�л�������̬
	virtual void PlayCtl(double startTime=0,DWORD rate=1);//��ʵ�ֿ����쵹
	virtual void SkipTo(char* PlyFileName,double time);

public:

	DWORD m_SimNumTimes;//�ܷ������
	DWORD m_iSim;//��ǰ�����

	//��¼�ط�״̬�����
	//DWORD m_RecPlayMode;//��¼�ط�״̬�������Ѷ���
	DWORD m_RemoteObjRec;//Զ�̶����Ƿ��¼
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

	double m_startTime;///��������ʱHLA���ƽ�����ʱ��
	double m_ScnStartTime;//������ʼ�����ʱ�䣬�п��ܲ�Ϊ0��ȡ���ڳ����ļ��ĵ�һ��ʱ���

	double m_ScnTime;//������ǰ���߼�ʱ�䣬Ҳ������ģ�͵�ʱ��
	double m_FedTime;//����ʱ��
	double m_ScnGxTime;//����������Ա�ƽ��Ĺ���ʱ��
	/////m_startTime+m_ScnGxTime=m_FedTime
	/////m_ScnStartTime+m_ScnGxTime=m_ScnTime

	double m_NextScnTime;//��һ�μƻ������¼���ִ��ʱ��
	double m_preTime;//���γ�����ʼ�����һ��ʱ��

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
