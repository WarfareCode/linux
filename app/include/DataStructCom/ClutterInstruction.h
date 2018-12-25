//ClutterInstruction.h: interface for the CClutterInstruction module.
//!!HDOSE_CLASS(CClutterInstruction,CEvt)
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_ClutterInstruction_H)
#define AFX_ClutterInstruction_H

#include "ClutterData.h"

//{{HDOSE_CLS_DES(CClutterInstruction)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATASTRUCTCOMPONENTDLL_API CClutterInstruction /*�Ӳ�����ָʾ*/ : public CEvt 
{
	DECLARE_CREATE;
public:
	CClutterInstruction();
	virtual ~CClutterInstruction();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	void	SetbClutterInstruction(bool val){m_bClutterInstruction=val;}
	bool	GetbClutterInstruction(){return m_bClutterInstruction;}
	void	SetClutterJammingInfo(CClutterData val[10]){
		for(int i=0;i<10;i++)
			m_ClutterJammingInfo[i]=val[i];
	}
	CClutterData*	GetClutterJammingInfo(){return m_ClutterJammingInfo;}
	void	SetClutterJammingInfoCount(long val){m_ClutterJammingInfoCount=val;}
	long	GetClutterJammingInfoCount(){return m_ClutterJammingInfoCount;}

	//{{HDOSE_MEMBER_FUNCTION(CClutterInstruction)
	//}}HDOSE_MEMBER_FUNCTION

public:
	
	//{{HDOSE_ATTRIBUTE(CClutterInstruction)
	bool	m_bClutterInstruction/*�Ӳ�����״ָ̬ʾ��0�ޣ�1�У�*/;
	CClutterData	m_ClutterJammingInfo[10]/*�Ӳ�������Ϣ��10��Ԫ�ص����飩*/;
	long	m_ClutterJammingInfoCount/*�Ӳ�������Ϣ���������10����*/;
	//}}HDOSE_ATTRIBUTE
};

#endif
