#ifndef ___BW_BASE_API_H___
#define ___BW_BASE_API_H___
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
#define BW_CAL_API
#elif defined(BW_CAL_EXPORTS)
#define BW_CAL_API __declspec(dllexport)
#else
#define BW_CAL_API __declspec(dllimport)
#endif

// 定义_BWCAL_OSAL预编译开关，是为了防止下述的定义与其它头文件中的定义冲突
#ifdef _BWCAL_OSAL  

#ifndef _DEBUG
#define HOutputDebugString(f) ((void)0)
#endif

#ifdef _BWCAL_LINUX
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

BW_CAL_API void __cdecl Trace(LPCTSTR lpszFormat, ...);
inline BOOL __stdcall IsValidAddress(const void* lp,UINT nBytes, BOOL bReadWrite = TRUE){return 1;};

inline void* __cdecl operator new(size_t nSize, LPCSTR lpszFileName, int nLine,int ver)
{
#ifdef _BWCAL_LINUX
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

#ifdef _BWCAL_LINUX
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

#define DOUBLE_MAX		  DBL_MAX
//defines constant for singular determination
#define DOUBLE_EPSILON    DBL_EPSILON

#define TOLERANT_ERROR    1.0e-12     //admissable iteration error

#define MAX_ITERATETIME   30          //the maximum iteration times

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

namespace BwCal
{
	typedef double Real;

#define PI  3.14159265358979323846
#define  PI_2		6.28318530717958647692			// 2π
#define  PI_1_2		1.57079632679489661923			// π/2
#define  PI_1_4		0.785398163397448309615		// π/4
#define	Deg2Rad     1.74532925199432957692e-2L		/* (M_PI/180)*/
#define	Rad2Deg     5.72957795130823208768e+1L		/* (180/M_PI)*/

	// 长度单位换算
#define NMile2Km(x)	( x * 1.852)   // 海里到公里
#define Km2NMile(x)	( x / 1.852) // 公里以海里
#define Mile2Km(x)		( x * 1.609344) //英里到公里
#define Km2Mile(x)		( x / 1.609344)	// 公里到英里
#define Feet2Meter(x)	( x * 0.3048)	// 英尺到米
#define Meter2Feet(x)	( x / 0.3048) // 米到英尺
#define Yard2Meter(x)	( x * 0.9144)	// 码到米
#define Meter2Yard(x)	( x / 0.9144)	// 米到码
#define	Cab2Km(x)		( x * 0.1852)	// 链到公里， 航海中的1链等于1/10海里
#define Km2Cab(x)		( x / 0.1852) //公里到链

	// 速度单位换算
#define Ms2Kh(x)		( x * 3.6)	// 米/秒到公里/小时
#define Kh2Ms(x)		( x / 3.6)	// 公里/小时到米/秒
#define Kn2Kh(x)		( x * 1.852) // 节到公里/小时， 1节(kn或kt)等于1海里/小时
#define Kh2Kn(x)		( x / 1.852) // 公里/小时到节
#define Kn2Ms(x)		( x * 0.5144)	// 节到米/秒
#define Ms2Kn(x)		( x / 0.5144)	// 米/秒到节
#define Ma2Ms(x)	( x * 340.3) // 马赫到米/秒
#define Ms2Ma(x)	( x / 340.3)	// 米/秒到马赫
}


#endif
