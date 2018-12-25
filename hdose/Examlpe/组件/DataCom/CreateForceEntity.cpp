//CreateForceEntity.cpp: implementation of the CCreateForceEntity module.
//!!HDOSE_CLASS(CCreateForceEntity,CEvt)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CreateForceEntity.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CCreateForceEntity,CEvt,ClassInit);


CCreateForceEntity::CCreateForceEntity()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CCreateForceEntity)
	m_EntityClassName=0;//new char[MAX_CHARLEN];
	m_strName=0;//new char[MAX_CHARLEN];
	m_SimObjId=0;
	m_Type=0;
	m_Kind=0;
	m_Country=0;
	m_Category=0;
	m_SubCategory=0;
	m_Specific=0;
	m_extra=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CCreateForceEntity::~CCreateForceEntity()
{

}

void CCreateForceEntity::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CCreateForceEntity)
	AttributeRegister(CCreateForceEntity,char*,EntityClassName);
	AttributeRegister(CCreateForceEntity,char*,strName);
	AttributeRegister(CCreateForceEntity,long,SimObjId);
	AttributeRegister(CCreateForceEntity,CLatLonH,Pos);
	AttributeRegister(CCreateForceEntity,short,Type);
	AttributeRegister(CCreateForceEntity,short,Kind);
	AttributeRegister(CCreateForceEntity,short,Country);
	AttributeRegister(CCreateForceEntity,short,Category);
	AttributeRegister(CCreateForceEntity,short,SubCategory);
	AttributeRegister(CCreateForceEntity,short,Specific);
	AttributeRegister(CCreateForceEntity,short,extra);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CCreateForceEntity::OnInit()
{
	//CEvt::OnInit();
}






