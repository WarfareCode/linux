//MissileState.h: interface for the CMissileState module.
//!!HDOSE_CLASS(CMissileState,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_MissileState_H)
#define AFX_MissileState_H


//{{HDOSE_CLS_DES(CMissileState)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CMissileState /*����״̬*/
{
public:
	CMissileState();
	~CMissileState();
public:
	
	//{{HDOSE_ATTRIBUTE(CMissileState)
	long	m_MissileNumber/*�������*/;
	long	m_MissileState/*����״̬��׼��0���ɷ���1������2��3�ѷ��䣩*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CMissileStateList;
void ReleaseMissileStateList(CMissileStateList* list);

#endif
