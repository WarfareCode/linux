//StateRepository.h: interface for the CStateRepository module.
//!!HDOSE_CLASS(CStateRepository,CNode)
//////////////////////////////////////////////////////////////////////

// Note: 1.---
// xks,��ʱ��m_OpdExtra1��ΪĬ�ϵ�rcsֵ����������
// ��״̬����m_extra_double1��Ϊ��ʱrcs�����������붨�ļ�����д��Ҳ����Ĭ��ֵ
// �����ʱ�򣬶��߶������ã�������Ĭ��ֵm_OpdExtra1��
// Note: 2.---
// xks,m_OpdEntityTypeΪĬ�ϵ�ʵ�������룬
// ��m_EntityType����m_OpdEntityType��ֵ��ȥ�ģ��ǿɶ��ķ����ı�����
// ͨ�����������붨�ļ����޸�m_EntityType��


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(AFX_StateRepository_H)
#define AFX_StateRepository_H


// class CNode;
// class Resource;
class CModel;

//{{HDOSE_CLS_DES(CStateRepository)
/*
Author:		
Version:	1.0
Descript:	
*/
//}}HDOSE_CLS_DES

class DATACOM_API CStateRepository /*ʵ��״̬��*/: public CNode  
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;
public:
	CStateRepository();
	virtual ~CStateRepository();
	static	void ClassInit(ClassInfo *clsinfo);
	
	virtual	void OnInit();

	virtual void SetValueString(char *att_name,char* pstr);
	
	virtual void OnSetParameter(char *name,char *value);
	virtual void OnClose();
	virtual	void tick(double lasttime);
	virtual void Simulation(double lasttime);
	virtual void Output();

	//CNode*	GetEntity();

	//����APIΪԶ��״̬�ط��񣬲���ģ�ͻ���Դ
	//��Ϊ����ģ�ͻ���Դ��ͨ��ʵ����
	//Resource*	LookupResource(char* name);
	//void		LookupResources(CULongArray& reses,char* type=0);
	//void        LookupAllResources(CULongArray & resourceArray);
	void		LookupModels(CULongArray& models,char* type=0);
	CModel*		LookupModel(char* className);
	//CModel*		LookupModel(char* name);
	char *m_modelIDs;

public:
	bool m_bInitPermit;
	long m_oldId;

};

#endif
