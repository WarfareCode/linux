//CreateCtrlObj.cpp: implementation of the CCreateCtrlObj module.
//!!HDOSE_CLASS(CCreateCtrlObj,CEvt)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CreateCtrlObj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CCreateCtrlObj,CEvt,ClassInit);


CCreateCtrlObj::CCreateCtrlObj()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CCreateCtrlObj)
	m_CtrlObjClassName=0;//new char[MAX_CHARLEN];
	m_strName=0;//new char[MAX_CHARLEN];
	m_SimObjId=0;
	m_LinePointsCount=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CCreateCtrlObj::~CCreateCtrlObj()
{

}

void CCreateCtrlObj::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CCreateCtrlObj)
	AttributeRegister(CCreateCtrlObj,char*,CtrlObjClassName);
	AttributeRegister(CCreateCtrlObj,char*,strName);
	AttributeRegister(CCreateCtrlObj,long,SimObjId);
	AttributeRegister(CCreateCtrlObj,long,LinePointsCount);
	AttributeRegister(CCreateCtrlObj,CLatLonH[10],LinePoints);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CCreateCtrlObj::OnInit()
{
	//CEvt::OnInit();
}






