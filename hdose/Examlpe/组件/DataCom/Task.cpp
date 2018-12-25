// Task.cpp: implementation of the CTask class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Task.h"

IMPLEMENT_CREATE_EX(CTask,CEvt,ClassInit)
IMPLEMENT_CREATE_EX(CSetDataRequest,CTask,ClassInit)
//////////////////////////////////////////////////////////////////////
// CTask
//////////////////////////////////////////////////////////////////////

long currentTaskId=1;
 
CTask::CTask()
{
	m_taskId=currentTaskId;
	currentTaskId++; 
	//m_desclsname="CTaskController";
	m_recver=-1;
}

CTask::~CTask()
{

}

void CTask::ClassInit(ClassInfo *clsinfo)
{
	AttributeRegister(CTask,short,cmdRole);
	AttributeRegister(CTask,long,taskId);
	AttributeRegister(CTask,long,recver);
}


BOOL CTask::MatchRecver(long ref)
{
	if(m_recver<0)
		return 1;
	return m_recver==ref;
}
//////////////////////////////////////////////////////////////////////
// CSetDataRequest
//////////////////////////////////////////////////////////////////////
void CSetDataRequest::ClassInit(ClassInfo *clsinfo)
{
	AttributeRegister(CSetDataRequest,char*,fieldName);
	AttributeRegister(CSetDataRequest,char*,value);
}

CSetDataRequest::CSetDataRequest()
{
	m_desclsname="CSDRController";
}

void CSetDataRequest::OnSetParameter(int idx,char *value)
{
	switch(idx){
	case 0:strcpy(m_fieldName,value);break;
	case 1:strcpy(m_value,value);break;
	default:
		strcat(m_value,",");
		strcat(m_value,value);
		break;
	}
}

PlanStr	CSetDataRequest::FormatParaStr()
{
	PlanStr ret;
	ret.Format("%s,%s",m_fieldName,m_value);
	return ret;
}