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
	DWORD maxObjNu;//Ӧ�ò��趨
	DWORD ObjSize;//���������
	ClsObj* BaseClsObj;//ƫ����
	DataObj* Objs;//����������Ķ���ĵ�ַƫ����
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
	DWORD m_maxCLsObj;//������������
	DWORD m_ClsObjNu;//��ǰ���������
	DataObj* m_pObj;//�Ѿ����䵽����ĵ�ַƫ����
	EvtObj* m_EvtObj;//�¼������׵�ַƫ����
	DWORD m_EvtNu;
	DWORD m_EvtNu2;

};

class MDB_API CMdb
{

public:
	CMdb(void){};
	virtual ~CMdb(void){};
	virtual BOOL Create(BOOL srv=0,int clsnu=MAXCLSNU,int mem_size=MAXMEM){return 0;};//��������1
	/////////////
	virtual ClsObj* RegisterClsObj(char* Name,char* BaseName,DWORD MaxObj,DWORD ObjSize){return 0;};//ע�������
	/////////////
	virtual DataObj* CreateDataObj(ClsObj* pCls,int objid){return 0;};//�������ݶ���
	virtual void DeleteDataObj(DataObj* pObj){};//ע������ݶ���
	/////////////
	virtual void DatToMdb(char *pDat,DataObj* obj,double time){};//�����ݴ��뵽MDB�Ķ�����
	virtual void MdbtoDat(DataObj* obj,char *pDat,double &time){};//��MDB�еĶ���������
	/////////////���Ҷ���
	virtual ClsObj* LookupClsObj(DWORD cls_sn){return 0;};
	virtual ClsObj* LookupClsObj(char* cls_name){return 0;};
	virtual DataObj* LookupDataObj(ClsObj* cls,DWORD obj_sn){return 0;};
	virtual DataObj* LookupDataObj(DWORD cls_sn,DWORD obj_sn){return 0;};
	////////////
	virtual char* GetObjDat(DataObj* obj){return 0;};//��ȡ���ݶ�������ݵ�ַ
	/////////////�¼�����:1Ϊ�����¼���2Ϊ����¼�
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
	/////////////�ڴ����ݿ�״̬����
	virtual MdbStatus *GetMemDat(){return 0;};
	virtual void Wait(){};
	virtual void Release(){};

};
/////������C�����ṩ�Ľӿ�
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

MDB_API void Mdb_DeleteDataObj(MDBHandle pMdb,OBJHandle pObj);//ע������ݶ���

	/////////////
MDB_API void Mdb_DatToMdb(MDBHandle pMdb,char *pDat,OBJHandle obj,double time);//�����ݴ��뵽MDB�Ķ�����

MDB_API double Mdb_MdbtoDat(MDBHandle pMdb,OBJHandle obj,char *pDat);//��MDB�еĶ���������

MDB_API char* Mdb_GetObjDat(MDBHandle pMdb,OBJHandle obj);//��ȡ���ݶ�������ݵ�ַ

	/////////////���Ҷ���
MDB_API CLSHandle Mdb_LookupClsObjByID(MDBHandle pMdb,DWORD cls_sn);

MDB_API CLSHandle Mdb_LookupClsObjByName(MDBHandle pMdb,char* cls_name);

MDB_API OBJHandle Mdb_LookupDataObjByName(MDBHandle pMdb,CLSHandle cls,DWORD obj_sn);

MDB_API OBJHandle Mdb_LookupDataObjByID(MDBHandle pMdb,DWORD cls_sn,DWORD obj_sn);

	/////////////�¼�����
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
