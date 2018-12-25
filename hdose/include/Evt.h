// Evt.h: interface for the CEvt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVT_H__FB7F666A_305F_42DA_A472_2596B057F760__INCLUDED_)
#define AFX_EVT_H__FB7F666A_305F_42DA_A472_2596B057F760__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Item.h"
class CEvtMgrImp;

class HDOSE_API CEvt : public CItem  
{
	DECLARE_CREATE
	friend class CEvtMgrImp;

public:
	CEvt();
	virtual ~CEvt();
	static void ClassInit(ClassInfo *clsinfo);
	void SetDest(const char *ClsName=0,const char *ObjName=0);
	String GetDestCls();

	virtual void Send(double time=0);
	virtual void Post(double time=0);
	virtual void SendToMdb();

private:
	virtual void OnReflect(char *Para=0){};
	virtual void tick(double lasttime=0){};
	virtual void Simulation(double lasttime=0){};
	virtual void Output(){};

	virtual void OnCreate(char *Para=0){};
	virtual void OnInit(){};
	virtual void OnClose(){};
	virtual void OnEvent(CEvt *pEvt){};

public:
	int m_eventid;//�¼�ID������Ǵ�ģ���¼�����ֵ�����壬�������Ա�ʶ�¼�����
	int m_scope;//�¼�����ʱ�Ĵ�����Χ��0��ʾʵ���ڣ�1��ʾ��Ա�ڣ�2��ʾ�����ڣ�Ĭ��Ϊ1
	int m_sourceid;//�¼�����ID
	int m_desobjid;//�¼�Ŀ�ĵ�ID
	String m_desclsname;//�¼�Ŀ������
public:
	double m_time;//�¼�����ʱ�䣬�����Ա��Χ�ڷ����¼�����ֵ������
	char* m_buffer;//�¼������������������ģ���¼�����ֵ������
	EvtOverCbFun m_fun;//ָ���¼�������Ļص������������첽�������ʱ����һ����Դ��������֪ͨ


};

#endif // !defined(AFX_EVT_H__FB7F666A_305F_42DA_A472_2596B057F760__INCLUDED_)
