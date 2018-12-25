// MainMgr.cpp: implementation of the CMainMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "MainMgr.h"


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

END_EVENTMAP 

CMainMgr::CMainMgr()
{

}


CMainMgr::~CMainMgr()
{
	m_dlg.DestroyWindow();
	
} 

void CMainMgr::tick(double lasttime)
{

	CScnMgr::tick(lasttime);
	if(m_dlg.m_hWnd==0) return;

	m_dlg.tick();
}

void CMainMgr::OnInit()
{

	m_dlg.Create(IDD_ANTISHIPDISPLAYDIALOG);
	//m_dlg.ShowWindow(SW_SHOW);
	m_dlg.m_pEng=m_pEngine;
}

