//TorpedoBindingParams.cpp: implementation of the CTorpedoBindingParams module.
//!!HDOSE_CLASS(CTorpedoBindingParams,CEvt)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TorpedoBindingParams.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CTorpedoBindingParams,CEvt,ClassInit);


CTorpedoBindingParams::CTorpedoBindingParams()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CTorpedoBindingParams)
	m_RcverId=0;
	m_TargetId=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CTorpedoBindingParams::~CTorpedoBindingParams()
{

}

void CTorpedoBindingParams::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CTorpedoBindingParams)
	AttributeRegister(CTorpedoBindingParams,long,RcverId);
	AttributeRegister(CTorpedoBindingParams,long,TargetId);
	AttributeRegister(CTorpedoBindingParams,CLatLonH,TargetPos);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CTorpedoBindingParams::OnInit()
{
	////CEvt::OnInit();
}






