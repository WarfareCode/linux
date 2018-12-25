//FakeTargetData.h: interface for the CFakeTargetData module.
//!!HDOSE_CLASS(CFakeTargetData,)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FakeTargetData_H)
#define AFX_FakeTargetData_H


//{{HDOSE_CLS_DES(CFakeTargetData)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CFakeTargetData /*有源假目标数据*/
{
public:
	CFakeTargetData();
	~CFakeTargetData();
public:
	
	//{{HDOSE_ATTRIBUTE(CFakeTargetData)
	double	m_DelayDist/*延迟距离(m)*/;
	double	m_EchoPower/*反射功率（干扰机产生该假目标时的发射功率）*/;
	double	m_Speed/*速度(m/s)*/;
	long	m_Polarity/*极化（0水平，1垂直，2斜极化，3圆极化，4其它）*/;
	//}}HDOSE_ATTRIBUTE
};
typedef List<DWORD,DWORD> CFakeTargetDataList;
void ReleaseFakeTargetDataList(CFakeTargetDataList* list);

#endif
