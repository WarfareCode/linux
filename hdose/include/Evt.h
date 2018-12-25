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
	int m_eventid;//事件ID，如果是带模板事件，该值无意义，否则用以标识事件类型
	int m_scope;//事件调度时的传播范围，0表示实体内，1表示成员内，2表示联邦内，默认为1
	int m_sourceid;//事件发送ID
	int m_desobjid;//事件目的地ID
	String m_desclsname;//事件目的类名
public:
	double m_time;//事件调度时间，如果成员范围内发送事件，该值无意义
	char* m_buffer;//事件参数缓冲区，如果是模板事件，该值无意义
	EvtOverCbFun m_fun;//指向事件结束后的回调函数，用于异步调用完成时进行一个资源清理或完成通知


};

#endif // !defined(AFX_EVT_H__FB7F666A_305F_42DA_A472_2596B057F760__INCLUDED_)
