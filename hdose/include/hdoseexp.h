#ifndef __GLOBAL__h___
#define __GLOBAL__h___

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

////////////////////////////////////////////////////////////////////
///定义控制字
#define AUTO_NATIVE -1
#define AUTO_RTI   0

#define MAX_PACK_SIZE (50*1024)

#define MAX_CLS (1*1024)//最多的类的数量
#define MAX_CLS_OBJ (1*1024) ///一个类最多创建的对象数
#define MAX_OBJ_LEN (1*1024)//一个对象最多占用的字节数


#define PI 3.14159265358979323846

///////////////////////////////////////定义对象ID
#define ID_IVALIDATE -1
#define ID_SCNMGR 1

#define RTI_OBJ 0xFFFF //特指RTI对象


#define TYPE_RTI 0xFFFF  ///(0xFFFF~)
#define TYPE_AUTONATIVE 1000  //(1000->0xFFFF)MAX_AUTO_NATIVEOBJ_NU
#define TYPE_SPEC 0    //(0->1000) 

#define MAX_AUTO_NATIVEOBJ_NU   (0xFFFF-TYPE_AUTONATIVE)

/////////////////////////////////////定义消息号(事件)

///HDOSE 预定义
#define ANYCLS_Init 10 
#define ANYOBJ_Init 11 
#define ANYOBJ_tick 12 
#define ANYOBJ_Simulation 13 
#define ANYOBJ_Output 14 
#define ANYOBJ_Delete 15 
#define ANYOBJ_OnEvent 16 
#define ANYOBJ_Quit 17 

#define SimThreadInit 20 
///用户定义[1000,8000)
///HDOSE管理[8000,9000)
///RTI回调[9000，10000)
///RTI交互[10000~)
////#define TYPE_RTI 10000~

#define EVENT_USER 1000
#define LOCALEVENTNU 1000
#define LOCALEVENTBASE 8000

/////////////////////////////////////

#define SCOPE_ENTITY 0
#define SCOPE_FED 1
#define SCOPE_FEDERATION 2
///////////////////////////////定义HODSE的状态


#define STATUS_NULL 0
#define STATUS_LOADING 1
#define STATUS_LOADED 2
#define STATUS_INITING 3
#define STATUS_INITED 4
#define STATUS_RUNING 5
#define STATUS_PAUSE 59
#define STATUS_EXITING -1
#define STATUS_EXITED -2
class CEngine;

typedef void (* EngineStateChangeCB)(CEngine *,int);
typedef void (* ObjMgrNotifyCB)(CEngine*,DWORD,LPVOID);

typedef int (* PackFun)(CObj *,char *);
typedef void (* LogNotifyCB)(CEngine *,char *);
///////////////////////////////////////////////////////////////
class CParaEntry;
HDOSE_API void StartHdose(const char *filename,int mt=1,EngineStateChangeCB cb=0,int hdoseid=0,int run=5,CParaEntry *pe=0);
HDOSE_API void EndHdose(int hdoseid=0);


HDOSE_API int SizeOf(char *type);
HDOSE_API char *StrNormal(char *str);
HDOSE_API char *StrBaseName(char *str);
HDOSE_API void StrToByteStream(int len,char *buf,BYTE *p);

HDOSE_API char* EngineNew(int len);
HDOSE_API void EngineDelete(char* p);

class CMdb;
extern HDOSE_API EngineStateChangeCB ESChangeCBfun;
extern HDOSE_API CMdb g_mdb;

////////////////////////////////////////////////////////////////////
HDOSE_API CEngine* CreateEngine(DWORD id=0);
HDOSE_API CEngine* GetEngine(DWORD id);
HDOSE_API int DefaultPack(CObj *pobj,char *buf);
HDOSE_API int DefaultUnpack(CObj *pobj,char *buf);
HDOSE_API BOOL CopyObj(CObj *pDes,CObj *pScr);

///////////////////////////////////////////////////////////////
#define CreateInteractive(pEngine,iname) \
{\
	CEvt *pEvt=pEngine->CreateInteraction(iname)

#define SetParameter(pname,type,value) \
	*(type*)pEvt->GetAttributeAddress(pname)=value

#define GetParameter(pname,type) \
	*(type*)pEvt->GetAttributeAddress(pname)

#define SetParameterString(pname,value) \
	pEvt->SetValueString(pname,value)

#define GetParameterString(pname) \
	pEvt->GetValueString(pname)

#define SendInteractive(time) \
	pEvt->Send(time);\
	delete pEvt;\
}


class HDOSE_API DataBlock
{
	DWORD alloc_len;
	char *buf;
	CHMutex mutex;
public:
	DWORD uselen;
	DataBlock();
	DataBlock(DataBlock *pBlock);
	~DataBlock();
	void Reflesh();
	void Set(int size,char *pDat=0);
	int Add(char *buf,int len);
	int GetLen();
	char *GetBuf();
	int ToMem(char *mem);
};


#define DECLARE_DA(TYPE,MAX_NUM)\
struct DA_##TYPE\
{\
	DWORD m_item_len;\
	DWORD m_len;\
	TYPE m_items[MAX_NUM];\
	DA_##TYPE()\
	{\
		m_len=0;\
		m_item_len=sizeof(TYPE);\
	}\
	TYPE& operator[](int i)\
	{\
		return m_items[i];\
	}\
};



#define DECLARE_ObjStream(CLSNAME,TYPE,MAXARY) \
class CLSNAME :public CLink\
{\
	DECLARE_DA(TYPE,MAXARY);\
	DECLARE_CREATE;\
public:\
	DWORD m_p1;\
	DWORD m_p2;\
	DA_##TYPE m_da;\
	static void ClassInit(ClassInfo *clsinfo);\
public:\
	CLSNAME(void);\
	~CLSNAME(void);\
	virtual TYPE& operator[](int i);\
	virtual int GetCount();\
	virtual void UpdateData(int nu);\
};


#define IMPLEMENT_ObjStream(CLSNAME,TYPE) \
	IMPLEMENT_CREATE_EX(CLSNAME,CLink,ClassInit);\
	CLSNAME::CLSNAME(void)\
	{\
	}\
	CLSNAME::~CLSNAME(void)\
	{\
	}\
	void CLSNAME::ClassInit(ClassInfo *clsinfo)\
	{\
		AttributeRegister(CLSNAME,DWORD,p1);\
		AttributeRegister(CLSNAME,DWORD,p2);\
		AttributeRegister(CLSNAME,DA_##TYPE,da);\
	}\
	void CLSNAME::UpdateData(int nu)\
	{\
		m_da.m_len=nu;\
		CBridge *pBridge=(CBridge *)m_pEngine->LookupObj(RTI_OBJ);\
		if(pBridge)\
			pBridge->UpdateAttributeValues(this,0);\
	}\
	TYPE& CLSNAME::operator[](int i)\
	{\
		return m_da.m_items[i];\
	}\
	int CLSNAME::GetCount()\
	{\
		return m_da.m_len;\
	}


#endif
