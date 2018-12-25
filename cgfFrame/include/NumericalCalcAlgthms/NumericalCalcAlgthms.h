//////////////////////////////////////////////////////////////////////
// Algthms.h
//
// 算法库通用头文件。请在需调用的工作文件中包含此文件。
//
// xiekongshu编制, 2002/8
//////////////////////////////////////////////////////////////////////

#ifndef ____NUMERICALCALCALGTHMS_LIB_HEADER_____
#define ____NUMERICALCALCALGTHMS_LIB_HEADER_____

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <ctype.h>
#include <wchar.h>

#include <math.h>
#include <float.h>
#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>

// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <string>

#if !defined(_WIN32)
#define NUMERICALCALCALGTHMS_API
#elif defined(NumericalCalcAlgthms_EXPORTS)
#define NUMERICALCALCALGTHMS_API __declspec(dllexport)
#else
#define NUMERICALCALCALGTHMS_API __declspec(dllimport)
#endif


// 定义_NUMERICALCALCALGTHMS_OSAL预编译开关，是为了防止下述的定义与其它头文件中的定义冲突
#ifdef _NUMERICALCALCALGTHMS_OSAL  

#ifndef _DEBUG
#define HOutputDebugString(f) ((void)0)
#endif

#ifdef _NUMERICALCALCALGTHMS_LINUX
#ifdef _DEBUG
#define HOutputDebugString(f) std::cout<<f
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef unsigned int        UINT;
typedef void *LPVOID;
typedef void *HANDLE;

typedef void *HMODULE;

typedef void *HINSTANCE;
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

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define _vsnprintf_s vsnprintf
#define _vsnprintf   vsnprintf
#define _vstprintf   vsprintf

/////
#else
#include <crtdbg.h>
#include <tchar.h>
#include <windows.h>
#include <Mmsystem.h>

/////////////////////
#ifdef _DEBUG
#define HOutputDebugString(f) _CrtDbgReport(0,0,0,0,"%s",f)
#endif
////////

#endif

////////////////////////////////////////////////////////////////////////////
#ifndef __AFX_H__         //afx

#ifdef _DEBUG

#define TRACE      Trace
#define ASSERT(f) assert(f)
#define DEBUG_NEW new(THIS_FILE, __LINE__,1)

void __cdecl Trace(LPCTSTR lpszFormat, ...);
inline BOOL __stdcall IsValidAddress(const void* lp,UINT nBytes, BOOL bReadWrite = TRUE){return 1;};

inline void* __cdecl operator new(size_t nSize, LPCSTR lpszFileName, int nLine,int ver)
{
#ifdef _NUMERICALCALCALGTHMS_LINUX
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

#ifdef _NUMERICALCALCALGTHMS_LINUX
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

#endif

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif


#endif // #ifndef ____NUMERICALCALCALGTHMS_LIB_HEADER_____
