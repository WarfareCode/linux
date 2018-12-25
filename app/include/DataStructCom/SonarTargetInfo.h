//SonarTargetInfo.h: interface for the CSonarTargetInfo module.
//!!HDOSE_CLASS(CSonarTargetInfo,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_SonarTargetInfo_H)
#define AFX_SonarTargetInfo_H

#include "TargetData.h"

//{{HDOSE_CLS_DES(CSonarTargetInfo)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CSonarTargetInfo /*����Ŀ��ָʾ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CSonarTargetInfo();
	virtual ~CSonarTargetInfo();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetTargetInstructInfo(CTargetData val[]){
		for(int i=0;i<100;i++)
			m_TargetInstructInfo[i]=val[i];}
	CTargetData*	GetTargetInstructInfo(){return m_TargetInstructInfo;}
	void	SetTargetCount(long val){m_TargetCount=val;}
	long	GetTargetCount(){return m_TargetCount;}

	//{{HDOSE_MEMBER_FUNCTION(CSonarTargetInfo)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CSonarTargetInfo)
	CTargetData	m_TargetInstructInfo[100]/*Ŀ��ָʾ��Ϣ��100��Ԫ�ص����飬Ҫ�޸ģ�*/;
	long	m_TargetCount/*Ŀ����Ϣ���������100����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
