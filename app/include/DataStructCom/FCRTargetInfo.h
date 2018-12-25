//FCRTargetInfo.h: interface for the CFCRTargetInfo module.
//!!HDOSE_CLASS(CFCRTargetInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_FCRTargetInfo_H)
#define AFX_FCRTargetInfo_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CFCRTargetInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CFCRTargetInfo /*����״�Ŀ��ָʾ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CFCRTargetInfo();
	virtual ~CFCRTargetInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetInstructInfo(CTargetData val[100]){
		for(int i=0;i<100;i++)
			m_TargetInstructInfo[i]=val[i];
	}
	CTargetData*	GetTargetInstructInfo(){return m_TargetInstructInfo;}
	void	SetTargetCount(long val){m_TargetCount=val;}
	long	GetTargetCount(){return m_TargetCount;}

	//{{HDOSE_MEMBER_FUNCTION(CFCRTargetInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CFCRTargetInfo)
	CTargetData	m_TargetInstructInfo[100]/*Ŀ��ָʾ��Ϣ��100��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_TargetCount/*Ŀ����������100����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
