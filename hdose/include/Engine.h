// Engine.h: interface for the CEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENGINE_H__9A45EACE_34C2_4D21_BB34_A6B535FEA74C__INCLUDED_)
#define AFX_ENGINE_H__9A45EACE_34C2_4D21_BB34_A6B535FEA74C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class HDOSE_API CEngine  
{
public:
///////////////////////////////////////系统管理

	virtual void Exit()=0;
	virtual void Pause()=0;
	virtual void Resume()=0;
	virtual void ReStart(EngineStateChangeCB cb=0)=0;

	virtual DWORD GetID()=0;
	virtual LPVOID GetFederateID()=0;
	virtual int GetState()=0;
	virtual char* GetFedParameter()=0;
	virtual PackFun GetPackFun()=0;
	virtual void SetPackFun(PackFun fun)=0;
	virtual PackFun GetUnPackFun()=0;
	virtual void SetUnPackFun(PackFun fun)=0;

	virtual void Wait()=0;
	virtual void Release()=0;

///////////////////////////////////////时间管理//调度管理
	virtual void SetFastBest(BOOL s=1)=0;
	virtual BOOL GetFastBest()=0;
	virtual BOOL ResetWallClock(double period)=0;
	virtual BOOL ResetLogicClock(double step)=0;
	virtual double GetLookahead()=0;
	virtual double GetGrantTime()=0;
	virtual double GetLogicClock(CObj * pObj=0)=0;
	virtual double GetWallClock()=0;

	virtual void Fire()=0;

///////////////////////////////////////组件管理
	virtual LPVOID GetComList()=0;
	virtual void LoadComponent(char* Filename)=0;
	virtual COM_Info* LookupCom(char *Filename)=0;
	virtual ClassInfo* AddClass(char* ClsName,char *BaseName,char* ComName)=0;
	virtual COM_Info* AddCOM(char* ComName)=0;

////////////////////////////////////////////////////////////对象管理
	virtual CClasInfoList *GetRootClsInfoList()=0;
	virtual ClassInfo* GetClassInfo(int classid)=0;
	virtual ClassInfo* GetClassInfo(char *name)=0;
	virtual void RegisterNotify(ObjMgrNotifyCB pf)=0;

	virtual CObj *CreateObj(int classid,int id=AUTO_NATIVE,char *name=0,char* RecFile=0,char *opdName=0)=0;
	virtual CObj *CreateObj(char* className,int id=AUTO_NATIVE,char *name=0,char* RecFile=0,char *opdName=0)=0;
	virtual CObj *CreateObj(ClassInfo *info,int id=AUTO_NATIVE,char *name=0,char* RecFile=0,char *opdName=0)=0;
	virtual CObj *LookupObj(int id,CClasInfoList *path=0)=0;
	virtual CObj *LookupObj(char *classname,char *objname="*")=0;
	virtual CObjList *LookupObjFromClass(char *name)=0;
	virtual void LookupAllObjFromClass(char *clsname,CObjList* pList)=0;
	virtual void LookupAllObjFromClass(char *clsname,CObjList** ppList,int &nu)=0;
	virtual void DeleteObj(CObj *pObject)=0;

	virtual void UpdateAllObjects(char *ClsName)=0;

	virtual char* GetGdb()=0;

////////////////////////////////////////////////////////////事件管理
	virtual void SendEvent(CEvt *pEvent)=0;
	virtual void PostEvent(CEvt *pEvent)=0;
	virtual void ProcessEvent()=0;
	virtual DWORD RegisterEvent(char *evtName)=0;
	virtual DWORD GetEventID(char *evtName)=0;
	virtual CEvt* CreateEvt(char *name)=0;
	virtual CEvt* CreateEvt(int evtid)=0;
	virtual CEvt* CreateInteraction(char *name)=0;
	virtual BOOL RegisterHook(HookFun fun,int Evtid_start,int Evtid_len=1,char type='B')=0;
	virtual BOOL UnRegisterHook(HookFun fun,char type='B')=0;

///////////////////场景管理
	virtual void LoadScenario(char *ScnFile,char* Var=0)=0;
	virtual void UnLoadScenario()=0;
	virtual void PrintObjs(char *Filename)=0;
	virtual void SnapshotRead(char *FileName)=0;//快照恢复
	virtual void SnapshotWrite(char *FileName)=0;//快照
	virtual void StartRecord()=0;
	virtual void PauseRecord()=0;
	virtual void ResumeRecord()=0;
	virtual void StopRecord()=0;
	virtual DWORD GetRecPlayMode()=0;
	virtual BOOL IsRecPause()=0;
	virtual char* GetRecDir()=0;

	virtual void PlayToRun()=0;//回放态切换到运行态
	virtual void PlayCtl(double startTime=0,DWORD rate=1)=0;//可实现快进或快倒

////////////////////////////////////////////////////////////监管日志
	virtual BOOL AddLogLine(int type,const char * _Format, ...)=0;
	virtual void EnableLogger(BOOL enable=1)=0;
	virtual void SetLogFile(char *FileName,LogNotifyCB cb=0)=0;

};

#endif // !defined(AFX_ENGINE_H__9A45EACE_34C2_4D21_BB34_A6B535FEA74C__INCLUDED_)
