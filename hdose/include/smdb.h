#pragma once

#include "Mdb.h"
#include "shmem.h"

class MDB_API CSmdb:public CMdb
{
	MdbStatus* m_memDat;//ӳ�䵽�����̵Ĺ����ڴ����ַ���Ǽ����������е�ַ�����
	ClsObj* m_pFirstCls;//�׸������ĵ�ַ
	EvtObj* m_pEvtFirst;//�¼����ַ
	EvtObj* m_pEvtFirst2;//�¼����ַ
	CHMutex* m_mutex;

	CSharedMemory<MdbStatus> SmObj;
public:
	CSmdb(void);
	virtual ~CSmdb(void);
	virtual BOOL Create(BOOL srv=0,int clsnu=MAXCLSNU,int mem_size=MAXMEM);//��������1
	/////////////
	virtual ClsObj* RegisterClsObj(char* Name,char* BaseName,DWORD MaxObj,DWORD ObjSize);//ע�������
	/////////////
	virtual DataObj* CreateDataObj(ClsObj* pCls,int objid);//�������ݶ���
	virtual void DeleteDataObj(DataObj* pObj);//ע������ݶ���
	/////////////
	virtual void DatToMdb(char *pDat,DataObj* obj,double time);//�����ݴ��뵽MDB�Ķ�����
	virtual void MdbtoDat(DataObj* obj,char *pDat,double &time);//��MDB�еĶ���������
	/////////////���Ҷ���
	virtual ClsObj* LookupClsObj(DWORD cls_sn);
	virtual ClsObj* LookupClsObj(char* cls_name);
	virtual DataObj* LookupDataObj(ClsObj* cls,DWORD obj_sn);
	virtual DataObj* LookupDataObj(DWORD cls_sn,DWORD obj_sn);
	////////////
	virtual char* GetObjDat(DataObj* obj);//��ȡ���ݶ�������ݵ�ַ
	/////////////�¼�����:1Ϊ�����¼���2Ϊ����¼�
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
	/////////////�ڴ����ݿ�״̬����
	virtual MdbStatus *GetMemDat();
	virtual void Wait();
	virtual void Release();

};
