#ifndef __Reflection__h___
#define __Reflection__h___

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_CHARLEN   128
#include "Obj.h"
typedef void ( CObj::*EventFun)(CEvt *pEvent);
typedef CObj* (PASCAL* CreateFun)(char *para);
typedef BOOL (*HookFun)(CEvt *pEvent);
typedef void (* ClassInitFun)(ClassInfo*);
typedef ClassInfo* (PASCAL* RegisterClsFun)(DWORD ver);
class CMarkup;

/////////////////////////////////////
struct EventDispatch
{
	int eventid;
	char name[MAX_CHARLEN/2];
	EventFun pfn;
	char funname[MAX_CHARLEN/2];

};


class HDOSE_API CEventMAP
{
	friend class ClassInfo;
	CEventMAP* pBaseMap;
public:
	EventDispatch* lpEntries;
	CEventMAP(ClassInfo *classinfo,EventDispatch* pEn);
	~CEventMAP();
	EventFun GetEventFun(int eventid);
	EventDispatch* GetEventDispatch(int eventid);
};


//////////////////////////////////////
class HDOSE_API  COM_Info
{
public:
	String name;
	HMODULE dll_handle;
	CClasInfoList m_ClsList;
	void Write(char *name);
};


struct Parameter
{
	String name;
	String value;
};

struct AggregateObject
{
	String clsname;
	String type;
	String tag;
	String OPD;
	int sample;
	int id;
};
class CParaEntry;
class DataBlock;
struct ClsObj;
class HDOSE_API ClassInfo
{
public:
	DWORD m_ver;
	char className[96];
	char baseclassName[92];
	String externalName;
	COM_Info *pCom;
	ClsObj* pClsObj;
	int classid;
	WORD ObjSize;
	CreateFun CreateObject; 
	ClassInitFun classinit;
	CObjList objlist;
	CAgtList agtlist;
	CClasInfoList deriveclassinfolist;
	String m_Script;
	String m_ScriptLanguage;
	CClasInfoList *m_pclasslist;

	CAttributeInfos m_attributeinfos;
	CLPArray parameters;
	ClassInfo *pBaseClassinfo;
	CEventMAP *pEventmap;
	unsigned long ctlcode;
	DWORD dynamic;

	BOOL ParDisp;

	LPVOID ext;
	CParaEntry *OPD;
	DataBlock* m_pBlock;

	ClassInfo(char *name,CreateFun pf,char *basename=0,ClassInitFun cf=0,DWORD v=0,DWORD maxobj=320);
	void RegisterAttribute(char *name,unsigned long pos,unsigned long size,char* type=0);
	~ClassInfo();
public:
	char * GetParameterValue(char *Name);
	virtual BOOL IsDrivedFrom(char *basename);
	CObj* LookupObj(int id);
	CObj* LookupObj(char* name="*");
	AttributeInfo* GetAttribute(char *name);
	void Adjust();
	void AddParentAttributes();
	void Write(CMarkup *xml);//类信息写入XML
	static ClassInfo* CreateFromXml(CMarkup *pXml,CEngine *pEngine);/////从XML中创建类信息
	void ReadClsParameters(CMarkup *xml);

	static ClassInfo* Register(char *name,CreateFun pf,char *basename=0,ClassInitFun cf=0,DWORD v=0);
	static void DeleteClassInfo(CClasInfoList *path);


	static void AdjustAll(CClasInfoList *path);
	static void InitAllClass(CClasInfoList *path);
	static void RegisterAllClassToMdb(CClasInfoList *path);
	static void AddAllParentAttributes(CClasInfoList *path);
	static ClassInfo* GetClassInfo(int classid,CClasInfoList *path);
	static ClassInfo* GetClassInfo(char *name,CClasInfoList *path);
};

struct AttributeInfo
{
	DWORD  handle;
	char name[MAX_CHARLEN/2];
	DWORD offset;
	DWORD size;
	char type[MAX_CHARLEN/2];
};
extern HDOSE_API List<void*,void*> *g_reglist;

class HDOSE_API REG
{
public:
	RegisterClsFun m_regfun;
	HMODULE m_hModule;
	REG(RegisterClsFun regfun);
	~REG();
};


///////////////////////////////////////////////////////////////
#define DECLARE_CREATE	\
public:\
	static CObj* PASCAL Create(char *para=0);\
	static ClassInfo * PASCAL RegisterClass(DWORD ver);\
	static REG r;\
public:\
	virtual ClassInfo *GetClsInfo();\
	virtual char *GetClsName();


