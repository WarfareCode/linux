//DataRecModel.h: interface for the CDataRecModel module.
//!!HDOSE_CLASS(CDataRecModel,CModel)
//////////////////////////////////////////////////////////////////////

/* Note: xks��20161214
����Ϊ���ݼ�¼ģ�͵Ļ��࣬�������ݼ�¼ģ��Ϊȫ�ֶ������Ϊ�����붨���غ����ݼ�¼����������е����ݣ�
����յ��붨���ص��¼������붨����ʱ�������һ�ε����ݡ�
�����¼�����Ӧ����Ϊ�麯����û��д���κδ������ݣ�����Ӧ����д���պ�Ĵ������ݡ�
*/


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_DataRecModel_H)
#define AFX_DataRecModel_H

#include "Model.h"


//{{HDOSE_CLS_DES(CDataRecModel)
/*
Author:		xks
Version:	1.0
Descript:	ר�������ݼ�¼��ģ�͸���
*/
//}}HDOSE_CLS_DES

class HYCGF_API CDataRecModel /*���ݼ�¼ģ��*/ : public CModel 
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CDataRecModel();
	virtual ~CDataRecModel();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();


	//{{HDOSE_MEMBER_FUNCTION(CDataRecModel)
	//}}HDOSE_MEMBER_FUNCTION

protected:
	//{{HDOSE_EVENT_HANDLER(CDataRecModel)
	virtual void	OnScnReloadEvt(CEvt *pevent);
	//}}HDOSE_EVENT_HANDLER
public:
		
	//{{HDOSE_PARAMETER(CDataRecModel)
	//}}HDOSE_PARAMETER

	//{{HDOSE_ATTRIBUTE(CDataRecModel)
	//}}HDOSE_ATTRIBUTE

};

#endif
