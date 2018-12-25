#if !defined(__HDOSE__)
#define __HDOSE__

#include <stdio.h>
#include <stddef.h> 
#include <math.h>
#include <stdlib.h>

#if defined(WIN32)
	#include <process.h>    
	#include <windows.h>
	#include <tchar.h>

	#pragma warning(disable: 4251)
	#pragma warning(disable: 4267)
	#pragma warning(disable: 4996)
	#pragma warning(disable: 4244)


	#ifdef HDOSE_BUILDING
		#define HDOSE_API __declspec(dllexport)
	#else
		#define HDOSE_API __declspec(dllimport)
	#endif
#else
//	#define _HDOSE_LINUX
	#define HDOSE_API
	#define MDB_API
#endif

#include <osal.h>
#include <hfdsexp.h>
#include <Markup.h>
#include <hdef.h>
#include <Obj.h>
#include <Reflection.h>
#include <hdoseexp.h>
#include <Mdb.h>
#include <Evt.h>
#include <Engine.h>
#include <ScnMgr.h>
#include <ParaEntry.h>
#include <hBridge.h>
#include <Disp.h>
#include <Item.h>
#include <Link.h>
#include <Node.h>


#if defined(WIN32)
	#ifdef _DEBUG
		#pragma comment(lib, "osald.lib")
		#pragma comment(lib, "hfdsd.lib")
		#pragma comment(lib, "hdosed.lib")
		#pragma comment(lib, "mdbd.lib")
		#pragma comment(lib, "smdbd.lib")
	#else
		#pragma comment(lib, "osalr.lib")
		#pragma comment(lib, "hfdsr.lib")
		#pragma comment(lib, "hdoser.lib")
		#pragma comment(lib, "mdbr.lib")
		#pragma comment(lib, "smdbr.lib")
	#endif//_DEBUG
#endif//WIN
#endif//__HDOSE__
