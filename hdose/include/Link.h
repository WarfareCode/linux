// Link.h: interface for the CLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Link_H__08C6451A_D21A_4BBD_997B_12AF124B49C4__INCLUDED_)
#define AFX_Link_H__08C6451A_D21A_4BBD_997B_12AF124B49C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Item.h"

class HDOSE_API CLink : public CItem  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
	friend class CScnMgr;

public:
	CLink();
	virtual ~CLink();
	virtual void OnReflect(char *Para=0){};

	virtual void Adv(double lasttime=0);
	virtual void tick(double lasttime=0);
	virtual void Simulation(double lasttime=0);
	virtual void Output();
	virtual void Record(double lasttime);
	virtual void Play(double lasttime);
	virtual void UpdateAllAttributes(char *p=0);
	virtual void RequestUpdate();	
	virtual void AddAggregateObj(CObj *pObj);
	virtual void RemoveAggregateObj(CObj *pObj);
	virtual CObj* LookupAggregateObj(char *clsname);
	virtual CObj* LookupAgtObjByTag(char *tagname);
	virtual CParaEntry* GetOPD();

protected:	
	virtual BOOL PrepareRecord();
	virtual BOOL PreparePlay();

public:
	virtual void OnCreate(char *Para=0){};
	virtual void OnInit(){};
	virtual void OnClose();
	virtual void OnEvent(CEvt *pEvt);
	virtual void OnSetParameter(char *name,char *value);
	DWORD m_sample;
	CLink *m_pSr;///×´Ì¬³Ø

protected:
	char *m_RecFile;
	DWORD m_RecPlayMode;
	DWORD m_RecPause;

	CMemFileMap* m_FileMap;

public:
	CObjList m_agtlist;
	CObj* m_parent;
	String m_tag;
	CParaEntry* m_OPD;
	CLPArray m_parameters;

	virtual void StartRecord();
	virtual void PauseRecord();
	virtual void ResumeRecord();
	virtual void StopRecord();
	virtual void SetRecFile(const char* FileName);

	virtual DWORD GetRecPlayMode(){return m_RecPlayMode;};
	virtual BOOL IsRecPause(){return m_RecPause;};

	virtual CObjList* GetAgts();
	virtual CLPArray* GetParas();

};

#endif // !defined(AFX_Link_H__08C6451A_D21A_4BBD_997B_12AF124B49C4__INCLUDED_)
