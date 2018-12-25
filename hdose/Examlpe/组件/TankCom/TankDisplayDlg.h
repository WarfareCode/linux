#if !defined(AFX_DLG_H__C6D952B5_97B9_4D83_B1D2_D128B98FD80D__INCLUDED_)
#define AFX_DLG_H__C6D952B5_97B9_4D83_B1D2_D128B98FD80D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg dialog
#include "TankCom.h"
#include "LineObj.h"
class CTankDisplayDlg : public CDialog
{
// Construction
public:
	CTankDisplayDlg(CWnd* pParent = NULL);   // standard constructor
	CEngine *m_pEng;
	void plotObjData(double longt,double lat);
	void OutputText(CString str);

// Dialog Data
	//{{AFX_DATA(CDlg)
	enum { IDD = IDD_TANKDISPLAYDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
private:
	CDC		memoryDC0,memoryDC1;
	CBitmap MemBitmap0,MemBitmap1;	
	CBrush	BackBrush;
	CPen	penAxis,penLine,penTgt;
	CRect   clientRect;
	CRect	plotrect;
	

	void PlotBackBmp();

	



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	
//	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__C6D952B5_97B9_4D83_B1D2_D128B98FD80D__INCLUDED_)
