//StateRepository.h: interface for the CStateRepository module.
//!!HDOSE_CLASS(CStateRepository,CNode)
//////////////////////////////////////////////////////////////////////

// Note: 1.---
// xks,暂时将m_OpdExtra1作为默认的rcs值（常量），
// 且状态参数m_extra_double1作为临时rcs变量，可在想定文件中重写，也可用默认值
// 计算的时候，二者都可以用，建议用默认值m_OpdExtra1。
// Note: 2.---
// xks,m_OpdEntityType为默认的实体类型码，
// 而m_EntityType是由m_OpdEntityType赋值过去的，是可订阅发布的变量。
// 通常不建议在想定文件中修改m_EntityType。


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

class DATACOM_API CStateRepository /*实体状态池*/: public CNode  
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

	//以下API为远程状态池服务，查找模型或资源
	//因为本地模型或资源可通过实体获得
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
