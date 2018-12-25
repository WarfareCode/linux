#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>


#pragma warning(disable: 4251)
#pragma warning(disable: 4996)

#ifdef MDB_EXPORTS
#define MDB_API __declspec(dllexport)
#else
#define MDB_API __declspec(dllimport)
#endif

///////////////////////////////////////////////////////////////////

#define MAXMEM (180*1024*1024)
#define MAXCLSNU 1024
#define MAXEVTNU 1024*2
#define MAXEVTLEN (40*1024)

struct DataObj;
struct ClsObj
{
	char Name[64];
	DWORD maxObjNu;//应用层设定
	DWORD ObjSize;//可以算出来
	ClsObj* BaseClsObj;//偏移量
	DataObj* Objs;//本类所管理的对象的地址偏移量
};

struct DataObj
{
	int id;
//	int owner;
	double time;
	int len;
	char* dat;
//	char* GetAttibAdr(char* AttName);

};

struct EvtObj
{
	int eventid;
	char evtName[64];
	int scope;
	int sourceid;
	int desobjid;
	char desclsname[64];
	int len;
	char* dat;

};

struct MdbStatus
{
	DWORD m_maxCLsObj;//最大类对象数量
	DWORD m_ClsObjNu;//当前类对象数量
	DataObj* m_pObj;//已经分配到对象的地址偏移量
	EvtObj* m_EvtObj;//事件对象首地址偏移量
	DWORD m_EvtNu;
	DWORD m_EvtNu2;

};

class MDB_API CMdb
{

public:
	CMdb(void){};
	virtual ~CMdb(void){};
	virtual BOOL Create(BOOL srv=0,int clsnu=MAXCLSNU,int mem_size=MAXMEM){return 0;};//服务器置1
	/////////////
	virtual ClsObj* RegisterClsObj(char* Name,char* BaseName,DWORD MaxObj,DWORD ObjSize){return 0;};//注册类对象
	/////////////
	virtual DataObj* CreateDataObj(ClsObj* pCls,int objid){return 0;};//创建数据对象
	virtual void DeleteDataObj(DataObj* pObj){};//注册除数据对象
	/////////////
	virtual void DatToMdb(char *pDat,DataObj* obj,double time){};//将数据存入到MDB的对象中
	virtual void MdbtoDat(DataObj* obj,char *pDat,double &time){};//将MDB中的对象变成数据
	/////////////查找对象
	virtual ClsObj* LookupClsObj(DWORD cls_sn){return 0;};
	virtual ClsObj* LookupClsObj(char* cls_name){return 0;};
	virtual DataObj* LookupDataObj(ClsObj* cls,DWORD obj_sn){return 0;};
	virtual DataObj* LookupDataObj(DWORD cls_sn,DWORD obj_sn){return 0;};
	////////////
	virtual char* GetObjDat(DataObj* obj){return 0;};//获取数据对象的数据地址
	/////////////事件操作:1为输入事件，2为输出事件
	virtual void AddEventByID(int evtid,int scope,int sid,int desid,char *desName,int len,char *dat){};
	virtual void AddEventByName(char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat){};
	virtual void AddEventByIDandName(int evtid,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat){};
	virtual void AddEventByID2(int evtid,int scope,int sid,int desid,char *desName,int len,char *dat){};
	virtual void AddEventByName2(char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat){};
	virtual void AddEventByIDandName2(int evtid,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat){};

	virtual EvtObj *GetCurEvents(int &nu){return 0;};
	virtual EvtObj *GetCurEvents2(int &nu){return 0;};

	virtual BOOL LookupEventsByID(int Evtid,EvtObj** Evts,int &nu){return 0;};
	virtual BOOL LookupEventsByName(char *Name,EvtObj** Evts,int &nu){return 0;};
	virtual BOOL LookupEventsByID2(int Evtid,EvtObj** Evts,int &nu){return 0;};
	virtual BOOL LookupEventsByName2(char *Name,EvtObj** Evts,int &nu){return 0;};

	virtual void RemoveAllEvt(){};
	virtual void RemoveAllEvt2(){};
	/////////////内存数据库状态操作
	virtual MdbStatus *GetMemDat(){return 0;};
	virtual void Wait(){};
	virtual void Release(){};

};
/////以下是C语言提供的接口
#define MDBHandle void*
#define CLSHandle void*
#define OBJHandle void*
#define EVTHandle void*

extern "C"
{


/////////////
MDB_API CLSHandle Mdb_RegisterClsObj(MDBHandle pMdb,char* Name,char* BaseName,DWORD MaxObj,DWORD ObjSize);

/////////////
MDB_API OBJHandle Mdb_CreateDataObj(MDBHandle pMdb,CLSHandle pCls,int objid);

MDB_API void Mdb_DeleteDataObj(MDBHandle pMdb,OBJHandle pObj);//注册除数据对象

	/////////////
MDB_API void Mdb_DatToMdb(MDBHandle pMdb,char *pDat,OBJHandle obj,double time);//将数据存入到MDB的对象中

MDB_API double Mdb_MdbtoDat(MDBHandle pMdb,OBJHandle obj,char *pDat);//将MDB中的对象变成数据

MDB_API char* Mdb_GetObjDat(MDBHandle pMdb,OBJHandle obj);//获取数据对象的数据地址

	/////////////查找对象
MDB_API CLSHandle Mdb_LookupClsObjByID(MDBHandle pMdb,DWORD cls_sn);

MDB_API CLSHandle Mdb_LookupClsObjByName(MDBHandle pMdb,char* cls_name);

MDB_API OBJHandle Mdb_LookupDataObjByName(MDBHandle pMdb,CLSHandle cls,DWORD obj_sn);

MDB_API OBJHandle Mdb_LookupDataObjByID(MDBHandle pMdb,DWORD cls_sn,DWORD obj_sn);

	/////////////事件操作
MDB_API void Mdb_AddEventByID(MDBHandle pMdb,int evtid,int scope,int sid,int desid,char *desName,int len,char *dat);
MDB_API void Mdb_AddEventByName(MDBHandle pMdb,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);
MDB_API	void Mdb_AddEventByIDandName(MDBHandle pMdb,int evtid,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);

MDB_API EVTHandle Mdb_GetCurEvents(MDBHandle pMdb,int &nu);

MDB_API BOOL Mdb_LookupEventsByID(MDBHandle pMdb,int Evtid,EvtObj** Evts,int &nu);
MDB_API BOOL Mdb_LookupEventsByName(MDBHandle pMdb,char *Name,EvtObj** Evts,int &nu);


MDB_API void Mdb_RemoveAllEvt(MDBHandle pMdb);

MDB_API void Mdb_AddEventByID2(MDBHandle pMdb,int evtid,int scope,int sid,int desid,char *desName,int len,char *dat);
MDB_API void Mdb_AddEventByName2(MDBHandle pMdb,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);
MDB_API	void Mdb_AddEventByIDandName2(MDBHandle pMdb,int evtid,char* evtName,int scope,int sid,int desid,char *desName,int len,char *dat);

MDB_API EVTHandle Mdb_GetCurEvents2(MDBHandle pMdb,int &nu);

MDB_API BOOL Mdb_LookupEventsByID2(MDBHandle pMdb,int Evtid,EvtObj** Evts,int &nu);
MDB_API BOOL Mdb_LookupEventsByName2(MDBHandle pMdb,char *Name,EvtObj** Evts,int &nu);


MDB_API void Mdb_RemoveAllEvt2(MDBHandle pMdb);


}
