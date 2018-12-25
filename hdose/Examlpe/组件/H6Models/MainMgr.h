// MainMgr.h: interface for the CMainMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINMGR_H__3B8FB0C2_1FD7_11D5_A51E_00055D05A3E4__INCLUDED_)
#define AFX_MAINMGR_H__3B8FB0C2_1FD7_11D5_A51E_00055D05A3E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//##ModelId=3AC98B1C0258

class H6Ginit;
class CTargetIndicate;
class CMainMgr : public CScnMgr   
{
	DECLARE_CREATE;
	DECLARE_EVENTMAP;

protected:
	//##ModelId=3AC98B1C025A
	CMainMgr();
	//##ModelId=3AC98B1C025B
	virtual ~CMainMgr();

private:
	//##ModelId=3AC98B1C028A
	virtual void OnH6GInit(H6Ginit *pEvt);
	virtual void OnEnable(CEvt *pEvt);
	virtual void OnTargetIndicate(CTargetIndicate *pEvt);

	//##ModelId=3AC98B1C028C
	virtual void tick(double lasttime);
	//##ModelId=3AC98B1C028F
public:
	virtual void OnInit();
};

#endif // !defined(AFX_MAINMGR_H__3B8FB0C2_1FD7_11D5_A51E_00055D05A3E4__INCLUDED_)
