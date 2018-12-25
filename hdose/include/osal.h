#ifndef ___WINAPI_H__
#define ___WINAPI_H__
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <ctype.h>
#include <wchar.h>
#include <errno.h>

#ifndef _DEBUG
#define HOutputDebugString(f) ((void)0)
#endif

#ifdef _HDOSE_LINUX
#ifdef _DEBUG
#define HOutputDebugString(f) cout<<f
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef unsigned int        UINT;
typedef void VOID;
typedef void *LPVOID;

typedef int HANDLE;
typedef void* HMODULE;
typedef int HINSTANCE;

typedef DWORD *DWORD_PTR;

#ifdef UNICODE
typedef WCHAR				TCHAR;
typedef wchar_t           _TUCHAR;
#define _T(x)            L ## x

#else
typedef char				TCHAR;
typedef char				_TCHAR;
typedef unsigned char     _TUCHAR;
#define _T(x)      x
#endif

typedef short WCHAR;

typedef TCHAR  *			LPTSTR;
typedef const TCHAR  *	LPCTSTR;

#define   PASCAL    __stdcall  
#define   __cdecl 
#define   __stdcall  
#define   _cdecl 
#define   _stdcall  
#define   __declspec(x)
typedef const char *LPCSTR,*LPSTR;
typedef const wchar_t *LPWSTR,*LPCWSTR;

typedef const TCHAR *PCTSTR, *LPCTSTR;
#define TRUE 1
#define FALSE 0
#define MAX_PATH          260


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#include "pthread.h"
#include "semaphore.h"
#include "unistd.h"
#include "dlfcn.h"
#include "fcntl.h"
#include "sys/time.h"
#include "sys/mman.h"


#define Sleep(X) usleep((X)*1000)
#define GetCurrentThreadId pthread_self
#define FreeLibrary(f) dlclose(f)

#define GetCurrentDirectory(size, path) getcwd((path),(size))
#define SetCurrentDirectory chdir
#define GetCurrentProcessId getpid

inline int GetModuleFileName(HMODULE handle,char* FileName,int Size)
{
	return readlink("/proc/self/exe",FileName,Size);
}


#define HLoadLibrary(P) dlopen((P),RTLD_NOW)
#define HGetCurrentProcessId getpid

#define GetProcAddress dlsym
////////////////////////////////////////////////
#define FileHandle int
#define INVALID_HANDLE_VALUE -1
#define CreateDirectory(x,y) mkdir(x,0755)
inline FileHandle FileOpenForRead(const char *FileName)
{
	FileHandle hFile=open(FileName,O_RDONLY);
	return hFile;
}

inline FileHandle CreateFileForRW(const char *FileName)
{
	FileHandle hFile=open(FileName,O_RDWR);
	return hFile;

}

#define FileWrite(fh,buf,size,rsize) write(fh,buf,size)

#define FileRead(fh,buf,size,rsize) read(fh,buf,size)

#define FileClose(h) close(h)

#define GetFileSize(hFile,X) lseek(hFile,0L,SEEK_END)


#define _vsnprintf_s vsnprintf
#define _vsnprintf   vsnprintf
#define _vstprintf   vsprintf

#define InterlockedIncrement(p) __sync_fetch_and_add((p),1)
#define InterlockedDecrement(p) __sync_fetch_and_sub((p),1)


#define lstrlen(f) strlen(f)
#define lstrlenA(f) strlen(f)

#define _tcscpy strcpy
#define _tcslen strlen

#define _tcscmp strcmp
#define _tcsicmp strcmp
#define _tcscoll strcoll
#define _tcsicoll strcmp

#define _tcspbrk strpbrk
#define _tcsupr strupr
#define _tcslwr strlwr
#define _tcsrev strrev
#define _tcsstr strstr
#define _tcschr strchr
#define _tcsrchr strrchr
#define _tcsncmp strncmp
#define _tcsspn strspn
#define _tcscspn strcspn
#define _ttoi atoi
#define _istdigit isdigit
#define _istspace isspace
#define _tclen(p) 1

#define timeGetTime() clock()

#define TVOID void*
#define RE_NULL 0

