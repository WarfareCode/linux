// Model.cpp: implementation of the CModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Model.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_CREATE_EX(CModel,CNode,ClassInit)

BEGIN_EVENTMAP(CModel)

END_EVENTMAP

CModel::CModel()
{
	m_bInitPermit = true;
}

CModel::~CModel()
{

}

void CModel::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CModel)
    AttributeRegister(CModel,bool,bInitPermit);
    AttributeRegister(CModel,long,oldId);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CModel::OnInit()
{
	m_bInitPermit = false;
}

void CModel::tick(double lasttime)
{
// 	CNode::tick(lasttime);
// 	m_lasttime=lasttime;
// 	if(!m_bInitiative)
// 		return;
// 	UpdateAllAttributes();

}

void CModel::Simulation(double lasttime)
{
    if(m_bInitiative)
    {
        if(m_lasttime>=lasttime) return;
        m_lasttime=lasttime;
    }
}

CNode* CModel::GetEntity()
{
	return (CNode*)m_parent;
}

CStateRepository* CModel::GetStateRepository()
{
	return (CStateRepository *)((CNode*)m_parent)->m_pSr;
}

// 20160828,xks
void CModel::SendEntityEvt(CEvt *pEvt)
{	
	pEvt->m_scope = 0;
	pEvt->m_sourceid = m_id;
	pEvt->Send();
}


void CModel::CompressCustomizeData(__out BYTE * & pBuffer, __out int & size)
{
    pBuffer = NULL;
    size=0 ;

    m_oldId = GetID();
}

void CModel::RecoverCustomizeData(__in const BYTE * pBuffer, __in const int size)
{
    if(pBuffer==NULL || size==0)
    {
        return;
    }
}
