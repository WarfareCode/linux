//ConsoleEvtConductor.h: interface for the CConsoleEvtConductor module.
//!!HDOSE_CLASS(CConsoleEvtConductor,CModel)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ConsoleEvtConductor_H)
#define AFX_ConsoleEvtConductor_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CConsoleEvtConductor)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class CConsoleEvtConductor /*控制台事件处理器*/ : public CNode 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CConsoleEvtConductor();
	virtual ~CConsoleEvtConductor();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);

	//{{HDOSE_MEMBER_FUNCTION(CConsoleEvtConductor)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CConsoleEvtConductor)
	void	OnCreateObjRequest(CEvt *pevent);
	void	OnRemoveObjRequest(CEvt *pevent);
	void	OnSetData(CEvt *pevent);
// 	void	OnSimCtrl(CEvt *pevent);
// 	void	OnScnCtrl(CEvt *pevent);
// 	void	OnLoggerCtrl(CEvt *pevent);
// 	void	OnRequestBackEngineStateEvt(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CConsoleEvtConductor)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CConsoleEvtConductor)
	//}}HDOSE_ATTRIBUTE

	void SendBackEngineStateEvt(int engState, int fastBest);

	char currentScnFileName[MAX_CHARLEN];	// 记录当前加载的scn文件路径和名称
	int BackEngState;
	int FastBest;
};

#endif