#define IMPLEMENT_CREATE(class_name) \
	CObj* PASCAL class_name::Create(char *para) \
	{ \
		CObj* pobj= new class_name;\
		pobj->m_pClsInfo=(ClassInfo*)para;\
		pobj->m_pEngine=::GetEngine(pobj->m_pClsInfo->m_ver);\
		return pobj;\
	} \
	ClassInfo* PASCAL class_name::RegisterClass(DWORD ver)\
	{\
		ClassInfo* info=ClassInfo::Register(#class_name,class_name::Create,0,0,ver);\
		info->ObjSize=sizeof(class_name);\
		info->pEventmap=new CEventMAP(info,class_name::ms_eventEntries);\
		return info;\
	}\
	REG class_name::r(class_name::RegisterClass);\
	ClassInfo* class_name::GetClsInfo() {return m_pClsInfo;}\
	char *class_name::GetClsName() {return #class_name;}

///////////////////////////////////////////////////////////////

#define IMPLEMENT_CREATE_EX(class_name,base_class_name,class_init) \
	CObj* PASCAL class_name::Create(char *para) \
	{ \
		CObj* pobj= new class_name;\
		pobj->m_pClsInfo=(ClassInfo*)para;\
		pobj->m_pEngine=::GetEngine(pobj->m_pClsInfo->m_ver);\
		return pobj;\
	} \
	ClassInfo* PASCAL class_name::RegisterClass(DWORD ver)\
	{\
		ClassInfo* info=ClassInfo::Register(#class_name,class_name::Create,#base_class_name,class_init,ver);\
		info->ObjSize=sizeof(class_name);\
		info->pEventmap->lpEntries=class_name::ms_eventEntries;\
		return info;\
	}\
	REG class_name::r(class_name::RegisterClass);\
	ClassInfo* class_name::GetClsInfo() {return m_pClsInfo;}\
	char *class_name::GetClsName() {return #class_name;}

///////////////////////////////////////////////////////////////

#define IMPLEMENT_CREATE_EXT(class_name,base_class_name,class_init) \
	template<class TYPE, class ARG_TYPE>\
	CObj* PASCAL class_name<TYPE, ARG_TYPE>::Create(char *para) \
	{ \
		CObj* pobj= new class_name;\
		pobj->m_pClsInfo=(ClassInfo*)para;\
		pobj->m_pEngine=::GetEngine(pobj->m_pClsInfo->m_ver);\
		return pobj;\
	} \
	template<class TYPE, class ARG_TYPE>\
	ClassInfo* PASCAL class_name<TYPE, ARG_TYPE>::RegisterClass(DWORD ver)\
	{\
		ClassInfo* info=ClassInfo::Register(#class_name,class_name::Create,#base_class_name,class_init,ver);\
		info->ObjSize=sizeof(class_name);\
		info->pEventmap->lpEntries=class_name::ms_eventEntries;\
		return info;\
	}\
	template<class TYPE, class ARG_TYPE>\
	REG class_name<TYPE, ARG_TYPE>::r(class_name::RegisterClass);\
	template<class TYPE, class ARG_TYPE>\
	ClassInfo* class_name<TYPE, ARG_TYPE>::GetClsInfo() {return m_pClsInfo;}\
	template<class TYPE, class ARG_TYPE>\
	char *class_name<TYPE, ARG_TYPE>::GetClsName() {return #class_name;}

 //////////////////////////////////////////////////////////////////
#define DECLARE_EVENTMAP	\
protected: \
	static EventDispatch ms_eventEntries[];\
	virtual CEventMAP* GetEventMap(); 

#define BEGIN_EVENTMAP(theClass) \
	CEventMAP* theClass::GetEventMap() \
		{ return m_pClsInfo->pEventmap; } \
	EventDispatch theClass::ms_eventEntries[] = \
	{ 

#define ON_HEVENT(eventid, pFun) \
	{ eventid,#eventid,(EventFun)&pFun,#pFun},

#define ON_HDOSEEVENT(eventname, pFun) \
	{ 0,eventname,(EventFun)&pFun,#pFun},


#define END_EVENTMAP \
		{0L,"__end",(EventFun)0,""} \
	}; 


///////////////////////////////////////////////////////////////

#define AttributeRegister(class_name,att_type,att_name)	\
	clsinfo->RegisterAttribute(#att_name,offsetof(class_name,m_##att_name),sizeof(att_type),#att_type);\
	TRACE("class=%s attribute=%s offset=%d size=%d\n",#class_name,#att_name,offsetof(class_name,m_##att_name),sizeof(att_type));


#define SetObjValue(obj,PARA,TYPE,VALUE) \
	*(TYPE*)obj->GetAttributeAddress(PARA)=VALUE;


#define GetObjValue(obj,PARA,TYPE) \
	*(TYPE*)obj->GetAttributeAddress(PARA)



/////////////////////////////////////////////////////////
#endif
