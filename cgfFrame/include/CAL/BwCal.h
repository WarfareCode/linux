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

// ����_BWCAL_OSALԤ���뿪�أ���Ϊ�˷�ֹ�����Ķ���������ͷ�ļ��еĶ����ͻ
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
#define  PI_2		6.28318530717958647692			// 2��
#define  PI_1_2		1.57079632679489661923			// ��/2
#define  PI_1_4		0.785398163397448309615		// ��/4
#define	Deg2Rad     1.74532925199432957692e-2L		/* (M_PI/180)*/
#define	Rad2Deg     5.72957795130823208768e+1L		/* (180/M_PI)*/

	// ���ȵ�λ����
#define NMile2Km(x)	( x * 1.852)   // ���ﵽ����
#define Km2NMile(x)	( x / 1.852) // �����Ժ���
#define Mile2Km(x)		( x * 1.609344) //Ӣ�ﵽ����
#define Km2Mile(x)		( x / 1.609344)	// ���ﵽӢ��
#define Feet2Meter(x)	( x * 0.3048)	// Ӣ�ߵ���
#define Meter2Feet(x)	( x / 0.3048) // �׵�Ӣ��
#define Yard2Meter(x)	( x * 0.9144)	// �뵽��
#define Meter2Yard(x)	( x / 0.9144)	// �׵���
#define	Cab2Km(x)		( x * 0.1852)	// ������� �����е�1������1/10����
#define Km2Cab(x)		( x / 0.1852) //���ﵽ��

	// �ٶȵ�λ����
#define Ms2Kh(x)		( x * 3.6)	// ��/�뵽����/Сʱ
#define Kh2Ms(x)		( x / 3.6)	// ����/Сʱ����/��
#define Kn2Kh(x)		( x * 1.852) // �ڵ�����/Сʱ�� 1��(kn��kt)����1����/Сʱ
#define Kh2Kn(x)		( x / 1.852) // ����/Сʱ����
#define Kn2Ms(x)		( x * 0.5144)	// �ڵ���/��
#define Ms2Kn(x)		( x / 0.5144)	// ��/�뵽��
#define Ma2Ms(x)	( x * 340.3) // ��յ���/��
#define Ms2Ma(x)	( x / 340.3)	// ��/�뵽���
}


#endif
