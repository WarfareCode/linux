// MainMgr.h: interface for the CMainMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINMGR_H__3B8FB0C2_1FD7_11D5_A51E_00055D05A3E4__INCLUDED_)
#define AFX_MAINMGR_H__3B8FB0C2_1FD7_11D5_A51E_00055D05A3E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//##ModelId=3AC98B1C0258
#include "AntiShipDisplayDlg.h"

class MODELCOM_API CMainMgr : public CScnMgr   
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;

protected:
	CMainMgr();
	virtual ~CMainMgr();

private:
	virtual void tick(double lasttime);
public:
	CAntiShipDisplayDlg m_dlg;
	virtual void OnInit();
};

#endif // !defined(AFX_MAINMGR_H__3B8FB0C2_1FD7_11D5_A51E_00055D05A3E4__INCLUDED_)
