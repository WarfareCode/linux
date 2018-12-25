//EntityStateRep.cpp: implementation of the CNodeStateRep module.
//!!HDOSE_CLASS(CNodeStateRep,CSimObjStateRep)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EntityStateRep.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CNodeStateRep,CSimObjStateRep,ClassInit);


CNodeStateRep::CNodeStateRep()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CNodeStateRep)
	m_Vel=0;
	m_Head=0;
	m_Pitch=0;
	m_Roll=0;
	m_Type=0;
	m_Kind=0;
	m_Country=0;
	m_Category=0;
	m_SubCategory=0;
	m_Specific=0;
	m_extra=0;
	m_RealRCS=0;
	m_RealNoise=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CNodeStateRep::~CNodeStateRep()
{

}

void CNodeStateRep::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CNodeStateRep)
	AttributeRegister(CNodeStateRep,CLatLonH,Pos);
	AttributeRegister(CNodeStateRep,double,Vel);
	AttributeRegister(CNodeStateRep,double,Head);
	AttributeRegister(CNodeStateRep,double,Pitch);
	AttributeRegister(CNodeStateRep,double,Roll);
	AttributeRegister(CNodeStateRep,short,Type);
	AttributeRegister(CNodeStateRep,short,Kind);
	AttributeRegister(CNodeStateRep,short,Country);
	AttributeRegister(CNodeStateRep,short,Category);
	AttributeRegister(CNodeStateRep,short,SubCategory);
	AttributeRegister(CNodeStateRep,short,Specific);
	AttributeRegister(CNodeStateRep,short,extra);
	AttributeRegister(CNodeStateRep,double,RealRCS);
	AttributeRegister(CNodeStateRep,double,RealNoise);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CNodeStateRep::OnInit()
{
	CSimObjStateRep::OnInit();
	CParaEntry* entry=GetOPD();
	if(entry==0)
		return;
	//{{HDOSE_STATIC_PARA_EXTRACT(CNodeStateRep)
	if(!(entry->GetParameterValue("InitRCS")==NULL))
		m_InitRCS=atof(entry->GetParameterValue("InitRCS"));
	if(!(entry->GetParameterValue("InitNoise")==NULL))
		m_InitNoise=atof(entry->GetParameterValue("InitNoise"));
	//}}HDOSE_STATIC_PARA_EXTRACT
}


void CNodeStateRep::OnSetParameter(char *name,char *value)
{
	CSimObjStateRep::OnSetParameter(name,value);
	//{{HDOSE_PARA_EXTRACT(CNodeStateRep)
	if(strcmp(name,"Pos")==0){
		//CLatLonH m_Pos：非基本数据类型，自己定义参数提取算法
		String sPos=value;
		int index1=sPos.Find(',');
		int index2=sPos.ReverseFind(',');

		m_Pos.m_latitude=atof(sPos.Mid(0,index1));
		m_Pos.m_longitude=atof(sPos.Mid(index1+1,index2));
		m_Pos.m_height=atof(sPos.Mid(index2+1,sPos.GetLength()));
	}
	else if(strcmp(name,"Vel")==0){
		m_Vel=(float)atof(value);
	}
	else if(strcmp(name,"Head")==0){
		m_Head=(float)atof(value);
	}
	else if(strcmp(name,"Pitch")==0){
		m_Pitch=(float)atof(value);
	}
	else if(strcmp(name,"Roll")==0){
		m_Roll=(float)atof(value);
	}
	else if(strcmp(name,"Type")==0){
		m_Type=atoi(value);
	}
	else if(strcmp(name,"Kind")==0){
		m_Kind=atoi(value);
	}
	else if(strcmp(name,"Country")==0){
		m_Country=atoi(value);
	}
	else if(strcmp(name,"Category")==0){
		m_Category=atoi(value);
	}
	else if(strcmp(name,"SubCategory")==0){
		m_SubCategory=atoi(value);
	}
	else if(strcmp(name,"Specific")==0){
		m_Specific=atoi(value);
	}
	else if(strcmp(name,"extra")==0){
		m_extra=atoi(value);
	}
	else if(strcmp(name,"RealRCS")==0){
		m_RealRCS=(float)atof(value);
	}
	else if(strcmp(name,"RealNoise")==0){
		m_RealNoise=(float)atof(value);
	}
	//}}HDOSE_PARA_EXTRACT
}

void CNodeStateRep::OnClose()
{
	CSimObjStateRep::OnClose();
}

void CNodeStateRep::tick(double lasttime)
{
	CSimObjStateRep::tick(lasttime);
}

void CNodeStateRep::Simulation(double lasttime)
{
	CSimObjStateRep::Simulation(lasttime);
}

void CNodeStateRep::Output()
{
	CSimObjStateRep::Output();
}



