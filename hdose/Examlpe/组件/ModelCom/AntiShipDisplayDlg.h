#if !defined(AFX_ANTISHIPDISPLAYDLG_H__121222E8_5D5D_4F81_ABEE_4F51BDDA1894__INCLUDED_)
#define AFX_ANTISHIPDISPLAYDLG_H__121222E8_5D5D_4F81_ABEE_4F51BDDA1894__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AntiShipDisplayDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAntiShipDisplayDlg dialog
#include "ModelCom.h"
class CAntiShipDisplayDlg : public CDialog
{
// Construction
public:
	CAntiShipDisplayDlg(CWnd* pParent = NULL);   // standard constructor

	CEngine *m_pEng;
	void tick();
	void UpdataShipPos(char *Name,double longt,double lat);
	void UpdataSubPos(char *Name,double longt,double lat);
	void UpdataTorpedoPos(char *Name,double longt,double lat);
	void OutputText(CString str);

// Dialog Data
	//{{AFX_DATA(CAntiShipDisplayDlg)
	enum { IDD = IDD_ANTISHIPDISPLAYDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAntiShipDisplayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CDC		memoryDC0;
	CBitmap MemBitmap0;
	CBrush	BackBrush;
	CPen	penAxis,penText,penTor,penShip,penSub;
	CRect clientRect;
	CRect	plotrect;	

	void PlotBackBmp();
	virtual BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CAntiShipDisplayDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTISHIPDISPLAYDLG_H__121222E8_5D5D_4F81_ABEE_4F51BDDA1894__INCLUDED_)
