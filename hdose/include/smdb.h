#pragma once

#include "Mdb.h"
#include "shmem.h"

class MDB_API CSmdb:public CMdb
{
	MdbStatus* m_memDat;//映射到本进程的共享内存的首址，是计算其他所有地址的起点
	ClsObj* m_pFirstCls;//首个类对象的地址
	EvtObj* m_pEvtFirst;//事件表地址
	EvtObj* m_pEvtFirst2;//事件表地址
	CHMutex* m_mutex;

	CSharedMemory<MdbStatus> SmObj;
public:
	CSmdb(void);
	virtual ~CSmdb(void);
	virtual BOOL Create(BOOL srv=0,int clsnu=MAXCLSNU,int mem_size=MAXMEM);//服务器置1
	/////////////
	virtual ClsObj* RegisterClsObj(char* Name,char* BaseName,DWORD MaxObj,DWORD ObjSize);//注册类对象
	/////////////
	virtual DataObj* CreateDataObj(ClsObj* pCls,int objid);//创建数据对象
	virtual void DeleteDataObj(DataObj* pObj);//注册除数据对象
	/////////////
	virtual void DatToMdb(char *pDat,DataObj* obj,double time);//将数据存入到MDB的对象中
	virtual void MdbtoDat(DataObj* obj,char *pDat,double &time);//将MDB中的对象变成数据
	/////////////查找对象
	virtual ClsObj* LookupClsObj(DWORD cls_sn);
	virtual ClsObj* LookupClsObj(char* cls_name);
	virtual DataObj* LookupDataObj(ClsObj* cls,DWORD obj_sn);
	virtual DataObj* LookupDataObj(DWORD cls_sn,DWORD obj_sn);
	////////////
	virtual char* GetObjDat(DataObj* obj);//获取数据对象的数据地址
	/////////////事件操作:1为输入事件，2为输出事件
	virtual void AddEventByID(int evtid,int scope,int sid,int desid,char *desName,int len,char *dat);
	virtual void AddEventByName(char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);
	virtual void AddEventByIDandName(int evtid,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);
	virtual void AddEventByID2(int evtid,int scope,int sid,int desid,char *desName,int len,char *dat);
	virtual void AddEventByName2(char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);
	virtual void AddEventByIDandName2(int evtid,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);

	virtual EvtObj *GetCurEvents(int &nu);
	virtual EvtObj *GetCurEvents2(int &nu);

	virtual BOOL LookupEventsByID(int Evtid,EvtObj** Evts,int &nu);
	virtual BOOL LookupEventsByName(char *Name,EvtObj** Evts,int &nu);
	virtual BOOL LookupEventsByID2(int Evtid,EvtObj** Evts,int &nu);
	virtual BOOL LookupEventsByName2(char *Name,EvtObj** Evts,int &nu);

	virtual void RemoveAllEvt();
	virtual void RemoveAllEvt2();
	/////////////内存数据库状态操作
	virtual MdbStatus *GetMemDat();
	virtual void Wait();
	virtual void Release();

};