#define HCreateThread(p1,p2) \
	({\
		pthread_attr_t  attr; \
		pthread_attr_init(&attr); \
		pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM); \
		pthread_t thread;\
		int err=pthread_create(&thread,&attr,p1,(void*)(p2));\
		if(err!=0)\
		{\
			printf("create thread err for:%s\n",strerror(err));\
			err=-1;\
		}\
		else\
			err=thread;\
		err;\
	})




inline char* _tcsinc(const char *str)
{
	if(*str!='\0')
		str++;
	return (char*)str;
}

inline char* strupr(char *str)
{
	char *org=str;
	for(;*str!='\0';str++)
		*str=toupper(*str);
	return org;
}
inline char* strlwr(char *str)
{
	char *org=str;
	for(;*str!='\0';str++)
		*str=tolower(*str);
	return org;
}
inline char* strrev(char *s)
{
	char *h=s;
	char *t=s;
	char ch=0;
	while(*t++){};
	t--;
	t--;
	while(h<t)
	{
		ch=*h;
		*h++=*t;
		*t--=ch;
	}
	return s;
}
//////////////////////
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr *LPSOCKADDR;

#define SOCKET int
#define WSAGetLastError() errno
#define closesocket(f) close(f)
#define  WSACleanup()
#define SOCKET_ERROR            (-1)
#define  WSAECONNRESET ECONNRESET


#define WAIT_OBJECT_0  0x00000000L

#define WAIT_TIMEOUT   0x00000102L

inline BOOL IsExistPorcess(DWORD pid)
{
	int status;
	pid_t id=pid;
	pid_t re= waitpid(id,&status,WNOHANG);
	if(re==0)
		return 1;
	else
		return 0;
}


/////
#else
#include <crtdbg.h>
#include <tchar.h>
#include <windows.h>
#include <Mmsystem.h>
#include <process.h>   

inline BOOL IsExistPorcess(DWORD pid)
{
	HANDLE h=OpenProcess(PROCESS_DUP_HANDLE ,0,pid);
	if(h)
	{
		CloseHandle(h);
		return 1;
	}
	else
	{
		return 0;
	}
}

inline HMODULE HLoadLibrary(char *P1) 
	{
		extern char debug_release;
		int len=strlen(P1);
		if((P1[len-5]=='d')||(P1[len-5]=='r'))
			P1[len-5]=debug_release;
		return LoadLibraryEx((P1),0,LOAD_WITH_ALTERED_SEARCH_PATH);
	}

#define TVOID void
#define RE_NULL

#define HCreateThread(p1,p2) _beginthread(p1,0,p2)
#define HGetCurrentProcessId GetCurrentProcessId

#define socklen_t int
///////////////////
#define FileHandle HANDLE

