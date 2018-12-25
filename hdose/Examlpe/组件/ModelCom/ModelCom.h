// ModelCom.h : main header file for the MODELCOM DLL
//

#if !defined(AFX_MODELCOM_H__B6DA0E84_C6B4_49EA_A3F9_53F127F26594__INCLUDED_)
#define AFX_MODELCOM_H__B6DA0E84_C6B4_49EA_A3F9_53F127F26594__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CModelComApp
// See ModelCom.cpp for the implementation of this class
//

class CModelComApp : public CWinApp
{
public:
	CModelComApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModelComApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CModelComApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELCOM_H__B6DA0E84_C6B4_49EA_A3F9_53F127F26594__INCLUDED_)
