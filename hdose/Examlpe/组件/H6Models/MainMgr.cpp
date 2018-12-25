// MainMgr.cpp: implementation of the CMainMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "MainMgr.h"
#include "Sensor.h"

#include "H6Ginit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
 
IMPLEMENT_CREATE_EX(CMainMgr,CScnMgr,0)

BEGIN_EVENTMAP(CMainMgr)  
	ON_HDOSEEVENT("H6Ginit",CMainMgr::OnH6GInit)//�����¼�����ص�����
	ON_HDOSEEVENT("Enable",CMainMgr::OnEnable)
	ON_HDOSEEVENT("CTargetIndicate",CMainMgr::OnTargetIndicate)

END_EVENTMAP 

CMainMgr::CMainMgr()
{

}

//##ModelId=3AC98B1C025B
CMainMgr::~CMainMgr()
{

} 


//##ModelId=3AC98B1C028C
void CMainMgr::tick(double lasttime)
{
	CScnMgr::tick(lasttime);
	static BOOL change=0;
	if((lasttime>5)&&(change==0))
	{//5���Ӻ�
		change=1;
		for(int i=0;i<0;i++)////ʵ������������
		{
			CObj *pObj=m_pEngine->CreateObj("CPlatform",0);
			if(pObj)
			{
				AddAggregateObj(pObj);
			}
		}
	}

////////////////////////////////////////////////////
	
}

void CMainMgr::OnInit()
{
///////////////////////////////////////////////��ʾ��α������ж���
	CObjList* pList[10];
	int nu=10;
	m_pEngine->LookupAllObjFromClass("CNode",pList,nu);
	for(int i=0;i<nu;i++)
	{
		POSITION pos=pList[i]->GetHeadPosition();
		while(pos)
		{
			CObj *pObj=pList[i]->GetNext(pos);
		}
	}
}
void CMainMgr::OnEnable(CEvt *pEvt)
{ //��̬ģ����ս���
	
	TRACE("h6g OnEnable\n");
}

void CMainMgr::OnH6GInit(H6Ginit *pEvt)
{ //��̬ģ����ս���
	
	TRACE("h6g OnInit %f\n",pEvt->m_latitude);

}
void CMainMgr::OnTargetIndicate(CTargetIndicate *pEvt)
{	


}