inline FileHandle FileOpenForRead(const char *FileName)
{
	FileHandle hFile=CreateFile(FileName,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	return hFile;
}

inline FileHandle CreateFileForRW(const char *FileName)
{
	FileHandle hFile=CreateFile(FileName,GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	return hFile;

}

#define FileWrite(fh,buf,size,rsize) WriteFile(fh,buf,size,rsize,0)

#define FileRead(fh,buf,size,rsize) ReadFile(fh,buf,size,rsize,0)

#define FileClose(h) CloseHandle(h)


/////////////////////
#ifdef _DEBUG
#define HOutputDebugString(f) _CrtDbgReport(0,0,0,0,"%s",f)
#endif
////////

#endif



///////////////////////
#ifdef OSAL_EXPORTS
#define OSAL_API __declspec(dllexport)
#else
#define OSAL_API __declspec(dllimport)
#endif

////////////////////////////////////////////////////////////////////////////
#ifndef __AFX_H__         //afx

#ifdef _DEBUG

#define TRACE      Trace
#define ASSERT(f) assert(f)
#define DEBUG_NEW new(THIS_FILE, __LINE__,1)

OSAL_API void __cdecl Trace(LPCTSTR lpszFormat, ...);
inline BOOL __stdcall IsValidAddress(const void* lp,UINT nBytes, BOOL bReadWrite = TRUE){return 1;};

inline void* __cdecl operator new(size_t nSize, LPCSTR lpszFileName, int nLine,int ver)
{
#ifdef _HDOSE_LINUX
	return malloc(nSize);
#else
	return _malloc_dbg(nSize, _NORMAL_BLOCK, (const char*)lpszFileName, nLine);

#endif
}
inline void* __cdecl operator new[](size_t nSize, LPCSTR lpszFileName, int nLine,int ver)
{
	return ::operator new(nSize, lpszFileName, nLine,ver);
}

inline void __cdecl operator delete(void* pData, LPCSTR lpszFileName, int nLine,int ver)
{

#ifdef _HDOSE_LINUX
	free(pData);
#else
	_free_dbg(pData, _NORMAL_BLOCK);

#endif
}
inline void __cdecl operator delete[](void* pData, LPCSTR lpszFileName, int nLine,int ver)
{
	return ::operator delete(pData, lpszFileName, nLine,ver);
}

#else   // !_DEBUG

#define ASSERT(f)          ((void)0)
inline void _cdecl Trace(LPCTSTR, ...) { }
#define TRACE              1 ? (void)0 : ::Trace

#endif // !_DEBUG

#endif//__AFX_H__
////////////////////////////////////////////////////////////////////////
#ifndef _countof
#define _countof(myarray) (sizeof(myarray)/sizeof(myarray[0]))
#endif // _countof

///////////////////////////////////////////////////////////////////////////////
#define	DeclareTimer(p) extern static CTimeComputer p;
#define StartTimer(p) static CTimeComputer p(#p);
#define TraceTimer(p) p.Trace();
#define TraceExTimer(p) p.TraceEx();

class OSAL_API CTimeComputer
{
	char* name;
	bool bPause;
	unsigned int pausetime;
	unsigned int curpausetime;
	unsigned int time1;
	unsigned int  time2;
public:
	void Modify(int time);
	bool IsPause();
	void Pause();
	void Start();
	CTimeComputer(char *n=0);
	unsigned int Trace();
	unsigned int TraceEx();
};
///////////////////////////////////////////////////////////////////////////////////////////////	
typedef void (__stdcall *TimerFun)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

class OSAL_API CTimeSet
{
	int m_minperiod;
	int m_uid;
	int m_period;

#ifdef _HDOSE_LINUX
	pthread_t m_pthread;
	LPVOID m_para;
	friend void *timethread(void * arg);

#endif////_LINUX_

public:
	void ResetTimer(int period,LPVOID para);
	CTimeSet(int period,TimerFun fun,LPVOID para=0);
	~CTimeSet();
	TimerFun m_lpTimeProc;
};


class OSAL_API CMemFileMap
{
public:
	HANDLE m_fh;
	HANDLE m_map;
	LPVOID m_pAdr;
	int m_size;
	int m_type;//0：内存分配，1：内存映射，2：文件映射
	int m_pos;
	char m_name[32];

	CMemFileMap();
	~CMemFileMap();
	LPVOID CreateFileMap(char* fileName,int size=0);

	LPVOID CreateFileMap(HANDLE fh,int size=0);

	LPVOID CreateFileBufForWrite(char* fileName,int size=(50*1024*2));
	LPVOID CreateMemMap(int size,char* name);
	LPVOID OpenMemMap(int size,char* name);

	BOOL Read(LPVOID buf,DWORD len,DWORD &size);
	BOOL Write(LPVOID buf,DWORD len,DWORD &size);
	void Flush();
	LPVOID GetCurAdr();
	BOOL IsEndof();


};

class OSAL_API CHMutex
{
public:
	DWORD m_threadID;
	BOOL  m_bName;

#ifdef _HDOSE_LINUX
	CMemFileMap m_shm;
	pthread_mutex_t* m_mutex;
#else
	HANDLE m_mutex;
#endif

public:
	CHMutex();
	CHMutex(char* Name);
	~CHMutex();
	BOOL Create(char* Name);
	BOOL Open(char* Name);
	void Lock(unsigned long timeout=-1);
	void UnLock();
};


class OSAL_API CHEvent
{
public:
	BOOL  m_bName;

#ifdef _HDOSE_LINUX
	sem_t* m_id;
#else
	HANDLE m_id;
#endif////_LINUX_

public:
	CHEvent();
	CHEvent(char* Name);
	~CHEvent();
	BOOL Create(char* Name);
	BOOL Open(char* Name);
	DWORD Wait(int timeout=-1);
	void Fire();
	void Reset();
};


#endif//___WINAPI_H__
