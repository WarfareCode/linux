// Obj.h: interface for the CObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJ_H__9D3BDA06_E2BF_4D1E_BF4A_CD7AB2DD8DF7__INCLUDED_)
#define AFX_OBJ_H__9D3BDA06_E2BF_4D1E_BF4A_CD7AB2DD8DF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class ClassInfo;
class CEvt;
class CEngine;
class CMarkup;
class HDOSE_API CObj
{
public:
	CObj(){};
	virtual ~CObj(){};
	virtual char* GetName()=0;
	virtual void SetName(char *name)=0;
	virtual int GetID()=0;
	virtual void SetID(int id)=0;
	virtual int GetAttributeNumber()=0;
	virtual char* GetAttributeAddress(char *aname,int *size=0,char *type=0)=0;

	virtual char* GetValueString(char *att_name)=0;
	virtual void SetValueString(char *att_name,char* pstr)=0;

	virtual int GetValueInt(char *att_name)=0;
	virtual void SetValueInt(char *att_name,int value)=0;

	virtual double GetValueDouble(char *att_name)=0;
	virtual void SetValueDouble(char *att_name,double value)=0;

	virtual void OnCreate(char *Para=0)=0;
	virtual void OnInit()=0;
	virtual void OnSetParameter(char *name,char *value)=0;
	virtual void Pub(double time=0,int syn=1)=0;
	virtual void RequestUpdate()=0;
	virtual void OnClose()=0;
	virtual bool IsDrivedFrom(char *basename)=0;
	virtual BOOL IsInitiative()=0;
	virtual ClassInfo* GetClsInfo()=0;
	virtual CEventMAP* GetEventMap()=0; 
	virtual void AddAggregateObj(CObj *pObj)=0;
	virtual void RemoveAggregateObj(CObj *pObj)=0;
	virtual CObj* LookupAggregateObj(char *clsname)=0;
	virtual void Quit()=0;
	virtual void Read(CMarkup *xml)=0;
	virtual void Write(CMarkup *xml,BOOL into=0)=0;

	virtual void StartRecord()=0;
	virtual void PauseRecord()=0;
	virtual void ResumeRecord()=0;
	virtual void StopRecord()=0;
	virtual DWORD GetRecPlayMode()=0;
	virtual BOOL IsRecPause()=0;

	ClassInfo *m_pClsInfo;
	CEngine *m_pEngine;

};

#endif // !defined(AFX_OBJ_H__9D3BDA06_E2BF_4D1E_BF4A_CD7AB2DD8DF7__INCLUDED_)
