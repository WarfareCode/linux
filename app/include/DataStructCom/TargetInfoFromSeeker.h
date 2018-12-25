//TargetInfoFromSeeker.h: interface for the CTargetInfoFromSeeker module.
//!!HDOSE_CLASS(CTargetInfoFromSeeker,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_TargetInfoFromSeeker_H)
#define AFX_TargetInfoFromSeeker_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CTargetInfoFromSeeker)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CTargetInfoFromSeeker /*����ͷ�����Ŀ����Ϣ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CTargetInfoFromSeeker();
	virtual ~CTargetInfoFromSeeker();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetInfo(CTargetData *val){
		for(int i=0;i<10;i++)
			m_TargetInfo[i]=val[i];
	}
	CTargetData*	GetTargetInfo(){return m_TargetInfo;}
	void	SetTargetCount(long val){m_TargetCount=val;}
	long	GetTargetCount(){return m_TargetCount;}
	void	SetTargetNo(long val){m_TargetNo=val;}
	long	GetTargetNo(){return m_TargetNo;}

	//{{HDOSE_MEMBER_FUNCTION(CTargetInfoFromSeeker)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CTargetInfoFromSeeker)
	CTargetData	m_TargetInfo[10]/*Ŀ�����ݣ�100��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_TargetCount/*Ŀ����������100����*/;
	long	m_TargetNo/*Ҫ������Ŀ��ı�ţ����յ�������������Ҫ�õ��ϵģ�*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
