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

class HYCGF_API CInfraredDataStruct /*�������ݽṹ*/
{
public:
	CInfraredDataStruct();
	~CInfraredDataStruct();
public:
	
	//{{HDOSE_ATTRIBUTE(CInfraredDataStruct
	long	m_Mode/*����ģʽ(1������2�����ⲿ�ļ�)*/;
	double	m_Value/*�������ǿ��*/;
	long	m_extra1/*���Ӳ���1*/;
	double	m_extra2/*���Ӳ���2*/;
	long	m_Para1/*���Ӳ���3*/;
	double	m_Para2/*���Ӳ���4*/;
	//}}HDOSE_ATTRIBUTE
};

// ֻҪ���õ�CInfraredDataStructListʱ������֮������ص���ReleaseInfraredDataStructList(CInfraredDataStructList* list)�����ͷ�����ڴ�
typedef List<DWORD,DWORD> CInfraredDataStructList;
void ReleaseInfraredDataStructList(CInfraredDataStructList* list);	// ɾ����������new��CInfraredDataStruct*��


#endif
