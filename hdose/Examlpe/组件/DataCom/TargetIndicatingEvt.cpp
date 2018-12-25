//TargetIndicatingEvt.cpp: implementation of the CTargetIndicatingEvt module.
//!!HDOSE_CLASS(CTargetIndicatingEvt,CEvt)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TargetIndicatingEvt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CTargetIndicatingEvt,CEvt,ClassInit);


CTargetIndicatingEvt::CTargetIndicatingEvt()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CTargetIndicatingEvt)
	m_TargetCount=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CTargetIndicatingEvt::~CTargetIndicatingEvt()
{

}

void CTargetIndicatingEvt::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CTargetIndicatingEvt)
	AttributeRegister(CTargetIndicatingEvt,long,TargetCount);
	AttributeRegister(CTargetIndicatingEvt,CTargetData[10],TargetInfo);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CTargetIndicatingEvt::OnInit()
{
	////CEvt::OnInit();
}






