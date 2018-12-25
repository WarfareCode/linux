// Item.h: interface for the CItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Item_H__D936424F_0585_4C17_A561_F62B3F9C7247__INCLUDED_)
#define AFX_Item_H__D936424F_0585_4C17_A561_F62B3F9C7247__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Obj.h"
typedef void (* EvtOverCbFun)(CEvt *);
class CParaEntry;
struct DataObj;
class HDOSE_API CItem : public CObj
{
	DECLARE_CREATE
	DECLARE_EVENTMAP;
	friend class CScnMgr;
	friend class CEngineImp;
	friend class CObjMgrImp;
public:
	CItem();
	virtual ~CItem();
protected:
	int m_id;
	char *m_name;
	BOOL m_bInitiative;
	double m_createtime;
	int m_dynamic;
	DataObj* m_DataObj;
public:
	double m_lasttime;

public:
	static void ClassInit(ClassInfo *clsinfo);
	static CItem* PASCAL DynamicCreate(ClassInfo *clsInfo=0);

	virtual void Adv(double lasttime=0);
	virtual void tick(double lasttime=0);
	virtual void Simulation(double lasttime=0);
	virtual void Output();
	virtual void Record(double lasttime){};
	virtual void Play(double lasttime){};

	virtual void OnReflect(char *Para=0);
	virtual void OnCreate(char *Para=0);
	virtual void OnInit();
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual void OnEvent(CEvt *pEvt);

	virtual BOOL IsInitiative();
	virtual int GetAttributeNumber();
	virtual char* GetAttributeAddress(char *aname,int *size=0,char *type=0);
	virtual void SetID(int id);
	virtual void SetName(char *name);
	virtual char *GetName();
	virtual int GetID();
	virtual void Quit();
	virtual void AddAggregateObj(CObj *pObj){};
	virtual void RemoveAggregateObj(CObj *pObj){};
	virtual CObj* LookupAggregateObj(char *clsname){return 0;};
	virtual CObj* LookupAgtObjByTag(char *tagname){return 0;};

	virtual void Read(CMarkup *xml);
	virtual void Write(CMarkup *xml,BOOL into=0);


	virtual void Pub(double time=0,int syn=1);
	virtual void RequestUpdate(){};	
	virtual void UpdateAllAttributes(char *p=0){};
	virtual void Send(double time=0);
	virtual void Post(double time=0);

	virtual bool IsDrivedFrom(char *basename);
	virtual int GetObjSize();
	virtual CEventMAP* GetEventMap() const; 

	virtual char* GetValueString(char *att_name);
	virtual void SetValueString(char *att_name,char* pstr);

	virtual int GetValueInt(char *att_name);
	virtual void SetValueInt(char *att_name,int value);

	virtual double GetValueDouble(char *att_name);
	virtual void SetValueDouble(char *att_name,double value);

	virtual CParaEntry *GetOPD(){return 0;};

	virtual void StartRecord(){};
	virtual void PauseRecord(){};
	virtual void ResumeRecord(){};
	virtual void StopRecord(){};

	virtual DWORD GetRecPlayMode(){return 0;};
	virtual BOOL IsRecPause(){return 0;};

	virtual CObjList* GetAgts(){return 0;};
	virtual CLPArray* GetParas(){return 0;};

};

#endif // !defined(AFX_Item_H__D936424F_0585_4C17_A561_F62B3F9C7247__INCLUDED_)
