//InfraredDataStruct.h: interface for the CInfraredDataStruct module.
//!!HDOSE_CLASS(CInfraredDataStruct,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_InfraredDataStruct_H)
#define AFX_InfraredDataStruct_H

#include "CGFDS.h"

//{{HDOSE_CLS_DES(CInfraredDataStruct)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class HYCGF_API CInfraredDataStruct /*红外数据结构*/
{
public:
	CInfraredDataStruct();
	~CInfraredDataStruct();
public:
	
	//{{HDOSE_ATTRIBUTE(CInfraredDataStruct
	long	m_Mode/*数据模式(1常量、2依赖外部文件)*/;
	double	m_Value/*红外辐射强度*/;
	long	m_extra1/*附加参数1*/;
	double	m_extra2/*附加参数2*/;
	long	m_Para1/*附加参数3*/;
	double	m_Para2/*附加参数4*/;
	//}}HDOSE_ATTRIBUTE
};

// 只要是用到CInfraredDataStructList时，用完之后请务必调用ReleaseInfraredDataStructList(CInfraredDataStructList* list)函数释放相关内存
typedef List<DWORD,DWORD> CInfraredDataStructList;
void ReleaseInfraredDataStructList(CInfraredDataStructList* list);	// 删除链表中所new的CInfraredDataStruct*项


#endif
