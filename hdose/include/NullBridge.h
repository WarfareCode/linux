// NullBridge.h: interface for the CNullBridge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NULLBRIDGE_H__110E7642_1757_4AE6_B7C9_1C3FE7F90B07__INCLUDED_)
#define AFX_NULLBRIDGE_H__110E7642_1757_4AE6_B7C9_1C3FE7F90B07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "hBridge.h"

class CNullBridge : public CBridge  
{
	DECLARE_CREATE
	DECLARE_EVENTMAP;

public:
	CNullBridge();
	virtual ~CNullBridge();

	virtual int GetInteractionClassHandle(char *name);
	virtual int GetAttributeHandle(char *name,int clsid){return 0;};
	virtual int GetObjectClassHandle(char* str){return 0;};
	virtual int GetParameterHandle(char *name, int clsid){return 0;};

	virtual void ExecTimePolicy(BOOL bc,BOOL br,BOOL MTRTI){m_bConstrained=bc;m_bRegulation=br;};

	virtual double GetLookahead(){return m_lookahead;};
	virtual double GetGrantTime(){return m_grantTime;};
	virtual double GetLogicClock(){return m_timestep;};

	virtual void SetLookahead(double t){m_lookahead=t; };
	virtual void SetGrantTime(double t){m_grantTime=t;};
	virtual void SetLogicClock(double t){m_timestep=t;};

	virtual void OnMyEvent(CEvt* pEvt);
	virtual void RegisterObjectInstance(CObj *pObj);

	virtual void TimeAdvance(double time);

	double m_lookahead;
	double m_timestep;
	double m_grantTime;
	double m_wallclock;

	int m_bConstrained;
	int m_bRegulation;
};

#endif // !defined(AFX_NULLBRIDGE_H__110E7642_1757_4AE6_B7C9_1C3FE7F90B07__INCLUDED_)
