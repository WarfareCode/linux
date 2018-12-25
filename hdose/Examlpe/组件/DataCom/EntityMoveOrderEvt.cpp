//EntityMoveOrderEvt.cpp: implementation of the CNodeMoveOrderEvt module.
//!!HDOSE_CLASS(CNodeMoveOrderEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EntityMoveOrderEvt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CNodeMoveOrderEvt,CEvt,ClassInit);


CNodeMoveOrderEvt::CNodeMoveOrderEvt()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CNodeMoveOrderEvt)
	m_MoveType=0;
	m_RouteId=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CNodeMoveOrderEvt::~CNodeMoveOrderEvt()
{

}

void CNodeMoveOrderEvt::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CNodeMoveOrderEvt)
	AttributeRegister(CNodeMoveOrderEvt,short,MoveType);
	AttributeRegister(CNodeMoveOrderEvt,long,RouteId);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CNodeMoveOrderEvt::OnInit()
{
	//CEvt::OnInit();
}






