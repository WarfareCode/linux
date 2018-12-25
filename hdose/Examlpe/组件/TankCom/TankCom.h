// TankCom.h : main header file for the TANKCOM DLL
//

#if !defined(AFX_TANKCOM_H__BFB26609_4463_4679_9A20_AF6B37D44377__INCLUDED_)
#define AFX_TANKCOM_H__BFB26609_4463_4679_9A20_AF6B37D44377__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTankComApp
// See TankCom.cpp for the implementation of this class
//

class CTankComApp : public CWinApp
{
public:
	CTankComApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankComApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CTankComApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKCOM_H__BFB26609_4463_4679_9A20_AF6B37D44377__INCLUDED_)
