//Country.cpp: implementation of the CCountry module.
//!!HDOSE_CLASS(CCountry,CNode)
//////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Country.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;
IMPLEMENT_CREATE_EX(CCountry,CNode,ClassInit);

BEGIN_EVENTMAP(CCountry)
	//{{HDOSE_EVENT_MAP(CCountry)
	ON_HDOSEEVENT("CCommunication",CCountry::OnCCommunication)
	//}}HDOSE_EVENT_MAP
END_EVENTMAP

void CCountry::ClassInit(ClassInfo *clsinfo)
{
	//{{HDOSE_ATTRIBUTE_REGISTER(CCountry)
	AttributeRegister(CCountry,double,Population);
	AttributeRegister(CCountry,char*,Name);
	//}}HDOSE_ATTRIBUTE_REGISTER
}

CCountry::CCountry()
{ 
	m_periodicMessage = 0;
	ms_growthRate=0.001;
	//{{HDOSE_ATTRIBUTE_INIT(CCountry)
	m_Population=10000;
	m_Name=0;
	//}}HDOSE_ATTRIBUTE_INIT
}

CCountry::~CCountry()
{
	m_Name=0;
}

void CCountry::OnInit()
{
	CNode::OnInit();
	char sName[20];
	memset(sName,0,20);
	memcpy(sName,"Country_",8);

	strcat(sName,GetName());
	SetValueString("Name",sName);
}

void CCountry::OnClose()
{
	CNode::OnClose();
}

void CCountry::tick(double lasttime)
{
	CNode::tick(lasttime);
	if(!m_bInitiative)
		return;

	m_Population+=m_Population*ms_growthRate;
	CObjList *pList=m_pEngine->LookupObjFromClass("CCountry");

	if ((pList->GetCount()>=2)&&((m_periodicMessage++%10) == 0 ) )//当有其它的CCountry对象才发送CCommunication事件
	{
		cout<<"lookup two country"<<endl;

		CEvt *pEvt=m_pEngine->CreateEvt("CCommunication");
		pEvt->SetValueString("Message","Hello !!!");
		pEvt->SetValueString("Sender",m_Name);
		pEvt->m_scope=2;
		pEvt->m_desobjid=RTI_OBJ;
		pEvt->SetDest("CCountry");
		pEvt->Send();
		delete pEvt;

	/*	CCommunication evt;
		evt.SetValueString("Message","Hello !!!");
		evt.SetValueString("Sender",m_Name);
		evt.m_scope=2;
		evt.m_desobjid=RTI_OBJ;
		evt.SetDest("CCountry");
		evt.Send();*/
	}
}

void CCountry::Simulation(double lasttime)
{
	CNode::Simulation(lasttime);
	if(!m_bInitiative)
		return;
}

void CCountry::Output()
{
	CNode::Output();
	if(!m_bInitiative)
		return;
	if(m_Name) cout<<m_Name<<" , "<<"population:"<<m_Population<<endl;
}

void CCountry::OnCCommunication(CEvt *pevent)
{
	if(!m_bInitiative)
		return;
	CCommunication *pCommunicationEvt=(CCommunication *)pevent;

	char *Sender=pCommunicationEvt->GetValueString("Sender");
	char *Message=pCommunicationEvt->GetValueString("Message");
	
	cout<<m_Name<<" receive "<<Sender<<" say "<<Message<<endl<<endl;
}



