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

class DATASTRUCTCOMPONENTDLL_API CMissileState /*导弹状态*/
{
public:
	CMissileState();
	~CMissileState();
public:
	
	//{{HDOSE_ATTRIBUTE(CMissileState)
	long	m_MissileNumber/*导弹编号*/;
	long	m_MissileState/*导弹状态（准备0，可发射1，故障2，3已发射）*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CMissileStateList;
void ReleaseMissileStateList(CMissileStateList* list);

#endif
