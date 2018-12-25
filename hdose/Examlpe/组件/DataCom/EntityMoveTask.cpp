//EntityMoveTask.cpp: implementation of the CNodeMoveTask module.
//!!HDOSE_CLASS(CNodeMoveTask,CTask)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EntityMoveTask.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CNodeMoveTask,CTask,ClassInit);


CNodeMoveTask::CNodeMoveTask()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CNodeMoveTask)
	m_RecieverId=0;
	m_MoveType=0;
	m_RouteId=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CNodeMoveTask::~CNodeMoveTask()
{

}

void CNodeMoveTask::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CNodeMoveTask)
	AttributeRegister(CNodeMoveTask,long,RecieverId);
	AttributeRegister(CNodeMoveTask,short,MoveType);
	AttributeRegister(CNodeMoveTask,long,RouteId);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CNodeMoveTask::OnInit()
{
	//CTask::OnInit();
}






