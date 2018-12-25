//LineObj.cpp: implementation of the CLineObj module.
//!!HDOSE_CLASS(CLineObj,CControlObj)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LineObj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_CREATE_EX(CLineObj,CNode,ClassInit);


CLineObj::CLineObj()
{ 
	//{{HDOSE_ATTRIBUTE_INIT(CLineObj)
	m_PointsCount=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CLineObj::~CLineObj()
{

}

void CLineObj::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CLineObj)
	AttributeRegister(CLineObj,int,PointsCount);
	AttributeRegister(CLineObj,CLatLonH[10],Points);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

void CLineObj::OnInit()
{
	if(!m_bInitiative)
		return;
	CNode::OnInit();

}


void CLineObj::OnSetParameter(char *name,char *value)
{
	if(!m_bInitiative)
		return;
	CNode::OnSetParameter(name,value);
	if(strcmp(name,"PointsCount")==0){
		m_PointsCount=atoi(value);
	}
	else if(strcmp(name,"Points")==0){
		String str=value;
		int Num=0;
		int nStart=0;
		int pos=str.Find(';',nStart);
		while(pos!=-1)
		{
			int index1=str.Find(',',nStart);
			int index2=str.Find(',',index1+1);

			m_Points[Num].m_latitude=atof(str.Mid(nStart,index1));
			m_Points[Num].m_longitude=atof(str.Mid(index1+1,index2));
			m_Points[Num].m_height=atof(str.Mid(index2+1,pos));
			nStart=pos+1;
			pos=str.Find(';',nStart);
			Num++;
		}

	}
	
}

void CLineObj::OnClose()
{
	if(!m_bInitiative)
		return;
	CNode::OnClose();
}

void CLineObj::tick(double lasttime)
{
	if(!m_bInitiative)
		return;
	CNode::tick(lasttime);
}

void CLineObj::Simulation(double lasttime)
{
	if(!m_bInitiative)
		return;
	CNode::Simulation(lasttime);
}

void CLineObj::Output()
{
	if(!m_bInitiative)
		return;
	CNode::Output();
}



