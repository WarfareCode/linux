//StateRepository.cpp: implementation of the CStateRepository module.
//!!HDOSE_CLASS(CStateRepository,CStateRepository)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StateRepository.h"
//#include "Model.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_CREATE_EX(CStateRepository,CNode,ClassInit);

BEGIN_EVENTMAP(CStateRepository)

END_EVENTMAP

CStateRepository::CStateRepository()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CStateRepository)

	m_modelIDs=0;
	m_bInitPermit = true;

	
}

CStateRepository::~CStateRepository()
{

}

void CStateRepository::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CStateRepository)


	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CStateRepository::OnInit()
{
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CStateRepository)
	

	//}}HDOSE_STATIC_PARA_EXTRACT
}


void CStateRepository::OnSetParameter(char *name,char *value)
{
	//{{HDOSE_PARA_EXTRACT(CStateRepository)

	// »ù±¾ÊôÐÔ
	
	//}}HDOSE_PARA_EXTRACT
}

void CStateRepository::OnClose()
{
}
/*
CNode* CStateRepository::GetEntity()
{
	if(!m_bInitiative)
		return 0;		
	return (CNode*)m_parent;
}

Resource* CStateRepository::LookupResource(char* name)
{
	if(m_modelIDs==0)
		return 0;
	char buf[1024];
	strcpy(buf,m_modelIDs);
	char idStr[32];
	while(1){
		if(!ExtractStrItem(buf,idStr,','))
			break;
		long id=atoi(idStr);
		CObj* pObj=m_pEngine->LookupObj(id);
		if(pObj&&pObj->IsDrivedFrom("Resource")){
			Resource* res=(Resource*)pObj;
			if(res->IsNameMatching(name))
				return res;
		}
	}

	return 0;
}

void CStateRepository::LookupResources(CULongArray& reses,char* type)
{
	reses.RemoveAll();
	if(m_modelIDs==0)
		return;
	char buf[1024];
	strcpy(buf,m_modelIDs);
	char idStr[32];
	while(1){
		if(!ExtractStrItem(buf,idStr,','))
			break;
		long id=atoi(idStr);
		CObj* pObj=m_pEngine->LookupObj(id);
		if(pObj&&pObj->IsDrivedFrom("Resource")){
			Resource* res=(Resource*)pObj;
			if(res->IsTypeMatching(type))
				reses.Add((DWORD)res);
		}
	}
}


void CStateRepository::LookupAllResources(CULongArray & resourceArray)
{
    resourceArray.RemoveAll();
    if (m_modelIDs == 0)
    {
        return;
    }

    char buf[1024];
    strcpy(buf, m_modelIDs);
    char idStr[32];

    while (1)
    {
        if (!ExtractStrItem(buf, idStr, ','))
        {
            break;
        }

        long id = atoi(idStr);

        CObj * pObj = m_pEngine->LookupObj(id);

        if (pObj && pObj->IsDrivedFrom("Resource"))
        {
            resourceArray.Add((DWORD)pObj);
        }
    }
}
*/

CModel* CStateRepository::LookupModel(char* className)
{

 	POSITION pos=((CLink *)m_parent)->m_agtlist.GetHeadPosition();
	while(pos)
	{
		CObj *pModle=((CLink *)m_parent)->m_agtlist.GetNext(pos);
		if (pModle)
		{
			ClassInfo *pInfo=pModle->GetClsInfo();
			if (!strcmp(pInfo->className,className))
			{
				return (CModel*)pModle;
			}
		}
	}

 	return 0;
}

void CStateRepository::LookupModels(CULongArray& models,char* type)
{
// 	models.RemoveAll();
// 	if(m_modelIDs==0)
// 		return;
// 	char buf[1024];
// 	strcpy(buf,m_modelIDs);
// 	char idStr[32];
// 	while(1){
// 		if(!ExtractStrItem(buf,idStr,','))
// 			break;
// 		long id=atoi(idStr);
// 		CObj* pObj=m_pEngine->LookupObj(id);
// 		if(pObj&&pObj->IsDrivedFrom("CModel")){
// 			if(type==0)
// 				models.Add((DWORD)pObj);
// 			else if(pObj->IsDrivedFrom(type))
// 				models.Add((DWORD)pObj);
// 		}
// 	}
}

void CStateRepository::SetValueString(char *att_name,char* pstr)
{
	/*if(strcmp(att_name,"modelIDs")==0)
	{
		m_modelIDs=new char[MAX_CHARLEN];
		strcpy(m_modelIDs,pstr);
	}
	else*/
		CNode::SetValueString(att_name,pstr);
}


void CStateRepository::tick(double lasttime)
{
	if(!m_bInitiative)
		return;

	//UpdateAllAttributes();
}

void CStateRepository::Simulation(double lasttime)
{
}

void CStateRepository::Output()
{
}



